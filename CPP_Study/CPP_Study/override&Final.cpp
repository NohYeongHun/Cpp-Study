#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

// 오늘의 주제 : override, final

class Creature
{
	virtual void Attack()
	{

	}
};

class Player : public Creature
{

public:

	// 가상함수 : 실제 원본 객체의 함수를 호출한다!.
	virtual void Attack() override
	{
		cout << "Player!" << endl;
	}

};

class Knight : public Player
{
public:

	// 재정의(override)
	

	// const만 붙였을 뿐이지만? => 다른 함수이다.
	// virtual void Attack() const

	// 명시적으로 override된 함수라는 것을 알려주면 좋겠다!.

	/*
		자식 클래스만 확인해서는 virtual이 부모 클래스에 정의되었는지 확인 불가능.
		override를 붙이면!
		Player에는 Attack() 함수가 정의되어 있다는 것을 알 수 있다.

		final은? => 자식 클래스에는 해당 함수의 override를 막는다.
	*/
	virtual void Attack() override final
	{
		cout << "Knight!" << endl;
	}
	

	// 오버로딩(overloading) : 함수 이름의 재사용
	/*
	* void Attack(int a)
	{
		cout << "Attack! (int a)" << endl;
	}
	*/

private:
	int _stamina = 100;
	
};


class Test : public Knight
{
	virtual void Attack() override;
};

int main()
{
	// 불가능! => 부모 Creature에는 virtual이 선언되어 있지 않음
	// Creature* creature = new Knight()
	Player* player = new Knight();

	player->Attack();

	delete player;
	return 0;
}