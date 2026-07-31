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

  drive Chassis(3.25, 4.0/3, 72, 12, 0, leftDrive, rightDrive, PORT1);
  drivePID(-6);
  toggle.spin(forward, 100, percent);


}

void leftAuton() {

  //Use functions to create an auton for the left side of the field

}

void skillsAuton() {
  
  //Use functions to create a programming skills routine
  
}