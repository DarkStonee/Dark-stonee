

#include<Servo.h>
const int Trig = 13;
const int Echo = 12;
#define Ena 3
#define In1 6
#define In2 7
#define In3 8
#define In4 9
#define Max_DISTANCIA 20
Servo servoMotor;
Servo myservoMotor;
int rightDistance = 0;
int leftDistance   = 0;
int middleDistance = 0;


void forward()
{
analogWrite(Ena,120);
digitalWrite(In1,HIGH);
digitalWrite(In2,HIGH);
digitalWrite(In3,HIGH);
digitalWrite(In4,HIGH);
delay(1000);
Serial.println(" asia Adelante");

}

int distance()
{
unsigned int Tiempo=0;
 digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  Tiempo=((unsigned int) pulseIn(Echo, HIGH)/58);
  Serial.print("Distancia");
  Serial.print(Tiempo);
  Serial.println("cm");
 
  }
  
void Stop()
{
  analogWrite(Ena,0);
  digitalWrite(In1,LOW);
  digitalWrite(In2,LOW);
  digitalWrite(In3,LOW);
  digitalWrite(In4,LOW);
   Serial.println("alto");
}








void setup() {
 Serial.begin(9600);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  servoMotor.attach(10);
 
}
void loop() 
{
 servoMotor.write(102);
delay(2000);
Serial.println("giro de las llantas (linea recta"); 
if (middleDistance >= 170)
{
forward();
}
middleDistance = distance();
if (middleDistance <= 50)
{
  
Stop(100);
delay(100);
myservoMotor.write(0);
delay(500); 
myservoMotor.write(102);
delay(500);
myservoMotor.write(180);
delay(500);
//forward(); 
//delay(400);

rightDistance = distance();
if(rightDistance <= 50)
servoMotor.write(180);
delay(500);
myservoMotor.write(102);
delay(500);
leftDistance = distance();
delay(500);
leftDistance  = distance();
    
}
if (rightDistance > leftDistance && middleDistance )
{
myservoMotor.write(0);
 delay(500); 
myservoMotor.write(180);
 delay(500)
 servoMotor.write(0);
delay(3000);
servoMotor.write(102);
delay(3000);
}
if (rightDistance < leftDistance && middleDistance )
{

servoMotor.write(180);
delay(3000);
servoMotor.write(102);
delay(3000);
  
}
//forward(); 
//delay(400);
//servoMotor.write(0);
//delay(3000);
//Serial.println("giro de las llantas (0 grados) derecha");
//Serial.println("asia delante");

//Stop();

}
