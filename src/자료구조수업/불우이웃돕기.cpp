#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>


using namespace std;

#define MAX_VTXS 100

typedef struct Edge {
	int s, e, v;
	bool operator> (const Edge& temp) const {
		return v > temp.v;
	}
} Edge;

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

	void unionSets(int s1, int s2) {
		int root1 = findSet(s1);
		int root2 = findSet(s2);
		if (root1 != root2) {
			if (parent[root1] > parent[root2]) {
				parent[root1] = root2;
			}
			else {
				if (parent[root1] == parent[root2]) {
					parent[root1]--;
				}
				parent[root2] = root1;
			}
			nSets--;
		}
	}

};

int main() {
	int n;
	char ch;
	cin >> n;

	VertexSets vs(n);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	int sum = 0;
	//int k = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> ch;
			int v = 0;

			if ('a' <= ch && ch <= 'z') v = ch - 'a' + 1;
			else if ('A' <= ch && ch <= 'Z') v = ch - 'A' + 27;

			sum += v;
			if (i != j && v != 0)
				//cout << k << "번째: Edge에 push"<<endl<<"i: " << i << endl << "j : " << j << endl << "v : " << v << endl;
				pq.push(Edge{ i,j,v });
				//k++;
		}
	}

	

	int selectedEdges = 0;
	int result = 0;
	int k = 1;

	while (!pq.empty())
	{
		Edge now = pq.top();
		//cout << k << "번째 pop한 가중치:" << now.v << endl;
		//cout << "now.s는 " << now.s << "그리고, now.e는 " << now.e << endl;
		//cout << "------------------" << endl;
		pq.pop();

		if (vs.findSet(now.s) != vs.findSet(now.e))
		{
			vs.unionSets(now.s, now.e);
			result += now.v;
			selectedEdges++;
		}
		
		
		
	}

	if (selectedEdges == n - 1) cout << sum - result;
	else cout << "-1";

	return 0;
}