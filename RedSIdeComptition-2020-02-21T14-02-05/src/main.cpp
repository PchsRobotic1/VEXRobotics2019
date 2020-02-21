/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftMotor            motor         1               
// RightMotor           motor         10              
// ArmMotor             motor         8               
// ClawMotor            motor         3               
// Controller1          controller                    
// SliderMotor          motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
double straight(double x) { 
  double power = 70.0;
  double dist=x; 

  double deg; 

  //converts linear to degress 

  deg =(360*dist)/(6.28*2); 

  //startRotateFor makes both happen at same time 

  RightMotor.startRotateFor(vex::directionType::fwd,(deg), vex::rotationUnits::deg, power, vex::velocityUnits::pct);  
  LeftMotor.rotateFor(vex::directionType::fwd,(deg), vex::rotationUnits::deg,power, vex::velocityUnits::pct); 

  return double (x); 

} 
double turnLeft(double DegOfTurn){ 

  double deg; 

  // the degree it turns is 1/6 of the degree we give it so we times it by 6. 

  deg=(3*DegOfTurn); 

  RightMotor.startRotateFor(vex::directionType::fwd,(deg), vex::rotationUnits::deg, (50), vex::velocityUnits::pct); 

  return double(DegOfTurn); 

} 

double turnRight(double DegOfTurn){ 

  double deg;
  // the degree it turns is 1/6 of the degree we give it so we times it by 6. 

  deg=(-12*DegOfTurn); 

  LeftMotor.startRotateFor(vex::directionType::fwd,(deg), vex::rotationUnits::deg, (50), vex::velocityUnits::pct); 
  RightMotor.rotateFor(vex::directionType::rev,(deg), vex::rotationUnits::deg, (50), vex::velocityUnits::pct); 

  //LeftMotor.startRotateFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v) 

  return double(DegOfTurn); 

} 
void TurnRight90(){
  turnRight(90);
}

double straightandTurn(double dista, double angle){ 

  straight(dista); 

  turnLeft(angle); 

  return double(dista+angle); 

} 
void SpinRight(double degrees){
  //double FracCircle= degrees/360;
  //double arc= FracCircle*2*3.14*7;
  //Brain.Screen.print(arc);
  //double WheelDegs=(360*arc)/2*3.14*2;
  //Brain.Screen.print(WheelDegs);
  double WheelDegs= degrees*6.25/2;
  RightMotor.startRotateFor(vex::directionType::fwd,(WheelDegs), vex::rotationUnits::deg, (50), vex::velocityUnits::pct);  
  LeftMotor.rotateFor(vex::directionType::rev,(WheelDegs), vex::rotationUnits::deg,(50), vex::velocityUnits::pct); 
 
}

void spinRobot(double degrees, bool right) {
  double wheelDegs= degrees*6.25/2  ;  
  vex::directionType dirRight;
  vex::directionType dirLeft;
  if (right) {
    dirRight = vex::directionType::fwd;
    dirLeft = vex::directionType::rev;
  } else {
    dirRight = vex::directionType::rev;
    dirLeft = vex::directionType::fwd;    
  }
  RightMotor.startRotateFor(dirRight,wheelDegs, vex::rotationUnits::deg, (30), vex::velocityUnits::pct);  
  LeftMotor.rotateFor(dirLeft,wheelDegs, vex::rotationUnits::deg,(30), vex::velocityUnits::pct); 
   
}

void spinRight90() {
  spinRobot(93, true);
}

void spinLeft90() {
  spinRobot(87, false);
}

void BlueSideAuton(){
   straight(33);
 // spinRobot(90, false);
  //vex::task::sleep(500);
  spinRight90();
  //vex::task::sleep(500);
  straight(5);
//  vex::task::sleep(500);
  spinRight90();
 // vex::task::sleep(500);
  straight(25);
 // vex::task::sleep(500);
//2 blocks pushed agianst wall here
  straight(-10);
  //SpinRight(90);
  //vex::task::sleep(500);
  spinRight90();
  //vex::task::sleep(500);
  straight(15);
  //vex::task::sleep(500);
  spinRobot(87, false);;
 // vex::task::sleep(500);
  straight(18);
 // vex::task::sleep(500);
  SpinRight(90);
  //vex::task::sleep(500);
  straight(-35);
  straight(15);
}
void RedsideAuton(){
   straight(33);
 // spinRobot(90, false);
  //vex::task::sleep(500);
  spinLeft90();
  //vex::task::sleep(500);
  straight(5);
//  vex::task::sleep(500);
  spinLeft90();
 // vex::task::sleep(500);
  straight(25);
 // vex::task::sleep(500);
//2 blocks pushed agianst wall here
  straight(-10);
  //SpinRight(90);
  //vex::task::sleep(500);
  spinLeft90();
  //vex::task::sleep(500);
  straight(18);
  //vex::task::sleep(500);
  spinRight90();
 // vex::task::sleep(500);
  straight(15);
 // vex::task::sleep(500);
  turnLeft(90);
  //vex::task::sleep(500);
  straight(-35);
  straight(15);
}
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) { 
 RedsideAuton();
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
     // Drive Control
      // Set the left and right motor to spin forward using the controller's Axis position as the velocity value.
      // Since we are using a single joystick, we will need to calculate the final volicity for each motor.
      int armSpeedPCT  =50;
    int clawSpeedPCT =100;
      // (Axis3+Axis4)/2
      LeftMotor.spin(vex::directionType::fwd, (Controller1.Axis3.position() - Controller1.Axis4.position())/2, vex::velocityUnits::pct); 
      // (Axis3-Axis4)/2
      RightMotor.spin(vex::directionType::fwd, (Controller1.Axis3.position() + Controller1.Axis4.position())/2, vex::velocityUnits::pct);
    
      // Arm Control
      // If button up is pressed...
      if(Controller1.ButtonR1.pressing()) { 
        //...Spin the arm motor forward.
        ArmMotor.spin(vex::directionType::fwd, armSpeedPCT, vex::velocityUnits::pct);
      }
      // else If the down button is pressed...
      else 
      if(Controller1.ButtonR2.pressing()) { 
        //...Spin the arm motor backward.
        ArmMotor.spin(vex::directionType::rev, armSpeedPCT, vex::velocityUnits::pct);
      }
      // else If neither up or down button is pressed...
      else { 
        //...Stop the arm motor.
        // ArmMotor.stop(vex::brakeType::brake);
        ArmMotor.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
        Brain.Screen.clearScreen();
        }


       //Slider Motor control 
      if(Controller1.ButtonX.pressing()) {
        SliderMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
      }
      else
      if(Controller1.ButtonB.pressing()) {
        SliderMotor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
      }
      else
        SliderMotor.stop(vex::brakeType::brake);
      
      
      
      // Claw Control
      // If the A button is pressed...
      if(Controller1.ButtonL1.pressing()) { 
        //...Spin the claw motor forward.
        ClawMotor.spin(vex::directionType::fwd, clawSpeedPCT, vex::velocityUnits::pct);
      }
      // else If the Y button is pressed...
      else 
      if(Controller1.ButtonL2.pressing()) { 
        //...Spin the claw motor backward.
        ClawMotor.spin(vex::directionType::rev, clawSpeedPCT, vex::velocityUnits::pct);
      }
      // else If neither the A or Y button is pressed...
      else {
        //...Stop the claw motor.
        ClawMotor.stop(vex::brakeType::brake);        
      }
        //...Stop the claw motor.
      //SliderMotor.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct); 
    // Sleep the task for a short amount of time to prevent wasted resources.
    vex::task::sleep(20);

    // ........................................................................
    // Insert user code here. This is where you use the joystick values    to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
