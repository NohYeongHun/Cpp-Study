#include <iostream>
using namespace std;

class Base
{
public:
    // �����Լ� ���� �� �����Ǵ� ������ ������ ���
    // VirtualTable* __vptr; <= ���� ���̺��� ����Ű�� ������
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
    // �Ͻ��� ����ȯ
    Base* bPtr = &d1;
    // D1::Function1();
    bPtr->function1();

    D2 d2{};
    // �Ͻ��� ����ȯ
    bPtr = &d2;
    // D2::Function2();
    bPtr->function2();

    // ����� ����ȯ
    bPtr = (Base*)&d1;
    bPtr->function1();

    Base b1{};
    D1* dPtr = (D1*)&b1;
    dPtr->function1();

}