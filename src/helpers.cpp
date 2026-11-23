#include "helpers.hpp"
#include "liblvgl/llemu.hpp"
#include "pros/misc.h"

//Variables
    bool isIntaking = false;
    float drivetrainSpeedConstant = 0.85;
    float currentDriveSpeedMultiplier = 1.0;

/*
Motor velocity conversion
mostly for my own simplification
*/
	double motorVelocity(int givenVelocity) {
	    return (std::max(std::min(((givenVelocity * 127) / 100), 127), -127));
	}

/*
Slowed driving while holding a button
ideal for better control when desired
*can be turned off in main.cpp
(where joystick positions are taken)*
*/
	float drivetrainSpeedModifier(const std::optional<pros::controller_digital_e_t>& button, const bool& invertedSpeed) {
        if (invertedSpeed) {
            if (buttonStatus(button)) {
			currentDriveSpeedMultiplier = 1;
			return 1;
		    }

            currentDriveSpeedMultiplier = drivetrainSpeedConstant;
            return drivetrainSpeedConstant;
        }

		if (buttonStatus(button)) {
			currentDriveSpeedMultiplier = drivetrainSpeedConstant;
			return drivetrainSpeedConstant;
		}

		currentDriveSpeedMultiplier = 1;
		return 1;
	}

/*
Checks if a button is pressed or even exists
then asks which type of button press we want
*/
    bool buttonStatus(const std::optional<pros::controller_digital_e_t>& button, const enum buttonPressTypes& pressType) {
        if (button) {
            if (pressType == buttonPressTypes::NEW_PRESS) {
                return master.get_digital_new_press(*button);
            }

            if (pressType == buttonPressTypes::NEW_RELEASE) {
                return master.get_digital_new_release(*button);
            }

            return master.get_digital(*button);
        }

        return false;
    }

//motorHelper1
void motorHelper1(const bool forward, const bool backward, const float speed) {

}

//motorHelper2
void motorHelper2(const bool forward, const bool backward, const float speed) {
    
}

//motorHelper3
void motorHelper3(const bool forward, const bool backward, const float speed) {
    
}

/*
Motor controls
gives on main area where all motor functions go
assign controls in main.cpp
*/
	void motorControls(const struct motorControlOptions& options, const struct motorSpeedOptions& speedOptions) {
        motorHelper1(
            buttonStatus(options.NA1),
            buttonStatus(options.NA2),
            speedOptions.NA1
        );

        motorHelper2(
            buttonStatus(options.NA3),
            buttonStatus(options.NA4),
            speedOptions.NA2
        );

        motorHelper3(
            buttonStatus(options.NA5),
            buttonStatus(options.NA6),
            speedOptions.NA3
        );
	}

//pneumaticHelper1
void pneumaticHelper1(const bool out, const bool in) {

}

//pneumaticHelper2
void pneumaticHelper2(const bool out, const bool in) {

}

//pneumaticHelper3
void pneumaticHelper3(const bool out, const bool in) {

}

/*
Pneumatic controls
gives on main area where all pneumatic functions go
assign controls in main.cpp
*/
	void pneumaticControls(const struct pneumaticControlOptions& options) {
        pneumaticHelper1(
            buttonStatus(options.NA1),
            buttonStatus(options.NA2)
        );

        pneumaticHelper2(
            buttonStatus(options.NA3),
            buttonStatus(options.NA4)
        );

        pneumaticHelper3(
            buttonStatus(options.NA5),
            buttonStatus(options.NA6)
        );
	}

