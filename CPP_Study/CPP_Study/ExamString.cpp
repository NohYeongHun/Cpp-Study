#include <iostream>
using namespace std;

// 오늘의 주제 : 연습 문제

// 문제 1) 문자열 길이를 출력하는 함수
int StrLen(const char* str)
{
	// str이라는 문자열의 길이를 반환
	int cnt = 0;

	while (*(str + cnt) != '\0')
	{
		cnt++;
	}

	return cnt;
}

// 문제2) 문자열 복사 함수
// [H][e][l][l][o]['\0'][][][][][]
// [H][e][l][l][o]['\0'][][][][][]
char* StrCpy(char* dest, char* src)
{
	// size가 동일하다는 가정
	int len = StrLen(src);

	for (int i = 0; i < len; i++) {
		dest[i] = src[i];
	}
	dest[len] = '\0';
	return dest;
}

// 문제3) 문자열 덧붙이는 함수
// [H][e][l][l][o]['\0'][][][][][]
// [W][o][r][l][d]['\0'][][][][][]
// [H][e][l][l][o][W][o][r][l][d]['\0']
char* StrCat(char* dest, char* src)
{
	/*
	* 배열버전
	* int cnt = 0;
	while (src[cnt] != '\0')
	{
		dest[destLen + cnt] = src[cnt];
		cnt++;
	}

	dest[destLen + cnt] = '\0';
	*/

	// 포인터 버전
	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest++ = *src++;
	}

	*dest = '\0';

	return dest;

}


// 문제4) 문자열이 같은지 확인하는 함수
int StrCmp(char* dest, char* src)
{	
	int cnt = 0;
	
	while (dest[cnt] != '\0' || src[cnt] != '\0')
	{
		if (dest[cnt] > src[cnt])
			return 1;
		if (dest[cnt] < src[cnt])
			return -1;
		cnt++;
	}
	
	return 0;
}

// 문제5) 문자열을 뒤집는 함수
void ReverseStr(char* str)
{
	int len = StrLen(str);

	for (int i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	
}

#pragma warning(disable :4996)

int main()
{
	const int BUF_SIZE = 100;

	// [H][e][l][l][o]['\0'][][][][][]
	char t_a[BUF_SIZE] = "Hello";
	char t_b[BUF_SIZE] = "World";
	
	
	// 문제 1
	int len = StrLen(t_a);
	cout << len << endl;

	//// 문제 2
	StrCpy(t_b, t_a);
	cout << t_b << endl;

	// 문제 3
	char t_a3[BUF_SIZE] = "Hello";
	char t_b3[BUF_SIZE] = "World";
	StrCat(t_a3, t_b3);
	cout << t_a3 << endl;

	// 문제 4
	char t_a4[BUF_SIZE] = "Hello";
	char t_b4[BUF_SIZE] = "World";
	int value = StrCmp(t_a4, t_b4);
	cout << value << endl;

	// 문제 5
	char t5[BUF_SIZE] = "Hello";
	ReverseStr(t5);
	cout << t5 << endl;

	return 0;

}