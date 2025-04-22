#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_VTX 100

vector<vector<int>> A; //인접리스트
vector<int> visited;
void DFS(int a);
void BFS(int a);

int main() {
	int N, M, V;
	cin >> N >> M >> V;

	A.resize(N + 1); //인접 리스트는 노드의 개수+1 만큼 초기화
	visited = vector<int>(N + 1, 0); //나중에 BFS 사용해야 해서 bool형 아니고 int형

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		A[s].push_back(e); //무방향 그래프
		A[e].push_back(s);
	}

	//여러개 연결되어 있으면 가장 작은 노드 먼저 방문하라는 조건
	for (int i = 1; i <= N; i++)
	{
		sort(A[i].begin(), A[i].end()); //왜지...?????
	}

	DFS(V); cout << endl;
	visited = vector<int>(N + 1, -1); //배열 초기화
	BFS(V); cout << "긑" << endl;

	return 0;
}

	void DFS(int v) 
	{
		if (visited[v]) return; //종결조건
		visited[v] = true;
		cout << v << " ";

		for (int i : A[v])
		{
			if (visited[i] == false)
			{
				//cout << "DFS visited[i]: false::::"<<visited[i] << endl; //0
				DFS(i);
			}
		}
	}

	void BFS(int v) {
		queue<int> q;
		q.push(v);

		visited[v]++; //visited가 bool이 아니고 int일때는 [v]++ !!!!!!!!!!!!!!!!!!!!!!!!!!!

		while (!q.empty())
		{
			int id = q.front(); q.pop();
			cout << id << " ";

			for (int i : A[id])
			{
				if (visited[i] == -1)
				{
					visited[i] = visited[id] + 1;
					q.push(i);
				}
			}
		}
		
	}

