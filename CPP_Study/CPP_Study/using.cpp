#include <iostream>
using namespace std;
#include <vector>
#include <list>

// ������ ���� : using

typedef vector<int>::iterator VecIt;
typedef __int64 id;
using id2 = __int64;

// 1) ������
typedef void (*MyFunc)();
using MyFunc2 = void(*)();

// 2) ���ø�
template<typename T>
using List = std::list<T>;

/*
	template<typename T>
	typedef std::vector<T> List2;
	�Ұ���!.
*/

// using�� ������� �ʴ´ٸ�?
template<typename T>
struct List2
{
	typedef std::list<T> type;
};

int main()
{
	id playerId = 0;
	List<int> li;
	List2<int>::type li2;

	return 0;
}