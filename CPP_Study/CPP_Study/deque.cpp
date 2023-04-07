#include <iostream>
using namespace std;
#include<vector>
#include<deque>

// 오늘의 주제 : deque

// vector : 동적 배열
// [     ]

// list : 이중 연결 리스트
// [ ] <-> [ ] <-> [ ] <-> [ ]

// deque : double-ended queue 데크
// [       ]
// [       ]

int main()
{
	// 시퀀스 컨테이너 (Sequence Container)
	// 데이터가 삽입 순서대로 나열되는 형태
	// vector list deque

	// vector와 마찬가지로 배열 기반으로 동작
	// 다만 메모리 할당 정책이 다르다.
	
	// vector
	// [  기존 데이터    ] 
	// [  기존 데이터    ]   여유공간   ]


	vector<int> v(3, 1);
	deque<int> dq(3, 1);

	v.push_back(2);
	v.push_back(2);
	dq.push_back(2);
	dq.push_back(2);

	dq.push_front(3);
	dq.push_front(3);

	deque<int>::iterator;

	// _Size_type _Block = _Mycont->_Getblock(_Myoff);
	// _Size_type _Off = _Myoff % _Block_size;
	// return _Mycont->_Map[_Block][_Off];

	return 0;
}