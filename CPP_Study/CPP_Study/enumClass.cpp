#include <iostream>
using namespace std;
#include <set>
#include <algorithm>

// 오늘의 주제 : enum class

// unscoped enum (범위없는)
enum PlayerType : char
{
	// 5, 6, 7
	// default Type은 int임.
	// type을 지정할 수도 있음.
	Knight = 5,
	Archer,
	Mage,
};

/*
불가능! Knight가 겹친다.
enum MonsterType
{
	Knight,
	Orc,
};
*/


// enum class
// Modern C++
enum class ObjectType : short
{
	Player,
	Monster,
	Projecttile
};

// 가능!
enum class ObjectType2 : short
{
	Player,
	Monster,
	Projecttile
};


int main()
{

	// enum class (scoped enum)
	// 1) 이름공간 관리 (scoped)
	// - 기존 enum의 문제점?
	// - unscoped enum (범위가 없다 => 전체에 적용된다)
	


	PlayerType t;
	cout << sizeof(t) << endl;

	// 2) 암묵적 변환 금지
	// ?? enum 값이 double로 암묵적 변환이 됨.
	double value = Knight;

	// enum class는 암묵적 변환이 금지됨
	// 불가능
	// double value2 = ObjectType::Player;
	// 변환하고 싶으면 명시적 변환
	// 명시 변환 예시 1
	double value3 = static_cast<double>(ObjectType::Player);

	// 명시 변환 예시 2
	int choice;
	cin >> choice;
	if (choice == static_cast<int>(ObjectType::Monster))
	{

	}
	// 명시변환 예시 3
	unsigned int bitFlag;
	bitFlag = (1 << static_cast<int>(ObjectType::Player));


	return 0;
}