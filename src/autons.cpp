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
  InertialSensor.calibrate();
  drive Chassis(3.25, 4.0/3, 72, 12, 0, leftDrive, rightDrive, PORT1);
  toggle.spin( forward, 70, percent);
  Chassis.forwardsToPoint(72.0, 11.5);
  wait(2,sec);
  toggle.stop();
  Chassis.forwardsToPoint(72.0, 6.0);
  Chassis.forwardsToPoint(72.0, 18.0);
  Chassis.forwardsToPoint(85.0, 15.0);
  Chassis.forwardsToPoint(85.0, 37.0);
  Chassis.forwardsToPoint(85.0, 15.0);



}

void leftAuton() {

  //Use functions to create an auton for the left side of the field

}

void skillsAuton() {
  
  //Use functions to create a programming skills routine
  
}