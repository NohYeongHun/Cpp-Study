#include <iostream>
using namespace std;
#include<vector>
#include<deque>

// ������ ���� : deque

// vector : ���� �迭
// [     ]

// list : ���� ���� ����Ʈ
// [ ] <-> [ ] <-> [ ] <-> [ ]

// deque : double-ended queue ��ũ
// [       ]
// [       ]

int main()
{
	// ������ �����̳� (Sequence Container)
	// �����Ͱ� ���� ������� �����Ǵ� ����
	// vector list deque

	// vector�� ���������� �迭 ������� ����
	// �ٸ� �޸� �Ҵ� ��å�� �ٸ���.
	
	// vector
	// [  ���� ������    ] 
	// [  ���� ������    ]   ��������   ]


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