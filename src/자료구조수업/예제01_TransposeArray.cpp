/*
#include <iostream>
using namespace std;
#define ROWS 3
#define COLS 3

/*

----------------<배열>-------------------

01. 자료구조01_트랜스포즈 예제

*/

/*

void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS])
{
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            B[c][r] = A[r][c];
}

void matrix_print(int A[ROWS][COLS])
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

void main()
{
    int array1[ROWS][COLS]
        = { {2,3,0},
            {8,9,1},
            {7,0,5}
    };

    int array2[ROWS][COLS]; // 트랜스포즈 할 행렬2 선언

    matrix_transpose(array1, array2);
    matrix_print(array1);
    cout << " ------------------------ " << endl;
    matrix_print(array2);
}
*/