/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//2���� ���� mat1,2,3 ����
	vector<vector<int>> mat1(2, vector<int>(3)); //2�� 3�� �迭. ��� 0������ ó��
	vector<vector<int>> mat2(2, vector<int>(3, 1)); //2�� 3�� �迭. ��� 1������ ó��

	vector<vector<int>> mat3{ //2�� 3���� ����.
		{1, 2, 3},
		{4, 5, 6}
	};


	for (int r = 0; r < mat3.size(); r++) {
		for (int c = 0; c < mat3[r].size(); c++) {
			cout << mat2[r][c] << ",";
		}
		cout << endl;
	}

}
*/