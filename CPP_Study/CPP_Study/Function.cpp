#include <iostream>
using namespace std;

// ������ ���� : �Լ�(���ν���, �޼ҵ�, ��ƾ)

/*
* 
input���� ������ �ް�, output���� ������ ������ �����ش�.

��ȯŸ�� �Լ��̸�(����Ÿ�� �Ű�����)
{
	�Լ� ����

	return ---;
}
*/

// Hello World�� �ֿܼ� ����ϴ� �Լ��� ������!.
// input : ���� / output : ����
// Ÿ�� : int float double char-- void

void PrintHelloWorld()
{
	cout << "Hello World" << endl;

	return;
}

// ������ �Է�(�Լ�) �޾Ƽ�, �ֿܼ� ����ϴ� �Լ��� ������
// input : int // output : ����
void PrintNumber(int number)
{
	cout << "�Ѱ��ֽ� ���ڴ� " << number << endl;
}

// 2�� ���ϰ� ������� �޴� �Լ��� ������
// input : int / output : int
int MultiplyBy2(int number) 
{	
	return number * 2;;
}

// �� ���ڸ� ���ؼ� ������� �޴� �Լ��� ������
// input : int, int  / output : int

int MultiplyBy(int a, int b)
{
	return a * b;
}

int main()
{
	PrintHelloWorld();
	PrintNumber(2);
	int result = MultiplyBy2(4);
	PrintNumber(result);
	result = MultiplyBy(3, 5);
	PrintNumber(result);
	
}