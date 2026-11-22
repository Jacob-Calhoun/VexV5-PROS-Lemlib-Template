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
In this section, I will explain how to actually use the template, features it has, and what things do. For coders who are curious about learning, I will also try to explain what the more abstract syntax means and how you can use it in your own code; though, these sections of explanation and application may also come in the `Applying template syntax` section
## Start defining motors