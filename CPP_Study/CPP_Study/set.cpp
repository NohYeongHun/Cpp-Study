#include <iostream>
using namespace std;
#include <set>

// 오늘의 주제 : set

int main()
{
	// Key만 필요한경우
	set<int> s;

	s.insert(10);
	s.insert(30);
	s.insert(50);
	s.insert(70);
	s.insert(90);

	// 빼기
	s.erase(10);

	// 데이터 찾기;
	set<int>::iterator findIt = s.find(50);
	if (findIt == s.end())
	{
		cout << "못 찾음" << endl;
	}
	else
	{
		cout << "찾음" << endl;
	}



	// 순회하고
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << (*it) << endl;
	}


	return 0;
}