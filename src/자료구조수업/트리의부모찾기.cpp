#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> tree;
vector<int> visited;
vector<int> answer;
void DFS(int number);

int main() {
	cin >> N;

	tree.resize(N + 1);
	visited.resize(N + 1);
	answer.resize(N + 1);

	//이진트리 생성
	for (int i = 1; i < N; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		//인접 리스트 생성
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	DFS(1);

	for (int i = 2; i <= N; i++)
	{
		cout << answer[i] << endl;
	}

}

void DFS(int number)
{
	visited[number] = true;

	for (int i : tree[number])
	{
		if (!(visited[i])) // 방문하지 않았다면 = 새로 방문하는거면
		{
			answer[i] = number;
			DFS(i);
		}
	}
}