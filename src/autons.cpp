#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "lift.h"
#include "util.h"
#include "autons.h"

//test 

using namespace vex;

void rightAuton() {
 // DrivePidParams setting = {} //testing that there are no errors when building-- still need to test downloading
  drive Chassis(3.25, 3.0/4, 0, 0, 0, leftDrive, rightDrive, PORT11);
  Chassis.driveDistance(24, 0.1, 3.601, 0.000000000001, 0.176);
  InertialSensor.calibrate();
  Controller.rumble("... ---");
  Chassis.turnAngle(88, 1, 0.3, 0, 0);
  // Chassis.driveStop();
}

void leftAuton() {

  //Use functions to create an auton for the left side of the field

}

void skillsAuton() {
  
  //Use functions to create a programming skills routine
  
}