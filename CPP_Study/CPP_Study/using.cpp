#include <iostream>
using namespace std;
#include <vector>
#include <list>

// 오늘의 주제 : using

typedef vector<int>::iterator VecIt;
typedef __int64 id;
using id2 = __int64;

// 1) 직관성
typedef void (*MyFunc)();
using MyFunc2 = void(*)();

// 2) 템플릿
template<typename T>
using List = std::list<T>;

/*
	template<typename T>
	typedef std::vector<T> List2;
	불가능!.
*/

// using을 사용하지 않는다면?
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