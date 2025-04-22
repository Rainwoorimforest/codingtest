#include <iostream>
#include <queue>
#include <vector>


using namespace std;

#define MAX_VTX 100

vector<bool> visited;//bool visited[MAX_VTX]; 아님
vector<vector<int>> A;

void DFS(int v)
{
	

	if (visited[v]) return; //종결조건
	visited[v] = true;
	cout << v << " ";

	for (int i : A[v]) //int i
	{
		if (visited[i] == false)
		{
			DFS(i); //연결요소 DFS 판단 //DFS는 모든 노드 탐색 안할 수도 있나..?
		}
		
	}
	
}

void BFS(int v) {
	
	// 이 부분 없음

	queue<int> q;
	q.push(v);

	visited[v++]; //++

	while (!q.empty())
	{
		int id = q.front(); q.pop();
		cout << id << " ";
		for (int i : A[id]) //int i
		{
			if (visited[i] == -1) //false 아니고 -1 //visited[i]임 id아니고 i임
			{
				visited[i] = visited[i]+1;
				q.push(i); //bfs는 항상 que push 잊지말기
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	A.resize(N + 1);
	visited = vector<bool>(N + 1, false); //주의

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		A[s].push_back(e);
		A[e].push_back(s);
	}

	int count = 0; //연결 요소 카운트

	for (int i = 1; i < N; i++)
	{
		if (!visited[i]) {
			count++;
			DFS(i);
		}
	}

	cout << endl;
	cout << "cout: " << count << endl;

	return 0;
}
