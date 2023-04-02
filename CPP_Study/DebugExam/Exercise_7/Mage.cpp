#include "Mage.h"
#include <iostream>
using std::cout;
using std::endl;

Mage::Mage()
{

}

Mage::Mage(int hp) : Player(hp)
{

}

Mage::~Mage()
{
	cout << "~Mage()" << endl;
}

