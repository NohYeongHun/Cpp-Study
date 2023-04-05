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

	// �������� ������(�ڱ� �ڽ�)�� ��ȯ
	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}

	// �������� ���簪�� ��ȯ
	Iterator operator++(int)
	{
		Iterator temp = *this;
		_ptr++;
		return temp;
	}

	// �������� ������(�ڱ� �ڽ�)�� ��ȯ
	Iterator& operator--()
	{
		_ptr--;
		return *this;
	}

	// �������� ���簪�� ��ȯ
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
		// ���� operator== ȣ��.
		return !(*this == right);
	}

	// ������ ��ȯ
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
		// ���빰�� ����
		if (_size == _capacity)
		{
			// ���� �۾�
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;
			reserve(newCapacity);
		}

		// ������ ����
		_data[_size] = val;

		// ������ ���� ����
		_size++;
	}

	void reserve(int capacity)
	{
		_capacity = capacity;
		T* newData = new T[_capacity];

		// ������ ����
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		// ���� ������ ����
		if (_data != nullptr)
			delete[] _data;

		// �����͸� ���ο� ���� ���� �ּҷ� �ʱ�ȭ�Ѵ�.
		_data = newData;
	}

	// [] ������ �����ε�
	// &�� �ִ� ������ _data ��ü�� �������� ��ȯ�� ���̱� ����
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

	// ��� �����͸� ������ capacity�� ����.
	v.clear();

	return 0;
}