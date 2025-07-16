#define LED_BUILNIT 2
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILNIT,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(LED_BUILNIT,1);
  Serial.print("สวัสดี จิรภัทร นิ่มอนงค์ ");
  Serial.print("light ... \n");
  delay(1000);

  digitalWrite(LED_BUILNIT,0);
  Serial.print("สวัสดี จิรภัทร นิ่มอนงค์ ");
  Serial.print("not light ... \n");
  delay(1000);
}
