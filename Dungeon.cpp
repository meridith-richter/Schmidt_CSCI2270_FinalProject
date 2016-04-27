#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "Dungeon.h"
#include "Player.h"

using namespace std;

Dungeon::Dungeon(){}

Dungeon::~Dungeon(){}

void Dungeon::dungeonInit(){
	for(int i = 0; i < 64; i++){
		float loot = rand() % 10;
		float enemy = rand() % 10;
        int x_;
        int y_;

        if(nextRoomNumber == (1 + (8*currentChunk)) || nextRoomNumber == (2 + (8*currentChunk)) || nextRoomNumber == (5 + (8*currentChunk)) || nextRoomNumber == (8 + (8*currentChunk))){
            y_ = 2;
        }else if(nextRoomNumber == (3 + (8*currentChunk)) || nextRoomNumber == (6 + (8*currentChunk))){
            y_ = 1;
        }else if(nextRoomNumber == (4 + (8*currentChunk)) || nextRoomNumber == (7 + (8*currentChunk))){
            y_ = 3;
        }

        if(nextRoomNumber == (3 + (8*currentChunk)) || nextRoomNumber == (2 + (8*currentChunk)) || nextRoomNumber == (4 + (8*currentChunk))){
            x_ = (2 + (4*currentChunk));
        }else if(nextRoomNumber == (7 + (8*currentChunk)) || nextRoomNumber == (6 + (8*currentChunk)) || nextRoomNumber == (5 + (8*currentChunk))){
            x_ = (3 + (4*currentChunk));
        }else if(nextRoomNumber == (8 + (8*currentChunk))){
            x_ = (4 + (4*currentChunk));
        }else if(nextRoomNumber == (1 + (8*currentChunk))){
            x_ = (1 + (4*currentChunk));
        }

		addRoom(1, loot, enemy, nextRoomNumber, currentChunk, x_, y_);
        nextRoomNumber++;
        if(i != 0 && (i + 1) % 8 == 0){
            currentChunk++;
        }
	}
	for(int i = 0; i < 16; i++){
        if(i != 0){
            addEdge(1 + (8*i),8 + (8*(i - 1)),1,"we");
        }
        addEdge(1 + (8*i),2 + (8*i),1,"we");
    	addEdge(2 + (8*i),3 + (8*i),1,"ns");
    	addEdge(2 + (8*i),4 + (8*i),1,"ns");
    	addEdge(2 + (8*i),5 + (8*i),1,"we");
    	addEdge(4 + (8*i),7 + (8*i),1,"we");
    	addEdge(5 + (8*i),6 + (8*i),1,"ns");
    	addEdge(5 + (8*i),7 + (8*i),1,"ns");
    	addEdge(5 + (8*i),8 + (8*i),1,"we");
    }
    //currentChunk++;
}

void Dungeon::addRoom(int diff, int loot, int enemy, int roomNumber_, int currentChunk_, int x_, int y_){
    room r;
    r.difficulty = diff;
    r.lootChance = loot;
    r.enemyChance = enemy;
    r.roomNumber = roomNumber_;
    r.chunkNumber = currentChunk_;
    r.description = "no description provided";
    r.x = x_;
    r.y = y_;
    rooms.push_back(r);
}

void Dungeon::addEdge(int r1, int r2, int chunk, string direction){
    for(int i = (8*(chunk-1)); i < rooms.size(); i++){
        if(rooms[i].roomNumber == r1){
            for(int j = (8*(chunk-1)); j < rooms.size(); j++){
                if(rooms[j].roomNumber == r2 && i != j){
                    adjRoom ar1;
                    adjRoom ar2;
                    ar1.direction = direction;
                    ar2.direction = direction;
	                ar1.r = &rooms[j];
                    ar2.r = &rooms[i];
	                rooms[i].adj.push_back(ar1);
                    rooms[j].adj.push_back(ar2);
                }
            }
        }
    }
}

void Dungeon::printRooms(){
    for(int i = 0; i < rooms.size(); i++){
        cout<<rooms[i].chunkNumber<<":"<<rooms[i].roomNumber<<"-->";
        for(int j = 0; j < rooms[i].adj.size(); j++){
            cout<<rooms[i].adj[j].r->roomNumber;
            if(j != rooms[i].adj.size() - 1){
                cout<<"***";
            }
        }
        cout<<endl;
    }
}

int Dungeon::move(room r1){
    cout<<directionFacing<<endl;
    room *left = NULL;
    room *right = NULL;
    room *straight = NULL;
    room *back = NULL;

    int doors = r1.adj.size();
    for(int i = 0; i < doors; i++){

        if(directionFacing == "north"){
            if(r1.adj[i].direction == "we"){
                if(r1.adj[i].r->x > r1.x){
                    right = r1.adj[i].r;
                }else{
                    left = r1.adj[i].r;
                }
            }else if(r1.adj[i].direction == "ns"){
                if(r1.adj[i].r->y > r1.y){
                    back = r1.adj[i].r;
                }else{
                    straight = r1.adj[i].r;
                }
            }           
        }else if(directionFacing == "south"){
            if(r1.adj[i].direction == "we"){
                if(r1.adj[i].r->x > r1.x){
                    left = r1.adj[i].r;
                }else{
                    right = r1.adj[i].r;
                }
            }else if(r1.adj[i].direction == "ns"){
                if(r1.adj[i].r->y > r1.y){
                    straight = r1.adj[i].r;
                }else{
                    back = r1.adj[i].r;
                }
            }                   
        }else if(directionFacing == "west"){
            if(r1.adj[i].direction == "we"){
                if(r1.adj[i].r->x > r1.x){
                    back = r1.adj[i].r;
                }else{
                    straight = r1.adj[i].r;
                }
            }else if(r1.adj[i].direction == "ns"){
                if(r1.adj[i].r->y > r1.y){
                    left = r1.adj[i].r;
                }else{
                    right = r1.adj[i].r;
                }
            }                   
        }else if(directionFacing == "east"){
            if(r1.adj[i].direction == "we"){
                if(r1.adj[i].r->x > r1.x){
                    straight = r1.adj[i].r;
                }else{
                    back = r1.adj[i].r;
                }
            }else if(r1.adj[i].direction == "ns"){
                if(r1.adj[i].r->y > r1.y){
                    right = r1.adj[i].r;
                }else{
                    left = r1.adj[i].r;
                }
            }                   
        }
    }

    cout<<"Choose a direction"<<endl;

    int i = 1;

    string rightChoice = "";
    string leftChoice = "";
    string straightChoice = "";
    string backChoice = "";

    if(left != NULL){
        cout<<i<<". Left"<<endl;
        leftChoice = to_string(i);
        i++;
    }

    if(right != NULL){
        cout<<i<<". Right"<<endl;
        rightChoice = to_string(i);
        i++;
    }

    if(straight != NULL){
        cout<<i<<". Straight"<<endl;
        straightChoice = to_string(i);
        i++;
    }

    if(back != NULL){
        cout<<i<<". Back"<<endl;
        backChoice = to_string(i);
        i++;
    }

    string userInput = "";
    cin>>userInput;
    if(userInput == leftChoice){
        if(directionFacing == "north"){
            directionFacing = "west";
        }else if(directionFacing == "south"){
            directionFacing = "east";
        }else if(directionFacing == "east"){
            directionFacing = "north";
        }else if(directionFacing == "west"){
            directionFacing = "south";
        }
        return (left->roomNumber);
    }else if(userInput == rightChoice){
        if(directionFacing == "north"){
            directionFacing = "east";
        }else if(directionFacing == "south"){
            directionFacing = "west";
        }else if(directionFacing == "east"){
            directionFacing = "south";
        }else if(directionFacing == "west"){
            directionFacing = "north";
        }
        return (right->roomNumber);
    }else if(userInput == straightChoice){
        return (straight->roomNumber);
    }else if(userInput == backChoice){
        if(directionFacing == "north"){
            directionFacing = "south";
        }else if(directionFacing == "south"){
            directionFacing = "north";
        }else if(directionFacing == "east"){
            directionFacing = "west";
        }else if(directionFacing == "west"){
            directionFacing = "east";
        }
        return (back->roomNumber);
    }else{
        cout<<"Invalid input"<<endl;
    }
}

bool Dungeon::shouldLootSpawn(int chance, room r){
    float realChance = ((chance+r.lootChance)/2)*10;
    float random = 10 + (rand() % 100);
    if(random < realChance + levelDifficulty){
        return true;
    }else{
        return false;
    }
}