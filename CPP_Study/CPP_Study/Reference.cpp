#include <iostream>
using namespace std;

// ������ ���� : ������ vs ����

struct StatInfo
{
	int hp; // +0
	int attack; // +4
	int defence; // +8
};

// [�Ű�����][RET][��������(info)] [�Ű�����(&info)][RET][��������]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// Ư�� ������ �����ϴ� ���͸� ã�� �Լ�
StatInfo* FindMonster()
{
	// TODO : Heap �������� ������ ã�ƺ�
	// ã�Ҵ�!
	// return monster-;
	return nullptr;
}


StatInfo globalInfo;
// [�Ű�����][RET][��������(info)][�Ű�����(&info)][RET][��������]
void PrintInfoByPtr(StatInfo* info)
{
	if (info == nullptr)
	{
		return;
	}

	cout << "-------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "-------------------" << endl;

	// �� �ڿ� ���δٸ�?
	// StatInfo* const info
	// info��� �ٱ����� ���빰(�ּ�)�� �ٲ� �� ����
	// info��� �ּҰ��� ���� �ٱ��� -> �� �ּҰ��� �����̴�.

	// �� ������ ���δٸ�?
	// const StatInfo* info
	// info�� '����Ű�� �ִ�' �ٱ����� ���빰�� �ٲ� �� ����
	// '����' �ٱ����� ���빰�� �ٲ� �� ����

	// �Ѵ� ���������?
	// const StatInfo* const info
	// info[ �ּҰ� ]  === > �ּҰ� [ ������ ]
	//info = &globalinfo;
	//info->hp = 10000;
}


// 3) ���� ���� ���
void PrintInfoByRef(StatInfo& info)
{
	cout << "-------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "-------------------" << endl;

	// ������ �Դ�.
	// info.hp = 10000; => �Ұ���.
}

// �ٲ���� �ִٴ� ��Ʈ ����
#define OUT

void ChangeInfo(OUT StatInfo& info)
{

}


// StatInfo ����ü�� 1000����Ʈ¥�� ���� ����ü���?
// - (�� ����) StatInfo�� �ѱ�� 1000����Ʈ�� ����Ǵ�
// - (�ּ� ����) StatInfo*�� 8����Ʈ
// - (���� ����) StatInfo&�� 8����Ʈ

int main()
{
	StatInfo info;

	CreateMonster(&info);
	// ������ vs ���� ������ ���
	// ���� : �Ȱ���!
	// ���Ǽ� : ���� ��. `.` ������

	// 1) ���Ǽ� ����
	// ���Ǽ��� ���ٴ°� �� �������� �ƴϴ�.
	// �����ʹ� �ּҸ� �ѱ�� Ȯ���ϰ� ������ �ѱ�ٴ� ��Ʈ�� �� �� ����.
	// ������ �ڿ������� �𸣰� ����ĥ ���� ����!
	// ex) ������� ��ģ�ٸ�?
	// const�� ����ؼ� �̷� ������� ��ġ�� �κ� ���� ����

	// ����� �����͵� const�� ��� ����
	// * �������� �տ� ���̴���, �ڿ� ���̴��Ŀ� ���� �ǹ̰� �޶���.

	// 2) �ʱ�ȭ ����
	// ���� Ÿ���� �ٱ����� 2��° �̸�(��Ī?)
	// -> �����ϴ� ����� ������ �ȵ�
	// �ݸ� �����ʹ� �׳� � �ּҶ�� �ǹ�
	// -> ����� �������� ���� ���� ����
	// �����Ϳ��� '����'�� �ǹ̷�? == nullptr
	// ����Ÿ���� �̷� nullptr�� ����.

	StatInfo* pointer = nullptr;
	pointer = &info;
	PrintInfoByPtr(pointer);

	StatInfo& reference = info;
	PrintInfoByRef(reference);

	// �׷��� �����?
	// ��� Team By Team... ������ ���� ����
	// ex) ���ۿ��� ���� ���¼ҽ��� ���� ���� ������ ������ ���
	// ex) �𸮾� �������� reference�� �ֿ�

	// �������� ��ȣ ��Ÿ��
	// - ���� ��쵵 ����ؾ� �Ѵٸ� pointer (null üũ �ʼ�)
	// - �ٲ��� �ʰ� �д� �뵵(readonly)�� ����ϸ� const ref&
	// - �� �� �Ϲ������� ref (��������� ȣ���� �� OUT�� ���δ�)
	// -- ��, �ٸ� ����� pointer�� ����� ���Ҵٸ� ������ ��� ������� ����.
	ChangeInfo(OUT info);

	// Bonus) �����ͷ� ����ϴ��� ������ �ѱ�� ��
	// pointer [ �ּ�(&info) ]  ref, info [ ������ ]
	StatInfo& ref = *pointer;
	PrintInfoByRef(*pointer);
	// Bonus) ������ ����ϴ��� �����ͷ� �ѱ�� ��
	// pointer [ �ּ�(&info) ]  reference, info [ ������ ]
	StatInfo* ptr = &reference;
	PrintInfoByPtr(&reference);

	return 0;
}