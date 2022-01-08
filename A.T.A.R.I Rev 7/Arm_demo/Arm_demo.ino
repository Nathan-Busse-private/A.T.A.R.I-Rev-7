#include <Servo.h>
Servo motor1,motor2, motor3, motor4;
int degree1 = 100, degree2 = 100, degree3 = 15, degree4 = 180, degree5 = 1, degree6 = 50, degree7 = 100, degree8 = 90; ;

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
motor1.attach (6); // Claw
motor2.attach (9); // Right
motor3.attach (10); // Left
motor4.attach (11);// Middle
}

void loop() {
  // put your main code here, to run repeatedly: 
motor1.write (degree1);
delay(1000);
motor2.write (degree2);
delay(1000);
motor3.write (degree3);
delay(1000);
motor4.write (degree4);
delay(1000);


motor1.write (degree5);
delay(1000);
motor2.write (degree6);
delay(1000);
motor3.write (degree7);
delay(1000);
motor4.write (degree8);
delay(1000);
}
