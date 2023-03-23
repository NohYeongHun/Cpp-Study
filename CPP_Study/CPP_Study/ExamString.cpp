#include <iostream>
using namespace std;

// ������ ���� : ���� ����

// ���� 1) ���ڿ� ���̸� ����ϴ� �Լ�
int StrLen(const char* str)
{
	// str�̶�� ���ڿ��� ���̸� ��ȯ
	int cnt = 0;

	while (*(str + cnt) != '\0')
	{
		cnt++;
	}

	return cnt;
}

// ����2) ���ڿ� ���� �Լ�
// [H][e][l][l][o]['\0'][][][][][]
// [H][e][l][l][o]['\0'][][][][][]
char* StrCpy(char* dest, char* src)
{
	// size�� �����ϴٴ� ����
	int len = StrLen(src);

	for (int i = 0; i < len; i++) {
		dest[i] = src[i];
	}
	dest[len] = '\0';
	return dest;
}

// ����3) ���ڿ� �����̴� �Լ�
// [H][e][l][l][o]['\0'][][][][][]
// [W][o][r][l][d]['\0'][][][][][]
// [H][e][l][l][o][W][o][r][l][d]['\0']
char* StrCat(char* dest, char* src)
{
	/*
	* �迭����
	* int cnt = 0;
	while (src[cnt] != '\0')
	{
		dest[destLen + cnt] = src[cnt];
		cnt++;
	}

	dest[destLen + cnt] = '\0';
	*/

	// ������ ����
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


// ����4) ���ڿ��� ������ Ȯ���ϴ� �Լ�
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

// ����5) ���ڿ��� ������ �Լ�
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
	
	
	// ���� 1
	int len = StrLen(t_a);
	cout << len << endl;

	//// ���� 2
	StrCpy(t_b, t_a);
	cout << t_b << endl;

	// ���� 3
	char t_a3[BUF_SIZE] = "Hello";
	char t_b3[BUF_SIZE] = "World";
	StrCat(t_a3, t_b3);
	cout << t_a3 << endl;

	// ���� 4
	char t_a4[BUF_SIZE] = "Hello";
	char t_b4[BUF_SIZE] = "World";
	int value = StrCmp(t_a4, t_b4);
	cout << value << endl;

	// ���� 5
	char t5[BUF_SIZE] = "Hello";
	ReverseStr(t5);
	cout << t5 << endl;

	return 0;

}