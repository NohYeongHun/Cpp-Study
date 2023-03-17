#include <iostream>
using std::cout;
using std::endl;

// 주석을 달 수 있다.
// CTRL + K + C(Comment) Ctrl + K + U(UnComment) 단축키

/*
    주석이 여러 줄이라면 어떻게 달 수 있어요!
*/

// 프로그래밍을 단순하게 생각하면
// 적절한 데이터를 저장하고 가공하는 것`
// 데이터 + 로직

// 그 중에서도 가장 빈번하게 사용되는 정수에 대해 알아보기.

// 변수 선언 방법
// [타입] [이름];
// [타입] [이름] = [초기값];

// 0이 아닌 초기화 값이 있으면 .data 영역
int hp = 100;

char a; // 1byte
short b; // 2byte
int c; // 4byte
__int64 d; // 8byte (long long)

// 초기값이 0이거나, 초기값이 없는 변수라면 .bss 영역


int main()
{
    std::cout << "체력이 " << hp << "남았습니다" << std::endl;
}
