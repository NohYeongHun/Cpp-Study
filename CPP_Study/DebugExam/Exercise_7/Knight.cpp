#include "Knight.h"
#include <iostream>
using std::cout;
using std::endl;

Knight::Knight() 
{

}

Knight::Knight(int hp) : Player(hp)
{

}

Knight::~Knight()
{
	cout << "~Knight()" << endl;
}

