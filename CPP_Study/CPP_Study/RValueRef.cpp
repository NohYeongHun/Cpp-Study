#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

class Pet
{

};

class Knight
{
public:
	Knight()
	{
		cout << "Knight()" << endl;
	}

	// ���� ������
	Knight(const Knight& knight)
	{
		cout << "const Knight&" << endl;
	}

	// �̵� ������
	Knight(Knight&& knight)
	{

	}

	~Knight()
	{
		if (_pet)
			delete _pet;
	}

	// ���� ���� ������
	void operator=(const Knight& knight)
	{
		cout << "operator=(const Knight&)" << endl;
		
		// ���� ����
		_hp = knight._hp;
		
		// ���� ���� => ���� �����Ͱ� ���� �ʴ� ��ſ�..
		// ���翡 ���� ����� ���.
		if (knight._pet)
			_pet = new Pet(*knight._pet);
	}

	// �̵� ���� ������
	void operator=(Knight&& knight) noexcept
	{
		cout << "operator=(const Knight&&)" << endl;

		// ���� ���縦 �ϴ���? ���� ������ ������ ����.
		_hp = knight._hp;
		_pet = knight._pet;

		knight._pet = nullptr;
	}

	void PrintInfo()
	{

	}

public:
	int _hp = 100;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight)
{
	knight._hp = 200;
}

void TestKnight_LValueRef(Knight& knight)
{
	knight._hp = 200;
}

void TestKnight_ConstLValueRef(const Knight& knight)
{
	// ȣȯ���� �ʴ� ���� ������ const�� �Լ��� ��� ����.
	// knight.PrintInfo();
}


// ������ ����
void TestKnight_RValueRef(Knight&& knight) // �̵� ��� => ������ �������� �ʾƵ� �ȴ�.
{

}

// ������ ���� : ������(rvalue) std::move
int main()
{
	// �ް�(lvalue) vs ���� ��(rvalue)
	// - lvalue : ���Ͻ��� �Ѿ ��� ���ӵǴ� ��ü
	// - rvalue : lvaule�� �ƴ� ������ (�ӽ� ��, ������, ����, i++ ��)

	int a = 3;

	Knight k1;

	TestKnight_Copy(k1);
	TestKnight_LValueRef(k1);

	// �� const ������ ���� �ʱⰪ�� lvalue��
	// TestKnight_LValueRef(Knight());

	TestKnight_ConstLValueRef(k1);

	// rvalue ������ lvalue ���ε� �Ұ�
	// TestKnight_RValueRef(k1);

	TestKnight_RValueRef(Knight());

	// ��� ��ȯ�ؼ� ������ ��ĥ �� �ְ� k1 ���� ������. 
	TestKnight_RValueRef(static_cast<Knight&&>(k1));


	Knight k2;
	k2._pet = new Pet();
	k2._hp = 1000;

	// ������ ������ �ȴ� << �� Hint�� �ִ� �ʿ� �����.
	// ���縦 ���� ���� => �����͸� �̵��� => cost�� ���� ��.
	Knight k3;
	k3 = static_cast<Knight&&>(k2);

	k3 = std::move(k2); // ������ ������ ĳ����
	// std::move�� ���� �̸� �ĺ� �� �ϳ��� rvalue_cast

	std::unique_ptr<Knight> uptr = std::make_unique<Knight>();

	// �Ұ���! => �����͸� ������ �Ѱ��ۿ� �����Ҽ� ���� Ÿ��
	// std::unique_ptr<Knight> uptr2 = uptr;
	// 
	// ������ ����!
	std::unique_ptr<Knight> uptr2 = std::move(uptr);

	return 0;
}