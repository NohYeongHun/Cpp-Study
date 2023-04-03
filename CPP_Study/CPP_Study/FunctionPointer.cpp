#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 포인터

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
	int _itemId; // 아이템을 구분하기 위한 ID
	int _rarity; // 희귀도
	int _ownerId; // 소지자 ID
};

/*
	(함수)동작을 인자로 넣어줄 수 있다!
	bool(*selector)(item* item)
	== typedef bool (ITEM_SELECTOR)(Item* item);
*/
Item* FindItem(Item items[], int itemCount, bool(*selector)(Item* item))
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		// TODO 동작
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

	// 1) 포인터		*
	// 2) 변수 이름		pointer
	// 3) 데이터타입	int
	DATA* pointer = &a;

	// 함수
	typedef int(FUNC_TYPE)(int, int);
	FUNC_TYPE* fn;

	// 함수 포인터
	fn = Add;

	// 함수의 이름은 함수의 시작 주소 (배열과 유사)
	int result = fn(1, 2); // 기본문법
	cout << result << endl;

	// 함수 포인터는 *(접근 연산자) 붙여도 함수 주소
	int result2 = (*fn)(1, 2); 
	cout << result << endl;

	Item items[10] = {};
	items[3]._rarity = 2; // RARE
	Item* rareItem = FindItem(items, 10, IsRareItem);

	int (*fInt)(int, int);
	fInt = &Test; // & 생략 가능 (C언어 호환성 때문)

	fInt(1, 2);

	(*fInt)(1, 2);

	FUNC type; 
	type(1, 2);

	FUNC* fnc;
	fnc = &Test;

	return 0;
}