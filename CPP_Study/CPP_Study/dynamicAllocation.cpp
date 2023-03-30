#include <iostream>
using namespace std;


class Monster
{
public:
	Monster()
	{
		cout << "Monster()" << endl;
	}

	~Monster()
	{
		cout << "~Monster()" << endl;
	}
public:
	int _hp;
	int _x;
	int _y;
};

int main()
{
	void* pointer = malloc(sizeof(Monster));
	Monster* m1 = (Monster*)pointer;

	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	free(pointer);

	Monster* m2 = new Monster;
	m2->_hp = 200;
	m2->_x = 2;
	m2->_y = 3;
	delete m2;

	Monster* m3 = new Monster[5];
	m3->_hp = 200;
	m3->_x = 2;
	m3->_y = 3;
	

	Monster* m4 = (m3 + 1);
	m4->_hp = 200;
	m4->_x = 2;
	m4->_y = 3;
	delete[] m3;


	return 0;
}