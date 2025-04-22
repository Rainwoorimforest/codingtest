#include <iostream>
#include <vector>

using namespace std;

class BinaryNode {

	int data;
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(int val = 0, BinaryNode* l=NULL, BinaryNode* r = NULL) : data(val), left(l),right(r){}
	~BinaryNode(){}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right=r; }

	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }

};

class BinaryTree {

	//BinaryNode* root;
protected:
	BinaryNode* root;

public:
	BinaryTree(): root(NULL){}
	~BinaryTree(){}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getData() { return root; }

	bool isEmpty() { return root == NULL; }

};

class BinSrchTree: public BinaryTree // �߿�
{

public:
	BinSrchTree(void){}
	~BinSrchTree(void) {}

	BinaryNode* search(int key);
	BinaryNode* search(BinaryNode* n, int key);

	void insert(BinaryNode* n);
	void insert(BinaryNode* r, BinaryNode* n);
};

BinaryNode* BinSrchTree::search(int key) {
	
	BinaryNode* node = search(root, key);

	if (node != NULL)
	{
		//cout << "Ž�� ���� Ű����: " << node->getData() << "�� ���= 0x " << node << endl;
		
	}
	else
	{
		//cout << "Ž�� ����: Ű����: " << key << "�γ�����" << endl;
		
	}
		
	return node;

}

BinaryNode* BinSrchTree::search(BinaryNode* n, int key)
{
	if (n == NULL) return NULL;
	if (key == n->getData()) return n;
	else if (key < n->getData()) return search(n->getLeft(), key);
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
	else if (n->getData() < r->getData())
	{
		if (r->getLeft() == NULL) r->setLeft(n);
		else insert(r->getLeft(), n);
	}
	else
	{
		if (r->getRight() == NULL) r->setRight(n);
		else insert(r->getRight(), n);
	}
}



int main() {
	int N, M, a;
	BinSrchTree tree;
	vector<int> n, m;
	vector<int> result;

	cin >> N;
	n.resize(N);

	//����Ʈ������
	for (int i = 0; i < N; i++)
	{
		cin >> n[i];//�� ������ �ƴ϶� �迭�� �ߴ���?

		BinaryNode* node = new BinaryNode(n[i]);
		tree.insert(node);

		if (i == 0)
		{
			tree.setRoot(node);
		}
	}

	//���� �Է¹ް� Ž��

	cin >> M;
	m.resize(M);
	result.resize(M);

	for (int i = 0; i < M; i++)
	{
		cin >> m[i];

		if (tree.search(m[i]) == NULL)
		{
			result[i] = 0;
		}
		else
		{
			result[i] = 1;
		}
	}


	//��� ���
	for (int i = 0; i < M; i++)
	{
		cout << result[i] << endl;
	}



	return 0;
}
