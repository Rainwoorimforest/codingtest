/*
#include <iostream>
#include<vector>
#define MAX_QUEUE_SIZE 100
using namespace std;

class CircularQueue {

protected:
	int front; 		// ù ��° ��� ���� ��ġ
	int rear; 		// ������ ��� ��ġ
	int data[MAX_QUEUE_SIZE]; // ����� �迭
public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	void enqueue(int val) { // ť�� ����
		if (isFull())
		{
			cout << " error: ť�� ��ȭ�����Դϴ�" <<endl; exit(-1); 
		}
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
		}

		int dequeue() { 	// ù �׸��� ť���� ���� ��ȯ
			if (isEmpty()) { cout << " Error: ť�� ��������Դϴ�"; exit(-1); }
			else {
				front = (front + 1) % MAX_QUEUE_SIZE;
				return data[front];
			}
		}
		int peek() { 	// ù �׸��� ť���� ���� �ʰ� ��ȯ
			if (isEmpty()) printf(" Error: ť�� ��������Դϴ�\n");
			else
				return data[(front + 1) % MAX_QUEUE_SIZE];
		}
		void display() { 	// ť�� ��� ������ ������� ���
			printf("ť ���� : ");
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
	int getCount();		// ��� ����
	int getLeafCount();	// �ܸ� ��� ����
	int getHeight();	// Ʈ���� ����
	bool isFull();		// full binary tree���� 
	int calcLevel(int n);  	// �����Ͱ� n�� ����� ����

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
	vector<BinaryNode*> node; //�� *�ϱ�
	BinaryTree tree;//�� *�ϱ�


	cin >> N;

	node.resize(N);

	//�Է¹ޱ�

	for (int i = 0; i < N; i++)
	{
		//node.push_back('A' + i); //A:65, B:66 ... [65,66,67,68...]

		//node�� ������������ �ٲ�� ������ ���� new�����ڸ� ����� ��ü�� �Ҵ��ؾ� ��. 
		node[i] = new BinaryNode('A' + i);
	}

	//��� �� ��ũ ����
	for (int i = 0; i < N; i++)
	{
		cin >> p >> left >> right;

		if (left != '.')
		{
			node[p - 'A']->setLeft(node[left-'A']); //index�� ��Ÿ���� ���� �� p -'A', left-'A' //setleft������ node�� ���������� ���� ��.

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