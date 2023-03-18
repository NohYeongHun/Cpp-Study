#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	// 별찍기)
	// 유저들이 어떤 정수를 입력하면
	// N * N개의 별을 찍었으면 좋겠어요!
	int input;
	cin >> input;
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {
			cout << "*";
		}
		cout << endl;
	}
	
	cout << endl;
	// 별찍기2)
	// 음.. 그냥 N*N개 별을 찍으니까 너무 심심하다.
	// 1개부터 시작해서 순차적으로 줄마다 증가하게 수정해주세요!
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << '*';
		}
		cout << endl;
	}

	cout << endl;
	// 별찍기3)
	// 모양이 많이 개선되었는데
	// N개부터 시작해서 줄마다 1개씩 줄어드는 형태로?
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input - i; j++) {
			cout << '*';
		}
		cout << endl;
	}

	// 구구단)
	// 2*1 = 2
	// 2단부터 9단까지
	for (int i = 2; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			
			cout << i << " x " << j << " = " << setw(2) << i * j << " ";
		}
		cout << endl;
	}
}