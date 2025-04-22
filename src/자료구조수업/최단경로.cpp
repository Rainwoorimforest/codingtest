#include <iostream>
#include <vector>

using namespace std;

#define MAX 9999

int N, M,K; //��� ����, ���� ����
vector<vector<long>> m; //�������
vector<long> dist;
vector<bool> found;


//���� ����� ���� �̹湮 ���� ��ȯ
int chooseVertex() {
	int min = MAX; //����ġ�� ���� ���� ���� �������� - ����ġ
	int minpos = -1; //����ġ�� ���� ���� ��尡 �������� - ���

	for (int i = 1; i <= N; i++) //���ͽ�Ʈ��� i�� 1���� ����!! 
	{
		if (dist[i] < min && !found[i])
		{
			min = dist[i];
			minpos = i;
		}
	}

	return minpos;
}

void printDistance() { // dist[] ���
	for (int i = 1; i <= N; i++) //i��1���� ����
	{
		if (dist[i] == MAX) cout << "INF" << " ";
		else cout << dist[i] << " ";
	}
	cout << endl;
}

void ShortestPath(int start)
{
	for (int i = 1; i <= N; i++) //�ʱ�ȭ
	{
		dist[i] = m[start][i];
		found[i] = false;
	}

	found[start] = true;
	dist[start] = 0;

	for (int i = 1; i <= N; i++)
	{
		//printf("Setp%ld: ", i + 1);
		//printDistance();
		int u = chooseVertex();
		if (u == -1) break;

		for (int w = 1; w <= N; w++)
		{
			if (found[w] == false)
			{
				if (dist[w] > dist[u] + m[u][w]) //���İ��� �ͺ��� ������ ������
					dist[w] = dist[u] + m[u][w];
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	cin >> K;
	m.resize(N + 1); //N �ƴϰ� N+1
	dist.resize(N + 1);
	found.resize(N + 1);

	//dist �迭 ���Ѵ�� �ʱ�ȭ
	std::fill(dist.begin(), dist.end(), MAX);

	//���� ��Ŀ� ������ ����
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			m[i].push_back(MAX);
		}
	}

	//������Ŀ� ���� ���� �о ����
	for (int i = 0; i < M; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;
		m[s][e] = v;
	}


	//���ͽ�Ʈ�� �˰��� (�� ���� �ʿ��� ��. 1. ������� m �ʱ�ȭ �� �� ä���ֱ�)
	ShortestPath(K);

	//���
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == MAX) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}

	return 0;




}
