#include <iostream>
using namespace std;

// ������ ���� : ���������� �� ����

// ���� ����
// ����) �ʱ�ȭ ����, const �� .rodata, .data, .bss
// �޸��� ������ ������ ��.
void increaseHp(int hp)
{
	hp = hp + 1;
}

// [�Ű�����][RET][��������]
int main()
{
	int hp = 1;

	// 1
	cout << "Increase ȣ�� �� : " << hp << endl;
	increaseHp(hp);
	// 1
	cout << "Increase ȣ�� �� : " << hp << endl;

}