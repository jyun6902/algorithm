#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
//(1��V��20,000, 1��E��300,000)
vector <pair<int, int>> adj[20001];	//�׷��� ��������Ʈ. (����� ���� ��ȣ, ���� ����ġ) ���� ����

vector<int> dijkstra(int src, int V, int E)
{
	vector <int> dist(V, INT_MAX);	//vector v(n,x) ; v�� x ������ �ʱ�ȭ�� n���� ���Ҹ� ���´�.
	dist[src] = 0;

	priority_queue<pair<int, int >> pq;
	pq.push({ 0, src });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		if (dist[here] < cost)	//// ���� ���� ���� �ͺ��� �� ª�� ��θ� �˰� �ִٸ� ���� �������� �����Ѵ�.
			continue;

		for (int i = 0; i < adj[here].size() ; i++)	//������ ������ ��� �˻�
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if (dist[there] > nextDist)	//�� ª�� ��θ� �߰��ϸ�, dist[]�� �����ϰ� �켱���� ť�� ����
			{
				dist[there] = nextDist;
				pq.push({ -nextDist, there });	//�켱���� ť�� ���� ū ���Ұ� ť�������� ����. �Ÿ���ȣ �ٲ㼭 ���� �Ÿ����� ���������ϱ� ����
			}
		}
	}

	return dist;
}

int main()
{
	int V, E = 0;//(1��V��20,000, 1��E��300,000)
	int start = 0;

	cin >> V >> E >> start;

	V += 1;	//������ ���� 1���� ����
	for (int i = 0; i < E; i++)
	{
		int from, to, result;
		cin >> from >> to >> result;
		adj[from].push_back({to, result });
	}

	vector<int> answer = dijkstra(start, V, E);

	for (int i = 1; i < V; i++)
	{
		if (answer[i] == INT_MAX)
			cout << "INF" << endl;

		else
			cout << answer[i]<< endl;
	}
	////////////////////////////////////////////////////

	return 0;
}