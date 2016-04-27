#ifndef PLAYER_H
#define PLAYER_H

struct object{
	std::string type; //weapon, armor, potion, map, etc. (more to be added)
	std::string description;
	int numberOwned = 0;
	int attack;
	int defense;
	int durability;
	int rarity;
	int healAmount;
	bool isEquipped = false;
};

class Player{
	public:
		Player();
		~Player();
		int health = 100;
		int backPackSize = 7;
		int power;
		int luck;
		int experience;
		int level = 1;
		int currentRoom;
		std::string directionFacing;
		object weaponEquipped;
		std::vector<object> backPack;
		int potionsInBag = 0;
		object armorSet[4];
		void lootRoom(object obj);
		void attack();
		void dodge();
		void usePotion();
		void openBackpack();
		object spawnLoot();
		void equipItem(object obj, int index);
		void discardItem(int index);
		void setCurrentRoom(int room);
	private:
		void discardItem();
};

#endif // PLAYER_H