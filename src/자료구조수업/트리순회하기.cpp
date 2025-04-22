/*
#include <iostream>
#include<vector>
#define MAX_QUEUE_SIZE 100
using namespace std;

class CircularQueue {

protected:
	int front; 		// 첫 번째 요소 앞의 위치
	int rear; 		// 마지막 요소 위치
	int data[MAX_QUEUE_SIZE]; // 요소의 배열
public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	void enqueue(int val) { // 큐에 삽입
		if (isFull())
		{
			cout << " error: 큐가 포화상태입니다" <<endl; exit(-1); 
		}
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
		}

		int dequeue() { 	// 첫 항목을 큐에서 빼서 반환
			if (isEmpty()) { cout << " Error: 큐가 공백상태입니다"; exit(-1); }
			else {
				front = (front + 1) % MAX_QUEUE_SIZE;
				return data[front];
			}
		}
		int peek() { 	// 첫 항목을 큐에서 빼지 않고 반환
			if (isEmpty()) printf(" Error: 큐가 공백상태입니다\n");
			else
				return data[(front + 1) % MAX_QUEUE_SIZE];
		}
		void display() { 	// 큐의 모든 내용을 순서대로 출력
			printf("큐 내용 : ");
			int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
			for (int i = front + 1; i <= maxi; i++)
				cout << data[i % MAX_QUEUE_SIZE] << " ";
			cout << endl;
		}
	};

class BinaryNode
{
public:
	int data;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		: data(val), left(l), right(r) { }
	~BinaryNode() { }

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }
};

class BinaryTree {
	BinaryNode* root;

public:
	BinaryTree() : root(NULL) { }
	~BinaryTree() { }

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	// Tree Operation

	/*
	int getCount();		// 노드 개수
	int getLeafCount();	// 단말 노드 개수
	int getHeight();	// 트리의 높이
	bool isFull();		// full binary tree인지 
	int calcLevel(int n);  	// 데이터가 n인 노드의 레벨

	int getCount(BinaryNode* node);
	int getLeafCount(BinaryNode* node);
	int getHeight(BinaryNode* node);
	bool isFull(BinaryNode* node);
	int calcLevel(BinaryNode* node, int n, int level);
	*/
	void inorder() { cout << endl << "inorder: ";       inorder(root); }
	void preorder() { cout << endl << "preorder: ";    preorder(root); }
	void postorder() { cout << endl << "postorder: ";   postorder(root); }
	void levelorder();

private:
	void inorder(BinaryNode* node);
	void preorder(BinaryNode* node);
	void postorder(BinaryNode* node);


};

void BinaryTree::inorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL) inorder(node->getLeft());
		cout << "[" << (char)(node->getData()) << "] ";
		if (node->getRight() != NULL) inorder(node->getRight());
	}
}

void BinaryTree::preorder(BinaryNode* node) {
	if (node != NULL) {
		cout << "[" << (char)(node->getData()) << "] ";
		if (node->getLeft() != NULL) preorder(node->getLeft());
		if (node->getRight() != NULL) preorder(node->getRight());
	}
}

void BinaryTree::postorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL) postorder(node->getLeft());
		if (node->getRight() != NULL) postorder(node->getRight());
		cout << "[" << (char)(node->getData()) << "] ";
	}
}

/*
void BinaryTree::levelorder() {
	cout << endl << "levelorder: ";
	if (!isEmpty()) {
		CircularQueue q;
		q.enqueue(root);
		while (!q.isEmpty()) {
			BinaryNode* n = q.dequeue();
			if (n != NULL) {
				cout << " [" << n->getData() << "] ";
				q.enqueue(n->getLeft());
				q.enqueue(n->getRight());
			}
		}
	}
	printf("\n");
}
*/

int main() {
	int N;
	char p, left, right;
	vector<BinaryNode*> node; //왜 *일까
	BinaryTree tree;//왜 *일까


	cin >> N;

	node.resize(N);

	//입력받기

	for (int i = 0; i < N; i++)
	{
		//node.push_back('A' + i); //A:65, B:66 ... [65,66,67,68...]

		//node가 포인터형으로 바뀌면 다음과 같이 new연산자를 사용해 객체를 할당해야 해. 
		node[i] = new BinaryNode('A' + i);
	}

	//노드 간 링크 연결
	for (int i = 0; i < N; i++)
	{
		cin >> p >> left >> right;

		if (left != '.')
		{
			node[p - 'A']->setLeft(node[left-'A']); //index를 나타내고 싶을 때 p -'A', left-'A' //setleft때문에 node를 포인터형을 쓰는 것.

		}
		if (right != '.')
		{
			node[p - 'A']->setRight(node[right - 'A']);
		}
	}

	tree = BinaryTree();
	tree.setRoot(node[0]);

	//BinaryNode* root = tree.getRoot();

	tree.inorder();
	tree.preorder();
	tree.postorder();

	return 0;


}

*/