/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//1. 비어있는 값 벡터.
	vector<int> v1; //int형 값을 저장할 수 있는 vector 클래스의 v1이라는 객체
					
					// using namespace std; 생략 시에는 다음과 같이 선언
					// std::vector<int> v1;
	

	//v1객체에 원소 추가
	v1.push_back(10); //v1[0]
	v1.push_back(20); //v1[1]
	v1.push_back(30); //v1[2]

	
	//2. 비어있는 값이 아니라 크기를 지정해놓기
	vector<int> v2(10); //v2[0] ~ v2[9] 원소가 있음. int 기본값 0으로 저장
	vector<int> v3(10,1); //v2[0] ~ v2[9] 원소가 있음. 대신 1로 채워져 있음.
	vector<int> v4 { 10, 20, 30, 40, 50 }; //vector<int> v4 = { 10, 20, 30, 40, 50 }; 와 동일

	//3.기존에 있는 벡터를 이용해서 새로운 벡터 만들기
	vector<int> v5 = v4; // v4를 깊은 복사. // vector<int> v5(v4);와 동일

	//3-1. 기존에 있는 벡터의 원소 몇개만 가져오기
	vector<int> v6(v4.begin(), v4.begin + 3);

	for (int i = 0; i < v6.size(); i++)
		cout << v6[i] << endl;






}
*/