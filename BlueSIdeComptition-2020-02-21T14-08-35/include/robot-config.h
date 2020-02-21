using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftMotor;
extern motor RightMotor;
extern motor ArmMotor;
extern motor ClawMotor;
extern controller Controller1;
extern motor SliderMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );