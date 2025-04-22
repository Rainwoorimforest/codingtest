#include <iostream>
#include <fstream>
//#include "Car.h"
//#include "Road.h"
using namespace std;

// 다른 객체가 생성되도 변하지 않는 값들을 정의
// 속도는 10씩 늘어나야, 연료는 2씩 줄어든다. 최대 속도 200


#define ID_LEN	20
#define ACC_STEP 10
#define FUEL_STEP 2
#define MAX_SPD 200
#define BRK_STEP 10
// define 할 내용이 길어지면 namespace를 사용하는 방법도 있다.
//nampespace ##
//{
//	enum { ACC_STEP = 10, ...};
//}


class Car
{
private:
	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(const char* ID, int fuel);
	void ShowCarState(); 
	void Accel(); // 1.가속 함수 
	void Power(); // 2.급가속 함수 
	void Break(); // 3.정지 함수 
	void Curve(); // 4.커브 함수 
	void Slow(); //  5.감속함수 


};

void Car::InitMembers(const char* ID, int fuel)
{
	strcpy_s(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0; // 처음에는 다 정지한 상태로 프로그램을 만듭니다.
}

void Car::ShowCarState()
{
	cout << "소유자id: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << " km/h" << endl;
}

void Car::Accel()
{
	// 연료가 있을 경우, 없을 경우 
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= FUEL_STEP;

	// 속도 최대치
	if ((curSpeed + ACC_STEP) >= MAX_SPD)
	{
		curSpeed = MAX_SPD;
	}
	curSpeed += ACC_STEP; //ACC_STEP은 10
}

void Car::Power()
{
	//연료
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= 5;

	//속도
	if ((curSpeed + 20) >= MAX_SPD)
	{
		curSpeed = MAX_SPD;
	}
	curSpeed += 20;

}

// 정지하는 함수 구현
void Car::Break()
{
	if (curSpeed < BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= BRK_STEP;
}

void Car::Curve()
{

	//연료
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= 1;

	//속도
	/*if ((curSpeed + ACC_STEP) >= MAX_SPD)
	{
		curSpeed = MAX_SPD;
	}*/

	curSpeed -= 5;


}

void Car::Slow()
{
	//연료
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= 1;


	//속도
	if (curSpeed < 10)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= 10;




}


int main(void)
{
	int arr[10];
	Car run99;
	run99.InitMembers("신우림", 100); 	// run99 라는 객체 멤버들의 초기값을 설정해 줍니다.
	

	// 첫시간에 배운 switch 이용해서
	// 1을 입력하면 엑셀, 2를 입력하면 break 하는 형태로도 변경할 수 있습니다.

	// #include <fstream> !!! 이걸 넣으세요.
	// file1.inn을 현재 작업중인 cpp 파일이 있는 곳에 위치시킵니다. 
	// 다른 곳에 넣을 경우 ifstream에서 주소까지 함께 써 주세요.
	// file1.inn 을 읽습니다.
	// 5 10
	// 15 20 25
	ifstream test1("car_history.inn"); //10줄,..
	int a, b, c, d, e, f, g, h, i, j;
	test1 >> a;
	test1 >> b;
	test1 >> c;
	test1 >> d;
	test1 >> e;
	test1 >> f;
	test1 >> g;
	test1 >> h;
	test1 >> i;
	test1 >> j;

	
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;
	arr[4] = e;
	arr[5] = f;
	arr[6] = g;
	arr[7] = h;
	arr[8] = i;
	arr[9] = j;  //질문: 파일에서 읽은 문자를 정수형으로 바꿔 switch문으로 만드는 방법을 모르겠음.

	for (int i = 0; i < 10; i++)
	{

		switch (arr[i])
		{
		case 1: run99.Accel();
			break;
		case 2: run99.Power();
			break;
		case 3: run99.Break();
			break;
		case 4: run99.Curve();
			break;
		case 5: run99.Slow();
			break;
		default:
			break;
		}

	}

	run99.ShowCarState();
	// ifstream으로 텍스르틀 읽어서 가져오면
	// 공백이 구별이 된다. 줄바꿈이 구별이 된다.

	// 윗쪽 switch 에서 구별해서 콘솔창으로 입력을 받는 것 말고, 
	// file.inn 에 적혀 있는 값들을 이용해서 프로그램을 구동할 수 있습니다.

	return 0;
}
