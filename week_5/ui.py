import sys
import serial

from  PyQt5.QtWidgets import QApplication,QWidget,QPushButton,QVBoxLayout,QMessageBox

try :
  arduino = serial.Serial('COM3', 9600, timeout=1) #เปลี่ยน COM3 เป็นพอร์ตที่ Arduino เชื่อมต่อ
except Exception as e:
  arduino = None
  print("เชื่อต่อไม่ได้: ",e)

class AruinoControl(QWidget):
    def __init__(self):
      super().__init__()
      self.setWindowTitle("Aruino Controller") #ชื่อโปรแกรมที่กำหนด
      self.setGeometry(200,200,300,150) #ขนาด

      layout = QVBoxLayout()
      self.btn_on = QPushButton("LED ON")
      self.btn_on.clicked.connect(lambda:self.send_command("ON"))
      layout.addWidget(self.btn_on)

      self.btn_off = QPushButton("LED OFF")
      self.btn_off.clicked.connect(lambda:self.send_command("OFF"))
      layout.addWidget(self.btn_off)

      self.btn_BLINK = QPushButton("LED BLINK")
      self.btn_BLINK.clicked.connect(lambda:self.send_command("BLINK"))
      layout.addWidget(self.btn_BLINK)

      self.setLayout(layout)

    def send_command(self, command):
      if(arduino):
        arduino.write((command+'\n').encode())
      else:
        QMessageBox.critical(self, "Error","ไม่พบการเชื่อมต่อ Arduino")
if __name__ == "__main__":
  app = QApplication(sys.argv)
  window = AruinoControl()
  window.show()
  sys.exit(app.exec_())