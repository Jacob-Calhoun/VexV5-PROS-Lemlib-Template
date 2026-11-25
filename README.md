Hello! This file contains all the directions that should get you started and teach you how to use the template!

# Getting set up
This section will give directions on how to install the needed programs and the template itself so you can begin working.

## Installing VSCode
>[!CAUTION]
>These steps are from Windows installation, MacOS users may need to adapt some names for Mac apps.

1. Make a Github account
2. Follow [this link](https://code.visualstudio.com/download) for download options
3. Install the setup program for you
4. Open the setup program and install VSCode
5. Once installed, open it and click "sign in through Github"
6. Sign in with your Github information

## Installing git
>[!CAUTION]
>These steps are from Windows installation, MacOS users may need to adapt some names for Mac apps.

1. Follow [this link](https://git-scm.com/install/windows) for download options
2. Install the setup program for you
3. Open the setup program and install git
   -When prompted with the questions, go slowly.
   -Ensure you pick to use VSCode as your default, *not* Vim or VSCode insiders edition
4. Open VSCode
5. Go to "Terminal"
6. Select "New terminal"
7. Run `git --version`
   -If it returns something, then you're all set!
   -If you get nothing in return, troubleshoot through the community and ensure you followed the steps.

## Installing the template for your own repo
>[!CAUTION]
>These steps are from Windows installation, MacOS users may need to adapt some names for Mac apps.

### Method 1: Installing the .zip folder and making your own repo
1. Make a github account
2. Go to "My repositories"
3. Click "Create"
4. Give whatever name desired, turn off README option
5. A UI should appear with a link to copy for creating a repo
6. Go to [the repository](https://github.com/Jacob-Calhoun/VexV5-PROS-Lemlib-Template.git) in another tab
7. Click the code dropdown
8. Select "Local"
9. Click "Download ZIP"
10. Drag the .zip folder to your desired location
11. Unzip/Extract the .zip folder and delete the .zip
12. Rename the folder
13. Go to VSCode and make sure no folder/files are open
14. Click "file" and click "Open folder"
15. Select the extracted folder and click "open folder"
16. Go to "Terminal" and click "New terminal"
17. Type `git init` into the terminal and hit enter
18. Type `git remote add origin [paste your repo link here]` and hit enter
19. Type `git add .` and hit enter
20. Type `git commit -m "Start of project"` and hit enter
21. Type `git branch -M main` and hit enter
22. Type `git push -u origin main --force` and hit enter

### Method 2: Cloning the repo and changing the origin to your repo
1. Make a github account
2. Go to "My repositories"
3. Click "Create"
4. Give whatever name desired, turn off README option
5. A UI should appear with a link to copy for creating a repo
6. Open [the repository](https://github.com/Jacob-Calhoun/VexV5-PROS-Lemlib-Template.git) in another tab
7. Click the code dropdown
8. Select "Local"
9. Click to copy the link
10. Go to VSCode and make sure no folder/files are open
11. Go to terminal and click "New terminal"
12. Type `cd [desired file location]` and hit enter
    - Ensure that it is somewhere convenient
    - An example could be `C:/Users/[your name]`
    - An easy way to get this is to open the file explorer app and then copy the address bar at the top
13. Type `git clone -b main --single-branch [copied repo link here]` and hit enter
14. Type `cd VexV5-PROS-Lemlib-Template` and hit enter
15. Go to "file" and click "Open folder"
16. Select the repo folder and click "open folder"
17. Go to your repo in your browser
18. Copy the link offered to you
19. Go to VSCode again
20. Go to the terminal and type `Remove-Item -Recurse -Force .git` and hit enter
21. Type `git init` and hit enter
22. Type `git remote add origin [your repo link]` and hit enter
23. Type `git add .` and hit enter
24. Type `git commit -m "Start of project"` and hit enter
25. Type `git branch -M main` and hit enter
26. Type `git push -u origin main --force` and hit enter

## Installing required/desired extensions:
1. Looking at the sidebar of VSCode, select the square of 4 blocks labeled "extensions"
2. Search for the following listed extensions
### Required:
1. Lemlib Extension Pack
### Desired:
1. Better C++ Syntax
2. Clangd
3. Symbolizer for VEX V5
4. Material Icon Theme

## Installing the required PROS CLI & Toolchain
1. Please follow [this link for installing on Windows](https://pros.cs.purdue.edu/v5/getting-started/windows.html) or [this link for installing for MacOS](https://pros.cs.purdue.edu/v5/getting-started/macos.html) to be given the directions on what to do
2. Open terminal once more and run `pros build-compile-commands`
3. Once those directions are followed, please close the folder and then VSCode itself
4. Reopen both, everything should begin working
>[!CAUTION]
>Currently, there can be issues where clangd says things are wrong and highlights them red, it CAN be incorrect. If you are unsure about clangd's error message, type `pros build` into your terminal and see if you get an error. If not, your code is fine.

# Working with the template
In this section, I will explain how to actually use the template, features it has, and what things do. For coders who are curious about learning, I will also try to explain what the more abstract syntax means and how you can use it in your own code; though, these sections of explanation and application may also come in the ["Extra stuff" section](#Extra-stuff)
>[!WARNING]
>For this documentation, you can NOT use port 1 until you've gotten to [autonomous programs](#defining-autonomous-sensors), this is because the autonomous sensors are defaulted to port 1 and your brain will be confused if anything is in port 1. If you really want to use port 1 then go to `globals.cpp` and change the port numbers on `pros::Imu imu(1);`,`pros::Rotation verticalEncoder(1);`, and `pros::Rotation horizontalEncoder(1);` to an unused port on your robot.

## Libraries you'll use
This section has a bank of the libraries you'll be using so when writing code you know what you can call and where.

### Motor brake modes library
The referenced "brake modes" are part of a pros class, you will always use one of the following as your buttons:\
`pros::E_MOTOR_BRAKE_HOLD`\
`pros::E_MOTOR_BRAKE_BRAKE`\
`pros::E_MOTOR_BRAKE_COAST`\
These will be used in the [motor.set_brake_mode function](#motorset_brake_mode-function).

### Pros controller button library
The referenced "buttons" are part of a pros class, you will always use one of the following as your buttons:\
`pros::E_CONTROLLER_DIGITAL_UP`\
`pros::E_CONTROLLER_DIGITAL_DOWN`\
`pros::E_CONTROLLER_DIGITAL_LEFT`\
`pros::E_CONTROLLER_DIGITAL_RIGHT`\
`pros::E_CONTROLLER_DIGITAL_L1`\
`pros::E_CONTROLLER_DIGITAL_L2`\
`pros::E_CONTROLLER_DIGITAL_X`\
`pros::E_CONTROLLER_DIGITAL_B`\
`pros::E_CONTROLLER_DIGITAL_Y`\
`pros::E_CONTROLLER_DIGITAL_A`\
`pros::E_CONTROLLER_DIGITAL_R1`\
`pros::E_CONTROLLER_DIGITAL_R2`\
These ask for the button, it then must be passed through the [buttonStatus function](#buttonstatus-function) (or the\
`master.get_digital`/`master.get_digital_new_press`/`master.get_digital_new_release`\
function family for those more advanced) to get the button's state as a boolean[^3] value.

### Button press types library
The referenced "press types" are part of a custom class, you will always use one of the following as your type:\
`buttonPressTypes::HELD`\
`buttonPressTypes::NEW_PRESS`\
`buttonPressTypes::NEW_RELEASE`\
These tell the [buttonStatus function](#buttonStatus-function) what boolean[^3] value to return for a specified button's behavior.

### Tracking wheels library
The referenced "tracking wheel types" are as follows:\
`NEW_2`\
`NEW_275`\
`OLD_275`\
`NEW_275_HALF`\
`OLD_275_HALF`\
`NEW_32`\
`OLD_325`\
`NEW_325_HALF`\
`OLD_325_HALF`\
`NEW_4`\
`OLD_4`\
`NEW_4_HALF`\
`OLD_4_HALF`\
These will be used in [autonomous sensor definitions](#defining-autonomous-sensors) for your tracking wheels.

## Functions you'll use
The referenced functions are functions which will handle things for you. ensuring you understand them is crucial.

### motor.move function
The motor.move function is a function which tells motors to move based off a signed input from the domain of -127 to 127. The function requires you to write the name of the motor before being followed by `.move(n)` (where `-127<=n<=127`). Some examples are
```
intake.move(127);   // Moves forward at full speed
claw.move(-100);    // Moves backward at 100/127 speed
lift.move(35);  // Moves forward at 35/127 speed
```

### motorGroup.move function
The motorGroup.move function is a function which tells motor groups to move based off a signed input from the domain of -127 to 127. The function requires you to write the name of the motor group before being followed by `.move(n)` (where `-127<=n<=127`). Some examples are
```
intakeGroup.move(127);   // Moves forward at full speed
clawGroup.move(-100);    // Moves backward at 100/127 speed
liftGroup.move(35);  // Moves forward at 35/127 speed
```

### motor.set_brake_mode function
The motor.set_brake_mode function is a function which tells motors which braking method to use. Some examples are
```
intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);    // Tells the motor to try and hold exactly where it was when told to brake
claw.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);    // Tells the motor to come to a stop but not hold position
lift.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);    // Tells the motor to just turn off and allow spin
```
The available options are listed in the [motor brake modes class](#motor-brake-modes-library)

### motorGroup.set_brake_mode function
The motorGroup.set_brake_mode function is a function which tells motor groups which braking method to use. Some examples are
```
intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);    // Tells the motor group to try and hold exactly where it was when told to brake
claw.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);    // Tells the motor group to come to a stop but not hold position
lift.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);    // Tells the motor group to just turn off and allow spin
```
The available options are listed in the [motor brake modes class](#motor-brake-modes-library)

### motor.brake function
The motor.brake function is a function which tells motors to brake based off a previously defined choice. Some examples are
```
intake.brake(); // Intake motor brakes
claw.brake();   // Claw motor brakes
lift.brake();   // Lift motor brakes
```
To choose the brake mode, use the [motor brake modes class](#motor-brake-modes-library) in the [motor set brake mode function](#motorset_brake_mode-function).

### motorGroup.brake function
The motorGroup.brake function is a function which tells motors to brake based off a previously defined choice. Some examples are
```
intakeGroup.brake(); // Intake motor brakes
clawGroup.brake();   // Claw motor brakes
liftGroup.brake();   // Lift motor brakes
```
To choose the brake mode, use the [motor brake modes class](#motor-brake-modes-library) in the [motor group set brake mode function](#motorGroupset_brake_mode-function).

### buttonStatus function
The buttonStatus function is a function which takes an input of an optional button type (`std::optional<pros::controller_digital_e_t>`) and outputs a boolean[^3] value in return. To use it, write `buttonStatus(pros::E_CONTROLLER_DIGITAL_A)` or some other allowed [button](#pros-controller-button-library). You may also include a second parameter, this parameter tells it whether to process all presses or only new presses/releases. For instance,
```
buttonStatus(pros::E_CONTROLLER_DIGITAL_UP);    // Defaults to buttonPressTypes::HELD
buttonStatus(pros::E_CONTROLLER_DIGITAL_LEFT, buttonPressTypes::HELD);  // Sends signal if held/pressed
buttonStatus(pros::E_CONTROLLER_DIGITAL_B, buttonPressTypes::NEW_PRESS);    // Sends signal only when newly pressed
buttonStatus(pros::E_CONTROLLER_DIGITAL_X, buttonPressTypes::NEW_RELEASE);  // Sends signal only when newly released
```
Are all valid function calls and will return a boolean[^3] value.\
**Note:** Because this function is meant to return a value, you should normally only call it whenever trying to get a button's state for a function or conditional
>[!TIP]
>To make a "when *not* pressed/released/held" function, pass `!buttonStatus([chosen button], [optional param])"

### chassis.setPose function
The chassis.setPose function is a function which tells the robot what to set its new position to, it will then base any future instructions off the new position as if it was always there. This can be useful for 'checkpoints' in autonomous programs, checkpoints are places where the robot is forced into a specific position every time. There should always be a `set.pose` function at the start of your autonomous programs unless you want everything to be relative to the robot starting position. When using it, it takes 3 parameters, an x value, y value, and theta[^1] value. Your function call should be structured somewhat like this:
```
chassis.setPose(0, 0, 0);   // Sets the position to (0,0) while facing straight forward
chassis.setPose(10, 1, 45); // Sets the position to (10,1) while facing 45 degrees
```
For positional values, x and y should be in inches while the theta[^1] value should be in degrees.

### chassis.moveToPoint function
The chassis.moveToPoint function is a function which tells the robot to move to a specific coordinate, unlike the [moveToPose function](#chassismovetopose-function), it doesn't allow you to specify a final heading for the robot. It requires 3 arguments to run, an x value, y value, and a timeout value. The timeout value is the value which decides how long the robot will attempt this move command before continuing in the code. Your function call should be structured somewhat like this:
```
chassis.moveToPoint(10, 10, 3000);  // Tries to move to the point (10,10) with any theta value within 3 seconds
chassis.moveToPoint(-10, 10, 4700);  // Tries to move to the point (-10,10) with any theta value within 4.7 seconds
chassis.moveToPoint(3, -7, 8000);  // Tries to move to the point (3,-7) with any theta value within 8 seconds
```
For positional values, x and y should be in inches while the timeout value should be in milliseconds.

### chassis.moveToPose function
The chassis.moveToPose function is a function which tells the robot to move to a specific coordinate with a desired theta[^1] value. It requires 4 arguments to run, an x value, y value, a theta[^1] value, and a timeout value. The timeout value is the value which decides how long the robot will attempt this move command before continuing in the code. Your function call should be structured somewhat like this:
```
chassis.moveToPose(10, 10, 0, 3200);  // Tries to move to the point (10,10) with a theta value of 0 within 3.2 seconds
chassis.moveToPose(-10, 10, 75, 8100);  // Tries to move to the point (-10,10) with a theta value of 75 within 8.1 seconds
chassis.moveToPose(3, -7, -53, 700);  // Tries to move to the point (3,-7) with a theta value of -53 within 0.7 seconds
```
For positional values, x and y should be in inches, theta[^1] should be in degrees. The timeout value should be in milliseconds.

### chassis.turnToHeading function
The chassis.turnToHeading function is a function which tells the robot to turn to a specific theta[^1] value. It requires 2 arguments to run, a theta value and a timeout value. The timeout value is the value which decides how long the robot will attempt this turn command before moving on. Your function call should be structured somewhat like this:
```
chassis.turnToHeading(45,1000);    // Tries to face the heading 45 degrees within 1 second
chassis.turnToHeading(-70, 4000);   // Tries to face the heading -70 degrees within 4 seconds
chassis.turnToHeading(126, 3250);   // Tries to face the heading 126 degrees within 3.25 seconds
```

### pros::delay function
The pros::delay function is a function which tells the robot to wait a specific amount of time before continuing to the next line. It requires 1 argument, an amount of time in milliseconds. Using it should look similar to this:
```
pros::delay(500);   // Waits 0.5 seconds
pros::delay(8000);  // Waits 8 seconds
pros::delay(3520);  // Waits 3.52 seconds
```

## Drivetrain properties
This section will talk about drivetrains and what you can do with them for driver control.

### Define your drivetrain
When opening your project, you should see files in the "src" and "include" folder dropdowns, these files will be where you do all your coding. To start your project, click on the `globals.hpp` file within the "include" dropdown and look around.
>[!TIP]
>All of the .hpp files will be under the "include" dropdown, all of the .cpp files will be under the "src" dropdown.

Near the top of this file, you should see lines like\
`extern pros::MotorGroup drivetrainLeft;`\
These are motor group declarations[^4]. A declaration[^4] is what goes in your .hpp files, it tells your code that this group of motors exist and are named drivetrainLeft, but it will not be defined in this file. Now navigate to the `globals.cpp` file, in there you should find\
`pros::MotorGroup drivetrainLeft({1,1}, pros::v5::MotorGearset::green);`\
This is where we can define our drivetrain. The `{1,1}` is the list of ports for the motors in this group. Let's change it to reflect your actual drivetrain ports on the left side. If you have 3 motors on each side, no worries, add another comma and port number (example: `{1,2,3}`). Then look at the `pros::v5::MotorGearset::green`, this is your cartridge. Set it to whatever your drivetrain uses (you should be using the same cartridge for your entire drivetrain), if you use blue then it would be `pros::v5::MotorGearset::blue`. Now do the same for your right side in\
`pros::MotorGroup drivetrainRight({1,1}, pros::v5::MotorGearset::green)`\
We're not done, though! Motors on opposite sides of your drivetrain need to spin in the same direction (both spinning forwards should move your drivetrain forward), if your motors on the left are oriented the same and motors on the right are oriented the same, they would be `{1,2}`/`{1,2,3}` and `{-3,-4}`/`{-4,-5,-6}` respectively. A negative number for a port number means inverted, forward becomes backward and vice versa. When we test it in a moment, if the drivetrain drives incorrectly, that's okay! Just change the negative/positive ports until it begins working, you should be able to figure out which should be negative and positive by talking to your builder and experimenting. Some examples are the following:\
**1. 4-motor drivetrain with motors facing opposite ways**
```
In globals.cpp file:
pros::MotorGroup drivetrainLeft({4,-8}, pros::v5::MotorGearset::green);
pros::MotorGroup drivetrainRight({12,-9}, pros::v5::MotorGearset::green);
```
\
**2. 4-motor drivetrain with motors facing the same way**
```
In globals.cpp file:
pros::MotorGroup drivetrainLeft({-3,-2}, pros::v5::MotorGearset::green);
pros::MotorGroup drivetrainRight({5,17}, pros::v5::MotorGearset::green);
```
\
**3. 6-motor drivetrain with motors facing the same way**
```
In globals.cpp file:
pros::MotorGroup drivetrainLeft({-4,-8,-3}, pros::v5::MotorGearset::green);
pros::MotorGroup drivetrainRight({12,9,18}, pros::v5::MotorGearset::green);
```
\
**Note:** There are more examples which may end up with this configuration, these are not the only way that these happen.\
\

## Downloading code
To download code, first grab a download cord and plug it into your brain (or a paired controller) and your computer, ensure that the brain/controller are turned on for this. When downloading code, we can use the terminal, if you don't have a terminal open, go to "Terminal" and click "New terminal", now type `pros mu`, if you got no errors, your code is downloaded onto the brain! Now that the code is downloaded, it should default to slot 1, on the brain navigate to "programs" and click the program in the first slot, then click "run". Your brain should show you a long list of "None","N/A 1", "N/A 2", etc—this will eventually be your autonomous selector—click A on your controller to continue into driver control.
>[!IMPORTANT]
>Currently, there can be issues where clangd says things are wrong and highlights them red, it CAN be incorrect. If you are unsure about clangd's error message, type `pros build` into your terminal and see if you get an error. If not, your code is fine.

>[!TIP]
>To install code to other slots, write `pros mu --slot n` where n is an integer number 1 through 8.

**For those coming from the drivetrain section:** Use the joysticks. The left joystick should move the drivetrain forward/backward while the right joystick should turn the drivetrain left/right. If this is correct and works, move to the next section. If your drivetrain appears to be doing something wrong, check your ports and return to the drivetrain section.

## Motors
This section will focus on motors and what you can do with them, extra coding options and abilities may be located in the [extra syntax section](#extra-stuff)

### Define your motors
Now let's define some motors. Navigate back to `globals.hpp` and find the motor lines similar to\
`extern pros::Motor Motor1;`\
**Explanation:** This is a motor declaration[^4]. It follows a similar declaration format to the drivetrain. Unlike the drivetrain, we declare a single motor rather than a motor group. `extern pros::Motor` tells us that this is a motor which will be defined elsewhere. `Motor1` is the name of our declared motor.\
\
To start, let's change the motor's name from `Motor1` to something on your robot, try replacing it with `lift`, `claw`, `intake`, or whatever else you may have. Now navigate back to the `globals.cpp` file and find the line that looks like\
`pros::Motor Motor1(1, pros::v5::MotorGearset::green);`\
**Explanation:** This is a motor definition. It follows a similar definition format to the drivetrain. Unlike the drivetrain, we're defining a single motor rather than multiple. `pros::Motor` tells us that this is a motor, and `Motor1` is the name of our defined motor. `1` is the motor's port number. `pros::v5::MotorGearset::green` specifies the motor's cartridge (55-watt motors are considered green).\
\
This also follows the same format, but we only write a number like `1`/`-1` rather than `{1}`/`{-1}`. Continue on by changing the `Motor1` name to match whatever you wrote in your `globals.hpp` file and give it the port number to that part of your robot. Then make sure your motor gearset matches the motor cartridge you're using.\
**Example:**
```
In globals.hpp file:
    extern pros::Motor intake;
    extern pros::Motor lift;
    extern pros::Motor claw;

In globals.cpp file:
    pros::Motor intake(4, pros::v5::MotorGearset::green);
    pros::Motor lift(-7, pros::v5::MotorGearset::blue);
    pros::Motor claw(12, pros::v5::MotorGearset::red);
```
**Notice:** Unlike the template, the Motor4 and Motor5 lines are missing, this is because we can delete them if they're not being used. However, the contrary is also true, if you require more than just 5 motors, you may create your own motors on new lines by copying the same format. But be cautious, if you remove the motor declaration and definition, ensure you remove any other areas where it is used.\
\
Now let's give it a brake mode using the [motor.set_brake_mode function](#motorset_brake_mode-function), navigate to `main.cpp` and scroll until you find something like
```
//Set encoder unit, brake mode, tare position, and zero position here
    Motor1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    Motor2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    Motor3.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    Motor4.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    Motor5.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
```
**Explanation:** This section is referring to our template motors, notice how they are using the name to call the function. Because we changed the name of the motor in the definition and declaration, we also have to change it wherever else it's mentioned.\
\
We're going to rename `Motor1` to our chosen name and pick a new brake mode from the [brake modes library](#motor-brake-modes-library), for our example, we'll pick one for each option (if you're following with your own choices, you can use any combination), so our new code will look like this:
```
//Set encoder unit, brake mode, tare position, and zero position here
    intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    claw.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    Motor4.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    Motor5.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
```
**Notice:** If you removed the definitions and declarations of some of these motors (like `Motor4` and `Motor5`), you would also need to remove their corresponding lines. In this case, the corresponding lines are setting the brake mode for the motor.\
\
Now that we have all of this defined, let's test it! Find something in `main.cpp` that looks similar to the following:
```
void opcontrol () {
    //temporary code
```
Under the temporary code section, write `[your motor's name].move(127);`. This is using the [motor.move function](#motormove-function) to tell the computer to move your motor at full speed. Then we will write the [pros delay function](#prosdelay-function) `pros::delay(2500);` which tells the computer to wait 2.5 seconds before continuing to the next step. Finally, we can use the [motor.brake function](#motorbrake-function) by writing `[your motor's name].brake();`, this will tell the motor to brake using our newly selected brake option.\
**Example:**
```
void opcontrol() {
    //temporary code
        intake.move(127);
        pros::delay(2500);
        intake.brake();
```
Now download this by following the same [download instructions](#downloading-code) from before. Once done, run the code and click A to exit the autonomous selector, the motor should start spinning. If the motor spins for 2.5 seconds before stopping, you've properly declared, defined, and called a motor! If not, refer back to the above and check for any errors.\
\
**Note:** You can test your other motors doing the same thing, but for the sake of simplicity only one is shown.\
\
**Final code for our example:**
```
In globals.hpp:
    extern pros::Motor intake;
    extern pros::Motor lift;
    extern pros::Motor claw;

In globals.cpp:
    pros::Motor intake(4, pros::v5::MotorGearset::green);
    pros::Motor lift(-7, pros::v5::MotorGearset::blue);
    pros::Motor claw(12, pros::v5::MotorGearset::red);

In main.cpp:
    //Set encoder unit, brake mode, tare position, and zero position here
        intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        claw.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    
    [Other code]

    void opcontrol() {
        //temporary code
            intake.move(127);
            pros::delay(2500);
            intake.brake();
        
        [Other code]
    }
```

### Making motor helper functions
Helper functions are extremely important. They allow us to tell the robot what to do and when. They also allow us to make code more legible and keep it sorted into nicer groupings which make bugs easier to spot and isolate.\
\
Let's start by declaring a helper function. Navigate to `helpers.hpp` and find the line which says\
`void motorHelper1(const bool forward, const bool backward, const float speed);`\
**Explanation:** This is a helper function declaration included in the template. It serves to show you the structure of helper functions and how you'll write them. In the case of motor helper functions, they'll normally be structured to take two button inputs (in our case they're the forward and backward parameters) and one speed value (in our case it's called speed). As stated before, declarations tell the computer that this function exists somewhere. Special to the case of functions, though, it also tells the computer what parameters (things like `const bool forward`) the function expects, the parameter types (like `bool` and `float`), and the parameter names (like `forward`,`backward`, and `speed`).\
\
Change the name of this helper function to something fitting for what your declared motor is going to do, something like `liftControls`,`clawControls`, or `intakeControls`. Then we need to make sure the parameters make sense, ask "does this motor move your part forward/backward, up/down, in/out, open/close, etc?" Once you've decided, change the names of `forward` and `backward` to match your function. Then navigate to your `helpers.cpp` and find the line that looks like\
`void motorHelper1(const bool forward, const bool backward, const float speed) {`\
**Explanation:** This is the helper function's matching definition. Notice it has the same name and contains the same parameter types in the same order as the original declaration, this is what allows the computer to recognize them as the same function. They work together to tell the computer what this function is (declaration) and what it does (definition). We need to make sure we do the same thing and replicate our new name and function parameter names. Finally, the opening curly brackets (This: "{") tell the computer that everything between it and the closing curly bracket (This: "}") is part of our function's code.\
\
Change the name from `motorHelper1` to match the name in your `helpers.hpp` folder, then change the `forward`/`backward` to the new names you picked in your `helpers.hpp`. Some examples are as follows:\
**1. Lift system which moves up/down**
```
In helpers.hpp:
    void liftControls(const bool up, const bool down, const float speed);

In helpers.cpp:
    void liftControls(const bool up, const bool down, const float speed) {
        [Code here]
    }
```
\
**2. Intake system which takes pieces in/out**
```
In helpers.hpp:
    void intakeControls(const bool in, const bool out, const float speed);

In helpers.cpp:
    void intakeControls(const bool in, const bool out, const float speed) {
        [Future code here]
    }
```
**Note:** Similarly to the motors, if you do not plan on using these extra motor helper functions, you can delete them. If you need more, you can copy the format in the `helpers.hpp` file and in the `helpers.cpp` file (or directly from the documentation) and write them into the motorControls function with the same format as the other functions.\
\
Once you've finished that, you're going to scroll further down in your `helpers.cpp` file until you find the `motorControls` function, which should look like\
`void motorControls(const struct motorControlOptions& options, const struct motorSpeedOptions& speedOptions) {`\
**Explanation:** This is the larger motorControls function just to keep later things grouped into one area, you should never touch its definition line (the one above). The function parameters may be new to you, a structure (struct) is a large blueprint which allows us to input multiple related values and assign them defaults. More details on structs will be found later on.\
\
Inside of it, you should find something similar to the following:
```
motorHelper1(
    buttonStatus(options.NA1),
    buttonStatus(options.NA2),
    speedOptions.NA1
);
```
**Explanation:** This is where we call the motorHelper1 function that we've just customized to our own liking. While formatted on multiple lines, you can imagine it as if the parameters were all on one line. As stated earlier, parameters one and two were buttons, so what is happening here is as follows: we pull `options.NA1` from the struct (which will eventually be renamed and assigned a button on the controller) and pass it into the buttonStatus function, the buttonStatus function will then return a boolean[^3] value based on the state of the button. We then repeat these steps for the second parameter. The third parameter doesn't require the buttonStatus function because it's a speed value.\
\
This must be renamed to the same name as your new function, to do this, simply replace `motorHelper1` with your new function name. This will be where your function is called and soon will run a program. But for now, you've made a helper function!
**Example:**
```
intakeControls(
    buttonStatus(options.NA1),
    buttonStatus(options.NA2),
    speedOptions.NA1
);
```
\
**Final code for our example:**
```
In helpers.hpp:
    void intakeControls(const bool in, const bool out, const float speed);

In helpers.cpp:
    void intakeControls(const bool in, const bool out, const float speed) {

    }

    [Other code]

    void motorControls(const struct motorControlOptions& options, const struct motorSpeedOptions& speedOptions) {
        intakeControls(
            buttonStatus(options.NA1),
            buttonStatus(options.NA2),
            speedOptions.NA1
        );
    }
```
**Notice:** Because our example project doesn't use `motorHelper2` or `motorHelper3` they were removed from the code completely.

### Writing a simple program inside our motor helper function
Since you've created the helper function, now you need to write code inside it. Look back at your function *definition*, it should currently look something like
```
void intakeControls(const bool in, const bool out, const float speed) {

}
```
>[!NOTE]
>Yours may have different names, that's okay, you can copy the project if it makes more sense that way, but the lesson can be adapted to a different/unique function.

We're now going to add code here, let's start on a simple idea: We want a motor to spin forwards when you click the `in` button and backwards when we click the `out` button (for preface, these boolean[^3] inputs are buttons that we will define in [the next section](#defining-motor-controls)). Let's start this by writing our `in` conditional, we will write
```
if (in) {
    intake.move(speed);
    return;
}
```
This may seem like a jump, but this can be broken apart.\
The `if (in)` is asking if the `in` boolean[^3] is set to true, in the example code's context, this will eventually mean "is the selected button being held?"\
The `intake.move(speed);` line is simply saying "the intake motor must start spinning at the value of `speed`."\
The `return;` tells the function that it is done doing what it must and can immediately leave.\
Now what about when it should move out? Let's write something similar, under our new code block, we will write something like
```
if (out) {
    intake.move(-speed);
    return;
}
```
This is almost exactly the same, except now the code is asking about the `out` button and is spinning in the opposite direction (due to it being the negative speed value). Finally, what if it should brake when not being pressed? Under the other two block codes, we will write `intake.brake();`. Now the `return;` line has meaning, without it, our robot would see that we pressed a button, move the motor, and then immediately brake the motor. With this `return;` line, we tell the function that once it's activated from a button, it can stop looking for more code to run and exits the function.\
The final code for our example looks as follows:
```
void intakeControls(const bool in, const bool out, const float speed) {
    if (in) {
        intake.move(speed);
        return;
    }

    if (out) {
        intake.move(-speed);
        return;
    }

    intake.brake();
}
```
**Explanation:** Notice what's happening here, we're asking if our function parameters are true or false. The `if (in)` line asks if the `in` boolean (our button's status) is set to true or false. If it is, then it tells the motor to spin, crucially, the `return;` line keeps the other code from running. Right now, the return line is mostly used to avoid the `intake.brake();` line, keeping our motor from immediately stopping.\
**Notice:** Again, your code may look slightly different or have different names, that's okay. However, if your code isn't working as desired, follow the example's steps.\
\
Now you've written a simple program inside your helper function! But to make it run, we have to define motor controls.\
\
**Final code for our example:**
```
In helpers.cpp:
void intakeControls(const bool in, const bool out, const float speed) {
    if (in) {
        intake.move(speed);
        return;
    }

    if (out) {
        intake.move(-speed);
        return;
    }

    intake.brake();
}
```

### Defining motor controls
Defining motor controls is probably one of the silliest looking parts, but with practice it should make sense. To begin, navigate to the `helpers.hpp` file and find this block of code:
```
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
```
For our intake function, let's rename `NA1` and `NA2` to `intakeIn` and `intakeOut` respectively. Though, you can also make your own names. Our example code should look something like the following:
```
struct motorControlOptions {
    /*
    Do NOT touch the assigned type   |           | change amount and  | do not change
                                        v           v names as needed    v given value
    */
    std::optional<pros::controller_digital_e_t> intakeIn = std::nullopt;
    std::optional<pros::controller_digital_e_t> intakeOut = std::nullopt;
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
```
**Explanation:** Remember those `options.NA1`/`options.NA2` lines from the helpers.cpp file? This is where they come from. This is a structure (when we make them, we only write struct) and it allows us to create a large input of multiple data types, these values are called members. In our case, all of these data types are the same because they're all going to be buttons. The `= std::nullopt` tells us that the value will be defaulted to nothing unless we tell it otherwise. In a moment, we'll overwrite the default with controller buttons.\
**Note:** For these, we can similarly delete and add more as needed, though, any that are deleted need to be removed everywhere. (Hint: `main.cpp` and `helpers.cpp` both have references to `NA1` through `NA6`).\
\
These will soon be our new controls for our intake helper function. To do this, move back to `helpers.cpp` and scroll down to the `motorControls` function, you should see something like:
```
void motorControls(const struct motorControlOptions& options, const struct motorSpeedOptions& speedOptions) {
    intakeControls(
        buttonStatus(options.NA1),
        buttonStatus(options.NA2),
        speedOptions.NA1
    );

    [Other code here]
}
```
Change the names of the two parameters from `options.NA1` and `options.NA2` to your newly chosen names. For our example project, it would look as follows:
```
void motorControls(const struct motorControlOptions& options, const struct motorSpeedOptions& speedOptions) {
    intakeControls(
        buttonStatus(options.intakeIn),
        buttonStatus(options.intakeOut),
        speedOptions.NA1
    );

    [Other code here]
}
```
**Explanation:** You know our `intakeControls` function and how we declared a boolean named `in` and then called it? We're doing something very similar here. Structures (structs) have many related variables, so writing only the structure's name when calling it wouldn't be useful. To call the specific values of the struct, we call the struct by name (our struct names are `options` and `speedOptions`) and then put a period and the specific struct value we're calling. In our case, the 2 struct values we're calling for our intake helper function are the `intakeIn` button and `intakeOut` button. Putting the notation together, we get `options.intakeIn` and `options.intakeOut`.\
\
You've now told your code which values to use through more clarified naming conventions! However, the controls haven't actually been defined yet. To do this, go your `main.cpp` file and scroll until you find the `motorControls` function in main, it should look as follows:
```
motorControls({
    //Controls options for motors
    //remove entire line for no control of said motor
    .NA1 = std::nullopt,
    .NA2 = std::nullopt,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt,

},{
    //Speed options for the motors
    //remove entire line for default speed of 100% for said motor
    .NA1 = 127,
    .NA2 = 127,
    .NA3 = 127
});
```
**Note:** You can remove .NA3 through .NA6 if you're not using them, you can also add more, but if you add more, make sure you also create them in the struct (Hint: The large `struct motorControlOptions` code block in `helpers.hpp` is where you add/delete lines)\
\
For now, we will only change `.NA1` and `.NA2`. Start by changing their names to match the same ones you typed out earlier, for our example our intake function would be:
```
motorControls({
    //Controls options for motors
    //remove entire line for no control of said motor
    .intakeIn = std::nullopt,
    .intakeOut = std::nullopt,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt,

},{
    //Speed options for the motors
    //remove entire line for default speed of 100% for said motor
    .NA1 = 127,
    .NA2 = 127,
    .NA3 = 127
});
```
Finally, we can assign controller buttons to these! To start, assign your first one to some [button](#pros-controller-button-library), for our example, we will assign `.intakeIn` to `pros::E_CONTROLLER_DIGITAL_UP` which is the up-arrow [button](#pros-controller-button-library) on the controller. Then for our example, `.intakeOut` will be assigned to `pros::E_CONTROLLER_DIGITAL_DOWN`, the controller down-arrow. Your final should look something like this (with your own naming, of course):
```
motorControls({
    //Controls options for motors
    //remove entire line for no control of said motor
    .intakeIn = pros::E_CONTROLLER_DIGITAL_UP,
    .intakeOut = pros::E_CONTROLLER_DIGITAL_DOWN,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt,

},{
    //Speed options for the motors
    //remove entire line for default speed of 100% for said motor
    .NA1 = 127,
    .NA2 = 127,
    .NA3 = 127
});
```
**Explanation:** Earlier, we made `intakeIn` and `intakeOut` part of our struct, now we need to tell our function that they're going to be buttons in the controller (remember earlier we saw that they're all defaulted to `std::nullopt`). Also notice how only up to `.NA6` is written, earlier you saw that the struct has up to `.NA12`. The reasoning is that the struct has defaults already given, so if you delete `.NA3` through `.NA6` everything would still work since they were also defaulted to `std::nullopt` in the struct definition. Similarly to the extra motor helper functions (`motorHelper2` and `motorHelper3`), if you don't use these other NA values, they can be deleted in the struct definition (Hint: The large code block in helpers.hpp is the struct definition, struct definitions are different and go in header files).\
\
Now download it and test it! Does holding your first [button](#pros-controller-button-library) move it forward/up/in and your second [button](#pros-controller-button-library) moves it backward/down/out? If so, you've successfully coded a working helper function with defined controls!
>[!NOTE]
>If your forward/up/in goes backward/down/out, flip your motor port to be negative.

But what if your motor intake is spinning too fast? How do we turn it down? Using the speedOptions struct we can set speeds other than the default 100%!\
\
**Final code for our example:**
```
In helpers.hpp:
    struct motorControlOptions {
        /*
        Do NOT touch the assigned type   |           | change amount and  | do not change
                                            v           v names as needed    v given value
        */
        std::optional<pros::controller_digital_e_t> intakeIn = std::nullopt;
        std::optional<pros::controller_digital_e_t> intakeOut = std::nullopt;
    };

In helpers.cpp:
    void motorControls(const struct motorControlOptions& options, const struct motorSpeedOptions& speedOptions) {
    intakeControls(
        buttonStatus(options.intakeIn),
        buttonStatus(options.intakeOut),
        speedOptions.NA1
    );

    [Other code here]
    }

In main.cpp:
    motorControls({
        //Controls options for motors
        //remove entire line for no control of said motor
        .intakeIn = pros::E_CONTROLLER_DIGITAL_UP,
        .intakeOut = pros::E_CONTROLLER_DIGITAL_DOWN

    },{
        //Speed options for the motors
        //remove entire line for default speed of 100% for said motor
        .NA1 = 127,
        .NA2 = 127,
        .NA3 = 127
    });
```
**Notice:** For the example, the other template values (`options.NA3` through `options.NA12`) weren't needed, so they were removed from the code completely.

### Defining motor speeds
Following similar steps as before, move back to the `helpers.hpp` file and find the `motorSpeedOptions` struct. Change `NA1` to be a name suitable for you, in the case of the example, a good name would be `intakeSpeed`. Now move to the `helpers.cpp` file and go to the `motorControls` function, inside of it is your function which still calls `speedOptions.NA1`, change `NA1` to your new name. For our example project, it will now look as follows:
```
In helpers.hpp:
    struct motorSpeedOptions {
        double intakeSpeed = 127;
        double NA2 = 127;
        double NA3 = 127;
        double NA4 = 127;
        double NA5 = 127;
    };

In helpers.cpp:
	void motorControls(const struct motorControlOptions& options, const struct motorSpeedOptions& speedOptions) {
        intakeControls(
            buttonStatus(options.intakeIn),
            buttonStatus(options.intakeOut),
            speedOptions.intakeSpeed
        );

        [Other code]
    }
```
**Notice:** Because we don't need the status of the button we simply call the struct's member which is named `intakeSpeed`.\
\
Now, we need to set the speed. Go to `main.cpp` and find your motorControls code, it should look something like this:
```
motorControls({
    //Controls options for motors
    //remove entire line for no control of said motor
    .intakeIn = pros::E_CONTROLLER_DIGITAL_UP,
    .intakeOut = pros::E_CONTROLLER_DIGITAL_DOWN,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt,

},{
    //Speed options for the motors
    //remove entire line for default speed of 100% for said motor
    .NA1 = 127,
    .NA2 = 127,
    .NA3 = 127
});
```
Change `.NA1` to be your new name, in our case it will become `.intakeSpeed`. Now change 127 to be whatever speed you prefer. Now check if it builds and test it, if it works, you've successfully created a working helper function with customizable speed!
>[!TIP]
>There is a [motorVelocity function](#motorvelocity-function) which can be called, it takes integer percentage values from -100 to 100 and converts them to the -127 to 127 range. To use it, you can write something like:\
>`.intakeSpeed = motorVelocity(80);`\
>This will run the motor at 80% speed.
\
**Final code for our example:**
```
In helpers.hpp:
    struct motorSpeedOptions {
        double intakeSpeed = 127;
    };

In helpers.cpp:
	void motorControls(const struct motorControlOptions& options, const struct motorSpeedOptions& speedOptions) {
        intakeControls(
            buttonStatus(options.intakeIn),
            buttonStatus(options.intakeOut),
            speedOptions.intakeSpeed
        );

        [Other code]
    }

In main.cpp:
    motorControls({
        //Controls options for motors
        //remove entire line for no control of said motor
        .intakeIn = pros::E_CONTROLLER_DIGITAL_UP,
        .intakeOut = pros::E_CONTROLLER_DIGITAL_DOWN,

    },{
        //Speed options for the motors
        //remove entire line for default speed of 100% for said motor
        .intakeSpeed = 127,
    });
```
**Notice:** For the example, the other template values (`speedOptions.NA2` through `speedOptions.NA6`) weren't needed, so they were removed from the code completely.

## Motor groups
This section will focus on motors and what you can do with them, extra coding options and abilities may be located in the [extra syntax section](#extra-stuff)

### Define your motor groups
Now let's define some motor groups. Navigate back to `globals.hpp` and find the motor group lines similar to\
`extern pros::MotorGroup MotorGroup1;`\
**Explanation:** This is a motor group declaration[^4]. It follows a similar declaration format to the drivetrain. `extern pros::MotorGroup` tells us that this is a motor group which will be defined elsewhere. `MotorGroup1` is the name of our declared motor group.\
\
To start, let's change the motor group's name from `MotorGroup1` to something on your robot, try replacing it with `lift`, `claw`, `intake`, or whatever else you may have. Now navigate back to the `globals.cpp` file and find the line that looks like\
`pros::MotorGroup MotorGroup1(1, pros::v5::MotorGearset::green);`\
**Explanation:** This is a motor group definition. It follows a similar definition format to the drivetrain. `pros::MotorGroup` tells us that this is a motor group, and `MotorGroup1` is the name of our defined motor. `{1,1}` are the motor group's port numbers. When assigning ports, remember that motors in pairs could spin opposite ways, you'll likely need to make one negative. `pros::v5::MotorGearset::green` specifies the motor group's cartridge (55-watt motors are considered green), cartridges should be the same for your entire motor group.\
\
Continue on by changing the `MotorGroup1` name to match whatever you wrote in your `globals.hpp` file and give it the port numbers to that part of your robot. Then make sure your motor gearset matches the motor cartridge you're using for your motor group.\
**Example:**
```
In globals.hpp file:
    extern pros::MotorGroup liftGroup;
    extern pros::MotorGroup intakeGroup;
    extern pros::MotorGroup clawGroup;

In globals.cpp file:
    pros::MotorGroup liftGroup({15,-16}, pros::v5::MotorGearset::blue);
    pros::MotorGroup intakeGroup({-5,-10,13,17}, pros::v5::MotorGearset::green);
    pros::MotorGroup clawGroup({2,4,18}, pros::v5::MotorGearset::red);
```
**Notice:** Unlike the template, the MotorGroup4 and MotorGroup5 lines are missing, this is because we can delete them if they're not being used. However, the contrary is also true, if you require more than just 5 motors groups, you may create your own motors on new lines by copying the same format. But be cautious, if you remove the motor group declaration and definition, ensure you remove any other areas where it is used.\
\
Now let's give it a brake mode using the [motorGroup.set_brake_mode function](#motorgroupset_brake_mode-function), navigate to `main.cpp` and scroll until you find something like
```
//Set encoder unit, brake mode, tare position, and zero position here
    MotorGroup1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    MotorGroup2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    MotorGroup3.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    MotorGroup4.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    MotorGroup5.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
```
**Explanation:** This section is referring to our template motor groups, notice how they are using the name to call the function. Because we changed the name of the motor group in the definition and declaration, we also have to change it wherever else it's mentioned.\
\
We're going to rename `MotorGroup1` to our chosen name and pick a new brake mode from the [brake modes library](#motor-brake-modes-library), for our example, we'll pick one for each option (if you're following with your own choices, you can use any combination), so our new code will look like this:
```
//Set encoder unit, brake mode, tare position, and zero position here
    intakeGroup.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    liftGroup.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    clawGroup.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    Motor4.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    Motor5.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
```
**Notice:** If you removed the definitions and declarations of some of these motors (like `Motor4` and `Motor5`), you would also need to remove their corresponding lines. In this case, the corresponding lines are setting the brake mode for the motor.\
\
Now that we have all of this defined, let's test it! Find something in `main.cpp` that looks similar to the following:
```
void opcontrol () {
    //temporary code
```
Under the temporary code section, write `[your motor group's name].move(127);`. This is using the [motorGroup.move function](#motorGroupmove-function) to tell the computer to move your motor at full speed. Then we will write the [pros delay function](#prosdelay-function) `pros::delay(2500);` which tells the computer to wait 2.5 seconds before continuing to the next step. Finally, we can use the [motorGroup.brake function](#motorGroupbrake-function) by writing `[your motor group's name].brake();`, this will tell the motor to brake using our newly selected brake option.\
**Example:**
```
void opcontrol() {
    //temporary code
        liftGroup.move(127);
        pros::delay(2500);
        liftGroup.brake();
```
Now download this by following the same [download instructions](#downloading-code) from before. Once done, run the code and click A to exit the autonomous selector, the motor group should start spinning. If the motor group spins for 2.5 seconds before stopping, you've properly declared, defined, and called a motor! If not, refer back to the above and check for any errors.\
\
**Note:** You can test your other motor groups doing the same thing, but for the sake of simplicity only one is shown.\
\
**Final code for our example:**
```
In globals.hpp:
    extern pros::MotorGroup liftGroup;
    extern pros::MotorGroup intakeGroup;
    extern pros::MotorGroup clawGroup;

In globals.cpp:
    pros::MotorGroup liftGroup({15,-16}, pros::v5::MotorGearset::blue);
    pros::MotorGroup intakeGroup({-5,-10,13,17}, pros::v5::MotorGearset::green);
    pros::MotorGroup clawGroup({2,4,18}, pros::v5::MotorGearset::red);

In main.cpp:
    //Set encoder unit, brake mode, tare position, and zero position here
        intakeGroup.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        liftGroup.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        clawGroup.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    
    [Other code]

    void opcontrol() {
        //temporary code
            liftGroup.move(127);
            pros::delay(2500);
            liftGroup.brake();
        
        [Other code]
    }
```

### Making motor group helper functions
Helper functions are extremely important. They allow us to tell the robot what to do and when. They also allow us to make code more legible and keep it sorted into nicer groupings which make bugs easier to spot and isolate.\
\
Let's start by declaring a helper function. Navigate to `helpers.hpp` and find the line which says\
`void motorGroupHelper1(const bool forward, const bool backward, const float speed);`\
**Explanation:** This is a helper function declaration included in the template. It serves to show you the structure of helper functions and how you'll write them. In the case of motor group helper functions, they'll normally be structured to take two button inputs (in our case they're the forward and backward parameters) and one speed value (in our case it's called speed). As stated before, declarations tell the computer that this function exists somewhere. Special to the case of functions, though, it also tells the computer what parameters (things like `const bool forward`) the function expects, the parameter types (like `bool` and `float`), and the parameter names (like `forward`,`backward`, and `speed`).\
\
Change the name of this helper function to something fitting for what your declared motor group is going to do, something like `liftGroupControls`,`clawGroupControls`, or `intakeGroupControls`. Then we need to make sure the parameters make sense, ask "does this motor move your part forward/backward, up/down, in/out, open/close, etc?" Once you've decided, change the names of `forward` and `backward` to match your function. Then navigate to your `helpers.cpp` and find the line that looks like\
`void motorGroupHelper1(const bool forward, const bool backward, const float speed) {`\
**Explanation:** This is the helper function's matching definition. Notice it has the same name and contains the same parameter types in the same order as the original declaration, this is what allows the computer to recognize them as the same function. They work together to tell the computer what this function is (declaration) and what it does (definition). We need to make sure we do the same thing and replicate our new name and function parameter names. Finally, the opening curly brackets (This: "{") tell the computer that everything between it and the closing curly bracket (This: "}") is part of our function's code.\
\
Change the name from `motorGroupHelper1` to match the name in your `helpers.hpp` folder, then change the `forward`/`backward` to the new names you picked in your `helpers.hpp`. Some examples are as follows:\
**1. Lift system which moves up/down**
```
In helpers.hpp:
    void liftGroupControls(const bool up, const bool down, const float speed);

In helpers.cpp:
    void liftGroupControls(const bool up, const bool down, const float speed) {
        [Code here]
    }
```
\
**2. Intake system which takes pieces in/out**
```
In helpers.hpp:
    void intakeGroupControls(const bool in, const bool out, const float speed);

In helpers.cpp:
    void intakeGroupControls(const bool in, const bool out, const float speed) {
        [Future code here]
    }
```
**Note:** Similarly to the motor groups, if you do not plan on using these extra motor group helper functions, you can delete them. If you need more, you can copy the format in the `helpers.hpp` file and in the `helpers.cpp` file (or directly from the documentation) and write them into the motorControls function with the same format as the other functions.\
\
Once you've finished that, you're going to scroll further down in your `helpers.cpp` file until you find the `motorControls` function, which should look like\
`void motorGroupControls(const struct motorGroupControlOptions& options, const struct motorGroupSpeedOptions& speedOptions) {`\
**Explanation:** This is the larger motorGroupControls function just to keep later things grouped into one area, you should never touch its definition line (the one above). The function parameters may be new to you, a structure (struct) is a large blueprint which allows us to input multiple related values and assign them defaults. More details on structs will be found later on.\
\
Inside of it, you should find something similar to the following:
```
motorGroupHelper1(
    buttonStatus(options.NA7),
    buttonStatus(options.NA8),
    speedOptions.NA4
);
```
**Explanation:** This is where we call the motorGroupHelper1 function that we've just customized to our own liking. While formatted on multiple lines, you can imagine it as if the parameters were all on one line. As stated earlier, parameters one and two were buttons, so what is happening here is as follows: we pull `options.NA7` from the struct (which will eventually be renamed and assigned a button on the controller) and pass it into the buttonStatus function, the buttonStatus function will then return a boolean[^3] value based on the state of the button. We then repeat these steps for the second parameter. The third parameter doesn't require the buttonStatus function because it's a speed value.\
\
This must be renamed to the same name as your new function, to do this, simply replace `motorGroupHelper1` with your new function name. This will be where your function is called and soon will run a program. But for now, you've made a helper function!
**Example:**
```
liftGroupControls(
    buttonStatus(options.NA1),
    buttonStatus(options.NA2),
    speedOptions.NA1
);
```
\
**Final code for our example:**
```
In helpers.hpp:
    void liftGroupControls(const bool in, const bool out, const float speed);

In helpers.cpp:
    void liftGroupControls(const bool in, const bool out, const float speed) {

    }

    [Other code]

    void motorGroupControls(const struct motorGroupControlOptions& options, const struct motorGroupSpeedOptions& speedOptions) {
        liftGroupControls(
            buttonStatus(options.NA7),
            buttonStatus(options.NA8),
            speedOptions.NA4
        );
    }
```
**Notice:** Because our example project doesn't use `motorGroupHelper2` or `motorGroupHelper3` they were removed from the code completely.

### Writing a simple program inside our motor group helper function
Since you've created the helper function, now you need to write code inside it. Look back at your function *definition*, it should currently look something like
```
void liftGroupControls(const bool up, const bool down, const float speed) {

}
```
>[!NOTE]
>Yours may have different names, that's okay, you can copy the project if it makes more sense that way, but the lesson can be adapted to a different/unique function.

We're now going to add code here, let's start on a simple idea: We want a motor to spin forwards when you click the `up` button and backwards when we click the `down` button (for preface, these boolean[^3] inputs are buttons that we will define in [the next section](#defining-motor-group-controls)). Let's start this by writing our `up` conditional, we will write
```
if (up) {
    liftGroup.move(speed);
    return;
}
```
This may seem like a jump, but this can be broken apart.\
The `if (up)` is asking if the `up` boolean[^3] is set to true, in the example code's context, this will eventually mean "is the selected button being held?"\
The `liftGroup.move(speed);` line is simply saying "the liftGroup motors must start spinning at the value of `speed`."\
The `return;` tells the function that it is done doing what it must and can immediately leave.\
Now what about when it should move down? Let's write something similar, under our new code block, we will write something like
```
if (down) {
    liftGroup.move(-speed);
    return;
}
```
This is almost exactly the same, except now the code is asking about the `down` button and is spinning in the opposite direction (due to it being the negative speed value). Finally, what if it should brake when not being pressed? Under the other two block codes, we will write `liftGroup.brake();`. Now the `return;` line has meaning, without it, our robot would see that we pressed a button, move the motor group, and then immediately brake the motor group. With this `return;` line, we tell the function that once it's activated from a button, it can stop looking for more code to run and exits the function.\
The final code for our example looks as follows:
```
void liftGroupControls(const bool up, const bool down, const float speed) {
    if (up) {
        liftGroup.move(speed);
        return;
    }

    if (down) {
        liftGroup.move(-speed);
        return;
    }

    liftGroup.brake();
}
```
**Explanation:** Notice what's happening here, we're asking if our function parameters are true or false. The `if (up)` line asks if the `up` boolean (our button's status) is set to true or false. If it is, then it tells the motor to spin, crucially, the `return;` line keeps the other code from running. Right now, the return line is mostly used to avoid the `liftGroup.brake();` line, keeping our motor group from immediately stopping.\
**Notice:** Again, your code may look slightly different or have different names, that's okay. However, if your code isn't working as desired, follow the example's steps.\
\
Now you've written a simple program inside your helper function! But to make it run, we have to define motor controls.\
\
**Final code for our example:**
```
In helpers.cpp:
void liftGroupControls(const bool up, const bool down, const float speed) {
    if (up) {
        liftGroup.move(speed);
        return;
    }

    if (down) {
        liftGroup.move(-speed);
        return;
    }

    liftGroup.brake();
}
```

### Defining motor group controls
Defining motor group controls is probably one of the silliest looking parts, but with practice it should make sense. To begin, navigate to the `helpers.hpp` file and find this block of code:
```
struct motorGroupControlOptions {
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
```
For our intake function, let's rename `NA1` and `NA2` to `liftGroupUp` and `liftGroupDown` respectively. Though, you can also make your own names. Our example code should look something like the following:
```
struct motorControlOptions {
    /*
    Do NOT touch the assigned type   |           | change amount and  | do not change
                                        v           v names as needed    v given value
    */
    std::optional<pros::controller_digital_e_t> liftGroupUp = std::nullopt;
    std::optional<pros::controller_digital_e_t> liftGroupDown = std::nullopt;
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
```
**Explanation:** Remember those `options.NA1`/`options.NA2` lines from the helpers.cpp file? This is where they come from. This is a structure (when we make them, we only write struct) and it allows us to create a large input of multiple data types, these values are called members. In our case, all of these data types are the same because they're all going to be buttons. The `= std::nullopt` tells us that the value will be defaulted to nothing unless we tell it otherwise. In a moment, we'll overwrite the default with controller buttons.\
**Note:** For these, we can similarly delete and add more as needed, though, any that are deleted need to be removed everywhere. (Hint: `main.cpp` and `helpers.cpp` both have references to `NA1` through `NA6`).\
\
These will soon be our new controls for our intake helper function. To do this, move back to `helpers.cpp` and scroll down to the `motorGroupControls` function, you should see something like:
```
void motorGroupControls(const struct motorGroupControlOptions& options, const struct motorGroupSpeedOptions& speedOptions) {
    liftGroupControls(
        buttonStatus(options.NA1),
        buttonStatus(options.NA2),
        speedOptions.NA1
    );

    [Other code here]
}
```
Change the names of the two parameters from `options.NA1` and `options.NA2` to your newly chosen names. For our example project, it would look as follows:
```
void motorControls(const struct motorGroupControlOptions& options, const struct motorGroupSpeedOptions& speedOptions) {
    liftGroupControls(
        buttonStatus(options.liftGroupUp),
        buttonStatus(options.liftGroupDown),
        speedOptions.NA1
    );

    [Other code here]
}
```
**Explanation:** You know our `liftGroupControls` function and how we declared a boolean named `up` and then called it? We're doing something very similar here. Structures (structs) have many related variables, so writing only the structure's name when calling it wouldn't be useful. To call the specific values of the struct, we call the struct by name (our struct names are `options` and `speedOptions`) and then put a period and the specific struct value we're calling. In our case, the 2 struct values we're calling for our intake helper function are the `liftGroupUp` button and `liftGroupDown` button. Putting the notation together, we get `options.liftGroupUp` and `options.liftGroupDown`.\
\
You've now told your code which values to use through more clarified naming conventions! However, the controls haven't actually been defined yet. To do this, go your `main.cpp` file and scroll until you find the `motorGroupControls` function in main, it should look as follows:
```
motorGroupControls({
    //Controls options for motor groups
    //remove entire line for no control of said motor group
    .NA1 = std::nullopt,
    .NA2 = std::nullopt,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt,

},{
    //Speed options for the motor groups
    //remove entire line for default speed of 100% for said motor group
    .NA1 = 127,
    .NA2 = 127,
    .NA3 = 127
});
```
**Note:** You can remove .NA3 through .NA6 if you're not using them, you can also add more, but if you add more, make sure you also create them in the struct (Hint: The large `struct motorGroupControlOptions` code block in `helpers.hpp` is where you add/delete lines)\
\
For now, we will only change `.NA1` and `.NA2`. Start by changing their names to match the same ones you typed out earlier, for our example our intake function would be:
```
motorControls({
    //Controls options for motor groups
    //remove entire line for no control of said motor group
    .liftGroupUp = std::nullopt,
    .liftGroupDown = std::nullopt,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt,

},{
    //Speed options for the motor groups
    //remove entire line for default speed of 100% for said motor group
    .NA1 = 127,
    .NA2 = 127,
    .NA3 = 127
});
```
Finally, we can assign controller buttons to these! To start, assign your first one to some [button](#pros-controller-button-library), for our example, we will assign `.liftGroupUp` to `pros::E_CONTROLLER_DIGITAL_L1` which is the up-arrow [button](#pros-controller-button-library) on the controller. Then for our example, `.liftGroupDown` will be assigned to `pros::E_CONTROLLER_DIGITAL_L2`, the controller down-arrow. Your final should look something like this (with your own naming, of course):
```
motorGroupControls({
    //Controls options for motor groups
    //remove entire line for no control of said motor group
    .liftGroupUp = pros::E_CONTROLLER_DIGITAL_L1,
    .liftGroupDown = pros::E_CONTROLLER_DIGITAL_L2,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt,

},{
    //Speed options for the motor groups
    //remove entire line for default speed of 100% for said motor group
    .NA1 = 127,
    .NA2 = 127,
    .NA3 = 127
});
```
**Explanation:** Earlier, we made `liftGroupUp` and `liftGroupDown` part of our struct, now we need to tell our function that they're going to be buttons in the controller (remember earlier we saw that they're all defaulted to `std::nullopt`). Also notice how only up to `.NA6` is written, earlier you saw that the struct has up to `.NA12`. The reasoning is that the struct has defaults already given, so if you delete `.NA3` through `.NA6` everything would still work since they were also defaulted to `std::nullopt` in the struct definition. Similarly to the extra motor group helper functions (`motorGroupHelper2` and `motorGroupHelper3`), if you don't use these other NA values, they can be deleted in the struct definition (Hint: The large code block in helpers.hpp is the struct definition, struct definitions are different and go in header files).\
\
Now download it and test it! Does holding your first [button](#pros-controller-button-library) move it forward/up/in (our example should be up) and your second [button](#pros-controller-button-library) moves it backward/down/out (our example should be down)? If so, you've successfully coded a working helper function with defined controls!
>[!NOTE]
>If your forward/up/in goes backward/down/out, flip your motor group ports from negative to positive and positive to negative.

But what if your motor intake is spinning too fast? How do we turn it down? Using the speedOptions struct we can set speeds other than the default 100%!\
\
**Final code for our example:**
```
In helpers.hpp:
    struct motorGroupControlOptions {
        /*
        Do NOT touch the assigned type   |           | change amount and  | do not change
                                            v           v names as needed    v given value
        */
        std::optional<pros::controller_digital_e_t> liftGroupUp = std::nullopt;
        std::optional<pros::controller_digital_e_t> liftGroupDown = std::nullopt;
    };

In helpers.cpp:
    void motorGroupControls(const struct motorGroupControlOptions& options, const struct motorGroupSpeedOptions& speedOptions) {
    liftGroupControls(
        buttonStatus(options.liftGroupUp),
        buttonStatus(options.liftGroupDown),
        speedOptions.NA1
    );

    [Other code here]
    }

In main.cpp:
    motorControls({
        //Controls options for motor groups
        //remove entire line for no control of said motor group
        .liftGroupUp = pros::E_CONTROLLER_DIGITAL_L1,
        .liftGroupDown = pros::E_CONTROLLER_DIGITAL_L2

    },{
        //Speed options for the motor groups
        //remove entire line for default speed of 100% for said motor group
        .NA1 = 127,
        .NA2 = 127,
        .NA3 = 127
    });
```
**Notice:** For the example, the other template values (`options.NA3` through `options.NA12`) weren't needed, so they were removed from the code completely.

### Defining motor group speeds
Following similar steps as before, move back to the `helpers.hpp` file and find the `motorGroupSpeedOptions` struct. Change `NA1` to be a name suitable for you, in the case of the example, a good name would be `liftGroupSpeed`. Now move to the `helpers.cpp` file and go to the `motorGroupControls` function, inside of it is your function which still calls `speedOptions.NA1`, change `NA1` to your new name. For our example project, it will now look as follows:
```
In helpers.hpp:
    struct motorGroupSpeedOptions {
        double liftGroupSpeed = 127;
        double NA2 = 127;
        double NA3 = 127;
        double NA4 = 127;
        double NA5 = 127;
    };

In helpers.cpp:
	void motorGroupControls(const struct motorGroupControlOptions& options, const struct motorGroupSpeedOptions& speedOptions) {
        liftGroupControls(
            buttonStatus(options.liftGroupUp),
            buttonStatus(options.liftGroupDown),
            speedOptions.liftGroupSpeed
        );

        [Other code]
    }
```
**Notice:** Because we don't need the status of the button we simply call the struct's member which is named `liftGroupSpeed`.\
\
Now, we need to set the speed. Go to `main.cpp` and find your motorGroupControls code, it should look something like this:
```
motorGroupControls({
    //Controls options for motor groups
    //remove entire line for no control of said motor group
    .liftGroupUp = pros::E_CONTROLLER_DIGITAL_L1,
    .liftGroupDown = pros::E_CONTROLLER_DIGITAL_L2,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt,

},{
    //Speed options for the motor groups
    //remove entire line for default speed of 100% for said motor group
    .NA1 = 127,
    .NA2 = 127,
    .NA3 = 127
});
```
Change `.NA1` to be your new name, in our case it will become `.liftGroupSpeed`. Now change 127 to be whatever speed you prefer. Now check if it builds and test it, if it works, you've successfully created a working helper function with customizable speed!
>[!TIP]
>There is a [motorVelocity function](#motorvelocity-function) which can be called, it takes integer percentage values from -100 to 100 and converts them to the -127 to 127 range. To use it, you can write something like:\
>`.liftGroupSpeed = motorVelocity(80);`\
>This will run the motor at 80% speed.
\
**Final code for our example:**
```
In helpers.hpp:
    struct motorGroupSpeedOptions {
        double liftGroupSpeed = 127;
    };

In helpers.cpp:
	void motorGroupControls(const struct motorGroupControlOptions& options, const struct motorGroupSpeedOptions& speedOptions) {
        liftGroupControls(
            buttonStatus(options.liftGroupUp),
            buttonStatus(options.liftGroupDown),
            speedOptions.liftGroupSpeed
        );

        [Other code]
    }

In main.cpp:
    motorGroupControls({
        //Controls options for motor groups
        //remove entire line for no control of said motor group
        .liftGroupUp = pros::E_CONTROLLER_DIGITAL_L1,
        .liftGroupDown = pros::E_CONTROLLER_DIGITAL_L2,

    },{
        //Speed options for the motor groups
        //remove entire line for default speed of 100% for said motor group
        .liftGroupSpeed = 127,
    });
```
**Notice:** For the example, the other template values (`speedOptions.NA2` through `speedOptions.NA6`) weren't needed, so they were removed from the code completely.

## Pneumatics
This section will focus on pneumatics and what you can do with them, extras may be located in the [extra stuff section](#extra-stuff)

### Define your pneumatics
Similar to earlier, we're now going to define our pneumatic parts. Navigate back to `globals.hpp` and find the motors lines similar to\
`extern pros::adi::Pneumatics Pneumatic1;`\
**Explanation:** This is the same idea as the motor declaration from earlier. It's telling the computer that a pneumatic named Pneumatic1 exists and is defined elsewhere. Notice how we call `pros::adi::Pneumatics` instead of `pros::Motor`.\
\
These will be pneumatic pistons on your robot. To start, let's change the pneumatic's name from `Pneumatic1` to something on your robot, try replacing it with `clawToggle` or `intakeToggle`. Now navigate back to the `globals.cpp` file and find the line that looks like\
`pros::adi::Pneumatics Pneumatic1('A', startRetracted);`\
**Explanation:** Pneumatic definitions are also very similar to motor definitions, notice it's in the same format but the type has changed to `pros::adi::Pneumatics` just like the earlier declaration. Unlike motors, pneumatics use a single capital letter as input for their port. This line declares a pneumatic named Pneumatic1 in port A. It also details if the pneumatic starts extended; in our case, it doesn't because we've written `startRetracted`. Different from motors, you don't flip pneumatic directions in the code, you flip the hoses attached to the pneumatic.\
\
Now let's define our new pneumatic. Give it a port letter and choose `startExtended` or `startRetracted`. For our example, we'll pick to start retracted. Our final should look something like the following:
```
In globals.hpp:
    extern pros::adi::Pneumatics clawToggle;

In globals.cpp:
    pros::adi::Pneumatics clawToggle('C', startRetracted);
```
>[!TIP]
>To test if your pneumatic configuration is proper, set its starting position to extended and [download the code](#downloading-code), if it starts extended then everything works! If not, try flipping the hoses around first. If it still fails, check your definition.

### Making pneumatic helper functions
Navigate to `helpers.hpp` and find the line which says\
`void pneumaticHelper1(const bool out, const bool in);`\
**Explanation:** This is a helper function declaration included in the template. It serves to show you the structure of helper functions and how you'll write them. In the case of motor helper functions, they'll normally be structured to take two button inputs (in our case they're the in and out parameters). As stated before, declarations tell the computer that this function exists somewhere. Special to the case of functions, though, it also tells the computer what parameters (things like `const bool in`) the function expects, the parameter types (like `bool`), and the parameter names (like `in` and `out`).\
\
Change the name of this helper function to something fitting for what your declared motor is going to do, something like `clawToggleControls` or `intakeToggleControls`. Then we need to make sure the parameters make sense, ask "does this pneumatic move your part in/out, up/down, toggle, etc?" Once you've decided, change the names of `in` and `out` to match your function. Then navigate to your `helpers.cpp` and find the line that looks like\
`void pneumaticHelper1(const bool out, const bool in) {`\
**Explanation:** This is the helper function's matching definition. Notice it has the same name and contains the same parameter types in the same order as the original declaration, this is what allows the computer to recognize them as the same function. They work together to tell the computer what this function is (declaration) and what it does (definition). We need to make sure we do the same thing and replicate our new name and function parameter names. Finally, the opening curly brackets (This: "{") tell the computer that everything between it and the closing curly bracket (This: "}") is part of our function's code.\
\
Change the name from `pneumaticHelper1` to match the name in your `helpers.hpp` folder, then change the `in`/`out` to the new names you picked in your `helpers.hpp`. Some examples are as follows:\
**Examples:**\
**1. A claw which toggles between open and closed**
```
In helpers.hpp:
    void clawToggleControls(const bool open, const bool close);

In helpers.cpp:
    void clawToggleControls(const bool open, const bool close) {
        [Code here]
    }
```
\
**2. A motor which switches from intake to lift**
```
In helpers.hpp:
    void intakeToLiftToggle(const bool intake, const bool lift);

In helpers.cpp:
    void intakeToLiftToggle(const bool intake, const bool lift) {
        [Code here]
    }
```
\
Once you've finished that, you're going to scroll further down in your `helpers.cpp` file until you find the `pneumaticControls` function, which should look like\
`void pneumaticControls(const struct pneumaticControlOptions& options) {`\
**Explanation:** This is the larger pneumaticControls function just to keep later things grouped into one area, you should never touch its definition line (the one above). The function parameters may be new to you, a structure (struct) is a large blueprint which allows us to input multiple related values and assign them defaults. More details on structs will be found later on.\
\
Inside of it, you should find something similar to the following:
```
pneumaticHelper1(
    buttonStatus(options.NA1),
    buttonStatus(options.NA2),
);
```
**Explanation:** This is where we call the pneumaticHelper1 function that we've just customized to our own liking. While formatted on multiple lines, you can imagine it as if the parameters were all on one line. As stated earlier, parameters one and two were buttons, so what is happening here is as follows: we pull `options.NA1` from the struct (which will eventually be renamed and assigned a button on the controller) and pass it into the buttonStatus function, the buttonStatus function will then return a boolean[^3] value based on the state of the button. We then repeat these steps for the second parameter.\
\
This must be renamed to the same name as your new function, to do this, simply replace `pneumaticHelper1` with your new function name. This will be where your function is called and soon will run a program. But for now, you've made a helper function!\
\
**Final code for our example:**
```
In helpers.hpp:
    void clawToggleControls(const bool open, const bool closed);

In helpers.cpp:
    void clawToggleControls(const bool open, const bool closed) {

    }

    [Other code]

    void pneumaticControls(const struct pneumaticControlOptions& options) {
        clawToggleControls(
            buttonStatus(options.NA1),
            buttonStatus(options.NA2)
        );
    }
```
**Notice:** Because our example project doesn't use `pneumaticHelper2` or `pneumaticHelper3` they were removed from the code completely.

### Writing a simple program inside our pneumatic helper function
Since you've created the helper function, now you need to write code inside it. Look back at your function *definition*, it should currently look something like our example project:
```
void clawToggleControls(const bool open, const bool closed) {

}
```
>[!NOTE]
>Yours may have different names, that's okay, you can copy the project if it makes more sense that way, but the lesson can be adapted to a different/unique function.

We're now going to add code here, let's start on a simple idea: We want a pneumatic to open the claw when you click the `open` button and close it when we click the `close` button. For preface, these boolean[^3] inputs are buttons that we will define in the next section. For our example, let's start this by writing our `open` conditional, we will write
```
if (open) {
    clawToggle.extend();
    return;
}
```
This may seem like a jump, but this can be broken apart, similarly to the motors helper function.\
The `if (open)` is asking if the `open` boolean[^3] is set to true, in the example code's context, this will eventually mean "was the selected button pressed?"\
The `clawToggle.extend();` line is simply saying "the pneumatic should now extend."\
The `return;` tells the function that it is done doing what it must and can immediately leave.\
Now what about when it should close? Let's write something similar, under our new code block, we will write something like
```
if (close) {
    clawToggle.retract();
}
```
This is almost exactly the same, except now the code is asking about the `close` button and retracting the piston. Now the `return;` line in the "open" statement has meaning; without it, if someone pressed both buttons, our robot would instantly extend and retract the piston, wasting air; now the function ends early so that this doesn't happen.\
The final example code looks as follows:
```
void clawToggleControls(const bool open, const bool close) {
    if (open) {
    clawToggle.extend();
    return;
    }

    if (close) {
    clawToggle.retract();
    }
}
```
**Again, your code may look slightly different or have different names, that's okay. However, if your code isn't working as desired, follow the example's steps.**\
Now you've written a simple program inside your helper function! But to make it run, we have to define pneumatic controls.

### Defining pneumatic controls
To begin, navigate to the `helpers.hpp` file and "struct" block of code. It should look close to this:
```
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
```
The comments directly instruct you on what to do, for our clawToggle example function let's rename `NA1` and `NA2` to `clawOpen` and `clawClose` respectively (replace `NA1` and `NA2` with your own names).\
**Example:**
```
struct pneumaticControlOptions {
    /*
    Do NOT touch the assigned type   |           | change amount and  | do not change
                                        v           v names as needed    v given value
    */
    std::optional<pros::controller_digital_e_t> clawOpen = std::nullopt;
    std::optional<pros::controller_digital_e_t> clawClose = std::nullopt;
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
```
**Explanation:** Remember those `options.NA1`/`options.NA2` lines from the helpers.cpp file? This is where they come from. This is a structure (when we make them, we only write struct) and it allows us to create a large input of multiple data types, these values are called members. In our case, all of these data types are the same because they're all going to be buttons. The `= std::nullopt` tells us that the value will be defaulted to nothing unless we tell it otherwise. In a moment, we'll overwrite the default with controller buttons.\
**Note:** For these, we can similarly delete and add more as needed, though, any that are deleted need to be removed everywhere. (Hint: `main.cpp` and `helpers.cpp` both have references to `NA1` through `NA6`).\
\
These will soon be our new controls for our claw helper function. To do this, move back to `helpers.cpp` and scroll down to the `pneumaticControls` function, you should see something like:
```
void pneumaticControls(const struct pneumaticControlOptions& options) {
    clawToggleControls(
        buttonStatus(options.NA1),
        buttonStatus(options.NA2)
    );

    [Other code here]
}
```
Change the names of the two parameters from `options.NA1` to `options.clawOpen` and `options.NA2` to `options.clawClose` (or whatever names you've chosen). Then, add a new parameter to the [buttonStatus function](#buttonstatus-function) by putting a comma after the first parameter, now type `buttonPressTypes::NEW_PRESS`. This is telling the buttonStatus function to look for a new press of the [button](#pros-controller-button-library), so if the [button](#pros-controller-button-library) is held it will only activate once.\
**Example:**
```
void pneumaticControls(const struct pneumaticControlOptions& options) {
    clawToggleControls(
        buttonStatus(options.clawOpen, buttonPressTypes::NEW_PRESS),
        buttonStatus(options.clawClose, buttonPressTypes::NEW_PRESS)
    );

    [Other code here]
}
```
**Explanation:** You know our `clawToggleControls` function and how we declared a boolean named `open` and then called it? We're doing something very similar here. Structures (structs) have many related variables, so writing only the structure's name when calling it wouldn't be useful. To call the specific values of the struct, we call the struct by name (our struct name is `options`) and then put a period and the specific struct value we're calling. In our example's case, the 2 struct values we're calling for our claw helper function are the `clawOpen` button and `clawClose` button. Putting the notation together, we get `options.clawOpen` and `options.clawClose`.\
\
You've now told your code which values to use through more clarified naming conventions! Though, the controls haven't actually been defined yet. To do this, go your `main.cpp` file and scroll until you find the `pneumaticControls` function in main, it should look as follows:
```
pneumaticControls({
    //Controls options for pneumatics
    //remove entire line for no control of said motor
    .NA1 = std::nullopt,
    .NA2 = std::nullopt,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt
});
```
**Note:** You can remove .NA3 through .NA6 if you're not using them, you can also add more, but if you add more, make sure you also create them in the struct (Hint: The large `struct pneumaticControlOptions` code block in `helpers.hpp` is where you add/delete lines)\
\
For now, we will only change `.NA1` and `.NA2`. Start by changing their names to match the same ones you typed out earlier, for our example it would be:
```
pneumaticControls({
    //Controls options for pneumatics
    //remove entire line for no control of said motor
    .clawOpen = std::nullopt,
    .clawClose = std::nullopt,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt
});
```
Finally, we can assign controller [buttons](#pros-controller-button-library) to these! To start, assign your first one to some [button](#pros-controller-button-library). For our example, we will assign `.clawOpen` to `pros::E_CONTROLLER_DIGITAL_LEFT` which is the left-arrow button on the controller. Then for our example, `.clawClose` will be assigned to `pros::E_CONTROLLER_DIGITAL_RIGHT`, the controller right-arrow. Your final should look something like this:
```
pneumaticControls({
    //Controls options for pneumatics
    //remove entire line for no control of said motor
    .clawOpen = pros::E_CONTROLLER_DIGITAL_LEFT,
    .clawClose = pros::E_CONTROLLER_DIGITAL_RIGHT,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt
});
```
Now download it and test it! Does pressing your first button open the claw? Does pressing the second [button](#pros-controller-button-library) close the claw? If so, you've successfully coded a pneumatic helper function and its controls!
>[!NOTE]
>If your open instead closes, flip your attached hoses on the pneumatic.

**Final code for our example:**
```
In helpers.hpp:
    struct pneumaticControlOptions {
        /*
        Do NOT touch the assigned type   |           | change amount and  | do not change
                                            v           v names as needed    v given value
        */
        std::optional<pros::controller_digital_e_t> clawOpen = std::nullopt;
        std::optional<pros::controller_digital_e_t> clawClose = std::nullopt;
    };

In helpers.cpp:
    void pneumaticControls(const struct pneumaticControlOptions& options) {
        clawToggleControls(
            buttonStatus(options.clawOpen, buttonPressTypes::NEW_PRESS),
            buttonStatus(options.clawClose, buttonPressTypes::NEW_PRESS)
        );

        [Other code here]
    }

In main.cpp:
    pneumaticControls({
        //Controls options for pneumatics
        //remove entire line for no control of said motor
        .clawOpen = pros::E_CONTROLLER_DIGITAL_LEFT,
        .clawClose = pros::E_CONTROLLER_DIGITAL_RIGHT
    });
```

## Autonomous programs
In this section, you'll learn about the auton selector and making autonomous programs.\
**Note: It is highly recommended that you first code a full and working driver control system for your robot before moving to autonomous.**

### Defining autonomous sensors
For a robot to do an autonomous program, you'll need the following 3 sensors:
1. An IMU
2. A horizontal tracking wheel (wheel parallel to drivetrain wheels)
3. A vertical tracking wheel (wheel perpendicular to drivetrain wheels)
To start, your IMU should be placed flat and protected for best results. Then your tracking wheels must be placed firmly against the ground but able to smoothly roll with your robot (this is usually done through the use of rubber bands). Once these have been set up properly by your builder, we can define them. Move into the `globals.cpp` file and find the code that looks like this:
```
//Sensors
	pros::Imu imu(1);

//Tracking Wheels
	pros::Rotation verticalEncoder(1);
	lemlib::TrackingWheel verticalTrackingWheel(&verticalEncoder, lemlib::Omniwheel::NEW_2, 0);

	pros::Rotation horizontalEncoder(1);
	lemlib::TrackingWheel horizontalTrackingWheel(&horizontalEncoder, lemlib::Omniwheel::NEW_2, 0);
```
These are your 3 main sensors. We need to change those number 1's to the corresponding ports. Then for the following line where it says\
`lemlib::Omniwheel::NEW_2`\
please refer to [the libraries section](#tracking-wheels-library) and ask your builder which is the correct one.\
**Note: If you're unsure, try NEW_2.**\
Finally, the `0` is the signed distance of how far away the wheel is (in inches) from the center of your robot on the opposite axis.\
**Examples:**
```
lemlib::TrackingWheel verticalTrackingWheel(&verticalEncoder, lemlib::Omniwheel::NEW_2, -5);    // Vertical tracking wheel 5 inches to the left
lemlib::TrackingWheel verticalTrackingWheel(&verticalEncoder, lemlib::Omniwheel::NEW_2, 3);    // Vertical tracking wheel 3 inches to the right
lemlib::TrackingWheel horizontalTrackingWheel(&horizontalEncoder, lemlib::Omniwheel::NEW_2, 2);   // Horizontal tracking wheel 2 inches forward
lemlib::TrackingWheel horizontalTrackingWheel(&horizontalEncoder, lemlib::Omniwheel::NEW_2, -7);   // Horizontal tracking wheel 7 inches back
```
Once you've done this, you've successfully declared your sensors!

### Defining an autonomous program
So now you've got a working driver control system, or at least an idea on how to make one. Now we need an autonomous for skills and the 15 second auton in teamwork! Let's start by coding a simple program to help us calibrate our robot. First, go to the `autons.hpp` folder, there should be something that looks similar to this:
```
//Auton functions
    void autonRoute1();
    void autonRoute2();
    void autonRoute3();
```
This is where we will be declaring any autonomous functions we make. Let's change the name of `autonRoute1` to something more fitting, like `calibrationAuton`. Our end result should be this:
```
//Auton functions
    void calibrationAuton();
    void autonRoute2();
    void autonRoute3();
```
Now we need to add code to it! Go to `autons.cpp` and find the original function:
```
//Route 1
    void autonRoute1() {

    }
```
Now rename it to match our other. Your final should look like this:
```
//Route 1
    void calibrationAuton() {

    }
```
Though, it's still missing from the autonomous selector! Let's add it there, go to `autonSelector.cpp` and look for the block of code that looks similar to this:
```
std::array<std::string, 10> autons = {
    //Stays none
    "None",
    //Set to name of corresponding function
    "autonRoute1",
    "autonRoute2",
    "autonRoute3",
    "N/A 4",
    "N/A 5",
    "N/A 6",
    "N/A 7",
    "N/A 8",
    "N/A 9"
};

void (*autonFunctions[])() = {
    //Stays nullptr
    nullptr,
    //Set to name of corresponding function
    autonRoute1,
    autonRoute2,
    autonRoute3,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};
```
We are going to change the display name from "autonRoute1" to "Calibration auton", we will then change the function call name from `autonRoute1` to `calibrationAuton` so that it matches our newly defined function. Now our code should look as follows:
```
std::array<std::string, 10> autons = {
    //Stays none
    "None",
    //Set to name of corresponding function
    "Calibration auton",
    "autonRoute2",
    "autonRoute3",
    "N/A 4",
    "N/A 5",
    "N/A 6",
    "N/A 7",
    "N/A 8",
    "N/A 9"
};

void (*autonFunctions[])() = {
    //Stays nullptr
    nullptr,
    //Set to name of corresponding function
    calibrationAuton,
    autonRoute2,
    autonRoute3,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};
```
You've now defined an autonomous program! Now let's add some simple code to the function.

### Simple auton program
We've define an autonomous program, but it currently does nothing. Let's first use it to test our tracking wheels. Go to `autons.cpp` and find your newly defined function, we're going to add some code. First, we'll set the position to be (0, 0) and facing a heading of 0 degrees, we'll do this using the [chassis.setPose function](#chassissetpose-function). Then we can tell the robot to move to (0, 15), we'll use the [chassis.moveToPoint function](#chassismovetopoint-function) for this. Our current code should look as follows:
```
//Route 1
    void calibrationAuton() {
        chassis.setPose(0, 0, 0);
        chassis.moveToPoint(0, 15, 5000);
    }
```
Let's now [download](#downloading-code) this and run the code. When we run the code, a menu should appear and prompt us to select an autonomous. Use the up/down arrows on the controller to get the ">" arrow pointing at our new calibration autonomous, then click A to select it. The robot should begin moving forwards and stop near the value (0, 15)! If it instead keeps going forwards and reports a negative y-value, try flipping your vertical tracking wheel port to a negative number. If the issue persists, ensure you've follow the directions properly.

### Calibration auton program
While this is a good start, this isn't a square yet. We're then going to point to a heading of 90 using the [chassis.turnToHeading function](#chassisturntoheading-function), then moving to (15, 15) within 5 seconds. For (0, 15), we'll combine the heading and point using the [chassis.moveToPose function](#chassismovetopose-function) and tell it to move to (0, 15) with a theta value of -180. Now we have code that looks as follows:
```
//Route 1
    void calibrationAuton() {
        chassis.setPose(0, 0, 0);
        chassis.moveToPoint(0, 15, 5000);
        chassis.turnToHeading(90, 3000);
        chassis.moveToPoint(15, 15, 5000);
        chassis.moveToPose(0, 15, -180, 5000);
    }
```
We will then finish it with three more lines, facing (0, 0), returning to (0, 0), and spinning it to face a theta of 0 degrees once more. Turning the robot to a heading can be done using the [chassis.turnToHeading function](#chassisturntoheading-function) and we already know how to move the robot. Our final will look like this:
```
//Route 1
    void calibrationAuton() {
        chassis.setPose(0, 0, 0);
        chassis.moveToPoint(0, 15, 5000);
        chassis.turnToHeading(90, 3000);
        chassis.moveToPoint(15, 15, 5000);
        chassis.moveToPose(0, 15, -180, 5000);
        chassis.turnToHeading(-270, 3000);
        chassis.moveToPoint(0, 0, 5000);
        chassis.turnToHeading(0, 5000);
    }
```
Now download and test this, hopefully it runs roughly in a square. If not, ensure that you followed the steps properly. If it did work, you've coded a calibration program!

### Calibrating PID values
Now we have a calibrating program, but what are we calibrating? Put simply, we're calibrating the values for how the robot moves. These values are called the PID values because those are the 3 we work with. Their full names are proportional, integral, and derivative, but that won't be discussed here (it's in [the extras area](#extra-stuff)). For our basics, we won't even modify I.\
\
Think of our P and D values as parts of a rubber band. Our P value is how far we are from where we want the robot to be, think of it as how much you stretch the rubber band out. Then our D value stops the P value from growing too large, think of it as being how unelastic the rubber band is, pulling back on D to make it 0. We need to balance these values so that P and D don't undershoot or overshoot our robot's desired position.\
\
Navigate to `globals.cpp` and find the block that looks as follows:
```
// lateral PID controller
lemlib::ControllerSettings LateralController(
    7, // proportional gain (kP)
    0, // integral gain (kI)
    15, // derivative gain (kD)
    0, // anti windup
    0, // small error range, in inches
    0, // small error range timeout, in milliseconds
    0, // large error range, in inches
    0, // large error range timeout, in milliseconds
    0 // maximum acceleration (slew)
);
```
This is where we'll be changing values, right now we'll be specifically changing the proportional gain and derivative gain lines. Now run your autonomous program again and wait for it to move forwards, then try to look at the screen quickly, is the y value above or below 15?\
If it's above 15:\
-Turn up your kD value slightly\
If it's below 15:\
-Turn up your kP value slightly\
Repeat this process until it gets incredibly close to (0, 15).\
\
Now we need to tune our turning, find the block that looks as follows:
```
// angular PID controller
lemlib::ControllerSettings AngularController(
    2, // proportional gain (kP)
    0, // integral gain (kI)
    10, // derivative gain (kD)
    0, // anti windup
    0, // small error range, in degrees
    0, // small error range timeout, in milliseconds
    0, // large error range, in degrees
    0, // large error range timeout, in milliseconds
    0 // maximum acceleration (slew)
);
```
Now run the code and watch it turn at each point, is it turning too far or not far enough?\
If it's too far:\
-Turn up your kD value slightly\
If it's not far enough:\
-Turn up your kP value slightly\
Repeat until it aligns with the right angle almost perfectly.

### Autonomous clarifications and examples
When configuring an autonomous, remember that unless you set position with the proper offset and heading, everything you do will be relative to the robot's starting position. This isn't ideal when coding larger autonomous projects, so please attempt to figure out the actual coordinates you'll be starting at based off your own determined orientation.\
\
**Examples:**
```
void rightHalf() {
    chassis.setPose(0, -25, 0); // Sets starting position
    chassis.moveToPoint(10, 15, 2000);  // Tells the robot to move forward/right within 2 seconds
    chassis.turnToHeading(75, 1500);  // Tells the robot to turn and face 75 degrees within 1.5 seconds
    intake.move(127);   // Tells the robot to start spinning the intake motor at full speed
    chassis.moveToPoint(15, 20, 2000);   // Tells the robot to move further up/left within 2 seconds
                                         // For our example, imagine this is it picking up a piece
    intake.brake(); // Tells the intake motor to stop spinning
}
```

# The pros commands you'll use
When doing things with pros, you should rarely use more than `pros mu`, but here are a few other useful commands that may have been briefly covered.

## pros make
The `pros make` command is a simple command which tells pros to compile your project without actually attempting to download it, as mentioned in an earlier tip, this can be useful to see if you have any real errors while writing code.

## pros upload
The `pros upload` command is a simple command which tells pros to download your compiled project, requiring you to run `pros make` to download anything new with the `pros upload` command. Though, as mentioned in a tip, writing `--slot n` (where n is an integer: 1<=n<=8) after your command will download it to the specified slot rather than the default.

# The git commands you'll use
You'll use a few git commands, these commands may seem somewhat confusing so they'll be covered in this section.

## Sending and getting code from github
This section will detail how to send code to github and how to pull it from github and work on it.

### git add .
The `git add .` command tells git that you want to add all of your changes to a list, this is used before submitting changes to a commit[^2].

### git commit -m
The `git commit -m` command tells git that you're committing your changes with an attached message, this is done after the [git add . command](#git-add-.). To write the message, use quotations after the `-m` and write your save message.\
**Examples:**
```
git commit -m "This is my first save"
git commit -m "Work in progress"
git commit -m "Fixed the lift bug"
```

### git push
The `git push` command tells git to send the new commit to github, this step comes after the [git commit command](#git-commit--m).

### git pull
The `git pull` command downloads changes from your remote repository and integrates them into your current branch. This is useful when another team member has uploaded changes that you need on your computer.

# Extra stuff
(Coming soon)

## Libraries you can use
(Coming soon)

## Functions you can use
This section will talk about extra functions at your disposal within the template and how to use them.

### Drivetrain speed modifier function
Has your team or driver ever needed to be fast but then slow down for moments to get accurate placement? Maybe even vice versa and you only want to be fast at certain times? Built into your drivetrain is a speed modifier function!
**Note: This feature is for holding a button, currently it doesn't support a toggle system.**\
Navigate to `main.cpp` and scroll down until you find the lines that look like this:
```
int leftY = drivetrainSpeedModifier() * master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
int rightX = drivetrainSpeedModifier() * master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
```
pick a [button](#pros-controller-button-library) for holding to slow down, for our example, let's pick Y. Inside the empty parentheses we will write our [button](#pros-controller-button-library). So in our case it is `pros::E_CONTROLLER_DIGITAL_Y`. Afterwards, it should look something like this:
```
int leftY = drivetrainSpeedModifier(pros::E_CONTROLLER_DIGITAL_Y) * master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
int rightX = drivetrainSpeedModifier(pros::E_CONTROLLER_DIGITAL_Y) * master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
```
Now navigate to `helpers.cpp` and near the top should be something like\
`float drivetrainSpeedConstant = 0.85;`\
This is the second value of the drive speed, it should be between 0 and 1 at all times. Set it to whatever value you like. Now download the code using [the download section](#downloading-code) and test it.

### motorVelocity function
The motorVelocity function is a function which takes `motor.move();` values in the -127 to 127 domain and restructures them into the -100 to 100 domain, effectively making your entered value a percentage rather than a standalone number. It has one restriction, it only takes integer values, but you normally shouldn't need decimal percentage values. To use it, rather than writing `motor.move(127);` you would write `motor.move(motorVelocity(100));`. While it does seem annoying, it can come in handy for autonomous and other functions. Unlike some other functions, if this function is written, you **have** to provide a parameter.\
**Note: Because this function is meant to return a value, you should normally only call it inside the .move**

## PID explained
This 


[^1]: Theta values are the direction which the robot faces, it can be both positive or negative. 0/360 directly forward, 180/-180 are directly backward, and so forth.
[^2]: Commits are git savestates of your code, they're meant to be pushed to github in order to allow you to work on multiple devices or have a saved copy of your code if needed.
[^3]: Booleans are a type of data which is either set to true or false.
[^4]: A statement that goes in .hpp files, it tells the compiler that an object exists and is defined within another file