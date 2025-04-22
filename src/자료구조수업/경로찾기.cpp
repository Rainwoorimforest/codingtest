#include<iostream>
#include<vector>

using namespace std;

#define MAX 999

int N;

vector<vector<int>> dist;

int main() {


	cin >> N;
	dist.resize(N+1);

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == 0 || j == 0)
			{
				dist[i].push_back(MAX);
				continue;
			}

			int a;
			cin >> a;
			if(a==0) dist[i].push_back(MAX);
			else dist[i].push_back(a);
		}
	}


	//플루이드 알고리즘
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = 1;
			}
		}
	}


	//출력
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i != 0 && j != 0)
			{
				if (dist[i][j] == MAX)
				{
					cout << 0 << " ";
					continue;
				}
					
				cout << dist[i][j] << " ";
			}
		}
		cout << endl;
	}

	return 0;

}
