#include <iostream>
using namespace std;


const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

int main()
{
	
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
			cout << "���� �·� : " << winRate<< endl;
		}
		cout << "< ";

		// �����
		int input;
		cin >> input;

		// 1 2 3 ��ǻ���� ����������
		int computer = 1 + (rand() % 3); // 1 + (0 ~ 32767) % 3 => 1 2 3

		if (input == SCISSORS) 
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