#include <iostream>
#include <vector>

using namespace std;

void mergeSort(int s, int e);

static vector<int> A;
static vector<int> tmp;

int main() {
	int N;
	cin >> N;
	A = vector<int>(N + 1, 0);
	tmp = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	mergeSort(1, N);

	for(int)
}