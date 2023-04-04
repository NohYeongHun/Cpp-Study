#include <iostream>
using namespace std;

// ������ ���� : ���ø� ����


// typename T�� ���̸� (� Ÿ�Ե� �� ���� �� ����)
// ������ typename�� �ٿ��� �ϴ� ���� �ƴ�.
template<typename T, int SIZE>
class RandomBox
{
public:
	T GetRandomData()
	{
		int idx = rand() % SIZE;
		return _data[idx];
	}

public:
	T _data[SIZE];
};

// ���ø� Ư��ȭ
template<int SIZE>
class RandomBox<double, SIZE>
{
public:
	double GetRandomData()
	{
		int idx = rand() % SIZE;
		cout << "double RandomBox" << endl;
		return _data[idx];
	}

public:
	double _data[SIZE];

};

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	RandomBox<int, 10> rb1;

	for (int i = 0; i < 10; i++)
	{
		rb1._data[i] = i;
	}
	int value1 = rb1.GetRandomData();
	cout << value1 << endl;


	RandomBox<double, 20> rb2;
	for (int i = 0; i < 20; i++)
	{
		rb2._data[i] = i;
	}

	double value2 = rb2.GetRandomData();
	cout << value2 << endl;

	// rb1�� rb2�� ������ Ÿ�԰��ƺ��̳� => �ٸ���!.
	// rb1 != rb2
}