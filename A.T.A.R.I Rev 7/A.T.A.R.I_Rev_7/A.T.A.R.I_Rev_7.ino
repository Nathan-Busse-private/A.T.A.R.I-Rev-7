#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display



int incomingByte = 0;
int MA1 =  12;     // Motor A
int MA2 =  9;      // Motor A
int PWM_A =10;     // Speed PWM Motor A
int MB1 =  13;     // Motor B
int MB2 =  8;      // Motor B
int PWM_B =11;  // Speed PWM Motor B

//int horn_Buzz = 4;
//boolean horn = false;
boolean lightFront = false;

int command;   

//Int to store app command state.

int speedCar = 255;  
int speedCarM = 255;// 50 - 255.
//int speed_Coeff = 4;

const int trigPin = A3;
const int echoPin = A2;

// defines variables
long duration;
int distance;
int safetyDistance;

//boolean lightFront = false;
//boolean lightBack = false;





void setup() {


pinMode(MA1, OUTPUT);   //Motor A1
pinMode(MA2, OUTPUT);   //Motor A2
pinMode(PWM_A, OUTPUT); //Speed PWM Motor A
pinMode(MB1, OUTPUT);   //Motor B1
pinMode(MB2, OUTPUT);   //Motor B2
pinMode(PWM_B, OUTPUT); //Speed PWM Motor 
//pinMode(horn_Buzz, OUTPUT);


    
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input


//pinMode(horn, OUTPUT);
lcd.init();
lcd.clear();         
lcd.backlight(); 
Serial.begin(9600);
Serial.println("I received");
lcd.setCursor(5,19);
lcd.println("A.T.A.R.I");
lcd.setCursor(19,12);   //Move cursor to character 2 on line 1
lcd.print(" Made by Nathan");

}

void loop() {
if (Serial.available() > 0) {
incomingByte = Serial.read();

}

switch (incomingByte)
{
//case 'V':horn = true;break;
//case 'v':horn = false;break;
//horn_Buzz;





case '0':speedCar = 100;break;
case '1':speedCar = 115;break;
case '2':speedCar = 130;break;
case '3':speedCar = 145;break;
case '4':speedCar = 160;break;
case '5':speedCar = 175;break;
case '6':speedCar = 190;break;
case '7':speedCar = 205;break;
case '8':speedCar = 220;break;
case '9':speedCar = 255;break; 
speedCar; 

{


case 'S':
      


Stop(1);
Serial.println("Stop");
//lcd.setCursor(5,19);
//lcd.println("");
//incomingByte = "DEC";
}
break;

case 'F':
     
{
Forward(1);
//lightFront;

Serial.println("Forward");
//lcd.setCursor(5,19);
//lcd.println("Forward");
//incomingByte = 'DEC';
}
break;
case 'B':
{
Backward(1);
Serial.println("Backward");
//lcd.setCursor(5,19);
//lcd.println("Backward");
//incomingByte = 'DEC';
}
break;
case 'R':
{
turnRight(1);
Serial.println("turn Right");
//lcd.setCursor(5,19);
//lcd.println("Turning Right");
//incomingByte = 'DEC';
}
break;
case 'L':
{
turnLeft(1);
Serial.println("turn Left");
//lcd.setCursor(5,19);
//lcd.println("Turning Left");
//incomingByte = 'DEC';
//{
//break;
//case 'J':

//horn(1);
//Serial.println("Buzzed");
//incomingByte = 'DEC';

}

break;
case 'I':
{
forwardRight(1);
Serial.println("turn Right");
//lcd.setCursor(5,19);
//lcd.println("Turning Right");
//incomingByte = 'DEC';
}

break;
case 'J':
{
backRight(1);
Serial.println("turn Right");
//lcd.setCursor(5,19);
//lcd.println("Turning Right");
//incomingByte = 'DEC';
}

break;
case 'G':
{
forwardLeft(1);
Serial.println("turn Left");
//lcd.setCursor(5,19);
//lcd.println("Turning Right");
//incomingByte = 'DEC';
}

break;
case 'H':
{
backLeft(1);
Serial.println("turn Left");
//lcd.setCursor(5,19);
//lcd.println("Turning Right");
//incomingByte = 'DEC';
}

}
}


void Forward(int time)
{
digitalWrite(MA1, HIGH);
digitalWrite(MA2, LOW);
analogWrite(PWM_A, speedCar);
digitalWrite(MB1, HIGH);
digitalWrite(MB2, LOW);
analogWrite(PWM_B, speedCar);
delay(time);
  

}

void Backward(int time)
{
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
analogWrite(PWM_A, speedCar);
digitalWrite(MB1, LOW);
digitalWrite(MB2, HIGH);
analogWrite(PWM_B, speedCar);
delay(time);

}



void turnLeft(int time)
{
digitalWrite(MA1, HIGH);
digitalWrite(MA2, LOW);
analogWrite(PWM_A, speedCar);
digitalWrite(MB1, LOW);
digitalWrite(MB2, HIGH);
analogWrite(PWM_B,speedCar);
delay(time);
}

void turnRight(int time)
{
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
analogWrite(PWM_A, speedCar);
digitalWrite(MB1, HIGH);
digitalWrite(MB2, LOW);
analogWrite(PWM_B, speedCar);
delay(time);
}

void forwardRight (int time)
{
digitalWrite (MB1, HIGH);
digitalWrite (MB2, LOW);
analogWrite(PWM_B, 255);
digitalWrite (MA1, LOW);
digitalWrite (MA2, LOW);
analogWrite(PWM_A, 0);

}

void backRight (int time)
{
digitalWrite (MB1, LOW);
digitalWrite (MB2, HIGH);
analogWrite(PWM_B, 255);
digitalWrite (MA1, LOW);
digitalWrite (MA2, LOW);
analogWrite(PWM_A, 0);



}

void forwardLeft (int time)
{

digitalWrite (MB1, LOW);
digitalWrite (MB2, LOW);
analogWrite(PWM_B, 0);
digitalWrite (MA1, HIGH);
digitalWrite (MA2, LOW);
analogWrite(PWM_A, 255);
}

void backLeft (int time)
{
digitalWrite (MB1, LOW);
digitalWrite (MB2, LOW);
analogWrite(PWM_B, 0);
digitalWrite (MA1, LOW);
digitalWrite (MA2, HIGH);
analogWrite(PWM_A, 255);

}



void Stop(int time)
{
digitalWrite(MA1, LOW);
digitalWrite(MA2, LOW);
analogWrite(PWM_A, 0);
digitalWrite(MB1, LOW);
digitalWrite(MB2, LOW);
analogWrite(PWM_B, 0);

delay(time);
}
