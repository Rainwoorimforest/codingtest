#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_VTXS 100

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
		if (s1 == s2) return;
		parent[s1] = s2;
		nSets--;
	}
};

//네트워크의 개수를 return 하도록 solution 함수를 작성하시오.

int solution(int N);

int main() {
	int N; //컴퓨터 개수

	cin >> N;

	cout<<solution(N);

	return 0;
}

int solution(int N)
{
	int result = 0;

	int root[201];


	// 정점 초기화
	VertexSets v(N);

	// 정점 union
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			if(a==1 && j<=i) { { v.unionSets(i, j); } }
			
		}
	}


	for (int i = 0; i < N; i++)
	{
		root[i] = v.findSet(i);
	}

	sort(root, root + N);
	result++;
	
	for (int i = 0; i < N - 1; i++)
	{
		if (root[i] != root[i + 1]) result++;
	}

	return result;
}