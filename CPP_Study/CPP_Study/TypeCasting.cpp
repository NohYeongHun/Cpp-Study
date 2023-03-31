#include <iostream>
using namespace std;

// ������ ���� : Ÿ�� ��ȯ

// malloc -> void*�� ��ȯ�ϰ�, �̸� �츮�� (Ÿ�� ��ȯ)�� ���� ���

class Knight
{
public:
	int _hp = 10;
};

class Dog
{
public:
	Dog();

	// Ÿ�� ��ȯ ������
	Dog(const Knight& knight)
	{
		_age = knight._hp;
	}

	// Ÿ�� ��ȯ ������
	operator Knight()
	{
		return (Knight)(*this);
	}

public:
	int _age = 1;
	int _cuteness = 2;
};

class BullDog : public Dog
{
public:
	bool _french; // ����ġ �ҵ�
};

int main()
{
	// -------------------- Ÿ�� ��ȯ ���� (��Ʈ�� �籸�� ����) ---------------

	// [1] �� Ÿ�� ��ȯ
	// Ư¡) �ǹ̸� �����ϱ� ���ؼ�, ���� ��ü�� �ٸ� ��Ʈ�� �籸��

	{
		int a = 123456789; // 2�� ����
		float b = (float)a; //�ε� �Ҽ���(���� + ��ȿ����)
		cout << b << endl;
	}
	
	// [2] ���� Ÿ�� ��ȯ
	// Ư¡) ��Ʈ���� �籸������ �ʰ�, `����`�� �ٲٴ� ��
	{
		int a = 123456789; // 2�� ����
		float b = (float&)a; //�ε� �Ҽ���(���� + ��ȿ����)
		cout << b << endl;
	}


	// ������ �з�

	// ������ ��ȯ
	{
		int a = 123456789;
		__int64 b = a;
		cout << b << endl;
	}

	// �Ҿ����� ��ȯ
	// Ư¡) �ǹ̰� �׻� 100% ��ġ�Ѵٰ� �������� ���ϴ� ���
	{
		int a = 123456789;
		float b = a;
		short c = a;
		cout << b << endl;
		cout << c << endl;
	}

	// -------------------- ���α׷��� �ǵ��� ���� �з� ----------------

	// [1] �Ͻ��� ��ȯ
	
	{
		int a = 123456789;
		float b = a; //�Ͻ�������
		cout << b << endl;
	}

	// [2] ����� ��ȯ
	{
		int a = 123456789;
		int* b = (int*)a; // ���������
		cout << b << endl;
	}

	// ------------------- �ƹ��� ���� ���谡 ���� Ŭ���� ������ ��ȯ -----------------

	// [1] �������� Ŭ���� ������ '�� Ÿ��' ��ȯ
	// Ư¡) �Ϲ������� �ȵ�
	{
		Knight knight;
		Dog dog = (Dog)knight;

		//Knight knight2 = dog;
	}

	// [2] �������� Ŭ���� ������ ���� Ÿ�� ��ȯ
	{
		Knight knight;
		Dog& dog = (Dog&)knight;
		dog._cuteness = 12;

	}

	// ----------------- ��� ���迡 �ִ� Ŭ���� ������ ��ȯ ----------------

	// [1] ��� ���� Ŭ������ �� Ÿ�� ��ȯ

	{
		//Dog dog;
		//BullDog bullDog;

		BullDog bullDog;
		Dog dog = bullDog;
	}
	
	//[2] ��� ���� Ŭ������ ���� Ÿ�� ��ȯ
	// Ư¡) �ڽ� -> �θ� OK / �θ�-> �ڽ� (�Ͻ���NO) (����� OK)
	{
		BullDog bullDog;

		Dog& dog = bullDog;
	}

}