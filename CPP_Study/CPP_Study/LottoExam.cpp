#include <iostream>
using namespace std;

// 오늘의 주제 : 로또 번호 생성기
void Swap(int& a, int& b);
void Sort(int numbers[], int size, bool reverse);
void quickSort(int numbers[], int l, int r);
void printArray(int numbers[], int size);
void ChooseLotto(int* numbers, int size);


void Swap(int& v1, int& v2)
{
	// 값 넣기.
	int temp = v1;
	v1 = v2;
	v2 = temp;

}

void Sort(int numbers[], int size, bool reverse)
{
	if (reverse) {
		for (int i = 0; i < size; i++)
		{
			numbers[i] *= -1;
		}
		quickSort(numbers, 0, size - 1);
		for (int i = 0; i < size; i++)
		{
			numbers[i] *= -1;
		}
	}
	else {
		quickSort(numbers, 0, size - 1);
	}
}

void quickSort(int numbers[], int l, int r) {
	
	int L = l;
	int R = r;
	int pivot = numbers[(L + R) / 2];

	// left가 right보다 오른쪽으로 올 떄 까지 반복
	while (l <= r) {

		// pivot보다 큰 수를 만나거나 pivot과 만나거나.
		while (numbers[l] < pivot)
		{
			l++;
		}

		// pivot보다 작은 수를 만나거나 pivot과 만나거나
		while (numbers[r] > pivot)
		{
			r--;
		}
		// left가 right보다 작거나 같을때만 swap후 이동
		if (l <= r)
		{
			// r과 l 값 변경
			Swap(numbers[r], numbers[l]);

			// 이후 값을 left 오른쪽 한칸, right 왼쪽 한칸 이동
			l++;
			r--;
		}
		
	}

	if (L < r) quickSort(numbers, L, r);
	if (l < R) quickSort(numbers, l, R);
}

void printArray(int numbers[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
}

void ChooseLotto(int* numbers, int size)
{
	
	// 1000 : 랜덤으로 1 ~ 45 사이의 숫자 6개를 골라주세요! (단, 중복이 없어야함)
	for(int cnt = 0; cnt < 6;)
	{
		int val = 1 + rand() % 45;
		bool isDuple = false;
		// 중복 체크
		for (int i = 0; i < cnt + 1; i++) {
			if (numbers[i] == val) {
				isDuple = true;
				break;
			}
		}

		if (isDuple) continue;
		else {
			numbers[cnt] = val;
			cnt++;
		}
	}

	Sort(numbers, size, false);
	printArray(numbers, size);

}

int main()
{
	srand((unsigned)time(0));
	// 1) Swap 함수 만들기
	int a = 1;
	int b = 2;
	Swap(a, b);
	
	// 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
	int numbers[6] = { 5, 1, 6, 3, 4, 2};
	// 오름차순 정렬
	Sort(numbers, sizeof(numbers) / sizeof(int), false);
	printArray(numbers, sizeof(numbers) / sizeof(int));
	// 내림차순 정렬
	Sort(numbers, sizeof(numbers) / sizeof(int), true);
	printArray(numbers, sizeof(numbers) / sizeof(int));

	// 3) 로또 번호 생성기
	int arr[6] = { };
	ChooseLotto(arr, sizeof(arr) / sizeof(*arr) );


}

