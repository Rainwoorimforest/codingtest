#include <iostream>
#include <vector>
#include <queue>

//��ū��: A(i)�� �����ʿ� �ִ� �� �߿��� ���ʺ��� ���� ���� ���̴� ��

using namespace std;

int main() {
	int N,compare;
	queue<int> q;

	cin >> N;
	//�Է¹ޱ�
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		q.push(a);
	}

	//��ū�� ���ϱ�
	/*
	�� ��: i
	
	*/
	for (int i = 0; i < N; i++)
	{
		compare = q.front();


	}

	return 0;
}