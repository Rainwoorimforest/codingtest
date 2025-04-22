/*
#include <iostream>

using namespace std;

int main()
{
	//int scores[5]; //가비지 값으로 채워짐 가급적이면 아래로 정의
	int scores[5] = { 50, 60, 70, 80, 90 };

	int sz = sizeof(scores) / sizeof(int);  //sizeof(scores) : 4byte 5개 = 20 반환  sizeof(int) : 4반환
	int s = 0; //합을 저장할 변수 s
	
	for (int i = 0; i < sz;  i++) {
		s += scores[i];
	}

	//배열 원소 평균 구하기
	float m = (float)s / sz;

	cout << "Mean score: " << m << endl;

}
*/