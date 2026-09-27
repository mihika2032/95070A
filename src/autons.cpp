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
  drivePID(10);
  


}

void leftAuton() {

  //Use functions to create an auton for the left side of the field

}

void skillsAuton() {
  
  //Use functions to create a programming skills routine
  
}