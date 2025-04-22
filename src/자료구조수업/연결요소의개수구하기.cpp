#include <iostream>
#include <vector>

using namespace std;
#define MAX_VTXS 100

class Node {
	int id; //������ id (id�� ����� ��ȣ, �� ����� ������ ���� Adjclass�� vertex[])
	Node* link; // ���� ����� ������

public:
	Node(int i,Node* l = NULL): id(i),link(l) {}
	~Node() { if (link != NULL) delete link; }

	int getid() { return id; }
	Node* getLink() { return link; }
	void setLink(Node* l) { link = l; }
};

class AdjListGraph {
protected:
	int size; //������ ����
	char vertices[MAX_VTXS]; //���� ����
	Node* adj[MAX_VTXS]; //�� ������ ���� ����Ʈ

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
		else cout << "Error: �׷��� ���� ���� �ʰ�" << endl;
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
	int count = 0; //���� ��� ���� ���ϱ�
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