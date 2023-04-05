#include <iostream>
using namespace std;
#include<vector>

// ���� : vector

int main()
{
	// �߰� ���� / ����

	// ó�� / ��,  ���� /����

	// ���� ����
	
	// �ݺ���(iterator)
	vector<int> v(10);
	v.reserve(1000);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		v[i] = i;

	vector<int>::iterator it;
	int* ptr;
	
	it = v.begin();
	ptr = &v[0];

	cout << (*it) << endl;
	cout << (*ptr) << endl;
	
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}

	int* ptrBegin = &v[0]; // v.bgin()._Ptr;
	int* ptrEnd = ptrBegin + 10; // v.end()._Ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
	{
		cout << (*ptr) << endl;
	}

	// const int*
	vector<int>::const_iterator cit1 = v.cbegin();

	// reverse_iterator ������ �̵�
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	{
		cout << (*it) << endl;
	}

	v.push_back(1);
	v.pop_back();

	/*vector<int>::iterator insertIt =  v.insert(v.begin() + 2, 5);
	vector<int>::iterator eraseIt1 =  v.erase(v.begin() + 2);
	vector<int>::iterator eraseIt2 =  v.erase(v.begin() + 2, v.begin() + 4);*/

	// ��~ ��ĵ�� �ϸ鼭, 3�̶�� �����Ͱ� ������ �ϰ� ����.
	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		int data = *it;
		if (data == 3)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}

	return 0;


}