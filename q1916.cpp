#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <climits>
using namespace std;
//(1��V��20,000, 1��E��300,000)
vector <pair<int, int>> adj[20001];	//�׷��� ��������Ʈ. (����� ���� ��ȣ, ���� ����ġ) ���� ����

vector<int> dijkstra(int src, int V, int E)//from, to, value
{
	vector <int> dist(V, INT_MAX);	//vector v(n,x) ; v�� x ������ �ʱ�ȭ�� n���� ���Ҹ� ���´�.
	dist[src] = 0;

	priority_queue <pair<int, int>> pq;
	pq.push({ 0,src });

	while (!pq.empty())
	{
		int cost = -pq.top().first;	//����� ���� ���� �� ���� pop
		int from = pq.top().second;	//src

		pq.pop();

		if (dist[from] < cost)
			continue;		//���� ���� �ͺ��� �� ª�� ��ΰ� �̹� �����Ҷ�

		for (int i = 0; i < adj[from].size(); i++)	//����� ���� ��ŭ for
		{
			int to = adj[from][i].first;//adj[from]�� ����ִ� ���� i��° index
			int next_cost = cost + adj[from][i].second;//value

			if (dist[to] > next_cost)
			{
				dist[to] = next_cost;
				pq.push({ -next_cost, to });
			}
		}
	}
	return dist;
}

int main()
{
	int n, m = 0;//(1��V��20,000, 1��E��300,000)
	int start = 0, end = 0;

	cin >> n >> m;

	n += 1;	//������ ���� 1���� ����
	for (int i = 0; i < m; i++)
	{
		int from, to, result;
		cin >> from >> to >> result;
		adj[from].push_back({ to, result });
	}
	cin >> start >> end;

	vector<int> answer = dijkstra(start, n, m);
	cout << answer[end] << endl;
	return 0;
}