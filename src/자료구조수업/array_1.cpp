#include <iostream>

using namespace std;

class DynamicArray
{
private:
	unsigned int sz; //배열 사이즈를 받을 변수
	int* arr; //메모리 공간을 가리킬 포인터 변수 배열

public:
	DynamicArray(int n) : sz(n) { // 생성자로 동적 할당한 메모리 선언
		arr = new int[sz] {}; // {}으로 비어있는 값이 가비지 값이 아닌 0으로 채움.
	}

	~DynamicArray() { delete[] arr; } // 소멸자로 동적 할당한 메모리 해제

	unsigned int size() { return sz; }

	int& operator[] (const int i) { return arr[i]; }
	const int& operator[] (const int i) const { return arr[i]; }
};

int main()
{
	int num, v;
	int count = 0;
	
	cin >> num; 

	DynamicArray da(num); //da라는 객체 생성 인수로 5를 넘겨줌.

	//배열에 num개의 정수 채우기
	for (int i = 0; i < da.size(); i++) {
		int a;
		cin >> a;
		da[i] = a;
	}

	cin >> v;
	//정수 v 찾기
	for (int i = 0; i < da.size(); i++) {
		if (da[i] == v)
			count++;
	}

	cout << count;
}