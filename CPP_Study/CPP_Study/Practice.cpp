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

	// Q1) number��� ���ڰ� ���Ϳ� üũ�ϴ� ��� (bool, ù ���� iterator)
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

	// Q2) 11�� ������ ���ڰ� ���Ϳ� �ִ��� üũ�ϴ� ���
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

	// Q3) Ȧ���� ������ ������? (count)
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

		cout << "Ȧ�� = " << count << endl;

	}

	// ���ϱ� ��
	cout << "==================���� ����=================" << endl;
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << endl;
	}

	// Q4) ���Ϳ� �� �ִ� ��� ���ڵ鿡 3�� ���ϱ�
	{
		vector<int>::iterator iter = v.begin();
		while (iter != v.end())
		{
			*iter *= 3;
			++iter;
		}
	}

	cout << "==================���� ����=================" << endl;
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << endl;
	}

	


	return 0;
}