
#include "api.h"
#include "lemlib/api.hpp"
#include "mvlib/Optional/lemlib.hpp"
#include "pros/motor_group.hpp"
#include <array>
#include <string>
#include <algorithm>
#include <optional>
  
//Controllers
    extern pros::Controller master;

//Drivetrain Motors
    extern pros::MotorGroup drivetrainLeft;
    extern pros::MotorGroup drivetrainRight;

//Motors
    extern pros::Motor Motor1;
    extern pros::Motor Motor2;
    extern pros::Motor Motor3;
    extern pros::Motor Motor4;
    extern pros::Motor Motor5;
  
//Pneumatics
    extern pros::adi::Pneumatics Pneumatic1;
    extern pros::adi::Pneumatics Pneumatic2;
    extern pros::adi::Pneumatics Pneumatic3;
    extern pros::adi::Pneumatics Pneumatic4;
    extern pros::adi::Pneumatics Pneumatic5;


//Sensors
    extern pros::Imu imu;

//Tracking Wheel
    extern pros::Rotation verticalEncoder;
    extern lemlib::TrackingWheel verticalTrackingWheel;
    extern pros::Rotation horizontalEncoder;
    extern lemlib::TrackingWheel horizontalTrackingWheel;

//Odom
    extern lemlib::OdomSensors Sensors;

//Drivetrain
    extern lemlib::Drivetrain Drivetrain;

//PID
    extern lemlib::ControllerSettings LateralController;
    extern lemlib::ControllerSettings AngularController;

//Input Curves
    extern lemlib::ExpoDriveCurve ThrottleCurve;
    extern lemlib::ExpoDriveCurve SteerCurve;

//Chassis
    extern lemlib::Chassis chassis;
