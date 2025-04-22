#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> A;
vector<bool> visited;

void DFS(int v)
{
	if (visited[v]) return; // ���� ����
	
	visited[v] = true;
	cout << v << " ";

	for (int i : A[v])
	{
		if (visited[i] == false)
			DFS(i);
	}
}