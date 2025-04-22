#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

/*


BinaryNode ��� Ŭ����


*/
class BinaryNode
{
	int data;
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL) : data(val), left(l), right(r) { }
	~BinaryNode() {}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isEmpty() { return this == NULL; } //this?
	bool isLeaf() { return left == NULL && right == NULL; }


};


/*


BinaryTree ����Ʈ�� Ŭ����


*/
class BinaryTree {

protected:
	BinaryNode* root;


public:


	BinaryTree() : root(NULL) { }
	~BinaryTree() { }

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	// Tree Operation
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


	void inorder() { cout << endl << "inorder: ";       inorder(root); }
	void preorder() { cout << endl << "preorder: ";    preorder(root); }
	void postorder() { cout << endl << "postorder: ";   postorder(root); }
	void levelorder();
	int evaluate();

	void inorder(BinaryNode* node);
	void preorder(BinaryNode* node);
	void postorder(BinaryNode* node);
	int evaluate(BinaryNode* node);

	//BinaryNode* insert(int n);
	//BinaryNode* insert(BinaryNode* r, int n);

	int minValue(BinaryNode* node);
	int maxValue(BinaryNode* node);

	bool isBST(BinaryNode* node);
};



int BinaryTree::getCount()
{
	return isEmpty() ? 0 : getCount(root);
}
int BinaryTree::getCount(BinaryNode* node)
{
	if (node == NULL) return 0;
	return 1 + getCount(node->getLeft())
		+ getCount(node->getRight());
}


int BinaryTree::getLeafCount()
{
	return isEmpty() ? 0 : getLeafCount(root);
}


int BinaryTree::getLeafCount(BinaryNode* node)
{
	if (node == NULL) return 0;
	if (node->isLeaf()) return 1;
	else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());


}


int BinaryTree::getHeight()
{
	return isEmpty() ? 0 : getHeight(root);
}


int BinaryTree::getHeight(BinaryNode* node)
{
	if (node == NULL) return 0;
	int hLeft = getHeight(node->getLeft());
	int hRight = getHeight(node->getRight());
	return (hLeft < hRight) ? hLeft + 1 : hRight + 1;
}

bool BinaryTree::isFull()
{
	return isEmpty() ? true : isFull(root);
}

bool BinaryTree::isFull(BinaryNode* node)
{
	if (node == NULL) return true; // �� Ʈ���� ���� ���� Ʈ���� �����մϴ�.

	// ��尡 �ܸ� ��尡 �ƴϸ鼭 �ڽ� ��� �� �ϳ��� ������ ���� ���� Ʈ���� �ƴմϴ�.
	if ((node->getLeft() && !node->getRight()) || (!node->getLeft() && node->getRight()))
		return false;

	// ��������� �ڽ� ��带 Ȯ���մϴ�.
	return isFull(node->getLeft()) && isFull(node->getRight());
}

int BinaryTree::calcLevel(int n)
{
	if (isEmpty()) return -1; // Ʈ���� ��������� �����͸� ã�� �� �����Ƿ� -1�� ��ȯ�մϴ�.
	return calcLevel(root, n, 0);
}

int BinaryTree::calcLevel(BinaryNode* node, int n, int level)
{
	if (node == NULL) return -1; // �����͸� ã�� ���� ��� -1�� ��ȯ�մϴ�.

	if (node->getData() == n) return level; // �����͸� ã�� ��� ���� ������ ��ȯ�մϴ�.

	// ���� ����Ʈ���� ������ ����Ʈ������ �����͸� ã���ϴ�.
	int leftLevel = calcLevel(node->getLeft(), n, level + 1);
	int rightLevel = calcLevel(node->getRight(), n, level + 1);

	// �����Ͱ� �� �� ����Ʈ������ ���� ��� �ش� ������ ��ȯ�մϴ�.
	if (leftLevel != -1) return leftLevel;
	if (rightLevel != -1) return rightLevel;

	// �����Ͱ� ��� �� ����Ʈ������ ������ -1�� ��ȯ�մϴ�.
	return -1;
}

void BinaryTree::inorder(BinaryNode* node)
{
	if (node != NULL) {
		if (node->getLeft() != NULL) inorder(node->getLeft());
		cout << (char)(node->getData());
		if (node->getRight() != NULL) inorder(node->getRight());
	}

}

void BinaryTree::preorder(BinaryNode* node)
{
	if (node != NULL) {
		cout << (char)(node->getData());
		if (node->getLeft() != NULL) preorder(node->getLeft());
		if (node->getRight() != NULL) preorder(node->getRight());
	}
}

void BinaryTree::postorder(BinaryNode* node)
{
	if (node != NULL) {
		if (node->getLeft() != NULL) postorder(node->getLeft());
		if (node->getRight() != NULL) postorder(node->getRight());
		cout << node->getData() << endl;
		//cout << (char)(node->getData());
	}
}
void BinaryTree::levelorder()
{
	cout << endl << "levelorder: ";
	if (!isEmpty()) {
		//queue<int> q;
		queue<BinaryNode*> q;
		q.push(root);
		while (!q.empty()) {
			BinaryNode* n = q.front();
			q.pop();
			if (n != NULL) {
				cout << " [" << n->getData() << "] ";
				q.push(n->getLeft());
				q.push(n->getRight());
			}
		}
	}
	printf("\n");
}

int BinaryTree::evaluate(BinaryNode* node)
{
	if (node == NULL) return 0;
	if (node->isLeaf()) return node->getData();
	else
	{
		int op1 = evaluate(node->getLeft());
		int op2 = evaluate(node->getRight());
		switch (node->getData())
		{
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
	}
}



/*


BinSrchTree ����Ž��Ʈ�� Ŭ����


*/

class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree(void) { }
	~BinSrchTree(void) { }

	BinaryNode* search(int key);
	BinaryNode* search(BinaryNode* n, int key);

	void insert(BinaryNode* n);
	void insert(BinaryNode* r, BinaryNode* n);

	void remove(int key);
	void remove(BinaryNode* parent, BinaryNode* node);
};

BinaryNode* BinSrchTree::search(int key) {
	BinaryNode* node = search(root, key);  //!!! parent class����: root=> protected
	if (node != NULL)
		cout << "Ž�� ���� : Ű ���� " << node->getData()
		<< " �� ��� = 0x " << node << endl;
	else	cout << "Ž�� ���� : Ű���� " << key << "�� ��� ���� " << endl;
	return node;
}

BinaryNode* BinSrchTree::search(BinaryNode* n, int key) {
	if (n == NULL) return NULL;
	if (key == n->getData()) return n;
	else if (key < n->getData()) return search(n->getLeft(), key);
	else return search(n->getRight(), key);
}

void BinSrchTree::insert(BinaryNode* n) {
	if (n == NULL) return;
	if (isEmpty()) root = n;
	else insert(root, n);
}

void BinSrchTree::insert(BinaryNode* r, BinaryNode* n) {
	if (n->getData() == r->getData()) return;
	else if (n->getData() < r->getData()) {
		if (r->getLeft() == NULL) r->setLeft(n);
		else insert(r->getLeft(), n);
	}
	else {
		if (r->getRight() == NULL) r->setRight(n);
		else insert(r->getRight(), n);
	}
}

void BinSrchTree::remove(BinaryNode* parent, BinaryNode* node) {

	// case 1: ���� ��尡 �ܸ��� ���
	if (node->isLeaf()) { // ���� ��尡 root�� ���  
		if (parent == NULL) root = NULL;
		else {  	  // ���� ��尡 left child
			if (parent->getLeft() == node)
				// left child ����
				parent->setLeft(NULL);
			else 	 // ���� ��尡 right child
											 // right child ����
				parent->setRight(NULL);
		}
	}
	// case 2: �����Ϸ��� ��尡 ����Ʈ�� �� �ϳ��� ������ �ִ� ���
	else if (node->getLeft() == NULL || node->getRight() == NULL) {
		// ���� ��尡 right child�� ������ ���
		BinaryNode* child = (node->getLeft() != NULL)
			? node->getLeft() : node->getRight();
		if (node == root) root = child;   //���� ��尡 root��,
		//root �����ϰ� child�� root�� !
		else {
			if (parent->getLeft() == node)  //�θ� ����� ���� �ڽ� ����
				parent->setLeft(child);
			else 			//�θ� ����� ������ �ڽ� ����
				parent->setRight(child);
		}
	}
	// case 3
	else {// �ѹ� ���������� ���� ��� �������� ���� leftmost node
		BinaryNode* succp = node;
		BinaryNode* succ = node->getRight();
		while (succ->getLeft() != NULL) {
			succp = succ;
			succ = succ->getLeft();
		}

		if (succp->getLeft() == succ)
			succp->setLeft(succ->getRight());
		else
			succp->setRight(succ->getRight());

		node->setData(succ->getData());
		node = succ;  // for deleting the node
	}
	delete node;
}


int BinaryTree::minValue(BinaryNode* node)
{
	if (node == NULL) return INT16_MAX;

	int value = node->getData();
	int leftMin = minValue(node->getLeft());
	int rightMin = minValue(node->getRight());

	return min(value, min(leftMin, rightMin));
}

int BinaryTree::maxValue(BinaryNode* node)
{
	if (node == NULL) return INT16_MIN;

	int value = node->getData();
	int leftMax = maxValue(node->getLeft());
	int rightMax = maxValue(node->getRight());

	return max(value, max(leftMax, rightMax));
}

bool BinaryTree::isBST(BinaryNode* node)
{
	if (node == NULL)
	{
		return true;
	}

	if (node->getLeft() != NULL && maxValue(node->getLeft()) >= node->getData()) // ���� ��尡 ������� �ʰ� root���� Ŭ ��
	{
		return false;
	}

	
	if (node->getRight() != NULL && minValue(node->getRight()) <= node->getData()) //������ ��尡 ������� �ʰ� root���� ���� ��
	{
		return false;
	}

	//#3
	// ���ʰ� ������ ����Ʈ���� BST���� Ȯ��
	if (!isBST(node->getLeft()) || !isBST(node->getRight()))
	{
		return false;
	}

	return true;

}
int main() {
	// cout<< min(56, NULL)<<endl; // 0
	// cout << min(56, 56) << endl; // 56

	int N;
	BinaryTree bt;
	vector<BinaryNode*> v;
	

	//input data �б�
	cin >> N;
	v.resize(N+1); //N�� �ƴ϶� N+1
	for (int i = 1; i <= N; i++)
	{
		v[i] = new BinaryNode(i); // �����Ϳ� ��ü �Ҵ�
	}


	
	//binary tree ����
	for (int i = 0; i < N; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;

		if (left != '.')
		{
			v[root - '0']->setLeft(v[left - '0']);
		}
		else
		{
			v[root - '0']->setLeft(NULL);
		}

		if (right != '.')
		{
			v[root - '0']->setRight(v[right - '0']);
		}
		else
		{
			v[root - '0']->setRight(NULL);
		}

		if (i == 0) { bt.setRoot(v[root - '0']); } //char���� int������

		
	}
	

	
	//BT���� BST���� üũ�ϱ�
	
	if (bt.isBST(bt.getRoot())) cout << "\n1";
	else cout << "\n0";
	

	return 0;
}
