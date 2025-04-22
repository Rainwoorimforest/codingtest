#include <iostream>
#include <queue>
#include <vector>


using namespace std;

#define MAX_VTX 100

vector<bool> visited;//bool visited[MAX_VTX]; �ƴ�
vector<vector<int>> A;

void DFS(int v)
{
	

	if (visited[v]) return; //��������
	visited[v] = true;
	cout << v << " ";

	for (int i : A[v]) //int i
	{
		if (visited[i] == false)
		{
			DFS(i); //������ DFS �Ǵ� //DFS�� ��� ��� Ž�� ���� ���� �ֳ�..?
		}
		
	}
	
}

void BFS(int v) {
	
	// �� �κ� ����

	queue<int> q;
	q.push(v);

	visited[v++]; //++

	while (!q.empty())
	{
		int id = q.front(); q.pop();
		cout << id << " ";
		for (int i : A[id]) //int i
		{
			if (visited[i] == -1) //false �ƴϰ� -1 //visited[i]�� id�ƴϰ� i��
			{
				visited[i] = visited[i]+1;
				q.push(i); //bfs�� �׻� que push ��������
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	A.resize(N + 1);
	visited = vector<bool>(N + 1, false); //����

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		A[s].push_back(e);
		A[e].push_back(s);
	}

	int count = 0; //���� ��� ī��Ʈ

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
