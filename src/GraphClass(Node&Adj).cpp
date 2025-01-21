#include <iostream>

using namespace std;

#define MAX_VTXS 100

class Node{
protected:
    int id; //정점의 id
    Node* link; //다음 노드의 포인터

public:
    Node(int i, Node *l = NULL) : id(i), link(l) {} //생성자
    ~Node() { if(link != NULL) delete link; } //소멸자

    int getId() { return id; }
    Node* getLink() { return link; }
    void setLink(Node *l) {link = l;}
};

class AdjLinkGraph{
protected: 
    int size; //정점의 개수
    char vertices[MAX_VTXS]; // 정점의 정보
    Node* adj[MAX_VTXS]; // 각 정점의 인접 리스트

public:
    AdjLinkGraph(): size(0) {} //생성자
    ~AdjLinkGraph() { reset(); } //소멸자

    void reset(void){
        for(int i=0; i < size; i++)
        {
            if(adj[i] != NULL) delete adj[i];
        }
        size = 0;
    }

    void insertVertex(char val){ // 정점 삽입 연산
        if(!isFull())
        {
            vertices[size] = val;
            adj[size++] = NULL; // 일단 NULL로 초기화
        }
        else cout << "Error: 그래프 정점 개수 초과" << endl;
    }

    void insertEdge(int u, int v) //간선 삽입 연산
    {
        // u : 0, v : 1일 때
        adj[u] = new Node(v, adj[u]); // 노드 1을 만들어서 adj[0]에 연결
        adj[v] = new Node(u, adj[v]); // 노드 0을 만들어서 adj[1]에 연결

    }

    void display(){
        cout << size <<endl; //정점의 개수 출력

        for(int i=0; i < size; i++)
        {
            cout << getVertex(i) << " "; //정점 i의 이름 출력

            for( Node *v = adj[i]; v != NULL; v = v->getLink()) 
            {
                cout << " " << getVertex(v -> getId()); //정점 i의 인접 노드를 출력
            }
        }
    }

    Node* adjacent(int v) { return adj[v]; }

    bool isEmpty() {return size ==0;}
    bool isFull() {return size >= MAX_VTXS;}
    char getVertex(int i) {return vertices[i];}
};

