#include <iostream>
#include <fstream>
//#include "Car.h"
//#include "Road.h"
using namespace std;

// �ٸ� ��ü�� �����ǵ� ������ �ʴ� ������ ����
// �ӵ��� 10�� �þ��, ����� 2�� �پ���. �ִ� �ӵ� 200


#define ID_LEN	20
#define ACC_STEP 10
#define FUEL_STEP 2
#define MAX_SPD 200
#define BRK_STEP 10
// define �� ������ ������� namespace�� ����ϴ� ����� �ִ�.
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
	void Accel(); // 1.���� �Լ� 
	void Power(); // 2.�ް��� �Լ� 
	void Break(); // 3.���� �Լ� 
	void Curve(); // 4.Ŀ�� �Լ� 
	void Slow(); //  5.�����Լ� 


};

void Car::InitMembers(const char* ID, int fuel)
{
	strcpy_s(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0; // ó������ �� ������ ���·� ���α׷��� ����ϴ�.
}

void Car::ShowCarState()
{
	cout << "������id: " << gamerID << endl;
	cout << "���ᷮ: " << fuelGauge << "%" << endl;
	cout << "����ӵ�: " << curSpeed << " km/h" << endl;
}

void Car::Accel()
{
	// ���ᰡ ���� ���, ���� ��� 
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= FUEL_STEP;

	// �ӵ� �ִ�ġ
	if ((curSpeed + ACC_STEP) >= MAX_SPD)
	{
		curSpeed = MAX_SPD;
	}
	curSpeed += ACC_STEP; //ACC_STEP�� 10
}

void Car::Power()
{
	//����
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= 5;

	//�ӵ�
	if ((curSpeed + 20) >= MAX_SPD)
	{
		curSpeed = MAX_SPD;
	}
	curSpeed += 20;

}

// �����ϴ� �Լ� ����
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

	//����
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= 1;

	//�ӵ�
	/*if ((curSpeed + ACC_STEP) >= MAX_SPD)
	{
		curSpeed = MAX_SPD;
	}*/

	curSpeed -= 5;


}

void Car::Slow()
{
	//����
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= 1;


	//�ӵ�
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
	run99.InitMembers("�ſ츲", 100); 	// run99 ��� ��ü ������� �ʱⰪ�� ������ �ݴϴ�.
	

	// ù�ð��� ��� switch �̿��ؼ�
	// 1�� �Է��ϸ� ����, 2�� �Է��ϸ� break �ϴ� ���·ε� ������ �� �ֽ��ϴ�.

	// #include <fstream> !!! �̰� ��������.
	// file1.inn�� ���� �۾����� cpp ������ �ִ� ���� ��ġ��ŵ�ϴ�. 
	// �ٸ� ���� ���� ��� ifstream���� �ּұ��� �Բ� �� �ּ���.
	// file1.inn �� �н��ϴ�.
	// 5 10
	// 15 20 25
	ifstream test1("car_history.inn"); //10��,..
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
	arr[9] = j;  //����: ���Ͽ��� ���� ���ڸ� ���������� �ٲ� switch������ ����� ����� �𸣰���.

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
	// ifstream���� �ؽ���Ʋ �о ��������
	// ������ ������ �ȴ�. �ٹٲ��� ������ �ȴ�.

	// ���� switch ���� �����ؼ� �ܼ�â���� �Է��� �޴� �� ����, 
	// file.inn �� ���� �ִ� ������ �̿��ؼ� ���α׷��� ������ �� �ֽ��ϴ�.

	return 0;
}
