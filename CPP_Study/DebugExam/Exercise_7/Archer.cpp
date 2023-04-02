#include "Archer.h"
#include "Pet.h"
#include <iostream>
using std::cout;
using std::endl;

Archer::Archer()
{
	// �̷� ���� ���� ä�� ����~
	_pet = new Pet();
}

Archer::Archer(int hp) : Player(hp)
{
	// �̷� ���� ���� ä�� ����~
	_pet = new Pet();
}

Archer::~Archer()
{
	cout << "~Archer()" << endl;

	// ��ſ��� �� �� :(
	if (_pet != nullptr)
		delete _pet;
}

