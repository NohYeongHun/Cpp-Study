#include <iostream>
using namespace std;
#include<vector>
#include<map>

class Knight
{
public:
	int _ho;

	Knight()
	{

	}
	
	Knight(int a, int b)
	{
		cout << "Knight(int, int)" << endl;
	}

	// �켱 ������ ���� ����
	Knight(initializer_list<int> li)
	{
		cout << "Knight(initializer list)" << endl;
	}
};

int main()
{
	// �߰�ȣ �ʱ�ȭ { }

	int a = 0;
	int b{ 0 };
	int c{ 0 };

	Knight k1;
	k1._ho = 1;
	// ���� ������ => ������ ���ÿ� �ʱ�ȭ (���� ������ X)
	Knight k2 = k1; 
	
	// �⺻ ������
	Knight k3; 
	// ���� ���� ������ => ���� �� �ʱ�ȭ
	k3 = k1; 

	Knight k4{ k2 };

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2(10, 1);
	int arr[] = { 1, 2, 3, 4 };
	
	
	// �߰�ȣ �ʱ�ȭ
	// 1) vector �� container�� �� ��︰��.
	vector<int> v3{ 1, 2, 3, 4 };

	// 2) ��� ��ȯ ���� => ������ �ս� ����.
	int x = 0;
	// double y{ x };

	// 3) Bonus
	// k4�� ���������� Knight Ÿ�� ��ü�� ��ȯ�ϴ� �Լ��̴�.
	// Knight k4();
	// ������ �⺻ �����ڷ� ����.
	Knight k5{};

	/*
		initalize_list�� �߰��Ѵٸ�
		���� Ÿ���� ����ϴ� 
		�ٸ� ��� �������� �켱������ ������.
	*/
	Knight k6{3, 3};

	// ��ȣ �ʱ�ȭ ()�� �⺻���� ����
	// - �������� C++ (�źΰ��� ����)
	// - vector �� Ư���� ���̽��� ���ؼ��� { } ���

	// �߰�ȣ �ʱ�ȭ { }�� �⺻���� ����.
	// - �ʱ�ȭ ������ ��ġȭ
	// - ��� ��ȯ ����

	return 0;

}