#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_VTXS 999

//���� ����ü
typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
}Edge;

//���� ���� Ŭ���� : Union-Find ���� ������ ����.
class VertexSets {
	int parent[MAX_VTXS]; // �θ��� ���� id
	int nSets; //������ ����

public:
	VertexSets(int n) :nSets(n) {
		for (int i = 0; i < nSets; i++) //�ʱ� ��� ������ root(���⼱ -1)�� �ʱ�ȭ ��. -> ��� ������ ������ ���տ� ����
			parent[i] = -1; 
	}

	bool isRoot(int i) { return parent[i] < 0; }
	
	int findSet(int v) {
		while (!isRoot(v)) v = parent[v];
		return v;
	}

	void unionSets(int s1, int s2) {
		//if (s1 == s2) return;
		parent[s1] = s2;
		nSets--;
	}

};

int main() {
	int n, m; //��� ����, ���� ����
	cin >> n >> m; 

	VertexSets vs(n);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	//����ġ �׷��� �����
	for (int i = 0; i < m; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;

		pq.push(Edge{ s,e,v });
	}

	int selectedEdges = 0; //MST ���ԵǴ� Edge ����
	int result = 0; //MST ����ġ ��

	while (selectedEdges < n - 1)
	{
		Edge now = pq.top();
		pq.pop();

		if (vs.findSet(now.s) != vs.findSet(now.e))
		{
			vs.unionSets(now.s, now.e);
			selectedEdges++;
			result += now.v;
		}
	}

	cout << result;
	return 0;
}