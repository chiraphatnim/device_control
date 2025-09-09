#include <ESP32Servo.h>
Servo myservo;
float angle = 0.0;

void setup() {
  Serial.begin(9600);
  myservo.attach(32);             // รอให้ Serial พร้อม     
}

void loop() {
  // เช็คว่ามีข้อมูล Serial เข้ามา
  if (Serial.available() > 0) {
    String line = Serial.readStringUntil('\n');  // อ่านค่าจนเจอ \n
    line.trim();                                 

      
      if (angle < 90.0) {
        myservo.write(line.toInt());
      } else {
        myservo.write(0);
      }
    }
  }
}
