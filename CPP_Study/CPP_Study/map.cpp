#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>

// ������ ���� : map
class Player
{
public:
	Player() : _playerId(0) {}
	Player(int playerId) : _playerId(playerId) { }

public:
	int _playerId;

};

int main()
{
	// map : ���� ���� Ʈ�� (AVL)
	// - ��� ���
	srand(static_cast<unsigned int>(time(nullptr)));
	
	class Node
	{
	public:
		Node* _left;
		Node* _right;

		// DATA
		int		_key;
		Player* _value;
	};

	// (Key, Value)
	map<int, int> m;


	pair<map<int, int>::iterator, bool> ok1;
	pair<map<int, int>::iterator, bool> ok2;
	ok1 = m.insert(make_pair(1, 100));
	ok2 = m.insert(make_pair(1, 200));

	// 1000
	for (int i = 0; i < 1000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// 500
	for (int i = 0; i < 500; i++)
	{
		int randomValue = rand() % 50000;

		// Erase By Key
		m.erase(randomValue);
	}

	/*
	 Q) ID = 1���� Player ã�� �ʹ�!
	 A) �ſ� ������ ã�� �� ����.
	 */
	map<int, int>::iterator findIt = m.find(100);

	// ã�� �������� m.end() iterator�� ����
	if (findIt != m.end())
	{
		cout << "ã��" << endl;
	}
	else
	{
		cout << "��ã��" << endl;
	}

	// map ��ȸ
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		pair<const int, int>& p = (*it);
		/*
		*	������.
			int key = it.first;
			int value = it.second;
		*/
		int key = it->first;
		int value = it->second;

		cout << key << " " << value << endl;
	}

	// map �������� ����
	// ������ �߰�, ������ ����
	m[5] = 500;

	m.clear();
	// [] ������ ����Ҷ� ����
	// ������ ���� �ʴ��� (Key, Value) ���°� �߰���.
	for (int i = 0; i < 10; ++i)
	{
		cout << m[i] << endl;
	}


	return 0;
}