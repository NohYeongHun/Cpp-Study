#include <iostream>
using namespace std;

// ������ ���� : Ÿ�� ��ȯ (������)
class Knight
{
public:
	int _hp = 10;
};

class Item
{

public:
	Item()
	{
		cout << "item()" << endl;
	}

	Item(int _itemType) : _itemType(_itemType)
	{
		cout << "Item(_itemType)" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Item" << endl;
	}

public:
	int _itemType = 1;
	int _itemDbid = 4;

	char _dummy[4096] = {}; // �̷� ���� ������� ���� �������

};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2
};

class Weapon : public Item
{
public:

	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
		_damage = 1 + rand() % 100;
	}

	~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

	void Test()
	{
		cout << "Test Weapon" << endl;
	}
public:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}

	~Armor()
	{
		cout << "~Armor()" << endl;
	}
public:
	int _defence = 0;
};


void TestItemPtr(Item* item)
{
	item->Test();
}

int main()
{
	// �������� ���� Ŭ���� ������ ������ ��ȯ �׽�Ʈ
	{
		Knight* knight = new Knight();

		// �Ͻ������δ� �Ұ���
		// ��������δ� ���
		Item* item = (Item*)knight;
		item->_itemType = 2;
		item->_itemDbid = 1;

	}

	// �θ� -> �ڽ� ��ȯ �׽�Ʈ
	{
		Item* item = new Item();

		// [ [item] ]
		
		Weapon* weapon = (Weapon*)item;
		// [ _damage ] => �޸� ������ �ʰ��� �޸𸮸� ����
		// weapon->_damage = 100; // �Ұ���

		delete item;
	}

	// �ڽ� -> �θ� ��ȯ �׽�Ʈ
	{
		Weapon* weapon = new Weapon();

		// �ڿ������� Ÿ�� ��ȯ ���� => �Ͻ��� ��ȯ
		Item* item = weapon;

		TestItemPtr(item);

		delete weapon;
	}

	// ��������� Ÿ�� ��ȯ�� ���� �׻� �����ؾ� �Ѵ�.
	// �Ͻ������� �� ���� �����ϴ�?
	// -> ��� ��������� Ÿ�� ��ȯ(ĳ����)�� ���ϸ� �Ǵ°� �ƴѰ�?

	Item* inventory[20] = {};

	srand((unsigned)time(nullptr));
	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2;
		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;
		case 1:
			inventory[i] = new Armor();
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}

	// ************************* �ſ� �ſ� �߿� **********************
	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		delete item;

	}
	

	


	return 0;
}