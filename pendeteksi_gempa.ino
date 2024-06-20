#define sensor_vibra 19 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor_vibra, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char baca_sensor = digitalRead(sensor_vibra);
  if (baca_sensor == HIGH){
    Serial.println(baca_sensor);
    Serial.println("Ada Gempa....!!!");
  } else{
    Serial.println(baca_sensor);
    Serial.println("Kondisi Aman");
  }
  delay(1000);
}
