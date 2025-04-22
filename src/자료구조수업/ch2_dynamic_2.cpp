/*
#include <iostream>

using namespace std;

class DynamicArray
{
private:
	unsigned int sz; //배열 사이즈를 받을 변수
	int* arr; //메모리 공간을 가리킬 포인터 변수 배열

public:
	DynamicArray(int n) : sz(n) { // 생성자로 동적 할당한 메모리 선언
		arr = new int[sz] {};
	}

	~DynamicArray() { delete[] arr; } // 소멸자로 동적 할당한 메모리 해제

	unsigned int size() { return sz; }

	int& operator[] (const int i) { return arr[i]; }
	const int& operator[] (const int i) const { return arr[i]; }
};

int main()
{
	DynamicArray da(5);
	da[0] = 10; 
	da[1] = 20;
	da[2] = 30;

	for (int i = 0; i < da.size(); i++)
		cout << da[i] << endl;
}

*/