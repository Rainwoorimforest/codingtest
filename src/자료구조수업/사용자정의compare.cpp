#include<iostream>
#include<vector>
#include<queue>
#include<cmath> //abs()�����Լ��� ���� ���̺귯��

using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{	
		//b�� �񱳿���
		//true -> �ڸ��ٲ�. false -> �״��. upheap ����
		//������� ���� �����ϰ�, 
		if (abs(a) == abs(b)) return a > b; //��������
		else return abs(a) > abs(b);
	}
};

int main() {
	int N;
	int i = 0;
	vector<int> v;

	cin >> N;

	priority_queue<int, vector<int>, compare> pq;

	while (i < N)
	{
		int a;
		cin >> a;
		
		if (a == 0) //������ ���� ���� �� ��� �� ����
		{
			if (!(pq.empty()))
			{
				v.push_back(pq.top());
				pq.pop();

				i++;
				continue;
			}
			v.push_back(0);
		}
		else if (a != 0) // pq�� ���Կ���
		{
			pq.push(a);
		}
		i++;
	}

	//����ϱ�
	cout << "���: " << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}


