# Schmidt_CSCI2270_FinalProject
Summary
Text based dungeon game. Rooms are made using a graph data structure and a player class can traverse through the rooms. Each room has a chance to spawn loot and the player has the choice to pick up the object and put it into their backpack.

How to Run
This project is composed of 5 files, including a project driver (FinalProject.cpp), a player class header file (Player.h), a player class function file (Player.cpp), a dungeon class header file (Dungeon.h), and a dungeon class function file (Dungeon.cpp). With these files, in a Linux terminal window (I coded entirely using sublime text and compiled on the CU virtual machine(running Xubuntu)), link the .cpp using the command...
g++ -std=c++11 -o game FinalProject.cpp Dungeon.cpp Player.cpp
and then run the executable using the command...
./game
then follow on screen instructions to play the game.

Dependencies
There are no dependencies for this project

System Requirements
Run using g++ compiler on Xubuntu via the CU CSCI virtual machine

Group Members
Walker Schmidt

Open Issues/Bugs/Enhancement Requests
This game is still very rough around the edges. The current problem with items is finding a way to equip items and move them into and out of a backpack/discard the item. Anything that would help the random spawning of items/finding a way to have random rooms would be very helpful. Enemies will eventually be added and a way to have random battles/random enemies/an enemy class would be useful. Feel free to email any questions/enhancement requests to walker.schmidt@colorado.edu.

