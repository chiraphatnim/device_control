
#include <ESP32Servo.h>
Servo myservo;
String a command;
void setup() {
  Serial.begin(9600);
  myservo.attach(22);
  Servo();
  pinMode(2, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "15") {
      // Serial.println('Servo Moter => 15');
      myservo.write(15);  //เป็นการกำหนดองค์ศา
      blinkLED();
    } else if (command == "30") {
      // Serial.println('Servo Moter => 30');
      myservo.write(30);  //เป็นการกำหนดองค์ศา
      blinkLED();
    } else if (command == "60") {
      // Serial.println('Servo Moter => 60');
      myservo.write(60);  //เป็นการกำหนดองค์ศา
      blinkLED();
    } else if (command == "90") {
      // Serial.println('Servo Moter => 90');
      myservo.write(90);  //เป็นการกำหนดองค์ศา
      blinkLED();
    } else if (command == "115") {
      // Serial.println('Servo Moter => 115');
      myservo.write(115);  //เป็นการกำหนดองค์ศา
      digitalWrite(2, HIGH);
    } else if (command == "135") {
      // Serial.println('Servo Moter => 135');
      myservo.write(135);  //เป็นการกำหนดองค์ศา
      digitalWrite(2, HIGH);
    } else if (command == "160") {
      // Serial.println('Servo Moter => 160');
      myservo.write(160);  //เป็นการกำหนดองค์ศา
      blinkLED150();

      
    } else if (command == "Stop") {
      // Serial.println('Servo Moter => 0');
      myservo.write(0);
      digitalWrite(2, LOW);
    }
  }
}

void blinkLED() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(2, HIGH);
    delay(400);
    digitalWrite(2, LOW);
    delay(400);
  }
}
void blinkLED150() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(2, HIGH);
    delay(3000);
    digitalWrite(2, LOW);
    delay(3000);
  }
}
void blinkLED140() {
    digitalWrite(2, LOW);  
}