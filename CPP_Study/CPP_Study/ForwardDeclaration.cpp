#include <iostream>
#include <stdlib.h>
using namespace std;
#include "P.h"


// 오늘의 주제 전방선언

int main()
{
	// P는 몇 바이트?
	// int 2개 = 2 * 4 => 8바이트
	P p1; // 지역변수 (Stack)

	P* p2 = new P(); // 동적할당 (Heap)
}