#include <LCD_I2C.h>
#include <Servo.h>

Servo sg90, sg902;

long duration;
int distance;

int pos = 0;

const int trigPin = 10;
const int echoPin = 11;


void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  sg90.attach(2);
  sg902.attach(3);
  //lcd.print("Back2TheFuture");
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  for ( pos = 0; pos <= 180; pos++) {
    sg90.write(pos);
    sg902.write(pos);
    delay(15);
  }
  for ( pos = 180; pos >= 0; pos--) {
    sg90.write(pos);
    sg902.write(pos);
    delay(15);
  }

  Serial.print("Distance: ");
  Serial.println(distance);

  //delay(3000);

}
