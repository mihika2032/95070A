#include "autons.h"
#include "robot-config.h"
#include "vex.h"
#include "util.h"
#include "PID.h"

using namespace vex;

void drivePID(double targetInches, DrivePidParams param, double kP, double kI, double kD){
double targetDegrees = inchesToDegrees(targetInches);

  double maxSpeed = param.maxSpeed;

  setDTPosition(0); 

  double error = targetDegrees;
  double integral = 0;
  double derivative = 0;
  double lastError = 0;
  double maxIntegral = 100;
  //int startTime = vex::timer::system();

  while (fabs(error) > 4.0) { 

    //if(vex::timer::system() - startTime > timeout) break;
    double leftAvg = (LF.position(degrees) + LB.position(degrees)) / 2.0;
    double rightAvg = (RF.position(degrees) + RB.position(degrees)) / 2.0;
    double avgPos = (leftAvg + rightAvg) / 2.0;

    error = targetDegrees - avgPos;
    integral += error;

   
    if (integral > maxIntegral) integral = maxIntegral;
    if (integral < -maxIntegral) integral = -maxIntegral;

    derivative = error - lastError;
    lastError = error;

    double power = (kP * error) + (kI * integral) + (kD * derivative);

  

    if (fabs(power) > maxSpeed) power = (power / fabs(power)) * maxSpeed;

    spinDT(power*0.7);
    spinDT(power*0.5);

    task::sleep(20); 
  }

  stopDT();
  Controller.Screen.print("done");
  Controller.Screen.print(targetDegrees);
}

void turnPID(double targetAngle, double kP = 0.1, double kI = 0.03, double kD = 0.) {
  
  //double dir =targetAngle/fabs(targetAngle);
 
void turnPID(double targetAngle, double kP, double kI, double kD) ;

  double dir = targetAngle/fabs(targetAngle);
  // Reset inertial and motor encoders
  InertialSensor.setRotation(0, degrees);
  // PID state
  double err = targetAngle;
  double integ = 0;
  double deriv = 0;
  double last = 0;
  const double maxI = 50.0;
  targetAngle=fabs(targetAngle);

  targetAngle = fabs(targetAngle);


  // loop til we’re close
  while (fabs(err) > 3.5) {
  while (fabs(err) > 1.0) {
    err = targetAngle - fabs(InertialSensor.rotation(degrees));
    integ += err;
    if (integ >  maxI) integ =  maxI;
    if (integ < -maxI) integ = -maxI;
    deriv = err - last;
    last  = err;

    Controller.Screen.clearScreen();
    Controller.Screen.setCursor(1, 1);
    Controller.Screen.print(InertialSensor.rotation(degrees));

    double power = kP*err + kI*integ + kD*deriv;
    if (power > 100) power = 100;
    if (power < -100) power = -100;

    spinLeftDT(dir*-power);
    spinRightDT(dir*power);

    vex::task::sleep(20);
  }

  Controller.Screen.print("done");
  Controller.Screen.print(targetAngle);

  stopDT();
  //stop();

}

}

PID::PID(double startError, double kp, double ki, double kd) {
  error = startError;
  kP = kp;
  kI = ki;
  kD = kd;
}

PID::PID(double startError, double kp, double ki, double kd, double Tolerance) {
  error = startError;
  kP = kp;
  kI = ki;
  kD = kd;
  tolerance = Tolerance;
}

PID::PID(double startError, double kp, double ki, double kd, double Tolerance, double WindupTheshold, double UpdateTime) {
  error = startError;
  kP = kp;
  kI = ki;
  kD = kd;
  tolerance = Tolerance;
  windupThreshold = WindupTheshold;
  updateTime = UpdateTime;
}

double PID::calculateTotal(double currentError) {
  error = currentError;

  if(fabs(error) < windupThreshold) {
    integral += error * ((double)updateTime / 1000);
  }

  derivative = (error - prevError) / ((double)updateTime / 1000);
  prevError = error;

  total = error * kP + integral * kI + derivative * kD;
  return total;

}

double PID::getUpdateTime() {
  return updateTime;
}