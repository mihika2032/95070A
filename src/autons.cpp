#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "lift.h"
#include "util.h"
#include "autons.h"

//test 
//MIHKa IS furry AND MOnkeY and FURry MonkeY


using namespace vex;

void rightAuton() {
  DrivePidParams setting = {};  //testing that there are no errors when building-- still need to test downloading
  setting.maxSpeed = 60.0;
  drivePID(12);
  turnPID(-88,0.30,0,0); 
  
  Controller.Screen.clearLine(3);
  Controller.Screen.setCursor(3, 1);
  Controller.Screen.print("start auton");

  drive Chassis(3.25, 4.0/3, 24, 0, 0, leftDrive, rightDrive, PORT1);

  Chassis.driveDistance(24, 1, 1, 0, 0.1);
}

void leftAuton() {
  turnPID(-90,1,1,1);

  //Use functions to create an auton for the left side of the field

}

void skillsAuton() {
  
  //Use functions to create a programming skills routine
  
}