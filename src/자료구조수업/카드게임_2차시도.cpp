#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N;
	bool flag=true;
	queue<int> q;

	cin >> N;

	//ť�� �Է�
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	//����
	while (q.size() != 1)
	{
		if (!(q.empty()))
		{
			//�� ���� ������
			q.pop();
			//���� -> �� �� ����

			int a;
			a = q.front();
			q.pop();
			q.push(a);
		}
	}

	//���
	cout << q.front() << endl;

	return 0;
}