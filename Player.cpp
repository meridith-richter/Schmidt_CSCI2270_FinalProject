#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "Player.h"
#include "Dungeon.h"

using namespace std;

Player::Player(){}

Player::~Player(){}

object Player::spawnLoot(){
	object obj;
	float randType = 1 + (rand() % 10);
	if(randType <= 5){
		obj.type = "potion";
		obj.healAmount = 15;
		obj.description = "Magical potion that slightly heals you, instantly!";
	}else if(randType > 5 && randType <= 8){
		obj.type = "armor";
		int randArmor = 1 + (rand() % 100);
		
		if(randArmor <= 25){
			obj.description = "boots";
			if(randArmor % 25 == 0){
				obj.defense = 25*level*(1 + (rand() % 3));
				obj.durability = 5 + (rand() % 10);
			}else if(randArmor % 5 == 0){
				obj.defense = 15*level*(1 + (rand() % 2));
				obj.durability = 7 + (rand() % 8);
			}else{
				obj.defense = 5*level;
				obj.durability = 15 + (rand() % 12);
			}
		}else if(randArmor > 25 && randArmor <= 50){
			obj.description = "legs";
			if(randArmor % 25 == 0){
				obj.defense = 25*level*(1 + (rand() % 3));
				obj.durability = 5 + (rand() % 10);
			}else if(randArmor % 5 == 0){
				obj.defense = 15*level*(1 + (rand() % 2));
				obj.durability = 7 + (rand() % 8);
			}else{
				obj.defense = 5*level;
				obj.durability = 15 + (rand() % 12);
			}
		}else if(randArmor > 50 && randArmor <= 75){
			obj.description = "chest";
			if(randArmor % 25 == 0){
				obj.defense = 25*level*(1 + (rand() % 3));
				obj.durability = 5 + (rand() % 10);
			}else if(randArmor % 5 == 0){
				obj.defense = 15*level*(1 + (rand() % 2));
				obj.durability = 7 + (rand() % 8);
			}else{
				obj.defense = 5*level;
				obj.durability = 15 + (rand() % 12);
			}
		}else if(randArmor > 75){
			obj.description = "helmet";
			if(randArmor % 25 == 0){
				obj.defense = 25*level*(1 + (rand() % 3));
				obj.durability = 5 + (rand() % 10);
			}else if(randArmor % 5 == 0){
				obj.defense = 15*level*(1 + (rand() % 2));
				obj.durability = 7 + (rand() % 8);
			}else{
				obj.defense = 5*level;
				obj.durability = 15 + (rand() % 12);
			}
		}

	}else if(randType > 8){
		obj.type = "weapon";
		obj.description = "sword";
		if(randType == 9){
			obj.attack = 15*level*(1 + (rand() % 2));
			obj.durability = 5 + (rand() % 10);
		}else if(randType == 10){
			obj.attack = 30*level*(1 + (rand() % 2));
			obj.durability = 2 + (rand() % 7);
		}
	}
	cout<<"You found a "<<obj.type<<"!"<<endl;
	return obj;
}

void Player::lootRoom(object obj){
	bool isDuplicate = false;
	if(obj.type == "potion"){
		for(int i = 0; i < backPack.size(); i++){
			if(backPack[i].type == "potion"){
				isDuplicate = true;
			}
		}
		if(isDuplicate){
			potionsInBag++;
			cout<<"You now have "<<potionsInBag<<" potions!"<<endl;
		}else{
			if(backPack.size() < backPackSize){
				potionsInBag++;
				backPack.push_back(obj);
				cout<<"You put a "<<obj.type<<" in your backpack"<<endl;
			}else{
				cout<<"Backpack is full!"<<endl;
			}
		}
	}else if(backPack.size() < backPackSize){
		backPack.push_back(obj);
		cout<<"You put a "<<obj.type<<" in your backpack"<<endl;
	}else{
		cout<<"Backpack is full!"<<endl;
	}
	isDuplicate = false;
}

void Player::attack(){}

void Player::dodge(){}

void Player::usePotion(){}

void Player::openBackpack(){
	string userInput = "";
	string itemNumber = "";
	cout<<"============================="<<endl;
	for(int i = 0; i < backPack.size(); i++){
		if(backPack[i].type == "armor"){
			cout<<i+1<<":"<<"Armor-->"<<"Defense; "<<backPack[i].defense<<" | 1. Equip/use item"<<endl;
		}else if(backPack[i].type == "potion"){
			cout<<i+1<<":"<<"Potion("<<potionsInBag<<")-->"<<backPack[i].description<<" | 1. Equip/use item"<<endl;
		}if(backPack[i].type == "weapon"){
			cout<<i+1<<":"<<"Weapon-->"<<"Attack; "<<backPack[i].attack<<" | 1. Equip/use item"<<endl;
		}
	}
	cout<<"2. Discard item"<<endl;
	cout<<"3. Leave backpack"<<endl;
	/*cin>>userInput;
	if(userInput == "1"){
		cout<<"What item would you like to equip?"<<endl;
		cin>>itemNumber;
		int item = stoi(itemNumber) - 1;
		equipItem(backPack[item], item);
	}else if(userInput == "2"){
		cout<<"What item would you like to discard?"<<endl;
		cin>>itemNumber;
		int item = stoi(itemNumber) - 1;
	}*/
}

void Player::discardItem(int indexToDiscard){

}

void Player::equipItem(object toEquip, int backPackIndex){
	/*object item;
	if(toEquip.type == "armor"){
		if(toEquip.description == "boots"){
			if(armorSet[0] == NULL){
				item = toEquip;
				armorSet[0] = item;
				backPack.erase(backPackIndex);
			}else{
				if(backPack.size() < backPackSize + 1){
					item = toEquip;
					backPack.erase(backPackIndex);
					backPack.push_back(armorSet[0]);
					armorSet[0] = item;
				}
			}
		}else if(toEquip.description == "legs"){
			if(armorSet[1] == NULL){
				item = toEquip;
				armorSet[1] = item;
				backPack.erase(backPackIndex);
			}else{
				if(backPack.size() < backPackSize + 1){
					item = toEquip;
					backPack.erase(backPackIndex);
					backPack.push_back(armorSet[1]);
					armorSet[1] = item;
				}
			}
		}else if(toEquip.description == "chest"){
			if(armorSet[2] == NULL){
				item = toEquip;
				armorSet[2] = item;
				backPack.erase(backPackIndex);
			}else{
				if(backPack.size() < backPackSize + 1){
					item = toEquip;
					backPack.erase(backPackIndex);
					backPack.push_back(armorSet[2]);
					armorSet[2] = item;
				}
			}
		}else if(toEquip.description == "helmet"){
			if(armorSet[3] == NULL){
				item = toEquip;
				armorSet[3] = item;
				backPack.erase(backPackIndex);
			}else{
				if(backPack.size() < backPackSize + 1){
					item = toEquip;
					backPack.erase(backPackIndex);
					backPack.push_back(armorSet[3]);
					armorSet[3] = item;
				}
			}
		}
	}else if(toEquip.type == "weapon"){
		if(weaponEquipped == NULL){
			item = toEquip;
			weaponEquipped = item;
			backPack.erase(backPackIndex);
		}else{
			if(backPack.size() < backPackSize + 1){
				item = toEquip;
				backPack.erase(backPackIndex);
				backPack.push_back(weaponEquipped);
				weaponEquipped = item;
			}
		}
	}else{
		cout<<"You cannot equip that item"<<endl;
	}*/
}

void Player::setCurrentRoom(int room){
	currentRoom = room;
}