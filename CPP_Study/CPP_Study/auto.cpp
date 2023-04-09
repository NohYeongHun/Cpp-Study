#include <iostream>
using namespace std;
#include<vector>
#include<map>

// 오늘의 주제 : auto

class Knight
{
public:
	int _ho;
};

template<typename T>
void Print(T t)
{
	cout << t << endl;
}


int main()
{
	// Modern C++ (C++ 11)

	auto a = 3;
	auto b = 3.14f;
	auto c = 1.23;
	auto d = Knight();
	auto e = "rookiss";

	// auto는 일종의 조커카드
	// 형식 영역 (type deduction)
	// -> 말이 되게 잘 맞춰봐 ~ (추론)
	// 추론 규칙은 생각보다 복잡해질 수 있다.

	auto f = &d;
	const auto test1 = b;
	auto* test2 = e;

	// 주의 !
	// 기본 auto는 const, & 무시.
	int& reference = a;
	const int cst = a;

	// int, int 로 반환됨.
	auto test1 = reference;
	auto test2 = cst;

	// 주의점.
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
	{
		// 참조 형태를 유지할 거라면? => &를 붙여준다.
		auto& data = v[i];
		data = 100;
	}

	// auto 만 사용하는 것은 비추천
	// -> 타이핑이 길어지는 경우 OK
	// -> 가독성을 위해 일반적으로 놔두기

	// 일반적으로 auto를 사용하는 경우
	map<int, int> m;
	auto ok = m.insert(make_pair(1, 100));
	
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}