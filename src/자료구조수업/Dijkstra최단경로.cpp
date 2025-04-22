#include <iostream>
#include <vector>
//#include <tuple>

using namespace std;

#define MAX 999

int N, M; //��� ����, ���� ����
vector<vector<long>> m; //2���� �������
vector<long> dist; //�� ����� distance �迭
vector<bool> found; //�湮���� üũ �迭

//�̹湮 ���� �� ���� ����� ���� ������ ��ȯ.
int chooseVertex() {
	long min = MAX; // �ּ� ����ġ
	int minpos = -1; // �ּ� ����ġ�� ������ ���

	for (int i = 1; i <= N; i++) //��� ���鿡 ���Ͽ�
	{	//���� S�� ������ �ʴ� �� �߿� ����� �ּ��� ��
		if (dist[i] < min && !found[i])
		{
			min = dist[i];
			minpos = i;
		}
	}
	return minpos;
}

//��� �������� dist[]�� ���
void printDistance() {
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == MAX) cout << "INF" << " ";
		else cout << dist[i] << " ";
	}
	cout << endl;
}

void ShortestPath(int start) {
	//�ʱ�ȭ
	for (int i = 1; i <= N; i++)
	{
		dist[i] = m[start][i];
		found[i] = false;
	}
	
	found[start] = true;
	dist[start] = 0;

	for (int i = 1; i <= N; i++)
	{
		printf("Step%2ld:", i + 1);
		printDistance();
		int u = chooseVertex();

		if (u == -1) break;
		found[u] = true;

		for (int w = 1; w <= N; w++)
		{
			if (found[w] == false)
			{
				if (dist[u] + m[u][w] < dist[w])
					dist[w] = dist[u] + m[u][w];
			}
		}
	}


}

int main() {
	cin >> N >> M;

	m.resize(N + 1);
	dist.resize(N + 1);
	found.resize(N + 1);

	//dist �迭 ���Ѵ�� �ʱ�ȭ
	std::fill(dist.begin(), dist.end(), MAX);

	//������Ŀ� ������ ����
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			m[j].push_back(MAX);
		}
	}

	//������Ŀ� ���� ���� �о ����
	for (int i = 0; i < M; i++)
	{
		int start, end, value;
		cin >> start >> end >> value;
		m[start][end] = value;
	}

	//������� ���
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	ShortestPath(1);

	//���
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == MAX) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}

