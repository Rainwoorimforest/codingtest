/*
#include <iostream>

using namespace std;

int main()
{
	//int scores[5]; //������ ������ ä���� �������̸� �Ʒ��� ����
	int scores[5] = { 50, 60, 70, 80, 90 };

	int sz = sizeof(scores) / sizeof(int);  //sizeof(scores) : 4byte 5�� = 20 ��ȯ  sizeof(int) : 4��ȯ
	int s = 0; //���� ������ ���� s
	
	for (int i = 0; i < sz;  i++) {
		s += scores[i];
	}

	//�迭 ���� ��� ���ϱ�
	float m = (float)s / sz;

	cout << "Mean score: " << m << endl;

}
*/