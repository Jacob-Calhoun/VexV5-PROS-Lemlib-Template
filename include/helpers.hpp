#pragma once
#include "globals.hpp"
#include "pros/misc.h"

//Variables
    extern bool isIntaking;
    extern float drivetrainSpeedConstant;
    extern float currentDriveSpeedMultiplier;
//Structs
    struct motorControlOptions {
        /*
        Do NOT touch the assigned type   |           | change amount and  | do not change
                                         v           v names as needed    v given value
        */
        std::optional<pros::controller_digital_e_t> NA1 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA2 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA3 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA4 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA5 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA6 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA7 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA8 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA9 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA10 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA11 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA12 = std::nullopt;
    };

    struct motorSpeedOptions {
        double NA1 = 127;
        double NA2 = 127;
        double NA3 = 127;
        double NA4 = 127;
        double NA5 = 127;
    };
    
    struct pneumaticControlOptions {
        /*
        Do NOT touch the assigned type   |           | change amount and  | do not change
                                         v           v names as needed    v given value
        */
        std::optional<pros::controller_digital_e_t> NA1 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA2 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA3 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA4 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA5 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA6 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA7 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA8 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA9 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA10 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA11 = std::nullopt;
        std::optional<pros::controller_digital_e_t> NA12 = std::nullopt;
    };
//Enums for classes
    enum class buttonPressTypes {
        HELD,
        NEW_PRESS,
        NEW_RELEASE
    };
//Functions (can make own, ask for help as needed)
    //Miscellaneous helpers
        double motorVelocity(int givenVelocity);
        float drivetrainSpeedModifier(const std::optional<pros::controller_digital_e_t>& button = std::nullopt);
        bool buttonStatus(const std::optional<pros::controller_digital_e_t>& button, const buttonPressTypes& pressType = buttonPressTypes::HELD);
    //Related to motors (use motorControls, do not remove it)
        void motorControls(const struct motorControlOptions& options = {}, const struct motorSpeedOptions& speedOptions = {});
        void motorHelper1(const bool forward, const bool backward, const float speed);
        void motorHelper2(const bool forward, const bool backward, const float speed);
        void motorHelper3(const bool forward, const bool backward, const float speed);
    //Related to pneumatics (use pneumaticControls, do not remove it)
        void pneumaticControls(const struct pneumaticControlOptions& options = {});
        void pneumaticHelper1(const bool out, const bool in);
        void pneumaticHelper2(const bool out, const bool in);
        void pneumaticHelper3(const bool out, const bool in);