#include <iostream>
#include <queue>

using namespace std;
#define MAX_VTXS 100

typedef struct Edge {
	int s, e, v;
	bool operator>(const Edge& temp) {
		return v > temp.v; //오름 차순 정렬
	}
}Edge;


class VertexSets { //정점 집합 클래스 // Unio-find 연산을 위한 class
	int parent[MAX_VTXS];
	int nSets; //집합의 개수!!! 집합의 개수!! 무끔개수 묵음개수 묶음개수 (주의. 노드 개수아님)
public:
	VertexSets(int n) : nSets(n) {   //n은 노드 개수. 초기에는 노드 하나당 하나의 집합으로 침. 이후에 두 개의 노드가 합쳐지면 Sets--하는 방법
		for (int i = 0; i <= nSets; i++) //<=  //i=0인지 i=1인지 확인
		{
			parent[i] = -1; //부모 노드 초기화 //0인덱스부터 초기화임
		}
	}

	bool isRoot(int i) { return parent[i] < 0; }

	int findSet(int v) {
		while (!isRoot(v)) v = parent[v];
		return v;
	}

	void unionSets(int s1, int s2) {
		if (s1 == s2) return; //양방향 그래프일 때
		parent[s1] = s2;
		nSets--;
	}


};

int main() {
	int V, E; //노드 개수, 엣지 개수
	cin >> V >> E;

	VertexSets vs(V);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq; //크루스칼 알고리즘 1단계: 가중치 오름차순 정렬

	for (int i = 0; i < E; i++) {
		int s, e, v;
		cin >> s, e, v;

		pq.push(Edge{ s,e,v });
	}

	int selectedEdge = 0; //MST에 포함시킨 엣지 개수 -> 그럼 당연히 그 STEP에서의 최소 길이겠죠?
	int result = 0; //MST에 포함시킨 엣지들의 가중치 총합

	while (selectedEdge == V - 1)
	{
		Edge now = pq.top();
		pq.pop();

		if (vs.findSet(now.s) != vs.findSet(now.e))
		{
			vs.unionSets(now.s, now.e);
			result += now.v;
			selectedEdge++;
		}
	}

	cout << result;
	return 0;
}
