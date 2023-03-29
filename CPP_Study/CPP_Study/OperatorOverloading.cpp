#include <iostream>
using namespace std;

// ������ ���� : ������ �����ε�(Opeartor Overloading)

// ������ vs �Լ�
// - �����ڴ� �ǿ������� ����/Ÿ���� �����Ǿ� ����

// ������ �����ε�
// �ϴ� [������ �Լ�]�� �����ؾ� ��
// �Լ��� ����Լ� vs �����Լ��� �����ϴ� ��ó��, ������ �Լ��� �ΰ��� ������� ���� �� ���� 

// - ��� ������ �Լ� version
// -- a op b ���¿��� ���� �������� �����
// -- �Ѱ�) a�� Ŭ������ �ƴϸ� ��� ����.

// ���� ���� ������
// - ���� �����ڰ� ���� �迡 [���� ���� ������]�� ���� �˾ƺ���
// �� �� �򰥸���. [���� ������] [���� ������] [���� ���� ������]
// - ���� ���� ������ - ���� ������ ��, �ڱ� �ڽ��� ���� Ÿ���� ���ڷ� �޴� ��.

class Position
{

public:
		
	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;

		return pos;
	}

	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;
		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}
	
	
	Position& operator=(int arg)
	{
		_x = arg;
		_y = arg;

		// Position* this = �� �ڽ��� �ּ�;
		return *this;
	}

	// [���� ������] [���� ���� ������] �� Ư�� ��츦 �޴� ����
	// �� �״�� ��ü�� '����'�Ǳ� ���ϴ� Ư¡ ����
	// arg�� ����Ű�� ���빰�� ������ �� ����.
	Position& operator=(const Position& arg)
	{
		_x = arg._x;
		_y = arg._y;

		// Position* this = �� �ڽ��� �ּ�;
		return *this;
	}
	
	Position& operator++()
	{
		_x++;
		_y++;
		return *this;
	}

	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;
		return ret;
	}

public:
	int _x;
	int _y;

};

Position operator+(int arg, const Position& b)
{
	Position ret;
	ret._x = b._x + arg;
	ret._y = b._y + arg;

	return ret;
}

int& test(const int& x)
{
	int ret = 1 + x;

	return ret;
}

int testLocalVariable()
{
	int x = 10;
	return x;
}

int main()
{
	int a = 1;
	int b = 2;

	int c = a + 3.0f;

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos._x = 0;
	pos._y = 0;

	Position pos3 = pos + pos2; 
	Position pos4 = pos3 + 1;
	
	Position pos5;
	// 1. (pos5 = 5) return &pos5
	// 2. pos3 = &pos5;

	pos3 = (pos5 = 5);
	// (const Pos&)�� ~ (Pos) ����
	//
	pos5 = pos3++;

	pos3++;
	++(++pos3);

	cout << test(testLocalVariable());
	


	return 0;
}														