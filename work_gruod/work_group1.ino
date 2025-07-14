int a = -1; // true = แสดงเลขคู่, false = แสดงเลขคี่
int maxNumber = 10;   // แสดงเลขถึงเลขสูงสุดนี้

void setup() {
  Serial.begin(9600);
  delay(1500);


  if (a==1) {
    Serial.print("แสดงลำดับเลขจำนวนเต็ม 'คู่' \n");
    for (int i = 0; i <= maxNumber; i++) {
      if (i % 2 == 0) {
        Serial.println(i);
        delay(1500); // หน่วงเวลาเพื่อดูการแสดงผล
      }
    }
  } else if(a==2){
    Serial.print("แสดงลำดับเลขจำนวนเต็ม 'คี่' \n");
    for (int i = 0; i <= maxNumber; i++) {
      if (i % 2 != 0) {
        Serial.println(i);
        delay(1500);
      }
    }
  }else{
    Serial.print("คุณไม่เลือกฟังก์ชั่นที่กำหนด");
  }

  Serial.print("จบการแสดงผล");
}

void loop() {
  
}
