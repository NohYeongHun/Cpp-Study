#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>

// 오늘의 주제 : map
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
	// map : 균형 이진 트리 (AVL)
	// - 노드 기반
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
	 Q) ID = 1만인 Player 찾고 싶다!
	 A) 매우 빠르게 찾을 수 있음.
	 */
	map<int, int>::iterator findIt = m.find(100);

	// 찾지 못했으면 m.end() iterator를 가짐
	if (findIt != m.end())
	{
		cout << "찾음" << endl;
	}
	else
	{
		cout << "못찾음" << endl;
	}

	// map 순회
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		pair<const int, int>& p = (*it);
		/*
		*	동일함.
			int key = it.first;
			int value = it.second;
		*/
		int key = it->first;
		int value = it->second;

		cout << key << " " << value << endl;
	}

	// map 데이터의 수정
	// 없으면 추가, 있으면 수정
	m[5] = 500;

	m.clear();
	// [] 연산자 사용할때 주의
	// 대입을 하지 않더라도 (Key, Value) 형태가 추가됨.
	for (int i = 0; i < 10; ++i)
	{
		cout << m[i] << endl;
	}


	return 0;
}