#include <iostream>
#include <vector>

using namespace std;
#define MAX_VTXS 100

class Node {
	int id; //정점의 id (id는 노드의 번호, 그 노드의 데이터 값은 Adjclass의 vertex[])
	Node* link; // 다음 노드의 포인터

public:
	Node(int i,Node* l = NULL): id(i),link(l) {}
	~Node() { if (link != NULL) delete link; }

	int getid() { return id; }
	Node* getLink() { return link; }
	void setLink(Node* l) { link = l; }
};

class AdjListGraph {
protected:
	int size; //정점의 개수
	char vertices[MAX_VTXS]; //정점 정보
	Node* adj[MAX_VTXS]; //각 정점의 인접 리스트

public:
	AdjListGraph():size(0){}
	~AdjListGraph() { reset(); }

	void reset(void) {
		for (int i = 0; i < size; i++)
		{
			if (adj[i] != NULL) delete adj[i];
		}
		size = 0;
	}

	void insertVertex(char val) {
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;
		}
		else cout << "Error: 그래프 정점 개수 초과" << endl;
	}

	void insertEdge(int u, int v) {
		adj[u] = new Node(v, adj[u]);
		adj[v] = new Node(u, adj[v]);
	}



	Node* adjacent(int v) { return adj[v]; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }
	char getVertex(int i) { return vertices[i]; }
};

class SrchALGraph :AdjListGraph
{
	bool visited[MAX_VTXS];
	
public:
	void resetVisited()
	{
		for (int i = 0; i < size; i++) visited[i] = false;
	}
	;
	bool isLinked(int u, int v)
	{
		for (Node* p = adj[u]; p != NULL; p->getLink())
		{
			if (p->getid() == v) return true;
		}
		return false;
	}
};

int main() {
	int n, m;
	int count = 0; //연결 요소 개수 구하기
	SrchALGraph adj;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj->insertEdge(u, v);
	}

	for (int i = 1; i <= n; i++)
	{
		if(adj.isLinked())
	}
	
}