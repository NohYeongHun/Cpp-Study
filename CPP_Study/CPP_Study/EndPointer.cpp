#include <iostream>
using namespace std;

// ������ ���� : ������ ������

// 1) ������ vs �迭 2ź
// 2) ���ǻ��� (��������?)

int* TestPointer()
{
	int a = 1;
	return &a;
}

void TestWrong(int* ptr)
{
	int a[100] = {};
	a[99] = 0xAAAAAAAA;
	*ptr = 0x12341234;
 }

int main()
{
	// �ּҸ� ��� �ٱ���
	// ������ ��~ �ָ� ��򰡿� ����
	// P�� ���� �� ������ �����ϴ� ��Ż
	int* p;

	// ��¥���! ���� ������
	// ����ó�� �������� ���� (��û ���� �Ŵ���)
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	// �׷��� ����� ���� ������� [�迭 = ������]�� ����.
	// - [�迭�� �̸�]�� �迭�� ���� �ּҰ��� ����Ű�� TYPE* �����ͷ� ��ȯ ����.
	p = arr;

	// - [TYPE�� 1���� �迭]�� [TYPE*�� ������]�� ������ ȣȯ�� �ȴ�.
	cout << p[0] << endl;
	cout << arr[0] << endl;
	cout << p[5] << endl;
	cout << arr[5 ] << endl;

	cout << *p << endl;
	cout << *arr << endl;
	cout << *(p + 3) << endl;
	cout << *(arr + 3) << endl;

	// ������ �����帰��.. (2���� �迭 vs ���� ������)
	// [1][2][3][4]
	int arr2[2][2] = { {1, 2}, {3, 4} };

	// pp [ �ּ�1 ] => pp�� 2�� �������̹Ƿ� �ּ�1�� �ּҸ� ��� �ִٰ� ������.
	// �ּ�1 [ �ּ�2 (�� 1) ] => �ּ� 1�� �̵��غ��� �Ǵٸ� �ּҰ��� ������ �ִ� ���� �ƴ� arr[0][1] ���� 1�� ����.
	// �ּ�2[ ] << 4����Ʈ
	// int** pp = arr2; 
	
	// TYPE name[����]
	
	// �ּ�1 => [1][2] (��)
	// pp [ �ּ�1 ]
	int(*p2)[2] = arr2;
	

	cout << (*p2)[0] << endl;
	cout << (*(p2 + 1))[0] << endl;
	cout << p2[0][0] << endl;
	cout << p2[1][0] << endl;
	
	// [�Ű�����][RET][��������] / [�Ű�����][RET][��������]
	int* pointer = TestPointer();

	TestWrong(pointer);

	return 0;

}