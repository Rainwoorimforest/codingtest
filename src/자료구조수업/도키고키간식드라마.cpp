#include<iostream>
#include<stack>
#include<queue>
#include<vector>

/*
�������� ��⿭ ������� ���� �������.

�Է� �޴� ��⿭��ȣ�� -> ť

1. ť -> ���� ������ζ�� ����
2. ť -> ���� ������ΰ� �ƴϸ� ������ ����
2-1. ����->���� 	���õ� ������ �Ǹ� pop�ؼ� ����


*/

using namespace std;

int main() {
	int N;
	int now = 1;
	bool flag = true;
	queue<int> q;
	stack<int> st;
	vector<int> v;

	cin >> N;

	//��⿭ �Է� �ޱ�
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		q.push(a);
	}

	//��⿭ ���� �̵�
	while(v.size()<=N)
	{
		if (!(st.empty()) || !(q.empty()))
		{
			//���� o, ť -> ����
			if (q.front() == now)
			{
				v.push_back(q.front());
				q.pop();

				now++;

			}

			//���� x, ť -> ����
			else
			{

				//������ �Ǹ� ���� -> ����
				if (st.top() == now)
				{
					v.push_back(st.top());
					st.pop();

					now++;
				}

				st.push(q.front());
				q.pop();
			
			}
		}
		
		
	}



	//���� �������� Ȯ��
	for (int i = 0; i < N; i++)
	{
		if (v[i] > v[i + 1])
		{
			flag = false;
			break;
		}
	}

	//���
	if (flag) { cout << "Nice" << endl; }
	else { cout << "Sad" << endl; }

	return 0;

}
