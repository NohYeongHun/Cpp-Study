#include <iostream>
using namespace std;

// ������ ���� : �迭

struct StatInfo
{
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defenece = 0xDDDDDDDD;
};

int main()
{
	// TYPE �̸�[����];

	// �迭�� ũ��� ������� �� (VC �����Ϸ� ����)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// ���²� �������� [�̸�]�� �ٱ����� �̸��̾���
	int a = 10;
	int b = a;

	// �׷��� �迭�� [�̸�] ���� �ٸ��� �����Ѵ�
	StatInfo players[10];

	// players = monsters;

	// �׷� �迭�� �̸��� ����?
	// �迭�� �̸��� �� �迭�� ���� �ּ�
	// ��Ȯ���� ���� ��ġ�� ����Ű�� TYPE* ������
	auto WhoAmI = monsters;
	
	// StatInfo [ ] StatInfo[ ]
	// �ּ�[ (100, 10, 1) ] StatInfo[ ]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 100;
	monster_0->defenece = 100;

	// �������� ����! ��¥ 1�� ���ϴ°� �ƴ϶�, StatInfoŸ�� �ٱ��� �Ѱ��� �̵��϶�� �ǹ�
	// �ּ�[ (100, 10, 1) ] StatInfo[ ]
	// monster_0[ �ּ� ]
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defenece = 2;

	// �����Ϳ� ������ ��������� ��ȯ �����ϴ�
	// StatInfo[ ] .. StatInfo[ ] StatInfo[ ] StatInfo[ ] ....
	// monsters_2[ �ּ� ]
	// ������ ������ ���� ����<- �ٸ� �̸�
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defenece = 3;

	// [����] �̰Ŵ� ���� �ٸ� �ǹ̴�
	/*
	*  StatInfo[ ] .. StatInfo[ ] StatInfo[���빰 ] StatInfo[ ] ....
	*  temp[  ���빰    ]
	*  StatInfo Ÿ���� temp�� monsters[2]�� ���� �����Ѵ�.
	*/
	StatInfo temp;
	temp = *(monsters + 2);
	temp.hp = 300;
	temp.attack = 30;
	temp.defenece = 3;

	// �̸� ���� �� �ڵ�ȭ�Ѵ�.
	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defenece = (i + 1);
	}

	// �ٵ� *(monsters + i) �ʹ� �����ϰ� �������� ��������... �� ���� ���?
	// �ε���!
	// �迭�� 0������ ����. N��° �ε����� �ش��ϴ� �����Ϳ� �����Ϸ��� �迭�̸�[N]
	// *(monsters + i) = monsters[i]
	
	monsters[0].hp = 100;
	monsters[0].attack = 10;
	monsters[0].defenece = 1;

	for (int i = 0; i < 10; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defenece = (i + 1);
	}

	// �迭 �ʱ�ȭ ���� ���
	int numbers[5] = {};
	int numbers1[10] = { 1, 2, 3, 4, 5 }; // ���������� ���� ������ ���� ������ 0���� �ʱ�ȭ
	int numbers2[] = { 1, 2, 3, 4, 11, 24, 124, 14, 1 }; // ������ ������ŭ�� ũ�⿡ �ش��ϴ� �迭�� ������ش�.

	char str[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	cout << str << endl;

	// �迭 ���:
	// 1) �����Ѵ�
	int arr[10] = { };

	// 2) �ε����� �����ؼ� ���
	arr[1] = 1;
	cout << arr[1] << endl;

	return 0;
}