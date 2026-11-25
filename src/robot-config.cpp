// src/robot-config.cpppppp
#include "robot-config.h"

using namespace vex;

//Configuration!

/* 
 * Reminders: 
 * Make sure that all your ports are different and correct! 
 * Make sure all of your motor + piston names are different and not confusing.
 * If it seems like some of your motors are running against eachother in the drivetrain, try switching around the true/false
*/

//DON'T CHANGE THE NAMES OF THE MOTORS OR SENSORS. Changing the ports to reflect your robot is ok.

brain Brain;
controller Controller(controllerType::primary);
motor LB(PORT1, ratio6_1, true); //Left Back Motor
motor LM(PORT2,true);
motor LF(PORT4, ratio6_1, true); //Left Front Motor
motor RB(PORT10, ratio6_1, false); //Right Back Motor
motor RM(PORT7,false);
motor RF(PORT5, ratio6_1, false); //Right Front Motor

motor_group leftDrive(LF, LM, LB);
motor_group rightDrive(RF, RM, RB);

motor Lift1(PORT3, gearSetting::ratio18_1, true); //Lift motor
motor Lift2(PORT6, gearSetting::ratio18_1, false); //Lift motor

digital_out DoubleActingPiston(Brain.ThreeWirePort.H);
digital_out SingleActingPiston(Brain.ThreeWirePort.B);
distance Distance(PORT11);

motor intakeMotor(PORT8, ratio18_1, false);
motor toggle(PORT9, ratio18_1, true);
motor  bottomIntakeMotor(PORT11, ratio18_1, false); 

inertial InertialSensor(PORT12);

optical OpticalSensor(PORT13);

void vexcodeInit() {
  InertialSensor.calibrate(); // retracted
  SingleActingPiston.set(false); // off
  while (InertialSensor.isCalibrating()) {
    task::sleep(100);
  }
  Controller.rumble(".... ..");
}