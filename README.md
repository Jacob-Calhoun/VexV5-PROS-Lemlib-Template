Hello! This file contains all the directions that should get you started!\
# Installing VSCode
1. Make a Github account
2. Follow [this link](https://code.visualstudio.com/download) for download options
3. Install the one for you
4. Once installed, open it and click "sign in through Github"
5. Sign in with your Github information

# Installing the template for your own repo
>[!CAUTION]
>These steps are for Windows, MacOS users may need to adapt some names for Mac apps
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
In this section, I will explain how to actually use the template, features it has, and what things do. For coders who are curious about learning, I will also try to explain what the more abstract syntax means and how you can use it in your own code; though, these sections of explanation and application may also come in the [`Extra syntax` section](#Extra-syntax)

## Define your drivetrain
When opening your project, you should see files in the "src" and "include" folder dropdown, these files will be where you do all your coding. To start your project, enter `globals.hpp` and look around. Near the top, you should see lines like\
`extern pros::MotorGroup drivetrainLeft;`\
These are motor group declarations. A declaration is what goes in your .hpp files, it tells your code that this group of motors exist and are named drivetrainLeft, but it will not be defined in this file. Now navigate to `globals.cpp`, in there you should find\
`pros::MotorGroup drivetrainLeft({1,1}, pros::v5::MotorGearset::green);`\
The `{1,1}` is the list of ports for the motors in this group. Let's change it to reflect your actual drivetrain ports on the left side. If you have 3 motors on each side, no worries, add another comma and port number (example: `{1,2,3}`). Then look at the `pros::v5::MotorGearset::green`, this is your cartridge. Set it to whatever your drivetrain uses (you should be using the same cartridge for your entire drivetrain), if you use blue then it would be `pros::v5::MotorGearset::blue`. Now do the same for your right side in\
`pros::MotorGroup drivetrainRight({1,1}, pros::v5::MotorGearset::green)`\
We're not done, though! Motors on opposite sides need to spin opposite ways, if your motors on the left and right all face the same way, they would be `{1,2}`/`{1,2,3}` and `{-3,-4}`/`{-4,-5,-6}` respectively. A negative number for a port number means inverted, forward becomes backward and vice versa. In a moment when we test, if the drivetrain drives incorrectly, that's okay! Just change the negative/positive ports until it begins working, you should be able to figure out which should be negative and positive by talking to your builder and experimenting.

## Downloading code
To download code, first grab a download cord and plug it into your brain (or a paired controller) and computer, ensure that the brain/controller are turned on for this. When downloading code, we can use the terminal, if you don't have a terminal open, go to "terminal" and click "New terminal", now type `pros mu`, if you got no errors, your code is downloaded onto the brain! Now that the code is downloaded, it should default to slot 1, on the brain navigate to "programs" and click the program in the first slot, then click "run". Your brain should show you a long list of "N/A 1", "N/A 2", click A on your controller to continue. Now use the joysticks, the left joystick should move forward/backward while the right joystick should move left/right. If this is correct, amazing! Move to the next section, if your drivetrain appears to be doing something wrong, check your ports and return to [the above section](#Define-your-drivetrain).

## Define your motors
Now let's define some motors. Navigate back to `globals.hpp` and find the motors lines like\
`extern pros::Motor Motor1;`\
These will be motors on your robot. It follows the same declaration format as the drivetrain but now we declare a single motor rather than a motorgroup.  To start, let's change the motor's name from `Motor1` to something on your robot, try replacing it with `lift`, `claw`, or `intake`. Now navigate back to the `globals.cpp` file and fine the line that looks like\
`pros::Motor Motor1(1, pros::v5::MotorGearset::green);`\
This also follows the same format, but we only write a number like `1`/`-1` rather than `{1}`/`{-1}` because there's only one port for a motor. Once this makes sense, change the `Motor1` name to match whatever you wrote in your `globals.hpp` file and give it the port to this part of your robot. Finally, we need to actually test it; let's start by going to `main.cpp` and scrolling down until you find\
```
void opcontrol () {
    //temporary code
```

# Extra syntax