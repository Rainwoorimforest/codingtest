#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100

typedef struct Edge {
	int s, e, v;
	bool operator>(const Edge& temp) const {
		return v > temp.v;
	}
}Edge;

class VertexSets {
	int parent[MAX];
	int nSets;
public:
	VertexSets(int n) :nSets(n) {
		for (int i = 0; i < nSets; i++)
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
		if (s1 == s2) return;
		parent[s1] = s2;
		nSets--;
	}
};

int main() {
	int N, M; //학교 수, 연결하는 도로의 수

	cin >> N >> M;

	VertexSets vs(N);
	vector<char> school;
	school.resize(N + 1);
	
	for (int i = 1; i <= N; i++) { //중요
		cin >> school[i];
	}

	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	for (int i = 0; i < M; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;

		if (school[s] != school[e]) //서로 다른 학교면 push //여 <-> 여 , 남<->남은 연결할 수 없음
		{
			pq.push(Edge{ s,e,v });
		}

	}
	
	int i = 0;

	int result = 0;
	int selectedEdge = 0;

	while (!pq.empty() && selectedEdge < N - 1) {
		Edge now = pq.top();
		pq.pop();

		if (vs.findSet(now.s) != vs.findSet(now.e)) {
			vs.UnionSets(now.s, now.e);
			result += now.v;
			selectedEdge++;
		}
	}

	if (selectedEdge == N - 1) cout << result << endl;
	else cout << "-1";

	return 0;




}
