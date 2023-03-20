#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 실습

struct StatInfo
{
	int hp; // +0 주소 위치
	int attack; // +4 주소 위치
	int defence; // +8 주소 위치
};

void EnterLobby();
StatInfo CreatePlayer(); // pointer 미적용
void CreateMonster(StatInfo* info); // pointer 적용

// 플레이어 승리 시 true, 아니면 false
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
	EnterLobby();
	return 0;
}


void EnterLobby()
{
	cout << "로비에 입장했습니다" << endl;

	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defence = 0xbbbbbbbb;

	// [매개변수][RET][지역변수(temp(c,c,c), player(b,b,b)] [매개변수(&temp)][RET][지역변수(ret(100, 10, 2))]
	// ret 값을 지역변수 temp에 temp(100, 10, 2)를 복사
	/*
	* 동작
	* player = CreatePlayer()는 다음과 같이 동작
	* 1. StatInfo temp = CreatePlayer();
	* 2. player = temp;
	*/ 
	player = CreatePlayer();
	

	// [매개변수][RET][지역변수(monster(40, 8, 1))] [매개변수(&monster)][RET][지역변수()]
	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.attack = 0xbbbbbbbb;
	monster.defence = 0xbbbbbbbb;

	CreateMonster(&monster);
	
	bool victory = StartBattle(&player, &monster);

	if (victory)
	{
		cout << "승리!" << endl;
	}
	else 
	{
		cout << "패배!" << endl;
	}


}

StatInfo CreatePlayer()
{
	StatInfo ret;
	
	cout << "플레이어 생성" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

	info -> hp = 40;
	info -> attack = 8;
	info -> defence = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->defence;
		if (damage < 0)
		{
			damage = 0;
		}

		monster->hp -= damage;
		if (monster->hp < 0)
		{
			monster->hp = 0;
		}

		cout << "몬스터 HP : " << monster->hp << endl;
		
		if (monster->hp == 0)
		{
			return true;
		}

		damage = monster->attack - player->defence;
		if (damage < 0)
		{
			damage = 0;
		}

		player->hp -= damage;
		cout << "플레이어 HP : " << player->hp << endl;
		if (player->hp < 0)
		{
			player->hp = 0;
		}

		if (player->hp == 0)
		{
			return false;
		}
	}
}