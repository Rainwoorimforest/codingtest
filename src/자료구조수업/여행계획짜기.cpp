#include <iostream>
#include <vector>
#include <stack>


using namespace std;
#define MAX_VTXS 100

class VertexSets {
	int parent[MAX_VTXS];
	int nSets;

public:
	VertexSets(int n) : nSets(n) {
		for (int i = 0; i < nSets; i++)
			parent[i] = -1;
	}

	bool isRoot(int i) { return parent[i] < 0; }

	int findSet(int v) {
		while (!isRoot(v)) v = parent[v];
		return v;
	}

	void unionSets(int s1, int s2) { //s2�� �θ� ��.
		if (s1 == s2) return;
		parent[s1] = s2;
		nSets--;
	}
};

int main() {
	int N, M; //������ ����, ���� ����� ���� ����
	int a, b;
	stack<int> connect;

	cin >> N;
	cin >> M;

	//connect.resize(N + 1); //0~N+1���� 2���� �迭. 0��°�� ����.
	VertexSets vs(N);

	//2���� ���� ����
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a;

			if (i < j)
			{
				if (a == 1) vs.unionSets(i,j); //j�� �θ� ��
			}
		}
	}
 
	//���� ��� �ޱ�
	for (int i = 0; i < M; i++)
	{
		cin >> b;

		if (i == 0)
		{
			connect.push(b); 
			continue;
		}

		if (vs.findSet(connect.top()) != vs.findSet(b)) // �θ� �ٸ� = ����Ǿ� ���� x
		{
			cout<<"NO";
			return 0;
		}

		if (i == M - 1) cout << "YES";


	}

	return 0;
}
