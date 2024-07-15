#include <LCD_I2C.h>
#include <Servo.h>
#include <math.h>
#include <NewPing.h>

#define SERVO_X_PIN 2
#define SERVO_Y_PIN 3
#define TRIG_PIN 10
#define ECHO_PIN 11
#define MAX_DISTANCE 100

Servo servoX, servoY;

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  servoX.attach(SERVO_X_PIN);
  servoY.attach(SERVO_Y_PIN);

  servoX.write(0);
  servoY.write(0);

  Serial.begin(115200);
}

void loop() {
    for (int x = 45; x <= 125; x += 10) {
      servoX.write(x);
      delay(500);
      for (int y = 0; y <= 180; y += 10) {
        servoY.write(y);
        delay(500);

        unsigned int distance = sonar.ping_cm();

        Serial.print(x);
        Serial.print(",");
        Serial.print(y);
        Serial.print(",");
        Serial.println(distance);

      }
    }
    delay(1000);
}
