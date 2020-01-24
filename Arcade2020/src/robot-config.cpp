#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;



// VEXcode device constructors
//controller Controller1 = controller(primary);
controller Controller1 = controller();
motor LeftMotor = motor(PORT1, ratio18_1, true);
motor RightMotor = motor(PORT10, ratio18_1, false);
motor ClawMotor = motor(PORT4, ratio18_1, false);
motor ArmMotor = motor(PORT5, ratio18_1, false);

// VEXcode generated functions
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;
bool Controller1RightShoulderControlMotorsStopped = true;

/*
// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_callback_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    // check the ButtonL1/ButtonL2 status to control ClawMotor
    if (Controller1.ButtonL1.pressing()) {
      ClawMotor.spin(reverse);
      Controller1LeftShoulderControlMotorsStopped = false;
    } else if (Controller1.ButtonL2.pressing()) {
      ClawMotor.spin(forward);
      Controller1LeftShoulderControlMotorsStopped = false;
    } else if (!Controller1LeftShoulderControlMotorsStopped) {
      ClawMotor.stop();
      // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
      Controller1LeftShoulderControlMotorsStopped = true;
    }
    // check the ButtonR1/ButtonR2 status to control ArmMotor
    if (Controller1.ButtonR1.pressing()) {
      ArmMotor.spin(reverse);
      Controller1RightShoulderControlMotorsStopped = false;
    } else if (Controller1.ButtonR2.pressing()) {
      ArmMotor.spin(forward);
      Controller1RightShoulderControlMotorsStopped = false;
    } else if (!Controller1RightShoulderControlMotorsStopped) {
      ArmMotor.stop();
      // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
      Controller1RightShoulderControlMotorsStopped = true;
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}
*/

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  //task rc_auto_loop_task_Controller1(rc_auto_loop_callback_Controller1);
}