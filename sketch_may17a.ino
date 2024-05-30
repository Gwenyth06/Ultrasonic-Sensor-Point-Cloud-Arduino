#include <LCD_I2C.h>
#include <Servo.h>
#include <math.h>

Servo sg90, sg902;

long duration;
int distance;

int deg = 0;
int deg2 = 0;
float adjacent,opposite,rad = 0;

const int trigPin = 10;
const int echoPin = 11;


void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  sg90.attach(2);
  sg902.attach(3);

  sg90.write(deg);
  sg902.write(deg2);
  //lcd.print("Back2TheFuture");
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(deg <= 180) {
    for (deg2 = 0; deg2 <= 180; deg2++) {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);

      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      duration = pulseIn(echoPin, HIGH);

      distance = duration * 0.034 / 2;

      rad = radians(deg);
      opposite = distance * sin(rad);
      adjacent = distance * cos(rad);

      sg902.write(deg2);
      delay(1000);
    }
    pos = pos + 5;
    sg90.write(deg);
  } else {

  }

  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("pos: ");
  Serial.println(pos);
  Serial.print("pos2: ");
  Serial.println(pos2);
  delay(1000);
}
