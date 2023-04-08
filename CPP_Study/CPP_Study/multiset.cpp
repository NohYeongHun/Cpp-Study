#include <iostream>
using namespace std;
#include <set>

int main()
{

	multiset<int> ms;
	// 넣기
	ms.insert(100);
	ms.insert(100);
	ms.insert(100);
	ms.insert(200);
	ms.insert(200);

	// 찾기
	multiset<int>::iterator findIt = ms.find(100);

	pair<multiset<int>::iterator, multiset<int>::iterator> itPair;
	itPair = ms.equal_range(100);

	for (multiset<int>::iterator it = itPair.first; it != itPair.second; ++it)
	{
		cout << *it << endl;
	}

	ms.equal_range(100);
	multiset<int>::iterator itBegin = ms.lower_bound(100);
	multiset<int>::iterator itEnd = ms.upper_bound(100);
	for (multiset<int>::iterator it = itBegin; it != itEnd; ++it)
	{
		cout << *it << endl;
	}

	// 삭제
	ms.erase(100);

	// 데이터 순회
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); ++it)
	{
		cout << *it << endl;
	}



}