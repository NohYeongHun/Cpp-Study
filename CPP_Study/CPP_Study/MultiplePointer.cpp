#include <iostream>
using namespace std;


// ������ ���� : ���� ������
void SetNumber(int* a);
void SetMessage(const char* a);
void SetMessage(const char** a);
void SetMessage2(const char*& a);

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}
void SetMessage(const char** a)
{
	*a = "Bye";
}
void SetMessage2(const char*& a)
{
	a = "Wow";
}

int main()
{
	int a = 0;
	SetNumber(&a);

	// .rdata Hello�ּ�[H][e][l][l][o][\0]
	// msg [ Hello �ּ� ] << 8����Ʈ

	// msg[ �ּ� ] << 8����Ʈ
	const char* msg = "Hello";

	// [�Ű�����][RET][��������(msg(Hello�ּ�))] [�Ű�����(a(Hello �ּ�))][RET][��������]
	SetMessage(msg);
	//cout << msg << endl; // Hello? Bye?

	// �ּ�2 [ ] << 1����Ʈ
	// �ּ�1 [ �ּ� 2 ] << 8����Ʈ
	// pp[ �ּ�1 ] << 8����Ʈ
	const char** pp = &msg; 
	// => pp�� ���빰�� ������ const char* Ÿ���̾�� ��.
	// pp [ &msg ] << 8����Ʈ
	// msg [ Hello �ּ� ] << 8����Ʈ

	// [�Ű�����][RET][��������(msg( Hello �ּ� ))] [�Ű�����(a(&msg msg�� �ּ�))][RET][��������]
	SetMessage(&msg);
	cout << msg << endl;
	// ���� �����.

	SetMessage2(msg);
	cout << msg << endl;

	return 0;
}