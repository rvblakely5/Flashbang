# Flashbang
When you want to ruin a blue teamer's day

This is a red team windows payload designed for competition use. The intended use case of this tool is to bring choas to an operators box when critical taks on that box have been comleted in order to disrupt blue team operations and draw attention away from other infrastructure.

Flashbang payload - "Flashbang's" the target box, disorienting operator and opening backdoors

# Features

Holepunch - Opens 3 reverse shells to your specified machine (Requires nc.exe in working directory of payload)

Persistance - Sets registry keys to run on startup to continue obstructing user.

Disable Task Manager - Disables the user from using the task manager

Disable Remote PowerShell - Turns off PS remote capabilities to prevent box interaction

Music Spam - Opens a thread to constantly spam music to the user. Requires wav 'lul1' in working directory. Sample wav is a clip of base boosted harry potter theme.

Box Spam - Opens a message box to the user that they've been owned, box is spammed over and over.

Block User Input - Opens a thread that constantly locks the mouse and keyboard input the operating system.

Console Spam - Spams open console windows to the user.

Browser Spam - Spams open browser windows where you specify the target URL's.
