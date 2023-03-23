#include <iostream>
using namespace std;

// 오늘의 주제 TextRPG2

// main
// - EnterLobby (PlayerInfo)
// -- CreatePlayer()
// -- EnterGame()
// --- CreateMonsters
// --- EnterBattle()

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct StatInfo
{
	int hp = 0;
	int attack = 0;
	int defence = 0;
};


void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* player);
void PrintStatInfo(const char* name, const StatInfo& info);
void EnterGame(StatInfo* playerInfo);
bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo);
void CreateMonsters(StatInfo* monster, int count);


int main()
{
	srand((unsigned)time(nullptr));
	EnterLobby();
	return 0;
}

void EnterLobby()
{
	while (true)
	{
		PrintMessage("로비에 입장했습니다");
		
		// PLAYER!;
		StatInfo playerInfo;
		CreatePlayer(&playerInfo);
		PrintStatInfo("Player", playerInfo);
		EnterGame(&playerInfo);
	}
}

void PrintMessage(const char* msg)
{
	cout << "****************************" << endl;
	cout << msg << endl;
	cout << "****************************" << endl;
}

void CreatePlayer(StatInfo* player)
{
	bool ready = false;
	int classId;
	PrintMessage("캐릭터 생성");
	cout << "(1) 기사 (2) 궁수 (3) 마법사" << endl;
	cout << "> ";
	cin >> classId;

	while (ready == false)
	{
		switch (classId)
		{
		case PT_Knight:
			player->hp = 100;
			player->defence = 10;
			player->attack = 20;
			ready = true;
			break;
		case PT_Archer:
			player->hp = 90;
			player->defence = 5;
			player->attack = 25;
			ready = true;
			break;
		case PT_Mage:
			player->hp = 80;
			player->defence = 0;
			player->attack = 30;
			ready = true;
			break;
		}

	}
	

}
void PrintStatInfo(const char* name, const StatInfo& info)
{
	cout << "****************************" << endl;
	cout << name << "HP = " << info.hp << " DEF = " << info.defence << " ATK = " << info.attack << endl;
	cout << "****************************" << endl;
}


void EnterGame(StatInfo* playerInfo)
{
	const int MONSTER_COUNT = 2;
	PrintMessage("게임에 입장했습니다");
	while (true)
	{
		StatInfo monsterInfo[MONSTER_COUNT];
		CreateMonsters(monsterInfo, MONSTER_COUNT);
		for (int i = 0; i < MONSTER_COUNT; i++)
		{
			PrintStatInfo("Monster", monsterInfo[i]);
		}

		PrintStatInfo("Player", *playerInfo);

		PrintMessage("[1] 전투 [2] 전투 [3] 도망");
		int input;
		cin >> input;

		if (input == 1 || input == 2)
		{
			int index = input - 1;
			bool victory = EnterBattle(playerInfo, &monsterInfo[index]);

			if (victory == false) return;
		}
		else
		{
			return;
		}
		
	}
}

void CreateMonsters(StatInfo* monsterInfo, int count)
{
	for (int i = 0; i < count; i++)
	{
		int monsterType = 1 + (rand() % 3);
		switch (monsterType)
		{
		case MT_Slime:
			PrintMessage("슬라임 생성중...");
			
			monsterInfo[i].hp = 30;
			monsterInfo[i].defence = 5;
			monsterInfo[i].attack = 1;

			break;
		case MT_Orc:
			PrintMessage("오크 생성중...");
			monsterInfo[i].hp = 40;
			monsterInfo[i].defence = 8;
			monsterInfo[i].attack = 2;

			break;
		case MT_Skeleton:
			PrintMessage("스켈레톤 생성중...");
			monsterInfo[i].hp = 50;
			monsterInfo[i].defence = 15;
			monsterInfo[i].attack = 3;
			break;
		}
	}
	
}

bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo)
{
	
	while (true)
	{
		int monsterHitDamage = playerInfo->attack - (monsterInfo->defence);
		if (monsterHitDamage < 0)
		{
			monsterHitDamage = 0;
		}

		monsterInfo->hp -= monsterHitDamage;
		if (monsterInfo->hp < 0)
		{
			monsterInfo->hp = 0;
		}

		PrintStatInfo("Monster", *monsterInfo);

		if (monsterInfo->hp == 0)
		{
			PrintMessage("몬스터를 처치했습니다");
			return true;
		}

		
		int playerHitDamage = monsterInfo->attack - (playerInfo->defence);
		if (playerHitDamage < 0)
		{
			playerHitDamage = 0;
		}

		playerInfo->hp -= playerHitDamage;
		if (playerInfo->hp < 0)
		{
			playerInfo->hp = 0;
		}

		PrintStatInfo("Player", *playerInfo);

		if (playerInfo->hp == 0)
		{
			PrintMessage("GAME OVER");
			return false;
		}	

	}
}

