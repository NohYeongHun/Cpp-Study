#include <iostream>
using namespace std;

// ������ ���� : �Լ� ������

// �����ε� (�ߺ� ���� : �Լ� �̸��� ����)
// - �Ű� ���� ������ �ٸ��ų�
// - �Ű����� Ÿ���� �ٸ��ų� (������ �ٸ��� ����)
int Add(int a, int b)
{
	int result = a + b;
	return result;
}

float Add(float a, float b)
{
	float result = a + b;
	return result;
}

// �⺻ ���ڰ�
// �⺻ ���ڰ� ������ ���� ����� ���� �ξ����.
void SetPlayerInfo(int hp, int mp, int attack, int guildId = 0, int castleId = 0)
{

}

// ���� �����÷ο�
int Factorial(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	return n * Factorial(n - 1);
}

int main()
{
	/*float result = Add(1.5f, 2.1f);
	cout << result << endl;

	SetPlayerInfo(100, 40, 10, 0, 1);*/

	// 5! =  5 * 4 * 3 * 2 * 1
	// 4! =  4 * 3 * 2 * 1
	// n! = n * ( n - 1)!
	int result = Factorial(100000);
	cout << result << endl;
	
}