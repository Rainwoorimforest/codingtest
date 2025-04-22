#include <iostream>

using namespace std;

class DynamicArray
{
private:
	unsigned int sz; //�迭 ����� ���� ����
	int* arr; //�޸� ������ ����ų ������ ���� �迭

public:
	DynamicArray(int n) : sz(n) { // �����ڷ� ���� �Ҵ��� �޸� ����
		arr = new int[sz] {}; // {}���� ����ִ� ���� ������ ���� �ƴ� 0���� ä��.
	}

	~DynamicArray() { delete[] arr; } // �Ҹ��ڷ� ���� �Ҵ��� �޸� ����

	unsigned int size() { return sz; }

	int& operator[] (const int i) { return arr[i]; }
	const int& operator[] (const int i) const { return arr[i]; }
};

int main()
{
	int num, v;
	int count = 0;
	
	cin >> num; 

	DynamicArray da(num); //da��� ��ü ���� �μ��� 5�� �Ѱ���.

	//�迭�� num���� ���� ä���
	for (int i = 0; i < da.size(); i++) {
		int a;
		cin >> a;
		da[i] = a;
	}

	cin >> v;
	//���� v ã��
	for (int i = 0; i < da.size(); i++) {
		if (da[i] == v)
			count++;
	}

	cout << count;
}