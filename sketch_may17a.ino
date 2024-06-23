#include <LCD_I2C.h>
#include <Servo.h>
#include <math.h>
#include <NewPing.h>

#define SERVO_X_PIN 2
#define SERVO_Y_PIN 3
#define TRIG_PIN 10
#define ECHO_PIN 11
#define MAX_DISTANCE 100

// bool startScan = false;

Servo servoX, servoY;

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  servoX.attach(SERVO_X_PIN);
  servoY.attach(SERVO_Y_PIN);

  servoX.write(0);
  servoY.write(0);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  // if (Serial.available() > 0) {
  //   String command = Serial.readStringUntil('\n');  // Read the incoming string

  //   if (command == "p") {
  //     startScan = true;  // Set the flag to stop the loop
  //     Serial.println("Scan started.");
  //   } 
  // }

  // if (startScan) {
    
    for (int x = 45; x <= 90; x += 1) {
      for (int y = 0; y <= 90; y += 1) {
        servoX.write(x);
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

    
  //   startScan = false;
  //   Serial.println("Scanning completed. Waiting for the start...");
  // }
    delay(500);
}
