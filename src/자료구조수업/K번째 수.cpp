#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

void Input()
{
	ios_base::sync_with_stdio(false);
	int N = 0;
	int K = 0;
	cin >> N;
	cin >> K;
	while (true)
	{
		if (N < K)
		{
			cin >> K;
		}
		else
		{
			break;
		}
	}

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	nth_element(v.begin(), v.begin() + (K - 1), v.end());
	cout << v[K - 1] << '\n';
}

int main()
{
	Input();

	return 0;
}