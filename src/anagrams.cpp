#include <iostream>
#include <sstream> // istringstream ������ ����
#include <string>
#include <algorithm>

using namespace std;

int N;
int main() {

    cin >> N;
    cin.ignore(); // ���� �ڵ嶧���� ���� ���� '/n'�� �� �����������

    // �Է�
    for (int i = 0; i < N; i++)
    {
        string s;
        getline(cin, s); //���� ���� ����

        istringstream iss(s); //���� ������ ������ ���� ������ �и�������

        string A, B;

        iss >> A >> B; //���� ���� A,B�� �ܾ ���� ����

        string sortedA = A;
        string sortedB = B;

        sort(A.begin(), A.end()); //sort �Լ��� ��ȯ���� ����!!?
        sort(B.begin(), B.end());

        if (A == B) cout << sortedA << '&' << sortedB << "are anagrams." << endl;
        else cout << sortedA << '&' << sortedB << "are NOT anagrams." << endl;



    }

    return 0;


}