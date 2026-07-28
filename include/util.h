/* Helps prevent header files from being included multiple times*/
#pragma once

/*
 * Function declarations should be in header (.h) files
 * Specify return type, function name, and parameters
*/

inline constexpr double GEAR_RATIO = 1.0;       // Your gear ratio
inline constexpr double WHEEL_DIAMETER = 3.25;

double inchesToDegrees(double inches, double gearRatio = GEAR_RATIO, double wheelDiameter = WHEEL_DIAMETER);

void setDTPosition(double inches, double gearRatio = GEAR_RATIO, double wheelDiameter = WHEEL_DIAMETER);

double degreesToInches(double deg, double gearRatio, double wheelDiameter);

void setDTPosition(double inches, double gearRatio, double wheelDiameter); //Good practice to use verb phrases as function names
void spinDT(double velocity);
void stopDT();
void spinRightDT(double velocity);
void spinLeftDT(double velocity);
void spinDTPosition(double velocity, double targetInches, double gearRatio, double wheelDiameter);
void turnForTime(double velocity, double time);
void runIntake();
void stopIntake();
void runoutake();

void spinDTPosition(double velocity, double targetInches);
void turnForTime(double velocity, double time);


struct DrivePidParams {
    double timeout = 3000;   // Maximum allowed time for movement (in ms)
    double maxSpeed = 100;   // Maximum motor voltage/speed (-127 to 127)
    double minSpeed = 0;     // Minimum speed to overcome friction
    double heading = 0;      // Target heading angle (if maintaining straight angle)
    bool useHeading = false; // Toggle for heading correction
};


