#include <iostream>
using namespace std;

template<typename T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr)
	{

	}

	Iterator(T* ptr) : _ptr(ptr)
	{

	}

	// 전위형은 참조값(자기 자신)을 반환
	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}

	// 후위형은 복사값을 반환
	Iterator operator++(int)
	{
		Iterator temp = *this;
		_ptr++;
		return temp;
	}

	// 전위형은 참조값(자기 자신)을 반환
	Iterator& operator--()
	{
		_ptr--;
		return *this;
	}

	// 후위형은 복사값을 반환
	Iterator operator--(int)
	{
		Iterator temp = *this;
		_ptr--;
		return temp;
	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	bool operator==(const Iterator& right)
	{
		return _ptr == right._ptr;
	}

	bool operator!=(const Iterator& right)
	{
		// 위의 operator== 호출.
		return !(*this == right);
	}

	// 참조값 반환
	T& operator*()
	{
		return *_ptr;
	}

public:
	T* _ptr;
};

template<typename T>
class Vector
{
public:
	Vector() : _data(nullptr), _capacity(0), _size(0)
	{

	}

	~Vector()
	{
		if (_data != nullptr)
			delete[] _data;
	}

	// [          ]
	void push_back(const T& val)
	{
		// 내용물이 꽉참
		if (_size == _capacity)
		{
			// 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;
			reserve(newCapacity);
		}

		// 데이터 저장
		_data[_size] = val;

		// 데이터 개수 증가
		_size++;
	}

	void reserve(int capacity)
	{
		_capacity = capacity;
		T* newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		// 기존 데이터 삭제
		if (_data != nullptr)
			delete[] _data;

		// 포인터를 새로운 값에 대한 주소로 초기화한다.
		_data = newData;
	}

	// [] 연산자 오버로딩
	// &를 넣는 이유는 _data 객체의 참조값을 반환할 것이기 때문
	T& operator[](const int pos) { return _data[pos]; }
	int size() { return _size; }
	int capacity() { return _capacity; }

public:
	typedef Iterator<T> iterator;

	void clear() { _size = 0; }
	iterator begin() { return iterator(&_data[0]); }
	iterator end() { return begin() + _size; }

private:
	int _size;
	int _capacity;
	T* _data;


};

int main()
{
	Vector<int> v;

	v.reserve(100);
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << "------------" << endl;
	for (Vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << endl;
	}

	// 모든 데이터를 날리되 capacity는 유지.
	v.clear();

	return 0;
}