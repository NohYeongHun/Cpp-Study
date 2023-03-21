#include <iostream>
using namespace std;

// ������ ���� : �ζ� ��ȣ ������
void Swap(int& a, int& b);
void Sort(int numbers[], int size, bool reverse);
void quickSort(int numbers[], int l, int r);
void printArray(int numbers[], int size);
void ChooseLotto(int* numbers, int size);


void Swap(int& v1, int& v2)
{
	// �� �ֱ�.
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

	// left�� right���� ���������� �� �� ���� �ݺ�
	while (l <= r) {

		// pivot���� ū ���� �����ų� pivot�� �����ų�.
		while (numbers[l] < pivot)
		{
			l++;
		}

		// pivot���� ���� ���� �����ų� pivot�� �����ų�
		while (numbers[r] > pivot)
		{
			r--;
		}
		// left�� right���� �۰ų� �������� swap�� �̵�
		if (l <= r)
		{
			// r�� l �� ����
			Swap(numbers[r], numbers[l]);

			// ���� ���� left ������ ��ĭ, right ���� ��ĭ �̵�
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
	
	// 1000 : �������� 1 ~ 45 ������ ���� 6���� ����ּ���! (��, �ߺ��� �������)
	for(int cnt = 0; cnt < 6;)
	{
		int val = 1 + rand() % 45;
		bool isDuple = false;
		// �ߺ� üũ
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
	// 1) Swap �Լ� �����
	int a = 1;
	int b = 2;
	Swap(a, b);
	
	// 2) ���� �Լ� ����� (���� ���ڰ� ���� ������ ����)
	int numbers[6] = { 5, 1, 6, 3, 4, 2};
	// �������� ����
	Sort(numbers, sizeof(numbers) / sizeof(int), false);
	printArray(numbers, sizeof(numbers) / sizeof(int));
	// �������� ����
	Sort(numbers, sizeof(numbers) / sizeof(int), true);
	printArray(numbers, sizeof(numbers) / sizeof(int));

	// 3) �ζ� ��ȣ ������
	int arr[6] = { };
	ChooseLotto(arr, sizeof(arr) / sizeof(*arr) );


}

