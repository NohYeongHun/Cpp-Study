#include <iostream>
using namespace std;

// 오늘의 주제 TextRPG
enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum GameType
{
	GT_Start = 1,
	GT_End = 2,
};

enum CombatType
{
	CT_Combat = 1,
	CT_Run = 2,
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};


struct ObjectInfo
{
	short type;
	int hp;
	int attack;
	int defence;
};
/*
* 2 + 4 + 4 + 4 = > 14bytes ?
* 14byte 크기와 정확하게 맞지 않을 수 있다.
*/ 


ObjectInfo playerInfo;
ObjectInfo monsterInfo;

int gameType;
int combatType;

const string line = "--------------------\n";

void GameStart();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void Battle();

void GameStart()
{
	while (true)
	{
		cout << line << "로비에 입장했습니다!\n" << line;

		// 플레이어 직업 선택
		SelectPlayer();

		cout << line << "(1) 필드 입장 (2) 게임 종료\n" << line;
		cout << "> ";

		int fieldType;
		cin >> fieldType;

		if (fieldType == GT_Start)
		{
			EnterField();
		}
		else 
		{
			return;
		}
	}
}
void SelectPlayer()
{
	while (true)
	{
		cout << line << "직업을 골라주세요!\n";
		cout << "(1) 기사 (2) 궁수 (3) 법사\n";
		cout << "> ";

		cin >> playerInfo.type;

		if (playerInfo.type == PT_Knight)
		{
			cout << "기사 생성중 ... !" << endl;
			playerInfo.hp = 100; 
			playerInfo.attack = 20; 
			playerInfo.defence = 5;
			break;
		}
		else if (playerInfo.type == PT_Archer)
		{
			cout << "궁수 생성중 ... !" << endl;
			playerInfo.hp = 90; 
			playerInfo.attack = 25; 
			playerInfo.defence = 0;
			break;
		}
		else if (playerInfo.type == PT_Mage)
		{
			cout << "법사 생성중 ...!" << endl;
			playerInfo.hp = 80; 
			playerInfo.attack = 30; 
			playerInfo.defence = 0;
			break;
		}
	}
}
void EnterField()
{
	while (playerInfo.hp > 0) {
		cout << "[PLAYER] HP : " 
			 << playerInfo.hp 
			 << " / ATK : " 
			 << playerInfo.attack 
			 << " / DEF : " 
			 << playerInfo.defence << endl;

		CreateRandomMonster();

		cout << "(1) 전투 (2) 도주" << endl;
		cout << "> ";
		cin >> combatType;

		if (combatType == CT_Combat)
		{
			Battle();
		}
		else
		{
			return;
		}
		
	}
}
void CreateRandomMonster()
{
	int monsterType = 1 + (rand() % 3); // 1 + (0 ~ 32767) % 3 => 1 2 3

	switch (monsterType)
	{
		case MT_Slime:
			monsterInfo.hp = 40;
			monsterInfo.attack = 5;
			monsterInfo.defence = 0;
			cout << "슬라임 생성중...!(HP : " << monsterInfo.hp << " / ATK : " << monsterInfo.attack << " / DEF : " << monsterInfo.defence << endl;
			cout << line;
			break;
		case MT_Orc:
			monsterInfo.hp = 40;
			monsterInfo.attack = 10;
			monsterInfo.defence = 5;
			cout << "오크 생성중...!(HP : " << monsterInfo.hp << " / ATK : " << monsterInfo.attack << " / DEF : " << monsterInfo.defence << endl;
			cout << line;
			break;
		case MT_Skeleton:
			monsterInfo.hp = 80;
			monsterInfo.attack = 15;
			monsterInfo.defence = 5;
			cout << "해골 생성중...!(HP : " << monsterInfo.hp << " / ATK : " << monsterInfo.attack << " / DEF : " << monsterInfo.defence << endl;
			cout << line;
			break;
	}
}
void Battle()
{
	while (true)
	{
		int MonsterHitDamage = (playerInfo.attack - monsterInfo.defence) > 0 ? playerInfo.attack - monsterInfo.defence : 0;
		int PlayerHitDamage = (monsterInfo.attack - playerInfo.defence) > 0 ? monsterInfo.attack - playerInfo.defence : 0;
		monsterInfo.hp = (monsterInfo.hp - MonsterHitDamage) > 0 ? monsterInfo.hp - MonsterHitDamage : 0;
		cout << "몬스터 남은 체력 : " << monsterInfo.hp << endl;
		if (monsterInfo.hp == 0) {
			cout << "몬스터를 처치했습니다." << endl;
			return;
		}
		
		playerInfo.hp = (playerInfo.hp - PlayerHitDamage) > 0 ? playerInfo.hp - PlayerHitDamage : 0;
		cout << "플레이어 남은 체력 : " << playerInfo.hp << endl;
		if (playerInfo.hp == 0) {
			cout << "당신은 사망했습니다... GAME OVER" << endl;
			return;
		}
	}
}

int main()
{	
	// 랜덤 시드 설정
	srand(time(0)); 

	// 게임 시작
	GameStart();
}