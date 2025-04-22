#include <iostream>

using namespace std;

#define MAX 100

class VertexSet {
	int parent[MAX];
	int nSets;
public:
	VertexSet(int n) :nSets(n) {
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

	void unionSets(int s1, int s2) {
		if (s1 == s2) return; //무방향 그래프
		parent[s1] = s2;
		nSets--;
	}
};



int main() {
	int n; //컴퓨터 개수
	int count = 1;
	cin >> n;

	VertexSet vs(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			int a;
			cin >> a;

			if (a == 1 && j <= j) vs.unionSets(i, j);

		}
	}

	int r;
	r = vs.findSet(0);

	for (int i = 1; i < n; i++) {

		int a;
		cin >> a;
		if (r != vs.findSet(a)) {
			count++;
		}

	}

	cout << count << endl;
	return 0;
}

/*
3
1 1 0
1 1 0
0 0 1
*/