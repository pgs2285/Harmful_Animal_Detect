#include "HCMotor.h"
//#include <Buzzer.h>
/* Pins used to drive the motors */
#define DIR_PIN 8 //Connect to drive modules 'direction' input.
#define CLK_PIN 9 //Connect to drive modules 'step' or 'CLK' input.


int input_data;
//Buzzer buzzer(13);
HCMotor HCMotor;



void setup() 
{
  Serial.begin(9600);
  HCMotor.Init();
  HCMotor.attach(0, STEPPER, CLK_PIN, DIR_PIN);
  HCMotor.Steps(0,CONTINUOUS);
  pinMode(9,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(9,LOW);
  digitalWrite(13,LOW);
}


void loop() 
{

  while(Serial.available()){
    input_data = Serial.read();
  }
  if(input_data == '0'){
    digitalWrite(9,LOW);
    digitalWrite(13,LOW);
    HCMotor.DutyCycle(0, 0);
  }
  else if(input_data =='5'){
    digitalWrite(9,HIGH);
    digitalWrite(13,HIGH);
    HCMotor.Direction(0, REVERSE); // 왼쪽
    HCMotor.DutyCycle(0, 10);
    delay(2000);
  }
  else if(input_data =='4'){
    digitalWrite(9,HIGH);
    digitalWrite(13,HIGH);
    HCMotor.Direction(0, REVERSE); // 왼쪽
    HCMotor.DutyCycle(0, 10);
    delay(1000);
  }
  else if(input_data =='3'){
    digitalWrite(9,HIGH);
    digitalWrite(13,HIGH);
    delay(1000);
  }
  else if(input_data =='2'){
    digitalWrite(9,HIGH);
    digitalWrite(13,HIGH);
    HCMotor.Direction(0, FORWARD);
    HCMotor.DutyCycle(0, 10);
    delay(1000);
  }
  else if(input_data =='1'){
    digitalWrite(9,HIGH);
    digitalWrite(13,HIGH);
    HCMotor.Direction(0, FORWARD); 
    HCMotor.DutyCycle(0, 10);
    delay(2000);
  }




  /* Set the duty cycle of the clock signal in 100uS increments */
//  HCMotor.DutyCycle(0, Speed);

}
