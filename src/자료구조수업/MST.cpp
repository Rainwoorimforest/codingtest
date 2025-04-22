#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_VTXS 999

//에지 구조체
typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
}Edge;

//정점 집합 클래스 : Union-Find 연산 구현을 위함.
class VertexSets {
	int parent[MAX_VTXS]; // 부모의 정점 id
	int nSets; //집합의 개수

public:
	VertexSets(int n) :nSets(n) {
		for (int i = 0; i < nSets; i++) //초기 모든 정점은 root(여기선 -1)로 초기화 됨. -> 모든 집합이 고유의 집합에 속함
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
	int n, m; //노드 개수, 에지 개수
	cin >> n >> m; 

	VertexSets vs(n);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	//가중치 그래프 만들기
	for (int i = 0; i < m; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;

		pq.push(Edge{ s,e,v });
	}

	int selectedEdges = 0; //MST 포함되는 Edge 개수
	int result = 0; //MST 가중치 합

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