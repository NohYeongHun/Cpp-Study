#include <iostream>
using namespace std;
#include <set>

// ������ ���� : set

int main()
{
	// Key�� �ʿ��Ѱ��
	set<int> s;

	s.insert(10);
	s.insert(30);
	s.insert(50);
	s.insert(70);
	s.insert(90);

	// ����
	s.erase(10);

	// ������ ã��;
	set<int>::iterator findIt = s.find(50);
	if (findIt == s.end())
	{
		cout << "�� ã��" << endl;
	}
	else
	{
		cout << "ã��" << endl;
	}



	// ��ȸ�ϰ�
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << (*it) << endl;
	}


	return 0;
}