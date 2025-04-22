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
		for (int i = 0; i < nSets; i++) //i=0 or i=1인지 초기화하기 나름
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
		if (s1 == s2) return; //양방향일때
		parent[s1] = s2;
		nSets--;
	}
};

int main() {
	int n, m; //노드 개수, 
	cin >> n >> m;

	vector<string> result;
	VertexSets vs(n); //VertexSets(n); 실수

	for (int i = 0; i < m; i++)
	{
		int op, s, e;
		cin >> op >> s >> e;

		if (op == 0) vs.UnionSets(s, e);
		else if (op == 1)
		{
			if (vs.findSet(s) == vs.findSet(e)) result.push_back("YES"); 
			else result.push_back("NO");
		}
	}

	//출력
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
		

	}

	return 0;
}

/*

7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1

*/