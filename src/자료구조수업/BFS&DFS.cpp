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
		else cout << "Error: 정점 개수 초과 Full" << endl;
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
	void resetVisited() //? // 모든 노드 '미방문'으로 초기화
	{
		for (int i = 0; i < size; i++) visited[i] = false;
	}

	bool isLinked(int u, int v) //? // u에 인접한 노드 중에 v가 있는지 확인
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
			
				DFS(p->getid()); //DFS만 recursion 구조 bfs는 while과 for문 구조
			}
		}
	}

	void BFS(int v) { //뚝심있게 연결리스트에서 한줄 한줄
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
					visited[id] = true; //BFS만 여기에 방문 표시. 왜? for문을 돌아야해서
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
	//getVertex(0)은 adj[0]
	cout << g.getVertex(0) << endl;

	g.insertEdge(0, 1);
	g.insertEdge(0, 3);
	g.insertEdge(2, 1);
	g.insertEdge(3, 1);
	g.insertEdge(2, 3);
	
	printf("인접리스트로 표현한 그래프 \n");
	g.display();
	printf("dfs: ");
	g.DFS(0);


}