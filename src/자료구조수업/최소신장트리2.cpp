#include <iostream>
#include <queue>
#include <vector>
#include <string>



using namespace std;
#define MAX_VTXS 100

class VertexSets {
	int parent[MAX_VTXS];
	int nSets;
public:
	VertexSets(int n) : nSets(n) {
		for (int i = 0; i < nSets; i++) //i=0 or i=1���� �ʱ�ȭ�ϱ� ����
		{
			parent[i] = -1;
		}
	}

	bool isRoot(int i) { return parent[i] < 0; }

	int findSet(int v) {
		while (!isRoot(v)) v = parent[v];
		return v;
	}

	void UnionSets(int s1, int s2) {
		if (s1 == s2) return; //������϶�
		parent[s1] = s2;
		nSets--;
	}
};

typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const{  //const�� 2���̴�!!!!!!!!!! ����� Ȯ �޶���
		return v > temp.v; //v�� �� ũ��? // ��������
	}
}Edge;

int main() {
	int N, M; //��� ����, ���� ����
	cin >> N >> M;

	VertexSets vs(N);

	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	for (int i = 0; i < M; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;

		pq.push(Edge{ s,e,v });
	}

	int selectedEdge = 0;
	int result = 0;

	while (selectedEdge < N - 1) {
		Edge now = pq.top();
		pq.pop();

		if (vs.findSet(now.e) != vs.findSet(now.s))
		{
			vs.UnionSets(now.s, now.e);
			result += now.v;
			selectedEdge++;
		}
	}

	cout << result;
	return 0;
}


/*

3 3
1 2 1
2 3 2
1 3 3
*/