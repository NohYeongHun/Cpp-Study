#include <iostream>
using namespace std;

// ������ ���� : �Լ� ������

typedef int* POINTER;
typedef int FUNC(int, int);
typedef int ARRAY[20];
typedef int(*PFUNC)(int, int);

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{
public:
	Item() : _itemId(0), _rarity(0), _ownerId(0)
	{

	}

public:
	int _itemId; // �������� �����ϱ� ���� ID
	int _rarity; // ��͵�
	int _ownerId; // ������ ID
};

/*
	(�Լ�)������ ���ڷ� �־��� �� �ִ�!
	bool(*selector)(item* item)
	== typedef bool (ITEM_SELECTOR)(Item* item);
*/
Item* FindItem(Item items[], int itemCount, bool(*selector)(Item* item))
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		// TODO ����
		if (selector(item)) return item;
	}
}

bool IsRareItem(Item* item)
{
	return item->_rarity >= 2;
}

bool IsOwnerItem(Item* item, int ownerId)
{
	return item->_ownerId == ownerId;
}

int Test(int a, int b)
{
	cout << "Test" << endl;
	return a + b;
}


int main()
{
	int a = 10;

	typedef int DATA;

	// 1) ������		*
	// 2) ���� �̸�		pointer
	// 3) ������Ÿ��	int
	DATA* pointer = &a;

	// �Լ�
	typedef int(FUNC_TYPE)(int, int);
	FUNC_TYPE* fn;

	// �Լ� ������
	fn = Add;

	// �Լ��� �̸��� �Լ��� ���� �ּ� (�迭�� ����)
	int result = fn(1, 2); // �⺻����
	cout << result << endl;

	// �Լ� �����ʹ� *(���� ������) �ٿ��� �Լ� �ּ�
	int result2 = (*fn)(1, 2); 
	cout << result << endl;

	Item items[10] = {};
	items[3]._rarity = 2; // RARE
	Item* rareItem = FindItem(items, 10, IsRareItem);

	int (*fInt)(int, int);
	fInt = &Test; // & ���� ���� (C��� ȣȯ�� ����)

	fInt(1, 2);

	(*fInt)(1, 2);

	FUNC type; 
	type(1, 2);

	FUNC* fnc;
	fnc = &Test;

	return 0;
}