#include <iostream>
#include <vector>

using namespace std;

#define MAX 999

vector<vector<int>> dist;

int main() {
	int n, m; //������ ����, ������ ����
	cin >> n;
	cin >> m;

	dist.resize(n + 1);

	//������� �ʱ�ȭ
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == j) dist[i].push_back(0); // dist[i][j] = 0;
			else dist[i].push_back(MAX); // dist[i][j] = MAX;
		}
	}

	//setup Edges
	for (int i = 0; i < m; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;

		//dist[s][e] = v;
		if (dist[s][e] > v) dist[s][e] = v; //���� ��ο� �ߺ� �ɶ�, ������� > ���� ���
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
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == MAX) cout << "0";
			else cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}
