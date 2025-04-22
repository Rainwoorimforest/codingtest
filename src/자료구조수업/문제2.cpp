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
		for (int i = 1; i <= nSets; i++)
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
	int N, M; //N: ������ ��, M: ���� ��ȹ�� ���� ���� ��
	cin >> N >> M;

	VertexSets v(N);
	vector<int> parent;

	//������� �����
	for (int i = 1; i <= N; i++) //0~N-1 (N�� ������ ������� �����)
	{
		for (int j = 1; j <= N; j++)
		{
			int op;
			cin >> op; //op�� 0 or 1 //1: ���� ��. 0:���� �� ��.
			 
			if (op == 1 && i < j) { v.unionSet(i, j);} //1�� ��, union ����
		}
	}


	
	
	//���� ��� �Է� �ޱ�
	//������ �������� �˻� �� ���
	for (int i = 1; i <= M; i++)
	{
		int route;
		cin >> route;
		parent.push_back(route);
		

		if (i != 1)
		{
			if (v.findSet(parent[0]) != v.findSet(route))
			{
				cout << "NO";
				break;
			}

			if (i == M)
			{
				cout << "YES";
			}
		}

	}
	

	return 0;
}