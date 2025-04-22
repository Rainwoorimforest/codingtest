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

	int findSet(int v) { //부모를 반환
		while (!isRoot(v)) v = parent[v];
		return v;
	}
	void unionSet(int s1, int s2) {
		parent[s1] = s2;
		nSets--;
	}


};

int main() {
	int N, M; //N: 도시의 수, M: 여행 계획에 속한 도시 수
	cin >> N >> M;

	VertexSets v(N);
	vector<int> parent;

	//인접행렬 만들기
	for (int i = 1; i <= N; i++) //0~N-1 (N개 도시의 인접행렬 만들기)
	{
		for (int j = 1; j <= N; j++)
		{
			int op;
			cin >> op; //op는 0 or 1 //1: 연결 됨. 0:연결 안 됨.
			 
			if (op == 1 && i < j) { v.unionSet(i, j);} //1일 때, union 연산
		}
	}


	
	
	//여행 경로 입력 받기
	//여행경로 가능한지 검사 및 출력
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