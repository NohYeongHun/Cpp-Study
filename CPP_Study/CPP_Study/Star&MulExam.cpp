#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	// �����)
	// �������� � ������ �Է��ϸ�
	// N * N���� ���� ������� ���ھ��!
	int input;
	cin >> input;
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {
			cout << "*";
		}
		cout << endl;
	}
	
	cout << endl;
	// �����2)
	// ��.. �׳� N*N�� ���� �����ϱ� �ʹ� �ɽ��ϴ�.
	// 1������ �����ؼ� ���������� �ٸ��� �����ϰ� �������ּ���!
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << '*';
		}
		cout << endl;
	}

	cout << endl;
	// �����3)
	// ����� ���� �����Ǿ��µ�
	// N������ �����ؼ� �ٸ��� 1���� �پ��� ���·�?
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input - i; j++) {
			cout << '*';
		}
		cout << endl;
	}

	// ������)
	// 2*1 = 2
	// 2�ܺ��� 9�ܱ���
	for (int i = 2; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			
			cout << i << " x " << j << " = " << setw(2) << i * j << " ";
		}
		cout << endl;
	}
}