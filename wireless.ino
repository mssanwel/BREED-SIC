/* This code sets the motor to spin at a fix speed and measures 


1) Rotation Count
2) Displays the current position 
3) Displays the speed of the motor
*/
//motor
int speed = 0;
char incomingByte ='0';
#include <Servo.h>
#include <string>
using namespace std;
long int counter = 0;
const long int ticRatioMainMotor = 6000;
float rel_angle = 0;
volatile long int pos_Main=0;
//0 = full, 1 means half
int SPEED = 0;
String w = "";
#define ENCA 3 // YELLOW
#define ENCB 2 // WHITE

Servo   pusherESC;  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Attach the relative encoder to the ISR
  pinMode(ENCA,INPUT_PULLUP);
  pinMode(ENCB,INPUT_PULLUP);
  attachInterrupt( digitalPinToInterrupt(ENCA), readEncoder_Main, RISING);
  Serial.println("Arming........");   // just some display message 
  delay(2000);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(pos_Main);
  //867
  //Serial.println(Serial.available());
  if(Serial.available() > 0){
    String val =  Serial.readString();
    Serial.println(val);
    SPEED = val.toInt();
    analogWrite(5,SPEED);
    
    
    }
   //left
   //if half of the cycle

   int tem = pos_Main%867 + 1;
   
   if(tem > 433 && tem < 867){
    analogWrite(5,60);//half speed
    Serial.println("left speed halved");
    
    }
    else{
      analogWrite(5,255);//full
      Serial.println("right");
      }

 //delay(200);
  delay(100);//pusherESC.writeMicroseconds(2000);
  analogWrite(5,255);
  //delay(2000);
  analogWrite(5,20);
  //delay(2000);
}



void readEncoder_Main(){
 int b_A = digitalRead(ENCB);
  if(b_A > 0){
    pos_Main++;
  }
  else{
    pos_Main--;
  }
}
