/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//1. ����ִ� �� ����.
	vector<int> v1; //int�� ���� ������ �� �ִ� vector Ŭ������ v1�̶�� ��ü
					
					// using namespace std; ���� �ÿ��� ������ ���� ����
					// std::vector<int> v1;
	

	//v1��ü�� ���� �߰�
	v1.push_back(10); //v1[0]
	v1.push_back(20); //v1[1]
	v1.push_back(30); //v1[2]

	
	//2. ����ִ� ���� �ƴ϶� ũ�⸦ �����س���
	vector<int> v2(10); //v2[0] ~ v2[9] ���Ұ� ����. int �⺻�� 0���� ����
	vector<int> v3(10,1); //v2[0] ~ v2[9] ���Ұ� ����. ��� 1�� ä���� ����.
	vector<int> v4 { 10, 20, 30, 40, 50 }; //vector<int> v4 = { 10, 20, 30, 40, 50 }; �� ����

	//3.������ �ִ� ���͸� �̿��ؼ� ���ο� ���� �����
	vector<int> v5 = v4; // v4�� ���� ����. // vector<int> v5(v4);�� ����

	//3-1. ������ �ִ� ������ ���� ��� ��������
	vector<int> v6(v4.begin(), v4.begin + 3);

	for (int i = 0; i < v6.size(); i++)
		cout << v6[i] << endl;






}
*/