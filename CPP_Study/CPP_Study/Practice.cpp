#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	vector<int> v;

	for (int i = 0; i < 100; ++i)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// Q1) number라는 숫자가 벡터에 체크하는 기능 (bool, 첫 등장 iterator)
	{
		bool found = false;
		int number = 50;

		// TODO
		vector<int>::iterator iter = v.begin();
		
		while (iter != v.end())
		{
			if (*iter == number) 
			{
				found = true;
				break;
			}
			++iter;
		}
	}

	// Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능
	{
		bool found = false;
		int number = 11;

		// TODO
		vector<int>::iterator iter = v.begin();
		while (iter != v.end())
		{
			if (*iter %number == 0)
			{
				found = true;
				break;
			}
			++iter;
		}

	}

	// Q3) 홀수인 숫자의 개수는? (count)
	{
		int count = 0;

		// TODO
		vector<int>::iterator iter = v.begin();
		while (iter != v.end())
		{
			if (*iter %2 != 0)
			{
				count++;
			}
			++iter;
		}

		cout << "홀수 = " << count << endl;

	}

	// 곱하기 전
	cout << "==================곱셈 이전=================" << endl;
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << endl;
	}

	// Q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱하기
	{
		vector<int>::iterator iter = v.begin();
		while (iter != v.end())
		{
			*iter *= 3;
			++iter;
		}
	}

	cout << "==================곱셈 이후=================" << endl;
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << endl;
	}

	


	return 0;
}