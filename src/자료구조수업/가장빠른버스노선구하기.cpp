#include <iostream>
#include <vector>

using namespace std;
#define MAX 999


vector<vector<int>> dist;

int main() {
	int N, M;//도시 개수, 노선 개수
	cin >> N;
	cin >> M;

	dist.resize(N+1);

	//인접행렬 초기화: 0과 INF로
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == j) dist[i].push_back(0); //초기화없이 0으로 넣으려고 해서오류가 생김.
			else dist[i].push_back(MAX);
		}
	}

	//버스 비용 고려한 인접행렬 초기화
	for (int i = 0; i < M; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;

		if(dist[s][e]>v)
			dist[s][e] = v;
	}

	//플루이드 알고리즘
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

	//정답 배열 출력하기
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
