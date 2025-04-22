#include <iostream>
#include <vector>
//#include <tuple>

using namespace std;

#define MAX 999

int N, M; //노드 개수, 에지 개수
vector<vector<long>> m; //2차원 인접행렬
vector<long> dist; //각 노드의 distance 배열
vector<bool> found; //방문유무 체크 배열

//미방문 정점 중 가장 비용이 적은 정점을 반환.
int chooseVertex() {
	long min = MAX; // 최소 가중치
	int minpos = -1; // 최소 가중치를 가지는 노드

	for (int i = 1; i <= N; i++) //모든 노드들에 대하여
	{	//집합 S에 속하지 않는 것 중에 비용이 최소인 것
		if (dist[i] < min && !found[i])
		{
			min = dist[i];
			minpos = i;
		}
	}
	return minpos;
}

//모든 정점들의 dist[]값 출력
void printDistance() {
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == MAX) cout << "INF" << " ";
		else cout << dist[i] << " ";
	}
	cout << endl;
}

void ShortestPath(int start) {
	//초기화
	for (int i = 1; i <= N; i++)
	{
		dist[i] = m[start][i];
		found[i] = false;
	}
	
	found[start] = true;
	dist[start] = 0;

	for (int i = 1; i <= N; i++)
	{
		printf("Step%2ld:", i + 1);
		printDistance();
		int u = chooseVertex();

		if (u == -1) break;
		found[u] = true;

		for (int w = 1; w <= N; w++)
		{
			if (found[w] == false)
			{
				if (dist[u] + m[u][w] < dist[w])
					dist[w] = dist[u] + m[u][w];
			}
		}
	}


}

int main() {
	cin >> N >> M;

	m.resize(N + 1);
	dist.resize(N + 1);
	found.resize(N + 1);

	//dist 배열 무한대로 초기화
	std::fill(dist.begin(), dist.end(), MAX);

	//인접행렬에 데이터 저장
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			m[j].push_back(MAX);
		}
	}

	//인접행렬에 에지 정보 읽어서 저장
	for (int i = 0; i < M; i++)
	{
		int start, end, value;
		cin >> start >> end >> value;
		m[start][end] = value;
	}

	//인접행렬 출력
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	ShortestPath(1);

	//출력
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == MAX) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}

