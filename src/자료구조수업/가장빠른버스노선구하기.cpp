#include <iostream>
#include <vector>

using namespace std;

#define MAX 999

vector<vector<int>> dist;

int main() {
	int n, m; //도시의 개수, 버스의 개수
	cin >> n;
	cin >> m;

	dist.resize(n + 1);

	//인접행렬 초기화
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
		if (dist[s][e] > v) dist[s][e] = v; //같은 경로에 중복 될때, 기존경로 > 새로 경로
	}

	//플로이드 알고리즘
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

	//출력
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
