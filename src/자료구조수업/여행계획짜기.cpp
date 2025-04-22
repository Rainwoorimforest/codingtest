#include <iostream>

using namespace std;

#define MAX 100

class VertexSet {
	int parent[MAX];
	int nSets;
public:
	VertexSet(int n) : nSets(n) {
		for (int i = 1; i <= nSets; i++) //i=1�� ����.
		{
			parent[i] = -1; //�ʱ�ȭ
		}
	}

	bool isRoot(int i) { return parent[i] < 0; } //������: { return parent[i] == -1; }

	int findSet(int v) {
		while (!isRoot(v)) v = parent[v];
		return v;
	}

	void UnionSets(int s1, int s2) {
		if (s1 == s2) return; //�ߺ��ؼ� union�ϴ°Ŷ� �׳� return
		parent[s1] = s2;
		nSets--;

	}
};

int main() {
	int N,M; //���� ����, ���� ��ȹ�� ���� ���� ����
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

	//���� ���� ���� �Ǻ�
	int temp,r;
	cin >> temp;
	r = vs.findSet(temp); //r�� �������� findSet�Ͽ� ��Ʈ ��� ã�� ��

	for (int i = 0; i < M; i++) //N�� �ƴ϶� ���� ����� M��
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