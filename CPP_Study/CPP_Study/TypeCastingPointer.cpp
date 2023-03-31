#include <iostream>
using namespace std;

// 오늘의 주제 : 타입 변환 (포인터)
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

	char _dummy[4096] = {}; // 이런 저런 정보들로 인해 비대해진

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
	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{
		Knight* knight = new Knight();

		// 암시적으로는 불가능
		// 명시적으로는 통과
		Item* item = (Item*)knight;
		item->_itemType = 2;
		item->_itemDbid = 1;

	}

	// 부모 -> 자식 변환 테스트
	{
		Item* item = new Item();

		// [ [item] ]
		
		Weapon* weapon = (Weapon*)item;
		// [ _damage ] => 메모리 범위를 초과한 메모리를 수정
		// weapon->_damage = 100; // 불가능

		delete item;
	}

	// 자식 -> 부모 변환 테스트
	{
		Weapon* weapon = new Weapon();

		// 자연스러운 타입 변환 가능 => 암시적 변환
		Item* item = weapon;

		TestItemPtr(item);

		delete weapon;
	}

	// 명시적으로 타입 변환할 때는 항상 조심해야 한다.
	// 암시적으로 될 때는 안전하다?
	// -> 평생 명시적으로 타입 변환(캐스팅)은 안하면 되는거 아닌가?

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

	// ************************* 매우 매우 중요 **********************
	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		delete item;

	}
	

	


	return 0;
}