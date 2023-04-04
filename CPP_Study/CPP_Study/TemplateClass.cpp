#include <iostream>
using namespace std;

// 오늘의 주제 : 템플릿 기초


// typename T를 붙이면 (어떤 타입도 다 넣을 수 있음)
// 무조건 typename을 붙여야 하는 것은 아님.
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

// 템플릿 특수화
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

	// rb1과 rb2는 동일한 타입같아보이나 => 다르다!.
	// rb1 != rb2
}