#include "P.h"
#include "M.h"

void P::KillMonster()
{
	/*
		������ Ǯ��Ẹ��!
		(*_target2)._hp = 0;

		[ �ּ� ] -> [ �ּ� ���~~ _hp ]
		_hp�� ���� �ּ��� ��� �ִ����� ��� Ȯ���ϴ°�?
		M�� ���赵�� �����ؾ��Ѵ�!.
		[ �ּ� ] -> [ [monsterId] [hp] [defence] ]
		
	*/
	// _target2->_hp = 0;

	/*
		KillMe()�� ȣ���ϱ����ؼ���?
		� ���·� ����� �ִ��� �˾ƾ� ȣ�� ����!
		- � ��ȯ�����ΰ�?
		- � ���ڰ��� �ʿ��Ѱ�?
		���� ���·� �����ϴ��������� ���� ��� ����! => �����ؼ� ������ ���̹Ƿ�
	*/
	_target2->KillMe();
}