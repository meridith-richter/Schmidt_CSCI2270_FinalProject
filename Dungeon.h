#ifndef DUNGEON_H
#define DUNGEON_H

struct room;

struct adjRoom{
    room *r;
    std::string direction; //we for west-east and ns for north-south
    bool isLocked;
};

struct room{
    int difficulty;
    int lootChance;
    int enemyChance;
    int roomNumber;
    int chunkNumber;
    bool visited = false;
    int x; //coordinates in a graph for directional purposes
    int y;
    std::string description;
    std::vector<adjRoom> adj;
    bool shouldLoad;
    const int maxAdjRooms = 4;
};

class Dungeon{
	public:
		Dungeon();
		~Dungeon();
		//std::string saveName;
		int levelDifficulty = 1;
		int currentChunk = 0;
		void dungeonInit();
		void printRooms();
		bool shouldLootSpawn(int chance, room r);
		std::vector<room> rooms;
		int nextRoomNumber = 1;
		int move(room r);
		std::string directionFacing;
	private:
        void addRoom(int difficulty, int lootChance, int enemyChance, int roomNumber_, int chunk, int x, int y);
        void addEdge(int room1, int room2, int chunk, std::string direction);
        //void shortestPath(std::string startingRoom,std::string endingRoom);
        //void fillEnemies();
};

#endif // DUNGEON_H