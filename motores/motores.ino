#include <AFMotor.h>
#include <Servo.h>
AF_Stepper motor (48, 2);
Servo servo1;
AF_DCMotor motordc(2);

int pinLlave1 = 2;
int ser;
String captura;
String input;
int mot = 0;
int val = 0;
int inputInt;
void setup()
{ Serial.begin(9600);
  servo1.attach(9);       // El servo 1 se controla con el pin 9
  //servo2.attach(10);      // El servo 2 se controla con el pin 10
  pinMode(pinLlave1,OUTPUT);
}
void loop()
{
  
 
  if(Serial.available()>0){
  input = Serial.readString();
  inputInt = input.toInt();
//  Serial.println(input);
//  }
 
  mot = inputInt / 100;
  if( mot > 10){
    mot = inputInt / 1000;
    val =  inputInt - (1000 * mot);
  }else if (mot >= 1 && mot <=10){
    mot = inputInt / 100;
    val = inputInt - (100 * mot);
  }else{
    mot = inputInt / 10;
    val = inputInt - (10 * mot);
  }

  if (mot == 1){

    

     pasos(val, BACKWARD, INTERLEAVE);
  }

  if (mot == 2){


    servo(val);
    
  }

  if (mot == 3){


    if (val == 1){
      dc (FORWARD);
    }
    if (val == 2){
      dc (BACKWARD);
    }
    if (val == 0){

        motordc.run(RELEASE);

    }
    
  }
//  Serial.println(mot);
//  Serial.println(val);

//    servo(captura.toInt());
 // }
  captura = Serial.readString();
  captura.toInt();
  //   servo(captura.toInt());
  //   pasos(50, BACKWARD, INTERLEAVE);
  }
//delay(500);
}

void servo(int serv) {
  Serial.println(serv);
  if (servo1.read() == 0){
    servo1.write(serv);
    delay(200);
  }
  else {
    servo1.write(0);
    delay(15);
    servo1.write(serv);
  }
}

void pasos (int paso, char sent, char movi) {
  motor.setSpeed(50);
  motor.step(paso, sent, movi);
}

void dc (char sent) {
  motordc.run(sent);
  motordc.setSpeed(100);
}
