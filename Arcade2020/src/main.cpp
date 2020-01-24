/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Left Arcade                                               */
/*    This example allows you to control the V5 Clawbot using the left        */
/*    joystick. Adjust the deadband value for more accurate movements.        */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftMotor            motor         1               
// RightMotor           motor         10              
// ClawMotor            motor         4               
// ArmMotor             motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Brain.Screen.clearScreen();
  Brain.Screen.print("work darn it");
  
  // Deadband stops the motors when Axis values are close to zero.
  int deadband = 5;

  //velocityUnits::pct percent;

  while (true) {
    // Get the velocity percentage of the left motor. (Axis3 + Axis4)
    int leftMotorSpeed =
        Controller1.Axis3.position() - Controller1.Axis4.position();
    // Get the velocity percentage of the right motor. (Axis3 - Axis4)
    int rightMotorSpeed =
        Controller1.Axis3.position() + Controller1.Axis4.position();

    Brain.Screen.print(Controller1.Axis3.position());
    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(leftMotorSpeed) < deadband) {
      // Set the speed to zero.
//      LeftMotor.setVelocity(0, vex::velocityUnits::pct);
      LeftMotor.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);  
    } else {
      // Set the speed to leftMotorSpeed
      LeftMotor.spin(vex::directionType::fwd, leftMotorSpeed, vex::velocityUnits::pct);  
      
//      LeftMotor.setVelocity(leftMotorSpeed, vex::velocityUnits::pct);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(rightMotorSpeed) < deadband) {
      // Set the speed to zero
      //RightMotor.setVelocity(0,vex::velocityUnits::pct);
      RightMotor.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);  

    } else {
      // Set the speed to rightMotorSpeed
      RightMotor.spin(vex::directionType::fwd, rightMotorSpeed, vex::velocityUnits::pct);  
      //RightMotor.setVelocity(rightMotorSpeed, vex::velocityUnits::pct);
    }


    //wait(25, msec);
  }
}
