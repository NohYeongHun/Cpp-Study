#include <iostream>
using namespace std;

class Base
{
public:
    // 가상함수 생성 시 생성되는 숨겨진 포인터 멤버
    // VirtualTable* __vptr; <= 가상 테이블을 가리키는 포인터
    virtual void function1() { cout << "Base Function1()" << endl; };
    virtual void function2() { cout << "Base Function2()" << endl; };
};

class D1 : public Base
{
public:
    void function1() override { cout << "D1 Function1()" << endl; };
};

class D2 : public Base
{
public:
    void function2() override { cout << "D2 Function1()" << endl; };
};

int main()
{
    D1 d1 {};
    // 암시적 형변환
    Base* bPtr = &d1;
    // D1::Function1();
    bPtr->function1();

    D2 d2{};
    // 암시적 형변환
    bPtr = &d2;
    // D2::Function2();
    bPtr->function2();

    // 명시적 형변환
    bPtr = (Base*)&d1;
    bPtr->function1();

    Base b1{};
    D1* dPtr = (D1*)&b1;
    dPtr->function1();

}