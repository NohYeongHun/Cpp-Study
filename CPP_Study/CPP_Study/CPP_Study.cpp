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

// signed 최상위 비트를 음수로 선택.
char a; // 1byte - signed 생략 (부호 존재) (-128 ~ 127)
short b; // 2byte - signed 생략 (부호 존재) (-32768 ~ 32767)
int c; // 4byte - signed 생략 (부호 존재) (-2,147,483,648  ~ 2,147,483,647) 21.4억
__int64 d; // 8byte (long long) - signed 생략 (부호 존재) ( -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807)

// unsigned 최상위 비트도 양수 => 양수값으로만 보겠다.
unsigned char ua; // 1byte (0 ~ 255)
unsigned short ub;// 2byte (0 ~ 65535)
unsigned int uc; // 4byte (0 ~ 4,294,967,295)
unsigned __int64 ud; // 8byte (long long) (0 ~ 어마어마하게 크다)

// 참고) 이론식으로 양수만 존재할 수 있는 데이터 unsigned
// 무조건 unsigned를 사용할지 의견이 갈림
// - 레벨이 음수라는 것은 말이 안된다 -> 그럼 차라리 그 자리에서 프로그램을 크래시 내서 버그를 빨리 찾자.
// - unsigned / signed사이의 변환

// 귀찮은데 그냥 대충 4바이트로 가면 안될까?
// -> 콘솔 / 모바일 게임 -> 메모리가 늘 부족
// -> 온라인 게임 -> 체력에 대한 정보를 보낼때마다 4byte * 1만명

// 초기값이 0이거나, 초기값이 없는 변수라면 .bss 영역


int main()
{
    // signed short의 양수 최대 범위 32767이므로 1을 더하면 -32768
    // 정수 오버플로우
    b = 32767;
    b = b + 1;
    cout << b << endl; // - 32768

    // 정수 언더플로우
    ub = 0;
    ub = ub - 1;
    cout << ub << endl; // 65535

    cout << "체력이 " << hp << "남았습니다" << endl;
}
