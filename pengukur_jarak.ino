#include<LiquidCrystal_I2C.h>//library LCD I2C
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);//(alamat lcd 0x27/0x3F, kolom, baris)

const int trigPin = 5;
const int echoPin = 18;

//mendefinisikan kecepatan suara cm/inci
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  // initialize LCD
  lcd.init();
  // turn on LCD backlight
  lcd.backlight();
  
  pinMode(trigPin, OUTPUT); // Set trigPin sebagai Output
  pinMode(echoPin, INPUT); // Set echoPin sebagai Input
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Perhitungan jarak
  distanceCm = duration * SOUND_SPEED / 2;

  // konversi ke inci
  distanceInch = distanceCm * CM_TO_INCH;

  // Prints jarak pada Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  
  // Prints jarak pada LCD
  // set kursor di kolom ke 0 baris ke 0
  lcd.setCursor(0, 0);
  lcd.print("Jarak:");
  lcd.print(distanceCm);
  lcd.print(" cm");
  // set kursor di kolom ke 0 baris ke 1
  lcd.setCursor(0, 1);
  lcd.print("Jarak:");
  lcd.print(distanceInch);
  lcd.print(" inch");
  if (distanceCm<30){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Jarak:");
    lcd.print(distanceCm);
    lcd.print(" cm");

    lcd.setCursor(0, 1);
    lcd.print("Jarak:Dekat");
  }else if (distanceCm<50){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Jarak:");
    lcd.print(distanceCm);
    lcd.print(" cm");

    lcd.setCursor(0, 1);
    lcd.print("Jarak:Normal");
  }else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Jarak:");
    lcd.print(distanceCm);
    lcd.print(" cm");

    lcd.setCursor(0, 1);
    lcd.print("Jarak:Jauh");
  }
  
  delay(2000);
  lcd.clear();
}