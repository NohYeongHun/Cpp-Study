#include <iostream>
using namespace std;
#include <map>

// ������ ���� : multimap

int main()
{
	multimap<int, int> mm;

	// ������ ����
	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(1, 200));
	mm.insert(make_pair(1, 300));
	mm.insert(make_pair(2, 400));
	mm.insert(make_pair(2, 500));
	mm.insert(make_pair(2, 600));


	// ����
	unsigned int count = mm.erase(1);

	// ã��
	multimap<int, int>::iterator itFind = mm.find(1);
	if (itFind != mm.end())
		mm.erase(itFind);

	// key�� �ش��ϴ� ���� ã��.
	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> itPair;
	itPair = mm.equal_range(2);

	for (multimap<int, int>::iterator it = itPair.first; it != itPair.second; ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	multimap<int, int>::iterator itBegin = mm.lower_bound(2);
	multimap<int, int>::iterator itEnd = mm.upper_bound(2);
	for (multimap<int, int>::iterator it = itBegin; it != itEnd; ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	mm.clear();
	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(1, 200));
	mm.insert(make_pair(1, 300));

	// ������ ��ȸ
	for (multimap<int, int>::iterator it = mm.begin(); it != mm.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	




	return 0;
}