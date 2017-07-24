#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <cstdio>
using namespace std;
int N, M; //N= ����, M=����
int maze[102][102];
int dx[4] = { -1, 1, 0, 0 };//��, ��, ��, ��
int dy[4] = { 0, 0, -1, 1 };

vector <pair<int, int>> adj[20000];
vector<int> dijkstra(int src)
{
	vector <int> dist(N*M + 1, INT_MAX);	//vector v(n,x) ; v�� x ������ �ʱ�ȭ�� n���� ���Ҹ� ���´�.
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;

	pq.push({ 0,src });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int from = pq.top().second;

		pq.pop();
		if (dist[from] < cost)
			continue;

		for (int i = 0; i < adj[from].size(); i++)
		{
			int to = adj[from][i].first;
			int next_cost = cost + adj[from][i].second;

			if (dist[to] > next_cost)
			{
				dist[to] = next_cost;
				pq.push({ -next_cost, to });
			}
		}
	}

	return dist;
}


#define num(x, y) ((x - 1)*M + y)	//�Ź� node�� ���� �ش簪 ����
int main()
{
	cin >> M >> N;	//M= ���� N=����

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			scanf("%1d", &maze[i][j]);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];

				if (y <= 0 || y > M || x <= 0 || x > N)
					continue;

				adj[num(i, j)].push_back({ num(x,y), maze[x][y] });
			}
		}
	}

	vector<int> answer = dijkstra(1);//1= ������
	cout << answer[M*N];
	////////////////////////////////////////////////////
	return 0;
}