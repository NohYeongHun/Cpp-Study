#include <iostream>
using namespace std;

// ������ ���� : �˰���
#include<algorithm>
#include<vector>


int main()
{
	// �ڷᱸ�� (�����͸� �����ϴ� ����)
	// �˰��� (������ �ذ��ϱ� ���� �������� ����)

	// find
	// find_if
	// count
	// count_if
	// all_of
	// any_of
	// none_of
	// for_each
	// remove 
	// remove_if

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
		// Iterator ��ȯ
		vector<int>::iterator itFind = find(v.begin(), v.end(), number);
		found = itFind == v.end() ? false : true;
	}

	// Q2) 11�� ������ ���ڰ� ���Ϳ� �ִ��� üũ�ϴ� ���
	{
		bool found = false;
		int number = 11;

		struct CanDivideBy11
		{
			bool operator()(int n)
			{
				return (n % 11) == 0;
			}
		};

		// TODO
		vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivideBy11());
		found = itFind == v.end() ? false : true;
	}

	// Q3) Ȧ���� ������ ������? (count)
	{
		struct IsOdd
		{
			bool operator()(int n)
			{
				return (n % 2) != 0;
			}
		};

		// TODO
		int n = count_if(v.begin(), v.end(), IsOdd());

		// ��� �����Ͱ� Ȧ���Դϱ�?
		bool b1 = all_of(v.begin(), v.end(), IsOdd());

		// Ȧ���� �����Ͱ� �ϳ��� �ֽ��ϱ�?
		bool b2 = any_of(v.begin(), v.end(), IsOdd());

		// ��� �����Ͱ� Ȧ���� �ƴմϱ�?
		bool b3 = none_of(v.begin(), v.end(), IsOdd());

		int g = 3;


	}

	// ���ϱ� ��
	cout << "==================���� ����=================" << endl;
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << endl;
	}

	// Q4) ���Ϳ� �� �ִ� ��� ���ڵ鿡 3�� ���ϱ�
	{

		struct MultipleBy3
		{
			void operator()(int& n)
			{
				n *= 3;
			}
		};

		for_each(v.begin(), v.end(), MultipleBy3());
	}


	cout << "==================���� ����=================" << endl;
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << endl;
	}


	/*
		remove
		remove_if
	*/

	// Ȧ���� �����͸� �ϰ� ����
	{
		v.clear();

		v.push_back(1);
		v.push_back(4);
		v.push_back(3);
		v.push_back(5);
		v.push_back(8);
		v.push_back(2);

		// 1 4 3 5 8 2

		// remove(v.begin(), v.end(), 4);


		struct isOdd
		{
			bool operator()(int n)
			{
				return (n % 2) != 0;
			}
		};

		/*
			template<class ForwardIt, class UnaryPredicate>
			ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p)
			{
				first = std::find_if(first, last, p);
				if (first != last)
					for (ForwardIt i = first; ++i != last;)
						if (!p(*i))
							*first++ = std::move(*i);
				return first;
			}
		*/
		// 1 4 3 5 8 2
		// 4 8 2 5 8 2

		// 4 8 2 |(������� �ʴ� ��ġ) 5 8 2 => ������� �ʴ� ��ġ�� ��ȯ��

		// ��ȿ���� ���� ��ġ
		vector<int>::iterator it = remove_if(v.begin(), v.end(), isOdd());
		// ��ȿ���� ���� ��ġ���� �������ּ���.
		v.erase(it, v.end());

		int a = 3;
		
		
	}

}