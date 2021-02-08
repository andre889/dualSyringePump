//#include <AccelStepper.h>
#include <MultiStepper.h>

#include <accelstepper.h>

#define dirPin 5
#define stepPin 2
#define motorInterfaceType 1

#define dirPin2 6
#define stepPin2 3
#define Q 10 //Flowrate in ml/min

AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
AccelStepper stepper2 = AccelStepper(motorInterfaceType, stepPin2, dirPin2);

void setup() {
  long stepdist = 25000;
  //long thespeed = 100;
  // put your setup code here, to run once:
 stepper.setMaxSpeed(calculateMaxSpeed(Q));
 stepper2.setMaxSpeed(calculateMaxSpeed(Q));
 pinMode(8,OUTPUT);
 digitalWrite(8,LOW);
 //stepper.setSpeed(thespeed);
 stepper.setAcceleration(100000.0);
 stepper.moveTo(stepdist);
 
 //stepper2.setSpeed(thespeed);
 stepper2.setAcceleration(100000.0);
 stepper2.moveTo(-stepdist);
 //stepper.run();
 Serial.begin(9600);
 Serial.print(calculateMaxSpeed(Q));
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (stepper.distanceToGo() == 0)
        stepper.moveTo(-stepper.currentPosition());

     if (stepper2.distanceToGo() == 0)
        stepper2.moveTo(-stepper2.currentPosition());
     //stepper.setSpeed(1000);
     //stepper2.setSpeed(1000);
  //stepper.runSpeed();
   stepper.run();
   stepper2.run();

}

long calculateMaxSpeed(double flowrate)
{
  //Flowrate is the volumetric flow rate given in mL/min!
  
  return (long)flowrate/0.009427;
}