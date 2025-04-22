#include <iostream>

using namespace std;

#define MAX 100

class VertexSet {
	int parent[MAX];
	int nSets;
public:
	VertexSet(int n) : nSets(n) {
		for (int i = 1; i <= nSets; i++) //i=1로 했음.
		{
			parent[i] = -1; //초기화
		}
	}

	bool isRoot(int i) { return parent[i] < 0; } //교수님: { return parent[i] == -1; }

	int findSet(int v) {
		while (!isRoot(v)) v = parent[v];
		return v;
	}

	void UnionSets(int s1, int s2) {
		if (s1 == s2) return; //중복해서 union하는거라 그냥 return
		parent[s1] = s2;
		nSets--;

	}
};

int main() {
	int N,M; //도시 개수, 여행 계획에 속한 도시 개수
	cin >> N;
	cin >> M;

	VertexSet vs(N);

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			int op;

			if (op == 1 && i < j) vs.UnionSets(i, j);
		}
	}

	//여행 가능 여부 판별
	int temp,r;
	cin >> temp;
	r = vs.findSet(temp); //r을 기준으로 findSet하여 루트 노드 찾을 것

	for (int i = 0; i < M; i++) //N이 아니라 여행 경로인 M임
	{
		int city;
		cin >> city;

		if (vs.findSet(city) != r)
		{
			cout << "NO" << endl;
			return;
		}

	}

	cout << "YES" << endl;
	return 0;
}

/*
3
3
0 1 0
1 0 1
0 1 0
1 2 3
*/