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
	int c = a * b;
	return c;
}

// Visual Studio �����
// F5 (�극��ũ ����Ʈ ���� ����)
// F10 (�Լ� ������ ����)
// F11 (�� �� �� ����)
int main()
{
	int a = 3;
	int b = 5;
	int result = MultiplyBy(a, b);
	PrintNumber(result);
	
}