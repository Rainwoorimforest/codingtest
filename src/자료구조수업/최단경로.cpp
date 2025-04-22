#include <iostream>
#include <vector>

using namespace std;

#define MAX 9999

int N, M,K; //노드 개수, 에지 개수
vector<vector<long>> m; //인접행렬
vector<long> dist;
vector<bool> found;


//가장 비용이 적은 미방문 정점 반환
int chooseVertex() {
	int min = MAX; //가중치가 가장 적은 것이 무엇인지 - 가중치
	int minpos = -1; //가중치가 가장 작은 노드가 무엇인지 - 노드

	for (int i = 1; i <= N; i++) //다익스트라는 i가 1부터 시작!! 
	{
		if (dist[i] < min && !found[i])
		{
			min = dist[i];
			minpos = i;
		}
	}

	return minpos;
}

void printDistance() { // dist[] 출력
	for (int i = 1; i <= N; i++) //i는1부터 시작
	{
		if (dist[i] == MAX) cout << "INF" << " ";
		else cout << dist[i] << " ";
	}
	cout << endl;
}

void ShortestPath(int start)
{
	for (int i = 1; i <= N; i++) //초기화
	{
		dist[i] = m[start][i];
		found[i] = false;
	}

	found[start] = true;
	dist[start] = 0;

	for (int i = 1; i <= N; i++)
	{
		//printf("Setp%ld: ", i + 1);
		//printDistance();
		int u = chooseVertex();
		if (u == -1) break;

		for (int w = 1; w <= N; w++)
		{
			if (found[w] == false)
			{
				if (dist[w] > dist[u] + m[u][w]) //거쳐가는 것보다 직빵이 느릴때
					dist[w] = dist[u] + m[u][w];
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	cin >> K;
	m.resize(N + 1); //N 아니고 N+1
	dist.resize(N + 1);
	found.resize(N + 1);

	//dist 배열 무한대로 초기화
	std::fill(dist.begin(), dist.end(), MAX);

	//인접 행렬에 데이터 저장
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			m[i].push_back(MAX);
		}
	}

	//인접행렬에 에지 정보 읽어서 저장
	for (int i = 0; i < M; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;
		m[s][e] = v;
	}


	//다익스트라 알고리즘 (그 전에 필요한 것. 1. 인접행렬 m 초기화 및 값 채워넣기)
	ShortestPath(K);

	//출력
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == MAX) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}

	return 0;




}
