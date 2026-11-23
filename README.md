Hello! This file contains all the directions that should get you started!
# Installing VSCode
1. Make a Github account
2. Follow [this link](https://code.visualstudio.com/download) for download options
3. Install the one for you
4. Once installed, open it and click "sign in through Github"
5. Sign in with your Github information

# Installing the template for your own repo
>[!CAUTION]
>These steps are for Windows, MacOS users may need to adapt some names for Mac apps.

## Method 1: Installing the .zip folder and making your own repo
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
16. Go to "terminal" and click "New terminal"
17. Type `git init` into the terminal and hit enter
18. Type `git remote add origin [paste your repo link here]` and hit enter
19. Type `git add .` and hit enter
20. Type `git commit -m "Start of project"` and hit enter
21. Type `git branch -M main` and hit enter
22. Type `git push -u origin main --force` and hit enter
## Method 2: Cloning the repo and changing the origin to your repo
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
   - Ensure that it is somewhere convienient
   - An example could be `C:/Users/[your name]`
   - An easy way to get this is to open the file explorer app and then copy the address bar at the top
13. Type `git clone -b main --single-branch [copied repo link here]` and hit enter
14. Type `cd VexV5-PROS-Lemlib-Template` and hit enter
15. Go to "file" and click "Open folder"
16. Select the repo folder and click "open folder"
17. Go to your repo in your browser
18. Copy the link offered to you
19. Go to VSCode again
20. Go to the terminal and type `Remove-Item -Recurse -Force .git` and hint enter
21. Type `git init` and hit enter
22. Type `git remote add origin [your repo link]` and hit enter
23. Type `git add .` and hit enter
24. Type `git commit -m "Start of project"` and hit enter
25. Type `git branch -M main` and hit enter
26. Type `git push -u origin main --force` and hit enter

# Installing required/desired extentions:
1. Looking at the sidebar of VSCode, select the square of 4 blocks labeled "extensions"
2. Search for the following listed extensions
## Required:
1. Lemlib Extension Pack
## Desired:
1. Better C++ Syntax
2. Clangd
3. Symbolizer for VEX V5
4. Material Icon Theme

# Installing the required PROS CLI & Toolchain
1. Please follow [this link for installing on Windows](https://pros.cs.purdue.edu/v5/getting-started/windows.html) or [this link for installing for MacOS](https://pros.cs.purdue.edu/v5/getting-started/macos.html) to be given the directions on what to do
2. Open terminal once more and run `pros build-compile-commands`
3. Once those directions are followed, please close the folder and then VSCode itself
4. Reopen both, everything should begin working
>[!CAUTION]
>Currently, there can be issues where clangd says things are wrong and highlights them red, it CAN be incorrect. If you are unsure about clangd's error message, type `pros build` into your terminal and see if you get an error. If not, your code is fine.

# Working with the template
In this section, I will explain how to actually use the template, features it has, and what things do. For coders who are curious about learning, I will also try to explain what the more abstract syntax means and how you can use it in your own code; though, these sections of explanation and application may also come in the ["Extra syntax" section](#Extra-syntax)

## Define your drivetrain
When opening your project, you should see files in the "src" and "include" folder dropdown, these files will be where you do all your coding. To start your project, click on `globals.hpp` file within the "include" dropdown and look around. Near the top of this file, you should see lines like\
`extern pros::MotorGroup drivetrainLeft;`\
These are motor group declarations. A declaration is what goes in your .hpp files, it tells your code that this group of motors exist and are named drivetrainLeft, but it will not be defined in this file. Now navigate to the `globals.cpp` file, in there you should find\
`pros::MotorGroup drivetrainLeft({1,1}, pros::v5::MotorGearset::green);`\
The `{1,1}` is the list of ports for the motors in this group. Let's change it to reflect your actual drivetrain ports on the left side. If you have 3 motors on each side, no worries, add another comma and port number (example: `{1,2,3}`). Then look at the `pros::v5::MotorGearset::green`, this is your cartridge. Set it to whatever your drivetrain uses (you should be using the same cartridge for your entire drivetrain), if you use blue then it would be `pros::v5::MotorGearset::blue`. Now do the same for your right side in\
`pros::MotorGroup drivetrainRight({1,1}, pros::v5::MotorGearset::green)`\
We're not done, though! Motors on opposite sides need to spin opposite ways, if your motors on the left and right all face the same way, they would be `{1,2}`/`{1,2,3}` and `{-3,-4}`/`{-4,-5,-6}` respectively. A negative number for a port number means inverted, forward becomes backward and vice versa. In a moment when we test, if the drivetrain drives incorrectly, that's okay! Just change the negative/positive ports until it begins working, you should be able to figure out which should be negative and positive by talking to your builder and experimenting.\
**Examples:**\
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
>[!NOTE]
>There are more examples which may end up with this configuration, these are not the only way that these happen.

## Downloading code
To download code, first grab a download cord and plug it into your brain (or a paired controller) and computer, ensure that the brain/controller are turned on for this. When downloading code, we can use the terminal, if you don't have a terminal open, go to "terminal" and click "New terminal", now type `pros mu`, if you got no errors, your code is downloaded onto the brain! Now that the code is downloaded, it should default to slot 1, on the brain navigate to "programs" and click the program in the first slot, then click "run". Your brain should show you a long list of "N/A 1", "N/A 2", click A on your controller to continue.\
For those coming from [the drivetrain section](#define-your-drivetrain), use the joysticks, the left joystick should move forward/backward while the right joystick should move left/right.If this is correct, amazing! Move to the next section, if your drivetrain appears to be doing something wrong, check your ports and return to [the above section](#Define-your-drivetrain).
>[!TIP]
>To install code to other slots, write `pros mu --slot n` where n is an integer number 1 through 8.

## Motors
This section will focus on motors and what you can do with them, extras may be located in the [extra syntax section](#extra-syntax)
### Define your motors
Now let's define some motors. Navigate back to `globals.hpp` and find the motors lines similar to\
`extern pros::Motor Motor1;`\
These will be motors on your robot. It follows the same declaration format as the drivetrain but now we declare a single motor rather than a motorgroup.  To start, let's change the motor's name from `Motor1` to something on your robot, try replacing it with `lift`, `claw`, or `intake`. Now navigate back to the `globals.cpp` file and fine the line that looks like\
`pros::Motor Motor1(1, pros::v5::MotorGearset::green);`\
This also follows the same format, but we only write a number like `1`/`-1` rather than `{1}`/`{-1}` because there's only one port for a motor. Once this makes sense, change the `Motor1` name to match whatever you wrote in your `globals.hpp` file and give it the port to this part of your robot.
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
\
Finally, we need to actually test it; let's start by going to `main.cpp` and scrolling down until you find
```
void opcontrol () {
    //temporary code
```
Under the temporary code section, write `[your motor's name].move(127);`. This is telling the computer to move your motor at full speed (speed is out of 127). Now download this by following the same [download instructions](#downloading-code) from before. Once done, the motor should start spinning. If the motor does spin, you've properly declared, defined, and called a motor! If not, refer back to the above and check for any errors. Now you can add/remove these motor definitions/declarations (remove both, not just one or the other) so that you only have the motors you're using!

### Making motor helper functions
Helper functions are the foundation for your code, they allow us to tell the robot what to do and when. Let's start by declaring a helper function. Navigate to `helpers.hpp` and find the line which says\
`void motorHelper1(const bool forward, const bool backward, const float speed);`\
Change the name to something fitting for what your declared motor is going to do, something like `liftControls`,`clawControls`, or `intakeControls`. Then, we need to make sure the parameters make sense, ask "does this motor move your part forward/backward, up/down, in/out, open/close, etc?" Once you've decided, change the names of `forward` and `backward` to match your function. Then navigate to your `helpers.cpp` and find the line that looks like\
`void motorHelper1(const bool forward, const bool backward, const float speed) {`\
Change the name from `motorHelper1` to match the name in your `helpers.hpp` folder, then change the `forward`/`backward` to the new names you picked in your `helpers.hpp`.\
**Examples:**\
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
        [Code here]
    }
```
\
Once you've finished that, you're going to scroll further down in your `helpers.cpp` file until you find the `motorControls` function, which should look like\
`void motorControls(const struct motorControlOptions& options, const struct motorSpeedOptions& speedOptions) {`\
Inside of it, you should find something similar to the following:
```
motorHelper1(
    buttonStatus(options.NA1),
    buttonStatus(options.NA2),
    speedOptions.NA1
);
```
This must be renamed to the same name as your new function. This will be where your function is eventually going to be used. But for now, you've made a helper function!
### Writing a simple program inside our motor helper function
Since you've created the helper function, now you need to write code inside it. Look back at your function *definition*, it should currently look something like
```
void intakeControls(const bool in, const bool out, const float speed) {

}
```
>[!NOTE]
>Yours may have different names, that's okay, you can copy the project if it makes more sense that way, but the lesson can be adapted to a different/unique function.

We're now going to add code here, let's start on a simple idea: We want a motor to spin forwards when you click the `in` button and backwards when we click the `out` button (for preface, these boolean inputs are buttons that we will define in [the next section](#defining-motor-controls)). Let's start this by writing our `in` conditional, we will write
```
if (up) {
    intake.move(speed);
    return;
}
```
This may seem like a jump, but this can be broken apart.\
The `if (up)` is asking if the `up` boolean is set to true, in the exmaple code's context, this will eventually mean "is the selected button being held?"\
The `intake.move(speed);` line is simply saying "the intake motor must start spinning at the value of `speed`."\
The `return;` tells the function that it is done doing what it must and can immediately leave.\
Now what about when it should move down? Let's write something similar, under our new code block, we will write something like
```
if (down) {
    intake.move(-speed);
    return;
}
```
This is almost exactly the same, except now the code is asking about the `down` button and is spinning in the opposite direction (due to it being the negative speed value). Finally, what if it should brake when not being pressed? Under the other two block codes, we will write `intake.brake();`. Now the `return;` line has meaning, without it, our robot would see that we pressed a button, move the motor, and then immediately brake the motor. With this `return;` line, we tell the function that once it's activated from a button, it can stop looking for more code to run.\
In the example, the final code looks as follows:
```
void intakeControls(const bool in, const bool out, const float speed) {
    if (up) {
        intake.move(speed);
        return;
    }

    if (down) {
        intake.move(-speed);
        return;
    }

    intake.brake();
}
```
**Again, your code may look slightly different or have different names, that's okay. However, if your code isn't working as desired, follow the example's steps.**\
Now you've written a simple program inside your helper function! But to make it run, we have to define motor controls.

### Defining motor controls
Defining motor controls is probably one of the silliest looking parts, but with practice (and if you read [the section on it](#extra-syntax)), it should make sense. To begin, navigate to the `helpers.hpp` file and "struct" block of code. It should look close to this:
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
The comments directly instruct you on what to do, for our intake function let's rename `NA1` and `NA2` to `intakeIn` and `intakeOut` respectively. These will soon be our new controls for our intake helper function. To do this, move back to `helpers.cpp` and scroll down to our the `motorControls` function, you should see something like:
```
void motorControls(const struct motorControlOptions& options, const struct motorSpeedOptions& speedOptions) {
    intakeControls(
        buttonStatus(options.NA1),
        buttonStatus(options.NA2),
        speedOptions.NA1
    );

    [other code here]
}
```
Change the names of the two parameters from `options.NA1` to `options.intakeIn` and `options.NA2` to `options.intakeOut`.\
**Example:**
```
void motorControls(const struct motorControlOptions& options, const struct motorSpeedOptions& speedOptions) {
    intakeControls(
        buttonStatus(options.intakeIn),
        buttonStatus(options.intakeOut),
        speedOptions.NA1
    );

    [other code here]
}
```
You've now told your code which values to use through more clarified naming conventions! Though, the controls haven't actually been defined yet. To do this, go your `main.cpp` file and scroll until you find the `motorControls` function in main, it should look as follows:
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
For now, we will only change `.NA1` and `.NA2`. Start by changing their names to match the same ones you typed out earlier, for our example it would be:
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
Finally, we can assign controller buttons to these! To start, assign your first one to some button, for our example, we will assign `.intakeIn` to `pros::E_CONTROLLER_DIGITAL_UP` which is the up-arrow button on the controller, and `.intakeOut` will be assigned to `pros::E_CONTROLLER_DIGITAL_DOWN`, the controller down-arrow. Your final should look something like this:
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
Now download it and test it! Does holding your first button move it forward/up/in and your second button moves it backward/down/out? If so, you've succesfully coded a working helper function with defined controls!
>[!NOTE]
>If your forward/up/in goes backward/down/out, flip your motor port to be negative.

But what if your motor intake is spinning too fast? How do we turn it down? Using the speedOptions struct we can set speeds other than the default 100%!
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
        motorHelper1(
            buttonStatus(options.NA1),
            buttonStatus(options.NA2),
            speedOptions.intakeSpeed
        );

        [other code]
    }
```
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
Change `.NA1` to be your new name, in our case it will become `.intakeSpeed`. Now change 127 to be whatever speed you prefer. Now check if it builds and test it, if it works, you've succesfully created a working helper function with customizable speed!
>[!TIP]
>There is a `motorVelocity` function which can be called, it takes integer percentage values from -100 to 100 and converts them to the -127 to 127 range. To use it, you can write something like:\
>`.intakeSpeed = motorVelocity(80);`\
>This will run the motor at 80% speed.

## Pneumatic
This section will focus on pneumatics and what you can do with them, extras may be located in the [extra syntax section](#extra-syntax)
### Define your pneumatics
Similar to earlier, we're now going to define our pneumatic parts. Navigate back to `globals.hpp` and find the motors lines similar to\
`extern pros::adi::Pneumatics Pneumatic1;`\
These will be pneumatic pistons on your robot. To start, let's change the pneumatic's name from `Pneumatic1` to something on your robot, try replacing it with `clawToggle` or `intakeToggle`. Now navigate back to the `globals.cpp` file and fine the line that looks like\
`pros::adi::Pneumatics Pneumatic1('A', false);`\
This line is declaring your pneumatic in port A and the second conditional tells it whether to start extended or not (true = start extended). Unlike motors, you don't flip pneumatic directions in the code, you flip the hoses attatched to the pneumatic.\
**Example:**
```
In globals.hpp:
    extern pros::adi::Pneumatics clawToggle;

In globals.cpp:
    pros::adi::Pneumatics clawToggle('C', false);
```
>[!TIP]
>To test if your pneumatic configuration is proper, set its starting position to extended and [download the code](#downloading-code), if it starts extended then everything works! If not, try flipping the hoses around first. If it still fails, check your definition.

### Making pneumatic helper functions
Navigate to `helpers.hpp` and find the line which says\
`void pneumaticHelper1(const bool out, const bool in);`\
Change the name to something fitting for what your declared motor is going to do, something like `intakeToggleControls` or `clawToggleControls`. Then, we need to make sure the parameters make sense, ask "does this pneumatic open/close a part, change it's function, etc?" Once you've decided, change the names of `out` and `in` to match your function. Then navigate to your `helpers.cpp` and find the line that looks like\
`void pneumaticHelper1(const bool out, const bool in) {`\
Change the name from `pneumaticHelper1` to match the name in your `helpers.hpp` folder, then change the `out`/`in` to the new names you picked in your `helpers.hpp`.\
**Examples:**\
**1. A claw which toggles between open and closed**
```
In helpers.hpp:
    void clawToggleControls(const bool open, const bool closed);

In helpers.cpp:
    void clawToggleControls(const bool open, const bool closed) {
        [code here]
    }
```
\
**2. A motor which switches from intake to lift**
```
In helpers.hpp:
    void intakeToLiftToggle(const bool intake, const bool lift);

In helpers.cpp:
    void intakeToLiftToggle(const bool intake, const bool lift) {
        [code here]
    }
```
\
Once you've finished that, you're going to scroll further down in your `helpers.cpp` file until you find the `pneumaticControls` function, which should look like\
`void pneumaticControls(const struct pneumaticControlOptions& options) {`\
Inside of it, you should find something similar to the following:
```
    pneumaticHelper1(
        buttonStatus(options.NA1),
        buttonStatus(options.NA2)
    );
```
This must be renamed to the same name as your new function. This will be where your function is eventually going to be used.

### Writing a simple program inside our pneumatic helper function
Since you've created the helper function, now you need to write code inside it. Look back at your function *definition*, it should currently look something like
```
void clawToggleControls(const bool open, const bool closed) {

}
```
>[!NOTE]
>Yours may have different names, that's okay, you can copy the project if it makes more sense that way, but the lesson can be adapted to a different/unique function.

We're now going to add code here, let's start on a simple idea: We want a pneumatic to open the claw when you click the `open` button and close it when we click the `close` button (for preface, these boolean inputs are buttons that we will define in [the next section](#defining-pneumatic-controls)). Let's start this by writing our `open` conditional, we will write
```
if (open) {
    clawToggle.extend();
    return;
}
```
This may seem like a jump, but this can be broken apart.\
The `if (open)` is asking if the `open` boolean is set to true, in the exmaple code's context, this will eventually mean "was the selected button pressed?"\
The `clawToggle,extend();` line is simply saying "the pneumatic should now extend."\
The `return;` tells the function that it is done doing what it must and can immediately leave.\
Now what about when it should close? Let's write something similar, under our new code block, we will write something like
```
if (close) {
    clawToggle.retract();
}
```
This is almost exactly the same, except now the code is asking about the `close` button and retracting the piston. Now the `return;` line in the "open" statement has meaning, without it, if someone pressed both buttons, our robot would instantly extend and retract the piston, wasting air. Now the function ends early so that this doesn't happen.\
In the example, the final code looks as follows:
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
The comments directly instruct you on what to do, for our clawToggle function let's rename `NA1` and `NA2` to `clawOpen` and `clawClose` respectively. These will soon be our new controls for our intake helper function. To do this, move back to `helpers.cpp` and scroll down to our the `pneumaticControls` function, you should see something like:
```
void pneumaticControls(const struct pneumaticControlOptions& options) {
    clawToggleControls(
        buttonStatus(options.NA1),
        buttonStatus(options.NA2)
    );

    [other code here]
}
```
Change the names of the two parameters from `options.NA1` to `options.clawOpen` and `options.NA2` to `options.clawClose`. Then, add a new parameter to the buttonStatus function by putting a comma after the first parameter, now type `buttonPressTypes::NEW_PRESS`. This is telling the buttonStatus function to look for a new press of the button, so if the button is held it will only activate once.\
**Example:**
```
void pneumaticControls(const struct pneumaticControlOptions& options) {
    clawToggleControls(
        buttonStatus(options.clawOpen, buttonPressTypes::NEW_PRESS),
        buttonStatus(options.clawClose, buttonPressTypes::NEW_PRESS)
    );

    [other code here]
}
```
You've now told your code which values to use through more clarified naming conventions! Though, the controls haven't actually been defined yet. To do this, go your `main.cpp` file and scroll until you find the `pneumaticControls` function in main, it should look as follows:
```
pneumaticControls({
    //Controls options for motors
    //remove entire line for no control of said motor
    .NA1 = std::nullopt,
    .NA2 = std::nullopt,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt
});
```
For now, we will only change `.NA1` and `.NA2`. Start by changing their names to match the same ones you typed out earlier, for our example it would be:
```
pneumaticControls({
    //Controls options for motors
    //remove entire line for no control of said motor
    .clawOpen = std::nullopt,
    .clawClose = std::nullopt,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt
});
```
Finally, we can assign controller buttons to these! To start, assign your first one to some button, for our example, we will assign `.clawOpen` to `pros::E_CONTROLLER_DIGITAL_LEFT` which is the left-arrow button on the controller, and `.clawClose` will be assigned to `pros::E_CONTROLLER_DIGITAL_RIGHT`, the controller right-arrow. Your final should look something like this:
```
motorControls({
pneumaticControls({
    //Controls options for motors
    //remove entire line for no control of said motor
    .clawOpen = pros::E_CONTROLLER_DIGITAL_LEFT,
    .clawClose = pros::E_CONTROLLER_DIGITAL_RIGHT,
    .NA3 = std::nullopt,
    .NA4 = std::nullopt,
    .NA5 = std::nullopt,
    .NA6 = std::nullopt
});
```
Now download it and test it! Does pressing your first button open the claw? Does pressing the second button close the claw? If so, you've successfully coded a pneumatic helper function and its controls!
>[!NOTE]
>If your open instead does close, flip your attatched hoses on the pneumatic.

# The pros commands you'll use
(Coming soon)

# The git commands you'll use
(Coming soon)

# Extra syntax
(Coming soon)