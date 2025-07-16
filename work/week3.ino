bool isOn = false;
bool ready = false;
int countdown = 0;

void setup() {
  
  Serial.begin(9600);
 
  
 
}

void loop() {
  Serial.println("นาย จิรภัทร นิ่มอนงค์");
  delay(1000);
  Serial.println("ใส่จำนวนวินาทีสำหรับ นับถอยหลัง ");
  delay(1000);
  if(Serial.available()){
    countdown = Serial.parseInt();
    Serial.print("จะเริ่ม นับถอยหลังที่ : ");
    Serial.print("countdown");
    ready = true;
  }


  if(ready){
    for(int i = countdown; i >=0; i--){
    Serial.print(">>Light---");
    Serial.println(i);
    delay(1000);
    }
    Serial.println("เวลา...");
    ready = false;
    Serial.println("พิมพ์ข้อมูลแล้วเริ่มใหม่ ...");

  }
  
  // if(isOn){
  //   serial.println("off");
  //   isOn = false;
  // }else{
  //   serial.println("ON");
  //   isOn = true;
  // }
  // delay(1000);
}
