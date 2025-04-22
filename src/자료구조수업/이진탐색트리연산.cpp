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

	//순회
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
	// 다음 search함수에 넘겨줄 node 정의하기
	BinaryNode* node = search(root, key);

	if (node != NULL)
	{
		cout << "탐색성공 key값이 " << node->getData() << "인 노드 = 0x  " << node << endl;
	}
	else
	{
		cout << "탐색실패";
	}
	return node;
}

BinaryNode* BinSrchTree::search(BinaryNode* n,int key) //n은 key값과 동일한 노드, 그 노드의 주소를 반환
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

	//초기화
	BinaryNode *parent = NULL;
	BinaryNode *node = root; //node는 제거하고자 하는 노드 = key

	while (node != NULL && node->getData() != key) //key값 찾기
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
	//case1 : 제거하려는 노드가 단말노드
	if(node->isLeaf())
	{
		if (root == node) node = NULL; //제거할 노드가 루트일때
		else {
			if (parent->getLeft() == node) parent->setLeft(NULL);
			else parent->setRight(NULL);
		}
	}

	//case2 : 제거하려는 노드가 왼쪽 하위트리나 오른쪽 하위트리 하나만 가질 때
	else if (node->getLeft() == NULL && node->getRight()==NULL)
	{
		//child 만들기
		BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();

		if (node == root) root = child; //제거 노드가 루트일 때, root를 child로
		else {
			if (parent->getLeft() == node) parent->setLeft(child);
			else parent->setRight(child);
		}
	}

	//case3: 제거하려는 노드가 두 자식 노드를 둘다 가질 때
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

		//복사
		node->setData(succ->getData()); //값 복사
		node = succ; //주소까지 이전

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