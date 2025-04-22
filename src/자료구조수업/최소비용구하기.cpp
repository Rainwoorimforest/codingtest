
#include<iostream>
#include<vector>

using namespace std;

#define MAX 999

int N, M;//���� ����, �����뼱 ����
vector<vector<int>> dist;

//�������� �־����� -> ���ͽ�Ʈ�� �˰������� Ǯ� �ȴ�.
int main() {

	int start, end;

	cin >> N;
	cin >> M;
	dist.resize(N + 1);

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == j) dist[i].push_back(0);
			else dist[i].push_back(MAX);
		}
	}

	for (int i = 0; i < M; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;

		if (dist[s][e] > v) dist[s][e] = v;
	}

	cin >> start >> end;

	//�÷��̵� �˰���
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}


	cout << dist[start][end];

}
