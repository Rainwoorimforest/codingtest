/*
#include <iostream>
using namespace std;
#define ROWS 3
#define COLS 3
*/
/*

----------------<�迭>-------------------

02. 2�����̻��� �迭�� �Ű������� ������ �� ����

*/

/*
void matrix_transpose_02(int A[][COLS], int B[][COLS]) // �Ű����� ���� ��, �� �ڸ��� ����γ� ���ڸ��� �ۼ�
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

    int array2[ROWS][COLS]; // Ʈ�������� �� ���2 ����

    matrix_transpose_02(array1, array2);
    cout << "����2 array1" << endl;
    matrix_print_02(array1);
    cout << " ------------------------ " << endl;
    cout << "����2 array2" << endl;
    matrix_print_02(array2);
}
*/