#include <iostream>
using namespace std;

// ������ ���� : nullptr

class Knight
{
public:
	void Test(){ } ;
};

Knight* FindKnight()
{
	// TODO

	return nullptr;
}

void Test(int a)
{
	cout << "Test(int)" << endl;
}

void Test(void* ptr)
{
	cout << "Test(*)" << endl;
}

// NullPtr ����

// �̱��� ���� ����?
class
{
public:

	// �� � Ÿ���� �����Ϳ͵� ġȯ ����
	template<typename T>
	operator T* () const
	{
		return 0;
	}

	// �� � Ÿ���� ��� �����Ϳ͵� ġȯ ����
	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}

private:
	void operator&() const; // �ּҰ� &�� ���´�.

} _nullptr;


int main()
{
	// 0 NULL
	int* ptr = nullptr;

	// 1) ������ ����
	// �� �� int Ÿ�� �Ű������� �Լ��� ȣ��ȴ�!.
	Test(0);
	Test(NULL);

	// ������ Ÿ���� �Ű������� �Լ��� ȣ��ȴ�!.
	Test(nullptr);
	Test(_nullptr);

	// 2) ������
	auto knight = FindKnight();
	if (knight == nullptr)
	{

	}

	Knight* kngiht2 = FindKnight();
	if (kngiht2 == _nullptr)
	{

	}

	void (Knight::* memFunc)();
	memFunc = &Knight::Test;

	if (memFunc == _nullptr)
	{

	}

	nullptr_t whoami = nullptr;
	

	return 0;
}