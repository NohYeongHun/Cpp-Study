#include <iostream>
using namespace std;

// ������� �ʹ� ���ε��� ��� �� ����?
// �ϳ��� ��Ʈ�� �����ϰ����.
const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

// ���ڸ� ���� ���ϸ� ù ���� 0���� ����.
// �� ���� ������ ���� �� + 1
// �޸𸮿� ������ ����.
enum ENUM_SRP
{
	ENUM_SCISSORS = 1,
	ENUM_ROCK,
	ENUM_PAPER,
};

// #�� ������ -> ��ó�� ���ù�
// #include <iostream> 
// => compile ���� iostream�̶�� ������ ã�Ƽ� �ش� ������ �������ּ���
// �����Ϸ��� ó�� ���� 1) ��ó�� 2) ������ 3) ��ũ
// #define => ���ǵ� ������ ������ ���ù����� �����.
#define DEFINE_SCISSORS 1+2
#define DEFINE_TEST cout << "Hello World" << endl;

int main()
{
	DEFINE_TEST;
	int result = DEFINE_SCISSORS * 2; // 6�ϰ� ������? ���� ��� ����
	// => 1 + 2 * 2 �� �����.
	cout << result << endl;

	srand(time(0)); // �õ� ����

	int winCnt = 0;
	int allCnt = 0;

	while (true)
	{

		cout << "����(1) ����(2) ��(3)�� �������ּ���" << endl;
		if (allCnt == 0) {
			cout << "���� �·� : ����" << endl;
		}
		else {
			int winRate = (winCnt * 100) / allCnt;
			cout << "���� �·� : " << winRate << endl;
		}
		cout << "< ";

		// �����
		int input;
		cin >> input;

		// 1 2 3 ��ǻ���� ����������
		int computer = 1 + (rand() % 3); // 1 + (0 ~ 32767) % 3 => 1 2 3

		if (input == ENUM_SCISSORS)
		{
			switch (computer)
			{
			case ROCK:
				cout << "��ǻ��(����) vs ���(����) �й��Ͽ����ϴ�." << endl;
				break;
			case SCISSORS:
				cout << "��ǻ��(����) vs ���(����) �����ϴ�." << endl;
				allCnt--;
				break;
			case PAPER:
				cout << "��ǻ��(��) vs ���(����) �¸��Ͽ����ϴ�." << endl;
				winCnt++;
				break;
			}
			allCnt++;
		}
		else if (input == ROCK)
		{
			switch (computer)
			{
			case ROCK:
				cout << "��ǻ��(����) vs ���(����) �����ϴ�." << endl;
				allCnt--;
				break;
			case SCISSORS:
				cout << "��ǻ��(����) vs ���(����) �¸��Ͽ����ϴ�." << endl;
				winCnt++;
				break;
			case PAPER:
				cout << "��ǻ��(��) vs ���(����) �й��Ͽ����ϴ�." << endl;
				break;
			}
			allCnt++;
		}
		else if (input == PAPER)
		{
			switch (computer)
			{
			case ROCK:
				cout << "��ǻ��(����) vs ���(��) �¸��Ͽ����ϴ�." << endl;
				winCnt++;
				break;
			case SCISSORS:
				cout << "��ǻ��(����) vs ���(��) �й��Ͽ����ϴ�." << endl;
				break;
			case PAPER:
				cout << "��ǻ��(��) vs ���(��) �����ϴ�." << endl;
				allCnt--;
				break;
			}
			allCnt++;
		}
		else
		{
			cout << "��Ű�� �Է��Ͽ� ����Ǿ����ϴ�." << endl;
			break;
		}

		cout << endl;

	}
	
}