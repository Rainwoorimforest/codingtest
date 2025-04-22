#include <iostream>
#include <queue>

using namespace std;

#define MAX_VTX 100

class Node {
protected:
	int id;
	Node* link;
public:
	Node(int i, Node *l = NULL) : id(i), link(l) {}
	~Node() { if (link != NULL) delete link; }

	int getid() { return id; }
	Node* getLink() { return link; }
	void setLink(Node* l) { link = l; }

};

class AdjList {
protected:
	int size;
	char vertices[MAX_VTX];
	Node* adj[MAX_VTX];

public:
	AdjList():size(0) {} //size(0)
	~AdjList() { reset(); }

	void reset(void) {
		for (int i = 0; i < size; i++)
		{
			if (adj[i] != NULL)
				delete adj[i];
		}
		size = 0;
	}

	void insertVertex(char val) {
		if (!isFull())
		{
			vertices[size] = val;
			adj[size++] = NULL;
		}
		else cout << "Error: ���� ���� �ʰ� Full" << endl;
	}

	void insertEdge(int v, int u) {
		adj[u] = new Node(v, adj[u]);
		adj[v] = new Node(v, adj[v]);
	}

	void display() {
		cout << size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << getVertex(i) << " ";
			for (Node* v = adj[i]; v != NULL; v = v->getLink())
				cout << " " << getVertex(v->getid());
			cout << endl;
		}
	}

	Node* adjacent(int v) { return adj[v]; }
	bool isFull() { return size > MAX_VTX; }
	bool isEmpty() { return size == 0; }
	int getVertex(int i) { return vertices[i]; } //?
};

class SrchGraph : public AdjList {
	bool visited[MAX_VTX]; //?

public:
	void resetVisited() //? // ��� ��� '�̹湮'���� �ʱ�ȭ
	{
		for (int i = 0; i < size; i++) visited[i] = false;
	}

	bool isLinked(int u, int v) //? // u�� ������ ��� �߿� v�� �ִ��� Ȯ��
	{
		for (Node* p = adj[v]; p != NULL; p->getLink())
			if (p->getid() == v) return true;
		return false;
	}

	void DFS(int v) { //adhd //?
		visited[v] = true;
		cout << getVertex(v) << " ";

		for (Node* p = adj[v]; p != NULL; p = p->getLink())
		{
			if (visited[p->getid()] == false)
			{
			
				DFS(p->getid()); //DFS�� recursion ���� bfs�� while�� for�� ����
			}
		}
	}

	void BFS(int v) { //�ҽ��ְ� ���Ḯ��Ʈ���� ���� ����
		visited[v] = true;
		cout << getVertex(v) << " ";

		queue<int> q;
		q.push(v);

		while (!q.empty()) {
			int p = q.front(); q.pop();
			for (Node* v = adj[p]; v != NULL; v=v->getLink())
			{
				int id = v->getid(); //?
				if (visited[id] == false) //
				{
					visited[id] = true; //BFS�� ���⿡ �湮 ǥ��. ��? for���� ���ƾ��ؼ�
					cout << getVertex(id);
					q.push(id);
				}
			}
		}
	}
};

void main() {

	SrchGraph g;

	for (int i = 0; i < 4; i++)
	{
		g.insertVertex('A' + i); //A,B,C,D
	}
	//getVertex(0)�� adj[0]
	cout << g.getVertex(0) << endl;

	g.insertEdge(0, 1);
	g.insertEdge(0, 3);
	g.insertEdge(2, 1);
	g.insertEdge(3, 1);
	g.insertEdge(2, 3);
	
	printf("��������Ʈ�� ǥ���� �׷��� \n");
	g.display();
	printf("dfs: ");
	g.DFS(0);


}