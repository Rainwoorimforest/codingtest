#include <iostream>
#include <vector>

using namespace std;

int N,root;
int deleteNode;
int answer = 0;
vector<vector<int>> tree; //2���� �迭
vector<bool> visited;
void DFS(int number);

int main() {
	cin >> N; //�Է�1

	tree.resize(N);
	visited.resize(N);
	root = 0;

	//��� tree���Ϳ� �ֱ�.�Է�2
	for (int i = 0; i <N; i++)
	{
		int a;
		cin >> a;
		if (a == -1)
		{
			root =i ;
		}
		else
		{
			tree[i].push_back(a);
			tree[a].push_back(i);
		}
	}

	cin >> deleteNode; //�Է�3

	if (deleteNode == root) cout << 0 << endl;
	else {
		DFS(root);
		cout << answer << endl;
	}
	

	
	return 0;

}

void DFS(int numbers)
{
	visited[numbers] = true;
	int cNode = 0;

	for (int i : tree[numbers])
	{
		if (i == deleteNode)
		{
			break;
		}

		if (!(visited[i])) //���� �湮�ϴ� ��
		{
			cNode++;
			DFS(i);
		}
	}
	if (cNode == 0) answer++;
}
