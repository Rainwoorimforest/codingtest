/*
#include <iostream>
using namespace std;
#define ROWS 3
#define COLS 3
*/
/*

----------------<배열>-------------------

02. 2차원이상의 배열을 매개변수로 전달할 때 예제

*/

/*
void matrix_transpose_02(int A[][COLS], int B[][COLS]) // 매개변수 전달 시, 행 자리는 비워두나 열자리는 작성
{
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            B[c][r] = A[r][c];
}

void matrix_print_02(int A[][COLS])
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            cout << A[r][c] << " ";
        }

        cout << endl;
    }

}


void main_Passing2DArray()
{
    int array1[ROWS][COLS]
        = { {2,3,0},
            {8,9,1},
            {7,0,5}
    };

    int array2[ROWS][COLS]; // 트랜스포즈 할 행렬2 선언

    matrix_transpose_02(array1, array2);
    cout << "예제2 array1" << endl;
    matrix_print_02(array1);
    cout << " ------------------------ " << endl;
    cout << "예제2 array2" << endl;
    matrix_print_02(array2);
}
*/