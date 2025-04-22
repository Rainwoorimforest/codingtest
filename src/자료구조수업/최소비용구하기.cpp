#include <iostream>
#include <vector>

using namespace std;

#define MAX 999

vector<vector<int>> dist; //int long

int main() {
	int n, m; //���� ����, ���� ����
	cin >> n;
	cin >> m;

	//���� �ʱ�ȭ //dist[i]�ϱ� �� ������ �ʱ�ȭ �ؾ���. push_back�� ������..
	dist.resize(n + 1);

	//�ʱ�ȭ
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == j) dist[i].push_back(0);
			else dist[i].push_back(MAX);
		}
	}

	//setup edge
	for (int j = 1; j <= m; j++)
	{
		int s, e, v;
		cin >> s >> e >> v;
		if (dist[s][e] > v) dist[s][e] = v;
	}

	//�÷��̵� �˰��� 
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	//���
	int start, end;
	cin >> start >> end;

	cout << dist[start][end];



}


