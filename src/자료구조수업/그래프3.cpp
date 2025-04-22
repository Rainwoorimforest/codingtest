#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_VTX 100

vector<vector<int>> A; //��������Ʈ
vector<int> visited;
void DFS(int a);
void BFS(int a);

int main() {
	int N, M, V;
	cin >> N >> M >> V;

	A.resize(N + 1); //���� ����Ʈ�� ����� ����+1 ��ŭ �ʱ�ȭ
	visited = vector<int>(N + 1, 0); //���߿� BFS ����ؾ� �ؼ� bool�� �ƴϰ� int��

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		A[s].push_back(e); //������ �׷���
		A[e].push_back(s);
	}

	//������ ����Ǿ� ������ ���� ���� ��� ���� �湮�϶�� ����
	for (int i = 1; i <= N; i++)
	{
		sort(A[i].begin(), A[i].end()); //����...?????
	}

	DFS(V); cout << endl;
	visited = vector<int>(N + 1, -1); //�迭 �ʱ�ȭ
	BFS(V); cout << "�P" << endl;

	return 0;
}

	void DFS(int v) 
	{
		if (visited[v]) return; //��������
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

		visited[v]++; //visited�� bool�� �ƴϰ� int�϶��� [v]++ !!!!!!!!!!!!!!!!!!!!!!!!!!!

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

