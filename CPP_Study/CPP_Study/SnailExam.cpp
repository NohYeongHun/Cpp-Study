#include <iostream>
#include <iomanip>
using namespace std;

// 오늘의 주제 : 연습 문제

const int MAX = 100;
int N;
int board[MAX][MAX] = { };

int main()
{
	cin >> N;
	
	int num = 1;
	int endNum = N * N;
	int r = 0; 
	int c = 0;
	int dir = 0;
	int size = N - 1;
	
	if (N % 2 != 0) board[N / 2][N / 2] = endNum;

	while (size > 0)
	{
			
		for (int i = 0; i < size; i++)
		{
			board[r][c++] = num++;
		}

		for (int i = 0; i < size; i++)
		{
			board[r++][c] = num++;
		}

		for (int i = 0; i < size; i++)
		{
			board[r][c--] = num++;
		}

		for (int i = 0; i < size; i++)
		{
			board[r--][c] = num++;
		}

		r++;
		c++;
		size -= 2;
	}
	
	int digit = 0;
	while (endNum > 0)
	{
		endNum /= 10;
		digit++;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setfill('0') << setw(digit) << board[i][j] << " ";
		}
		cout << endl;
	}


	
}