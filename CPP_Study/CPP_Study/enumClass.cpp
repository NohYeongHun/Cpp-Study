#include <iostream>
using namespace std;
#include <set>
#include <algorithm>

// ������ ���� : enum class

// unscoped enum (��������)
enum PlayerType : char
{
	// 5, 6, 7
	// default Type�� int��.
	// type�� ������ ���� ����.
	Knight = 5,
	Archer,
	Mage,
};

/*
�Ұ���! Knight�� ��ģ��.
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

// ����!
enum class ObjectType2 : short
{
	Player,
	Monster,
	Projecttile
};


int main()
{

	// enum class (scoped enum)
	// 1) �̸����� ���� (scoped)
	// - ���� enum�� ������?
	// - unscoped enum (������ ���� => ��ü�� ����ȴ�)
	


	PlayerType t;
	cout << sizeof(t) << endl;

	// 2) �Ϲ��� ��ȯ ����
	// ?? enum ���� double�� �Ϲ��� ��ȯ�� ��.
	double value = Knight;

	// enum class�� �Ϲ��� ��ȯ�� ������
	// �Ұ���
	// double value2 = ObjectType::Player;
	// ��ȯ�ϰ� ������ ����� ��ȯ
	// ��� ��ȯ ���� 1
	double value3 = static_cast<double>(ObjectType::Player);

	// ��� ��ȯ ���� 2
	int choice;
	cin >> choice;
	if (choice == static_cast<int>(ObjectType::Monster))
	{

	}
	// ��ú�ȯ ���� 3
	unsigned int bitFlag;
	bitFlag = (1 << static_cast<int>(ObjectType::Player));


	return 0;
}