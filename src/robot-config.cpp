// src/robot-config.cpppppp
#include "robot-config.h"555ppppp

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
motor LB(PORT15, ratio6_1, true); //Left Back Motor
motor LF(PORT14, ratio6_1, true); //Left Front Motor
motor RB(PORT16, ratio6_1, true); //Right Back Motor
motor RF(PORT13, ratio6_1, true); //Right Front Motor


motor_group leftDrive(LF, LB);
motor_group rightDrive(RF, RB);

motor Lift1(PORT20, gearSetting::ratio18_1, true); //Lift motor
motor Lift2(PORT19, gearSetting::ratio18_1, true); //Lift motor

digital_out DoubleActingPiston(Brain.ThreeWirePort.A);
digital_out SingleActingPiston(Brain.ThreeWirePort.B);

motor intakeMotor(PORT1, ratio18_1, false);
motor toggle(PORT18, ratio18_1, true);
//motor  bottomIntakeMotor(PORT12, ratio18_1, false); 

inertial InertialSensor(PORT17);

optical OpticalSensor(PORT21);

void vexcodeInit() {
  InertialSensor.calibrate();
  DoubleActingPiston.set(false); // retracted
  SingleActingPiston.set(false); // off
  while (InertialSensor.isCalibrating()) {
    task::sleep(100);
  }
  Controller.rumble("...");
}