#include <iostream>
#include <queue>

using namespace std;
#define MAX_VTXS 100

typedef struct Edge {
	int s, e, v;
	bool operator>(const Edge& temp) {
		return v > temp.v; //���� ���� ����
	}
}Edge;


class VertexSets { //���� ���� Ŭ���� // Unio-find ������ ���� class
	int parent[MAX_VTXS];
	int nSets; //������ ����!!! ������ ����!! �������� �������� �������� (����. ��� �����ƴ�)
public:
	VertexSets(int n) : nSets(n) {   //n�� ��� ����. �ʱ⿡�� ��� �ϳ��� �ϳ��� �������� ħ. ���Ŀ� �� ���� ��尡 �������� Sets--�ϴ� ���
		for (int i = 0; i <= nSets; i++) //<=  //i=0���� i=1���� Ȯ��
		{
			parent[i] = -1; //�θ� ��� �ʱ�ȭ //0�ε������� �ʱ�ȭ��
		}
	}

	bool isRoot(int i) { return parent[i] < 0; }

	int findSet(int v) {
		while (!isRoot(v)) v = parent[v];
		return v;
	}

	void unionSets(int s1, int s2) {
		if (s1 == s2) return; //����� �׷����� ��
		parent[s1] = s2;
		nSets--;
	}


};

int main() {
	int V, E; //��� ����, ���� ����
	cin >> V >> E;

	VertexSets vs(V);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq; //ũ�罺Į �˰��� 1�ܰ�: ����ġ �������� ����

	for (int i = 0; i < E; i++) {
		int s, e, v;
		cin >> s, e, v;

		pq.push(Edge{ s,e,v });
	}

	int selectedEdge = 0; //MST�� ���Խ�Ų ���� ���� -> �׷� �翬�� �� STEP������ �ּ� ���̰���?
	int result = 0; //MST�� ���Խ�Ų �������� ����ġ ����

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
