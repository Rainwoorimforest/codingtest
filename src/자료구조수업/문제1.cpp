#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX_VTXS 100

class VertexSets {
	int parent[MAX_VTXS];
	int nSets;
public:
	VertexSets(int n) :nSets(n) {
		for (int i = 0; i < nSets; i++)
		{
			parent[i] = -1;
		}
	}
	bool isRoot(int i) { return parent[i] < 0; }

	int findSet(int v) { //�θ� ��ȯ
		while (!isRoot(v)) v = parent[v];
		return v;
	}
	void unionSet(int s1, int s2) {
		parent[s1] = s2;
		nSets--;
	}


};

int main() {
	int N, M; // N: 0~N�� VERTEX, M: m���� ����
	vector<string> result;

	cin >> N >> M;

	VertexSets v(N+1);

	for (int i = 0; i < M; i++)
	{
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 0) //union����
		{
			if (a == b) continue;
			v.unionSet(a, b);

		}
		else if (op == 1) //find ����
		{
			int v1 = v.findSet(a);
			int v2 = v.findSet(b);

			if (a == b) { result.push_back("YES"); continue; }

			result.push_back("NO");
		}
	}
	

	//��� ��� ���
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}

	return 0;
}