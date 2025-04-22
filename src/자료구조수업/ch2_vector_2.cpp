/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//2차원 벡터 mat1,2,3 선언
	vector<vector<int>> mat1(2, vector<int>(3)); //2행 3열 배열. 모두 0값으로 처리
	vector<vector<int>> mat2(2, vector<int>(3, 1)); //2행 3열 배열. 모두 1값으로 처리

	vector<vector<int>> mat3{ //2행 3열의 벡터.
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