#include <iostream>
using namespace std;

// 오늘의 주제 : 콜백 (Callback)

class Item
{
public:

public:
	int _itemId = 0;
	int _rarity = 0;
	int _ownerId = 0;

};

// 함수 객체
class FindByOwnerId
{
public:
	// 연산자 오버로딩.
	bool operator()(const Item* item)
	{
		return (item->_ownerId == _ownerId);
	}

public:
	int _ownerId;
};

// 함수 객체
class FindByRarity
{
public:
	// 연산자 오버로딩.
	bool operator()(const Item* item)
	{
		return (item->_rarity >= _rarity);
	}

public:
	int _rarity;
};



template<typename T>
Item* FindItem(Item items[], int itemCount, T selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];

		// TODO : 조건 체크
		/*
		* selector의 타입에 따라 다른 조건값을 가져올 수 있음!.
		* _rairity or _onwerId
		*/ 

		if (selector(item))
			return item;
	}

	return nullptr;
}

int main()
{
	// 함수 포인터 + 함수 객체 + 템플릿
	// 콜백 (Callback) : 다시 호출하다? 역으로 호출하다
	
	// 게임을 만들 대 이런 콜백의 개념이 자주 등장한다.
	// ex) MoveTask 실습 등

	// 어떤 상황이 일어나면 -> 이 기능을 호출해줘
	// ex) UI 스킬 버튼을 누르면 -> 스킬을 쓰는 함수를 호출

	Item items[10];
	items[3]._ownerId = 100;
	items[8]._rarity = 2;

	FindByOwnerId functor1;
	functor1._ownerId = 100;

	FindByRarity functor2;
	functor2._rarity = 1;

	Item* item1 = FindItem(items, 10, functor1);
	Item* item2 = FindItem(items, 10, functor2);

	cout << "Item1()->ownerId = " << item1->_ownerId << endl;
	cout << "Item2()->rarity = " << item2->_rarity << endl;

	return 0;
}