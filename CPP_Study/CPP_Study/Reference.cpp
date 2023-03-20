#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 vs 참조

struct StatInfo
{
	int hp; // +0
	int attack; // +4
	int defence; // +8
};

// [매개변수][RET][지역변수(info)] [매개변수(&info)][RET][지역변수]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// 특정 조건을 만족하는 몬스터를 찾는 함수
StatInfo* FindMonster()
{
	// TODO : Heap 영역에서 뭔가를 찾아봄
	// 찾았다!
	// return monster-;
	return nullptr;
}


StatInfo globalInfo;
// [매개변수][RET][지역변수(info)][매개변수(&info)][RET][지역변수]
void PrintInfoByPtr(StatInfo* info)
{
	if (info == nullptr)
	{
		return;
	}

	cout << "-------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "-------------------" << endl;

	// 별 뒤에 붙인다면?
	// StatInfo* const info
	// info라는 바구니의 내용물(주소)를 바꿀 수 없음
	// info라는 주소값을 갖는 바구니 -> 이 주소값이 고정이다.

	// 별 이전에 붙인다면?
	// const StatInfo* info
	// info가 '가리키고 있는' 바구니의 내용물을 바꿀 수 없음
	// '원격' 바구니의 내용물을 바꿀 수 없음

	// 둘다 막고싶으면?
	// const StatInfo* const info
	// info[ 주소값 ]  === > 주소값 [ 데이터 ]
	//info = &globalinfo;
	//info->hp = 10000;
}


// 3) 참조 전달 방식
void PrintInfoByRef(StatInfo& info)
{
	cout << "-------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "-------------------" << endl;

	// 신입이 왔다.
	// info.hp = 10000; => 불가능.
}

// 바뀔수도 있다는 힌트 제공
#define OUT

void ChangeInfo(OUT StatInfo& info)
{

}


// StatInfo 구조체가 1000바이트짜리 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사되는
// - (주소 전달) StatInfo*는 8바이트
// - (참조 전달) StatInfo&는 8바이트

int main()
{
	StatInfo info;

	CreateMonster(&info);
	// 포인터 vs 참조 세기의 대결
	// 성능 : 똑같음!
	// 편의성 : 참조 승. `.` 연산자

	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만은 아니다.
	// 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있음.
	// 참조는 자연스럽게 모르고 지나칠 수도 있음!
	// ex) 마음대로 고친다면?
	// const를 사용해서 이런 마음대로 고치는 부분 개선 가능

	// 참고로 포인터도 const를 사용 가능
	// * 기준으로 앞에 붙이느냐, 뒤에 붙이느냐에 따라 의미가 달라짐.

	// 2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름(별칭?)
	// -> 참조하는 대상이 없으면 안됨
	// 반면 포인터는 그냥 어떤 주소라는 의미
	// -> 대상이 실존하지 않을 수도 있음
	// 포인터에서 '없다'는 의미로? == nullptr
	// 참조타입은 이런 nullptr이 없음.

	StatInfo* pointer = nullptr;
	pointer = &info;
	PrintInfoByPtr(pointer);

	StatInfo& reference = info;
	PrintInfoByRef(reference);

	// 그래서 결론은?
	// 사실 Team By Team... 정해진 답은 없다
	// ex) 구글에서 만든 오픈소스를 보면 거의 무조건 포인터 사용
	// ex) 언리얼 엔진에선 reference도 애용

	// 강의자의 선호 스타일
	// - 없는 경우도 고려해야 한다면 pointer (null 체크 필수)
	// - 바뀌지 않고 읽는 용도(readonly)만 사용하면 const ref&
	// - 그 외 일반적으로 ref (명시적으로 호출할 때 OUT을 붙인다)
	// -- 단, 다른 사람이 pointer로 만들어 놓았다면 참조를 섞어서 사용하진 않음.
	ChangeInfo(OUT info);

	// Bonus) 포인터로 사용하던걸 참조로 넘기는 법
	// pointer [ 주소(&info) ]  ref, info [ 데이터 ]
	StatInfo& ref = *pointer;
	PrintInfoByRef(*pointer);
	// Bonus) 참조로 사용하던걸 포인터로 넘기는 법
	// pointer [ 주소(&info) ]  reference, info [ 데이터 ]
	StatInfo* ptr = &reference;
	PrintInfoByPtr(&reference);

	return 0;
}