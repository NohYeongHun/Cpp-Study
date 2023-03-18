#include <iostream>
using namespace std;


const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

int main()
{
	
	srand(time(0)); // 시드 설정
	
	int winCnt = 0;
	int allCnt = 0;
	
	while (true) 
	{

		cout << "가위(1) 바위(2) 보(3)를 선택해주세요" << endl;
		if (allCnt == 0) {
			cout << "현재 승률 : 없음" << endl;
		}
		else {
			int winRate = (winCnt * 100) / allCnt;
			cout << "현재 승률 : " << winRate<< endl;
		}
		cout << "< ";

		// 사용자
		int input;
		cin >> input;

		// 1 2 3 컴퓨터의 가위바위보
		int computer = 1 + (rand() % 3); // 1 + (0 ~ 32767) % 3 => 1 2 3

		if (input == SCISSORS) 
		{
			switch (computer)
			{
				case ROCK:
					cout << "컴퓨터(바위) vs 당신(가위) 패배하였습니다." << endl;
					break;
				case SCISSORS:
					cout << "컴퓨터(가위) vs 당신(가위) 비겼습니다." << endl;
					allCnt--;
					break;
				case PAPER:
					cout << "컴퓨터(보) vs 당신(가위) 승리하였습니다." << endl;
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
				cout << "컴퓨터(바위) vs 당신(바위) 비겼습니다." << endl;
				allCnt--;
				break;
			case SCISSORS:
				cout << "컴퓨터(가위) vs 당신(바위) 승리하였습니다." << endl;
				winCnt++;
				break;
			case PAPER:
				cout << "컴퓨터(보) vs 당신(바위) 패배하였습니다." << endl;
				break;
			}
			allCnt++;
		}
		else if (input == PAPER) 
		{
			switch (computer)
			{
			case ROCK:
				cout << "컴퓨터(바위) vs 당신(보) 승리하였습니다." << endl;
				winCnt++;
				break;
			case SCISSORS:
				cout << "컴퓨터(가위) vs 당신(보) 패배하였습니다." << endl;
				break;
			case PAPER:
				cout << "컴퓨터(보) vs 당신(보) 비겼습니다." << endl;
				allCnt--;
				break;
			}
			allCnt++;
		}
		else
		{
			cout << "디른키를 입력하여 종료되었습니다." << endl;
			break;
		}

		cout << endl;
		
	}

}