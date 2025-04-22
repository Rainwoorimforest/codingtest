#include <iostream>
#include <vector>

using namespace std;

class BinaryNode {
	int data;
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(int val=0, BinaryNode* l=NULL,BinaryNode* r=NULL) : data(val), left(l),right(r){}
	~BinaryNode(){}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }


};

class BinaryTree {

protected:
	BinaryNode* root;

public:
	BinaryTree():root(NULL){}
	~BinaryTree() {}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }

	bool isEmpty() { return root == NULL; }

	//��ȸ
	void inorder() { inorder(root); }

private:
	void inorder(BinaryNode* node);

};

void BinaryTree::inorder(BinaryNode* node)
{
	if (node != NULL)
	{
		if (node->getLeft() != NULL) inorder(node->getLeft());
		cout << "[" << node->getData() << "]";
		if (node->getRight() != NULL) inorder(node->getRight());
	}
}

class BinSrchTree : public BinaryTree {

public:

	BinSrchTree(void){}
	~BinSrchTree(void) {}

	BinaryNode* search(int key);
	BinaryNode* search(BinaryNode* n, int key);

	void insert(BinaryNode* n);
	void insert(BinaryNode* r, BinaryNode* n);

	
	void remove(int key);
	void remove(BinaryNode *parent, BinaryNode *node);
};

BinaryNode* BinSrchTree::search(int key)
{
	// ���� search�Լ��� �Ѱ��� node �����ϱ�
	BinaryNode* node = search(root, key);

	if (node != NULL)
	{
		cout << "Ž������ key���� " << node->getData() << "�� ��� = 0x  " << node << endl;
	}
	else
	{
		cout << "Ž������";
	}
	return node;
}

BinaryNode* BinSrchTree::search(BinaryNode* n,int key) //n�� key���� ������ ���, �� ����� �ּҸ� ��ȯ
{
	if (n == NULL) return NULL;
	else if (n->getData() == key) return n;
	else if (n->getData() > key) return search(n->getLeft(), key);
	else return search(n->getRight(), key);
}

void BinSrchTree::insert(BinaryNode* n)
{
	if (n == NULL) return;
	if (isEmpty()) root = n;
	else insert(root, n);
}

void BinSrchTree::insert(BinaryNode* r, BinaryNode* n)
{
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


void BinSrchTree::remove(int key)
{
	if (isEmpty()) return;

	//�ʱ�ȭ
	BinaryNode *parent = NULL;
	BinaryNode *node = root; //node�� �����ϰ��� �ϴ� ��� = key

	while (node != NULL && node->getData() != key) //key�� ã��
	{
		parent = node;
		node = (key < node->getData()) ? node->getLeft() : node->getRight();
	}

	if (node == NULL)
	{
		cout << "ERROR";
	}
	else
	{
		remove(parent, node);
	}

}

void BinSrchTree::remove(BinaryNode* parent, BinaryNode* node)
{
	//case1 : �����Ϸ��� ��尡 �ܸ����
	if(node->isLeaf())
	{
		if (root == node) node = NULL; //������ ��尡 ��Ʈ�϶�
		else {
			if (parent->getLeft() == node) parent->setLeft(NULL);
			else parent->setRight(NULL);
		}
	}

	//case2 : �����Ϸ��� ��尡 ���� ����Ʈ���� ������ ����Ʈ�� �ϳ��� ���� ��
	else if (node->getLeft() == NULL && node->getRight()==NULL)
	{
		//child �����
		BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();

		if (node == root) root = child; //���� ��尡 ��Ʈ�� ��, root�� child��
		else {
			if (parent->getLeft() == node) parent->setLeft(child);
			else parent->setRight(child);
		}
	}

	//case3: �����Ϸ��� ��尡 �� �ڽ� ��带 �Ѵ� ���� ��
	else {

		BinaryNode* succp=node;
		BinaryNode* succ=node->getRight();

		//1.leftmost node
		while (succ->getLeft() != NULL)
		{
			succp = succ;
			succ = succ->getLeft();
		}

		if (succp->getLeft() == succ)
		{
			succp->setLeft(succ->getRight());
		}
		else
		{
			succp->setRight(succ->getRight());
		}

		//����
		node->setData(succ->getData()); //�� ����
		node = succ; //�ּұ��� ����

	}

	delete node;
}

int main() {
	int N;
	BinaryNode* n;
	BinSrchTree tree;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char ch;
		int node;
		cin >> ch>> node;

		if (ch == 'I')
		{
			n = new BinaryNode(node);
			tree.insert(n);
		}
		else if (ch == 'D')
		{
			tree.remove(node);
		}
		
	}

	tree.inorder();

	return 0;
}