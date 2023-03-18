#include <iostream>
using namespace std;

// 상수들이 너무 따로따로 노는 것 같음?
// 하나의 세트로 관리하고싶음.
const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

// 숫자를 지정 안하면 첫 값은 0부터 시작.
// 그 다음 값들은 이전 값 + 1
// 메모리에 잡히지 않음.
enum ENUM_SRP
{
	ENUM_SCISSORS = 1,
	ENUM_ROCK,
	ENUM_PAPER,
};

// #이 붙은거 -> 전처리 지시문
// #include <iostream> 
// => compile 전에 iostream이라는 파일을 찾아서 해당 내용을 가져와주세요
// 컴파일러의 처리 과정 1) 전처리 2) 컴파일 3) 링크
// #define => 정의된 문장을 왼항의 지시문으로 사용함.
#define DEFINE_SCISSORS 1+2
#define DEFINE_TEST cout << "Hello World" << endl;

int main()
{
	DEFINE_TEST;
	int result = DEFINE_SCISSORS * 2; // 6일것 같지만? 실제 사용 예시
	// => 1 + 2 * 2 로 변경됨.
	cout << result << endl;

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
			cout << "현재 승률 : " << winRate << endl;
		}
		cout << "< ";

		// 사용자
		int input;
		cin >> input;

		// 1 2 3 컴퓨터의 가위바위보
		int computer = 1 + (rand() % 3); // 1 + (0 ~ 32767) % 3 => 1 2 3

		if (input == ENUM_SCISSORS)
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