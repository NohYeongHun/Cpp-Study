#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

// ������ ���� : ����(lambda)

// �Լ� ��ü�� ������ ����� ����

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

	// ���� = �Լ� ��ü�� �ս��� ����� ����
	// ���� ��ü�� C++11�� '���ο�' ����� �� ���� �ƴ�.
	{

		// �Լ� ��ü ��� ����
		struct isUniqueItem
		{
			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}
		};

		auto findIt = std::find_if(v.begin(), v.end(), isUniqueItem());
		if (findIt != v.end())
			cout << "������ ID: " << findIt->_itemId << endl;

		// Ŭ���� (closure) = ���ٿ� ���� ������� ������� ��ü
		// ������ ���� [](�Ű�����) { ������ }
		auto isUniqueLambda = std::find_if(
			v.begin(), v.end(), [](Item& item) 
		{ 
			return item._rarity == Rarity::Unique; 
		}); // ���� ǥ����(lambda expression)
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
			cout << "������ ID : " << findIt->_itemId << endl;

		// ���ٰ�ü �����
		// [ ] ĸó(capture) : �Լ� ��ü ���ο� ���� ����
		// ������ ���.. ������ �������� ����.
		// �⺻ ĸó ��� : ��(����) ���(=) ���� ���(&)
		auto findByItemIdLambda = [&](Item& item) 
		{ 
			// ���� int itemId ������ ������ �´�.
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
			cout << "������ ID : " << findIt->_itemId << endl;

		int _itemId = 4;
		Rarity rarity = Rarity::Unique;
		ItemType type = ItemType::Weapon;

		auto findByItem = [&itemId, &rarity, type](Item& item)
		{
			return item._itemId == itemId && item._rarity == rarity && item._type == type;
		};

		auto findIt2 = std::find_if(v.begin(), v.end(), findByItem);
		if (findIt2 != v.end())
			cout << "������ ID : " << findIt2->_itemId << endl;

	}


	{
		class Knight
		{
		public:
			auto ResetHpJob()
			{
				auto f = [this]()
				{
					// 0x0126ED80  dddddddd  ???? => �޸𸮰� �ʱ�ȭ�� ����
					// 0x0126ED80  000000c8  ?... => �޸� ����
					this->_hp = 200;
				};

				return f;
			}

		public:
			int _hp = 100;
		};


		Knight* k = new Knight();
		auto job = k->ResetHpJob();

		// ���̻� ����� �����ʹ� ���������ʴ´�.
		delete k;
		// ����� �����ʹ� �� �̻� ��ȿ���� �ʴµ� �ش� ������ ���� �ִ´�
		// �޸� ������ �Ͼ��.
		job();

	}


	return 0;
}