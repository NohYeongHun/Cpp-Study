#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

// 오늘의 주제 : 람다(lambda)

// 함수 객체를 빠르게 만드는 문법

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	COnsumable
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item() {}
	Item(int itemId, Rarity rarity, ItemType type)
		: _itemId(itemId), _rarity(rarity), _type(type)
	{

	}

public:
	int _itemId = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;

};

int main()
{
	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	// 람다 = 함수 객체를 손쉽게 만드는 문법
	// 람다 자체로 C++11에 '새로운' 기능이 들어간 것은 아님.
	{

		// 함수 객체 사용 예시
		struct isUniqueItem
		{
			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}
		};

		auto findIt = std::find_if(v.begin(), v.end(), isUniqueItem());
		if (findIt != v.end())
			cout << "아이템 ID: " << findIt->_itemId << endl;

		// 클로저 (closure) = 람다에 의해 만들어진 실행시점 객체
		// 람다의 시작 [](매개변수) { 구현부 }
		auto isUniqueLambda = std::find_if(
			v.begin(), v.end(), [](Item& item) 
		{ 
			return item._rarity == Rarity::Unique; 
		}); // 람다 표현식(lambda expression)
	}

	{
		struct FindItemByItemId
		{
			FindItemByItemId(int itemId) : _itemId(itemId)
			{

			}

			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}

			int _itemId = 4;
		};

		int itemId = 4;

		auto findIt = std::find_if(v.begin(), v.end(), FindItemByItemId(itemId));

		if (findIt != v.end())
			cout << "아이템 ID : " << findIt->_itemId << endl;

		// 람다객체 만들기
		// [ ] 캡처(capture) : 함수 객체 내부에 변수 저장
		// 사진을 찍듯.. 일종의 스냅샷을 찍음.
		// 기본 캡처 모드 : 값(복사) 방식(=) 참조 방식(&)
		auto findByItemIdLambda = [&](Item& item) 
		{ 
			// 밖의 int itemId 변수를 가지고 온다.
			return item._itemId == itemId;
		};
		
		auto findIt2 = std::find_if(v.begin(), v.end(), findByItemIdLambda);
	}

	{
		struct FindItem
		{
			FindItem(int itemId, Rarity rarity, ItemType type) 
				: _itemId(itemId), _rarity(rarity), _type(type)
			{

			}

			bool operator()(Item& item)
			{
				return item._itemId == _itemId  == _itemId && item._rarity == _rarity && item._type == _type;
			}

			int _itemId;
			Rarity _rarity;
			ItemType _type;
		};

		int itemId = 4;

		auto findIt = std::find_if(v.begin(), v.end(), FindItem(itemId, Rarity::Rare, ItemType::Weapon));

		if (findIt != v.end())
			cout << "아이템 ID : " << findIt->_itemId << endl;

		int _itemId = 4;
		Rarity rarity = Rarity::Unique;
		ItemType type = ItemType::Weapon;

		auto findByItem = [&itemId, &rarity, type](Item& item)
		{
			return item._itemId == itemId && item._rarity == rarity && item._type == type;
		};

		auto findIt2 = std::find_if(v.begin(), v.end(), findByItem);
		if (findIt2 != v.end())
			cout << "아이템 ID : " << findIt2->_itemId << endl;

	}


	{
		class Knight
		{
		public:
			auto ResetHpJob()
			{
				auto f = [this]()
				{
					// 0x0126ED80  dddddddd  ???? => 메모리가 초기화된 상태
					// 0x0126ED80  000000c8  ?... => 메모리 오염
					this->_hp = 200;
				};

				return f;
			}

		public:
			int _hp = 100;
		};


		Knight* k = new Knight();
		auto job = k->ResetHpJob();

		// 더이상 기사의 포인터는 존재하지않는다.
		delete k;
		// 기사의 포인터는 더 이상 유효하지 않는데 해당 공간에 값을 넣는다
		// 메모리 오염이 일어난다.
		job();

	}


	return 0;
}