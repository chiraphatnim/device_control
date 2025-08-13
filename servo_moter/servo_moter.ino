#include <ESP32Servo.h>
Servo myservo;
char user_input;
void setup() {
  Serial.begin(9600);
  myservo.attach(22);
  Servo();
}

void loop() {
  while (Serial.available() > 0) {
    char select_mode = Serial.read();
    user_input = select_mode;
    if (user_input != select_mode) {
      user_input = select_mode;
    } else {
      user_input = user_input;
    }
  }

  if (user_input == '0') {
    Serial.println('Servo Moter => 0');
    myservo.write(0);  //เป็นการกำหนดองค์ศา
    delay(1000);
  } else if (user_input == '1') {
    Serial.println('Servo Moter => 120');
    myservo.write(120);  //เป็นการกำหนดองค์ศา
    delay(1000);
  } else if (user_input == '2') {
    Serial.println('Servo Moter => 150');
    myservo.write(150);  //เป็นการกำหนดองค์ศา
    delay(1000);
  } else if (user_input == '3') {
    Serial.println('Servo Moter => 180');
    myservo.write(180);  //เป็นการกำหนดองค์ศา
    delay(1000);
  } else if (user_input == '4') {
    Serial.println('Servo Moter => 45');
    myservo.write(45);  //เป็นการกำหนดองค์ศา
    delay(1000);
  }
}
