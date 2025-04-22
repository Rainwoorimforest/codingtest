#include <iostream>
#include <vector>

using namespace std;

#define MAX 999

vector<vector<int>> dist; //int long

int main() {
	int n, m; //도시 개슈, 버스 개수
	cin >> n;
	cin >> m;

	//벡터 초기화 //dist[i]니까 꼭 사이즈 초기화 해야함. push_back이 있지만..
	dist.resize(n + 1);

	//초기화
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
	int start, end;
	cin >> start >> end;

	cout << dist[start][end];



}


