/*
#include <iostream>

using namespace std;


int main() {

	//int* ptr = new int[3] {};  중괄호를 미리 선언하여 가비지 데이터가 없음. int형의 기본형인 0이 저장. 즉 ptr[2] = 0
	int* ptr = new int[3]; //동적 할당한 메모리

	ptr[0] = 10;
	ptr[1] = 20;

	for (int i = 0; i < 3; i++)
		cout << ptr[i] << endl;

	delete[] ptr; //동적 할당한 메모리 해제
	ptr = nullptr; //포인터 변수 초기화
}
*/