//https://github.com/walkyd12/Schmidt_CSCI2270_FinalProject.git
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <queue>
#include "Dungeon.h"
#include "Player.h"

using namespace std;

int main(int argc, char *argv[]){
	//Everything that needs to be instantiated before the game begins
	int srand (time(0));

	Dungeon dung;
	Player player;

	dung.dungeonInit();

	int currentRoomNumber = 1;

	object firstSword;
	firstSword.type = "weapon";
	firstSword.attack = 5;
	firstSword.durability = 2;

	player.currentRoom = 1;
	player.luck = 4;
	player.weaponEquipped = firstSword;
	dung.directionFacing = "east";

	string userInput = "main";
	string gameInput = "";

	//main menu, will have more options as things are added
	cout<<"Welcome to Walker's Dungeon"<<endl;
	while(userInput != "3"){
		if(userInput == "main"){
			cout<<"=========Main Menu========="<<endl;
			cout<<"1. Play Game"<<endl;
			cout<<"2. How to Play"<<endl;
			cout<<"3. Quit"<<endl;
			getline (cin, userInput);
		}

		if(userInput == "1"){
			//actual game loop
			while(gameInput != "quit"){
				for (int i = 0; i < dung.rooms.size(); i++){
					bool loot;
					object newLoot;

					//checks if loot should spawn in the player's room
					if(dung.rooms[i].roomNumber == player.currentRoom){			
						if(dung.rooms[i].roomNumber != 1 && dung.rooms[i].roomNumber != 2 && !dung.rooms[i].visited){
							loot = dung.shouldLootSpawn(player.luck, dung.rooms[i]);
							if(loot){
								newLoot = player.spawnLoot();
							}
						}

						dung.rooms[i].visited = true;

						//sets up another interface for the user to choose what to do
						cout<<"What would you like to do?"<<endl;

						string putLoot;
						string move;
						string checkBackpack;
						string main;

						//users can loot rooms if loot spawns in the room
						int menuNumber = 1;
						if(loot){
							cout<<menuNumber<<". Put Loot in Backpack"<<endl;
							putLoot = to_string(menuNumber);
							menuNumber++;
						}

						//user can move to a new room
						cout<<menuNumber<<". Move"<<endl;
						move = to_string(menuNumber);
						menuNumber++;

						//look through backpack
						cout<<menuNumber<<". Check Backpack"<<endl;
						checkBackpack = to_string(menuNumber);
						menuNumber++;

						cin>>gameInput;

						if(loot && gameInput == putLoot){
							player.lootRoom(newLoot);
						}

						if(gameInput == move){
							currentRoomNumber = dung.move(dung.rooms[i]);
						}else if(gameInput == checkBackpack){
							player.openBackpack();
						}

						player.setCurrentRoom(currentRoomNumber);
						
						i = 0;
						if(gameInput == "quit"){
							i = dung.rooms.size();
						}
					}
				}
			}
			userInput = "main";
		}
		if(userInput == "2"){
			//quick instructions on how to play
			cout<<"============================================="<<endl;
			cout<<"               How to Play"<<endl;
			cout<<"   You begin in a dungeon room and you can"<<endl;
			cout<<"           choose what you do"<<endl;
			cout<<"Follow on screen prompts and enter the exact"<<endl;
			cout<<"         number of your choices"<<endl;
			cout<<" While moving, you always enter a room with"<<endl;
			cout<<" your back facing the door you came through"<<endl;
			cout<<"============================================="<<endl;
			userInput = "main";
		}
	}
	cout << "Goodbye!" << endl;
}