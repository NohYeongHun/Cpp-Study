#include <iostream>
using namespace std;

// 오늘의 주제 : 알고리즘
#include<algorithm>
#include<vector>


int main()
{
	// 자료구조 (데이터를 저장하는 구조)
	// 알고리즘 (문제를 해결하기 위한 여러가지 동작)

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

	// Q1) number라는 숫자가 벡터에 체크하는 기능 (bool, 첫 등장 iterator)
	{
		bool found = false;
		int number = 50;

		// TODO
		// Iterator 반환
		vector<int>::iterator itFind = find(v.begin(), v.end(), number);
		found = itFind == v.end() ? false : true;
	}

	// Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능
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

	// Q3) 홀수인 숫자의 개수는? (count)
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

		// 모든 데이터가 홀수입니까?
		bool b1 = all_of(v.begin(), v.end(), IsOdd());

		// 홀수인 데이터가 하나라도 있습니까?
		bool b2 = any_of(v.begin(), v.end(), IsOdd());

		// 모든 데이터가 홀수가 아닙니까?
		bool b3 = none_of(v.begin(), v.end(), IsOdd());

		int g = 3;


	}

	// 곱하기 전
	cout << "==================곱셈 이전=================" << endl;
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << endl;
	}

	// Q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱하기
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


	cout << "==================곱셈 이후=================" << endl;
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << endl;
	}


	/*
		remove
		remove_if
	*/

	// 홀수인 데이터를 일괄 삭제
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

		// 4 8 2 |(사용하지 않는 위치) 5 8 2 => 사용하지 않는 위치를 반환함

		// 유효하지 않은 위치
		vector<int>::iterator it = remove_if(v.begin(), v.end(), isOdd());
		// 유효하지 않은 위치부터 삭제해주세요.
		v.erase(it, v.end());

		int a = 3;
		
		
	}

}