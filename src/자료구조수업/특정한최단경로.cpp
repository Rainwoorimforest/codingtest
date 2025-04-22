#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 999

//���ͽ�Ʈ�� ������ ������ ����Ͽ� Ǯ���.

int N, M; //��� ����, ���� ����
vector<vector<int>> m; //�������
vector<long> dist; //�� ��� ���� ..
vector<bool> found;

//���� �̹湮�� ������ �� ���� ����� ���� ����
int chooseVertex() {
	int minpos = -1; //���
	long min = MAX; // ����ġ

	for (int i = 1; i <= N; i++)
	{
		if (!found[i] && dist[i] < min)
		{
			min = dist[i];
			minpos = i;
		}
	}
	return minpos;
}

void printDistance() {
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == MAX) cout << "INF" << " ";
		else cout << dist[i] << " ";
	}
	cout << endl;
}

void ShortestPath(int start) {
	for (int i = 1; i <= N; i++)
	{
		dist[i] = m[start][i];
		found[i] = false;
	}

	found[start] = true;
	dist[start] = 0;

	for (int i = 1; i <= N; i++)
	{
		int u = chooseVertex();
		if (u == -1) break;
		found[u] = true;

		for (int w = 1; w <= N; w++)
		{
			if (found[w] == false)
			{
				if (dist[w] > dist[u] + m[u][w])
					dist[w] = dist[u] + m[u][w];
			}
		}
	}
}

int main()
{
	int result;

	cin >> N >> M;

	m.resize(N + 1);
	dist.resize(N + 1);
	found.resize(N + 1);

	std::fill(dist.begin(), dist.end(), MAX);

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			m[i].push_back(MAX);
		}
	}

	for (int i = 0; i < M; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;
		m[s][e] = v;
		m[e][s] = v;
	}

	int dt1, dt2;
	cin >> dt1 >> dt2;

	ShortestPath(1);
	int to_dt1 = dist[dt1];
	int to_dt2 = dist[dt2];

	ShortestPath(dt1);
	int dt1_to_dt2 = dist[dt2];
	int dt1_to_N = dist[N];

	ShortestPath(dt2);
	int dt2_to_N = dist[N];

	result = min(MAX, to_dt1+dt1_to_dt2+dt2_to_N);
	result = min(result, to_dt2 + dt1_to_dt2 + dt1_to_N);

	if (result >= MAX)
		cout << -1;
	else
		cout << result;

	return 0;
}