#include <iostream>
using namespace std;

// ������ ���� : delete (������ �Լ�)

class Knight
{
public:

private:
	// ���ǵ��� ���� �����(private �Լ�)
	// �ܺο����� ���Ұ�������?? => ���������δ� ��밡��.
	// void operator=(const Knight& k);

	// delete ����? => ������ �Լ�! ����� �Ұ��ϴ�.
	void operator=(const Knight& k) = delete;
	

	// friend class�� ����Ѵٸ� Admin���� prviate �κ��� �����Ѵ�.
	friend class Admin;

private:
	int _hp = 100;
};

class Admin
{
public:
	void CopyKnight(const Knight& k)
	{
		Knight k1;
		// ���� ���� => delete ���� �Ұ���.
		// k1 = k;
	}
};

int main()
{
	Knight k1;

	Knight k2;

	// ���� �����ڸ� ����ʹٸ�?
	// ���� ������ ����
	// k1 = k2;
	Admin admin;


	return 0;
}