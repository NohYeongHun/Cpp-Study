#include <iostream>
using namespace std;

// ������ ���� : ���м�

// ��ü���� (OOP Object Oriented Programming)
// - ��Ӽ�
// - ���м�
// - ������

// ���м� (Data Hiding) = ĸ��ȭ(Encapsulation)
// ���� �Ǵ� ���� ����ϰ� ����ڴ�.
// - 1) ���� �����ϰ� �ǵ帮�� �ȵǴ� ���
// - 2) �ٸ� ��η� �����ϱ� ���ϴ� ���

// �ڵ���
// - �ڵ�
// - ���
// - ����
// - ��
// - ���� ���⼱

// �Ϲ� ������ ���忡�� ����ϴ� ��?
// - �ڵ� / ��� / ��
// ���� �� (������ �ǵ帮�� ū�ϳ�)
// - ����, ���� ���⼱

// ���� ������ : public (������) protected (��ȣ�޴�) private (������)
// - public : �������׳� ����
// - protected : ���� �ڼյ鸸 ���.
// - private : ���� ����Ѵ�. << class Car ���ο�����.

class Car
{
public: //(���) ���� ������
	void MoveHandle() { }
	void PushPedal() { }
	void OpenDoor() { }

	void TurnKey()
	{
		// ...
		RunEngine();
	}

	// ������� �ش� ������ ������ ���������� �ؾ��ϴ��� �� ������
	// ���������� ������ �ξ�� ��.
private:
	void DisassembleCar() { } // ���� �����Ѵ�.
	void ConnectCircuit() { } // ���⼱ ����

protected:
	void RunEngine() { } // ������ ������Ų��.

public:
	// �ڵ�
	// ���
	// ����
	// ��
	// ���� ���⼱

};

class SuperCar : private Car // ��� ���� ������
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};


class TestSuperCar : public SuperCar
{

public:
	void Test()
	{
		// DisassembleCar(); �Ұ���
	}

};

// 'ĸ��ȭ'
// ������ �����Ϳ� �Լ��� �������� ������� ��

class Berserker
{
public:
	int GetHp() { return _hp; }
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}

private:
	// ��� : ü���� 50 ���Ϸ� �������� ����Ŀ ��� �ߵ� (������)
	void SetBerserkerMode()
	{
		cout << "�ſ� ������!" << endl;
	}
public:
	int _hp = 100;

};

int main()
{
	Berserker b;
	b.SetHp(50);

	Car car;

	// �ڵ��� ���� => 
	// car.DisassembleCar(); ��� �Ұ�
	// car.RunEngine(); ��� �Ұ�

	SuperCar superCar;
	superCar.PushRemoteController();
	return 0;
}