import cv2
import mediapipe as mp
import math
import serial


class HandAngleDetector:
    def __init__(self, min_detection_conf=0.7, min_tracking_conf=0.7, serial_port=None, baud_rate=9600):
        self.mp_hands = mp.solutions.hands
        self.mp_drawing = mp.solutions.drawing_utils
        self.hands = self.mp_hands.Hands(
            min_detection_confidence=min_detection_conf,
            min_tracking_confidence=min_tracking_conf,
        )
        self.cap = cv2.VideoCapture(0)
        self.esp = None
        if serial_port:
            try:
                self.esp = serial.Serial(serial_port, baud_rate, timeout=1)
                print(f"Connected to {serial_port} at {baud_rate} baud")
            except Exception as e:
                print("Error connecting to Serial:", e)
                self.esp = None

    def calculate_angle(self, wrist, thumb, index):
        # สร้าง vector
        v1 = [thumb[0] - wrist[0], thumb[1] - wrist[1]]
        v2 = [index[0] - wrist[0], index[1] - wrist[1]]

        # dot product และ magnitude
        dot = v1[0] * v2[0] + v1[1] * v2[1]
        mag1 = math.sqrt(v1[0] ** 2 + v1[1] ** 2)
        mag2 = math.sqrt(v2[0] ** 2 + v2[1] ** 2)

        if mag1 * mag2 != 0:
            return math.degrees(math.acos(dot / (mag1 * mag2)))
        return 0

    def run(self):
        while self.cap.isOpened():
            ret, frame = self.cap.read()
            if not ret:
                break

            frame = cv2.flip(frame, 1)
            rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            results = self.hands.process(rgb)

            if results.multi_hand_landmarks:
                for hand_landmarks in results.multi_hand_landmarks:
                    self.mp_drawing.draw_landmarks(
                        frame, hand_landmarks, self.mp_hands.HAND_CONNECTIONS
                    )

                    h, w, _ = frame.shape
                    thumb_tip = hand_landmarks.landmark[4]
                    index_tip = hand_landmarks.landmark[8]
                    wrist = hand_landmarks.landmark[2]  # แก้เป็นข้อมือจริง

                    # แปลงพิกัด
                    x0, y0 = int(wrist.x * w), int(wrist.y * h)
                    x1, y1 = int(thumb_tip.x * w), int(thumb_tip.y * h)
                    x2, y2 = int(index_tip.x * w), int(index_tip.y * h)

                    # คำนวณมุม
                    angle = self.calculate_angle((x0, y0), (x1, y1), (x2, y2))

                    # ส่งค่าไป Arduino (ถ้าเชื่อม)
                    if self.esp:
                        try:
                            self.esp.write(f"{int(angle)}\n".encode())
                        except Exception as e:
                            print("Error sending to Arduino:", e)

                    # แสดงผล
                    cv2.putText(
                        frame,
                        f"Angle: {int(angle)} deg",
                        (50, 100),
                        cv2.FONT_HERSHEY_SIMPLEX,
                        1,
                        (0, 255, 0),
                        2,
                    )

                    cv2.circle(frame, (x1, y1), 8, (255, 0, 0), -1)
                    cv2.circle(frame, (x2, y2), 8, (0, 0, 255), -1)

            cv2.imshow("Hand Angle Detection", frame)
            if cv2.waitKey(1) & 0xFF == 27:  # ESC
                break

        self.cap.release()
        cv2.destroyAllWindows()
        if self.esp:
            self.esp.close()


# เรียกใช้งาน
if __name__ == "__main__":
    detector = HandAngleDetector(serial_port='COM3', baud_rate=9600)
    detector.run()
