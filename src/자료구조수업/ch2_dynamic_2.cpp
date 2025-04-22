/*
#include <iostream>

using namespace std;

class DynamicArray
{
private:
	unsigned int sz; //�迭 ����� ���� ����
	int* arr; //�޸� ������ ����ų ������ ���� �迭

public:
	DynamicArray(int n) : sz(n) { // �����ڷ� ���� �Ҵ��� �޸� ����
		arr = new int[sz] {};
	}

	~DynamicArray() { delete[] arr; } // �Ҹ��ڷ� ���� �Ҵ��� �޸� ����

	unsigned int size() { return sz; }

	int& operator[] (const int i) { return arr[i]; }
	const int& operator[] (const int i) const { return arr[i]; }
};

int main()
{
	DynamicArray da(5);
	da[0] = 10; 
	da[1] = 20;
	da[2] = 30;

	for (int i = 0; i < da.size(); i++)
		cout << da[i] << endl;
}

*/