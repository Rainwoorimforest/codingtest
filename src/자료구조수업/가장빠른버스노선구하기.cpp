#include <iostream>
#include <vector>

using namespace std;
#define MAX 999


vector<vector<int>> dist;

int main() {
	int N, M;//���� ����, �뼱 ����
	cin >> N;
	cin >> M;

	dist.resize(N+1);

	//������� �ʱ�ȭ: 0�� INF��
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == j) dist[i].push_back(0); //�ʱ�ȭ���� 0���� �������� �ؼ������� ����.
			else dist[i].push_back(MAX);
		}
	}

	//���� ��� ����� ������� �ʱ�ȭ
	for (int i = 0; i < M; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;

		if(dist[s][e]>v)
			dist[s][e] = v;
	}

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

	//���� �迭 ����ϱ�
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dist[i][j] == MAX) cout << "0" << " ";
			else cout << dist[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
