
void setup() {
  Serial.begin(9600);
  delay(1000);
  

  
}

void loop() {
  Serial.println("นาย จิรภัทร นิ่มอนงค์");
  delay(1000);
  Serial.println("----- ไฟสัญญาณจราจร -----");
  for (int greenRoad = 1; greenRoad <= 4; greenRoad++) {
    for (int i = 1; i <= 4; i++) {
      if (i == greenRoad) {
        Serial.print(i);
        Serial.println(" is Green");
      } else {

        Serial.print(i);
        Serial.println(" is Red");
      }
    }
    Serial.println("-------------------");
    delay(3000);
  }
}
