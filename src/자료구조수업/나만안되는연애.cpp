#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_VTXS 999 

typedef struct Edge{
	int s,e,v;

bool operator > (const Edge& temp) const {
	return v > temp.v;
	}
} Edge;

char univ[MAX_VTXS];
int parent[MAX_VTXS];

class VertexSets {
	
	int nSets;

public:
	VertexSets(int n) : nSets(n) {
		for (int i = 0; i < nSets; i++)
			parent[i] = -1;
	}

	bool isRoot(int i) { return parent[i] < 0; }

	int findSet(int v) {
		if (parent[v] == v) return v;
		return parent[v] = findSet(parent[v]); // 경로 압축
	}

	void unionSets(int s1, int s2) {
		int root1 = findSet(s1);
		int root2 = findSet(s2);
		if (root1 != root2) {
			if (parent[root1] < parent[root2]) { // root1이 더 큰 트리를 가짐
				parent[root2] = root1; // root2를 root1의 자식으로
			}
			else {
				if (parent[root1] == parent[root2]) parent[root2]--; // 높이 증가
				parent[root1] = root2; // root1을 root2의 자식으로
			}
			nSets--;
		}
	}

};



int main(void) {
	
	int n, m;
	cin >> n >> m;

	VertexSets vs(n);

	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;


	for (int i = 1; i <= n; i++) { //univ parent 초기화
		cin >> univ[i];
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) { // 엣지 리스트에 입력넣기
		int s, e, v;
		cin >> s >> e >> v;

		if (univ[s] != univ[e]) //남초 여초끼리는 x
			pq.push(Edge{ s, e, v });
	}

	int seletedEdge = 0;
	int result = 0;

	while (seletedEdge < n - 1)
	{
		Edge now = pq.top();
		pq.pop();

		if (vs.findSet(now.s) != vs.findSet(now.e))
		{
			vs.unionSets(now.s, now.e);
			result += now.v;
			seletedEdge++;
		}
	}

	cout << result;


	return 0;
}




