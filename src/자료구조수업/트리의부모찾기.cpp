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

	//����Ʈ�� ����
	for (int i = 1; i < N; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		//���� ����Ʈ ����
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
		if (!(visited[i])) // �湮���� �ʾҴٸ� = ���� �湮�ϴ°Ÿ�
		{
			answer[i] = number;
			DFS(i);
		}
	}
}