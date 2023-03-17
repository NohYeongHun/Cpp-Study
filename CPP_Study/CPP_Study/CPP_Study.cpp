#include <iostream>
using std::cout;
using std::endl;

// 오늘의 주제 : 문자와 문자열
// bool은 그냥 정수미나, 참/ 거짓을 나타내기 위해 사용한다 했었다
// 사실 char도 마찬가지, 그냥 정수지만 '문자' 의미를 나타내기 위해 사용

// char : 알파벳 / 숫자 문자를 나타낸다
// wchar_t : 유니코드 문자를 나타낸다.

// '문자'의 의미로 작은 따옴표 '' 사용
char ch = 'a';
char ch2 = '1';
char ch3 = 'a' + 1;

// 국제화 시대에는 영어만으로 서비스 할 수 없음
// 전 세계 모든 문자에 대해 유일 코드를 부여한 것이 유니코드 (unicode)
// 참고) 유니코드에서 가장 많은 번호를 차지하는게 한국어/중국어~ ex(뚥쿩웱)

// 유니코드는 표기 방식이 여러가지가 있음. 대표적으로 UTF8 UTF16
// UTF8
// 
// - 알파벳, 숫자 1바이트(ASCII 동일한 번호)
// - 유럽 지역의 문자는 2바이트
// - 한글, 한자 등 3바이트
// 
// UTF16
// - 알파벳, 숫자, 한글, 한자 등 거의 대부분 문자 2바이트
// - 매~~우 예외적인 고대 문자만 4바이트 (사실상 무시해도 됨)

wchar_t wch = 0xc548; // L'안';

// Escape Sequence
// 표기하기 애매한 애들을 표현
// tab => '    ' ? => 띄어쓰기를 몇번한건지 tabe인건지?
// \t = 아스키코드9 = Tab
// \n = 아스키코드10 = LineFeed(한줄 아래로)
// \r = 아스키코드13 = CarriageReturn (커서 <<)
// (') 따옴표를 표기하고싶다면? => \', \"

// 문자열
// 문자들이 열을 지어서 모여 있는것 (문자 배열)
// 정수 (1 ~ 8바이트) 고정 길이
// string = "Hello World" => const char str[12] = ['H','e','l','l','o',' ','W','o','r','l','d','\0'];

char coma = '\'';
char coma2 = '\"';

const char str[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0' };
char str2[] = "Hello World";

int main()
{
	cout << ch << endl;
	cout << ch2 << endl;
	cout << ch3 << endl;

	// cout은 char 전용
	// wcout.imubue(std::locale("kor")) => 한글도 출력해줘
	std::wcout.imbue(std::locale("kor"));
	std::wcout << wch << endl;

	cout << coma << endl;
	cout << coma2 << endl;

	cout << str << endl;
	cout << char(9) << endl;
}
