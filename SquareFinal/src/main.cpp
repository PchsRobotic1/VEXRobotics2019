/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Student                                          */
/*    Created:      Tue Sep 17 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;






vex::motor LeftMotor   = vex::motor( vex::PORT1 );
vex::motor RightMotor  = vex::motor( vex::PORT10, true );

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here

//Defining Function to go straight
double straight(double x) {
  double dist=x;
    double deg;
    //converts linear to degress
    deg =(360*dist)/(6.28*2);
    //startRotateFor makes both happen at same time
   RightMotor.startRotateFor(vex::directionType::fwd,(deg), vex::rotationUnits::deg, (30), vex::velocityUnits::pct);
   LeftMotor.rotateFor(vex::directionType::fwd,(deg), vex::rotationUnits::deg,(30), vex::velocityUnits::pct);
   return double (x);
}
double turnLeft(double DegOfTurn){
  double deg;
  // the degree it turns is 1/6 of the degree we give it so we times it by 6.
  deg=(6*DegOfTurn);
  RightMotor.startRotateFor(vex::directionType::fwd,(deg), vex::rotationUnits::deg, (50), vex::velocityUnits::pct);
  return double(DegOfTurn);
}
double turnRight(double DegOfTurn){
  double deg;
  // the degree it turns is 1/6 of the degree we give it so we times it by 6.
  deg=(6*DegOfTurn);
  LeftMotor.startRotateFor(vex::directionType::fwd,(deg), vex::rotationUnits::deg, (50), vex::velocityUnits::pct);
  //LeftMotor.startRotateFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v)
  return double(DegOfTurn);
}
double straightandTurn(double dista, double angle){
  straight(dista);
  turnLeft(angle);
  return double(dista+angle);
}
int main() {
  for (int i=0; i<4; i++)
  {
   straightandTurn(40,90);
   vex::task::sleep(1500);
  }
  //straightandTurn(36,90);
  //straightandTurn(36,90);
  //straightandTurn(36,90);
  //straightandTurn(36,90);
  //straight(36);
  //turnLeft(90);
  //straight(1404);
    //makes the program do the math for distance for us
    //double dist=24.0;
    //double deg;
    //deg =(360*dist)/(6.28*2);
    //startRotateFor makes both happen at same time
    //RightMotor.startRotateFor(vex::directionType::fwd,(deg), vex::rotationUnits::deg);
    //LeftMotor.rotateFor(vex::directionType::fwd,(deg), vex::rotationUnits::deg);
   
}
