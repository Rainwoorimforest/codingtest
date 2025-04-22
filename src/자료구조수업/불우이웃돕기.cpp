#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100

typedef struct Edge {
	int s, e, v;
	bool operator >(const Edge& temp) const {
		return v > temp.v;
	}
};

class VertexSet {
	int parent[MAX];
	int nSets; //집합의 개수임

public:
	VertexSet(int n) :nSets(n) {
		for (int i = 0; i < nSets; i++)
			parent[i] = -1;
	}

	bool isRoot(int i) { return parent[i] < 0; }

	int findSet(int v) {
		while (!isRoot(v)) v = parent[v];
		return v;
	}

	/*
	void unionSets(int s1, int s2)  //암기!!!!!!!!!!!!!!!!!!!!!!
	{
		int root1 = findSet(s1);
		int root2 = findSet(s2);

		if (root1 != root2) {
			parent[root1] = root2;
			nSets--;
		}
	}
	*/

	
	void unionSets(int s1, int s2)
	{
		if(s1 == s2) return //불우이웃돕기 문제도 적용
		parent[s1] = s2;
		nSets--;
	}
	
};

int main() {
	int N; //컴퓨터 개수
	int maxV = 0;
	int result = 0;
	int seletedEdge = 0;
	cin >> N;

	VertexSet vs(N);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			
			char ch;
			int v;
			cin >> ch;

			if (ch >= 'a' && ch <= 'z') v = ch - 'a' + 1;
			else if (ch >= 'A' && ch <= 'Z') v = ch - 'A' + 27;
			maxV += v;

			if (i != j && v != 0)
			{
				pq.push(Edge{ i,j,v });
			}
			
		}
	}

	while (!pq.empty())
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

	if (seletedEdge == N - 1) cout << maxV - result << endl;
	else cout << "-1";

}

/*

*/