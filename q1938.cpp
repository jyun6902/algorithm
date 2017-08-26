#include <iostream>
#include <deque>
using namespace std;
/*
1�� �ƴҰ��� ��->Ż��(E)�϶� �����Ƿ�
*/
char maps[52][52] = { 1 };
int visit[52][52][2] = { 0 };	//�߰� x,y ��ǥ ���� [0];���� [1];����
deque <pair<pair<int, int>, int >> log1;//�볪�� �߰���ǥ1, ����
int main()
{
	int N = 0;	//4<=N<=50
	int cnt = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> maps[i][j];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (maps[i][j - 1] == 'B'&& maps[i][j] == 'B' && maps[i][j + 1] == 'B')
				log1.push_back({ { i,j }, 0 });//���η� �Ǿ��ִ� ���

			else if (maps[i - 1][j] == 'B'&& maps[i][j] == 'B' && maps[i + 1][j] == 'B')
				log1.push_back({ { i,j }, 1 });//���η� �Ǿ��ִ°��
		}
	}

	while (!log1.empty())
	{
		int k_size = log1.size();
		while (k_size--)
		{
			int x = log1.front().first.first;
			int y = log1.front().first.second;
			int dir = log1.front().second;

			log1.pop_front();
			visit[x][y][dir] = 1;
			if ((dir == 1 && maps[x - 1][y] == 'E' && maps[x][y] == 'E' && maps[x + 1][y] == 'E') || (dir == 0 && maps[x][y - 1] == 'E' && maps[x][y] == 'E' && maps[x][y + 1] == 'E'))
			{
				cout << cnt << endl;
				return 0;
			}
			if (dir == 1)
			{

				if (visit[x][y + 1][dir] == 0 && dir == 1 && y + 1 <= N && maps[x][y + 1] != '1' && maps[x - 1][y + 1] != '1' && maps[x + 1][y + 1] != '1')//����, ��
				{
					visit[x][y + 1][dir] = 1;
					log1.push_back({ { x, y + 1 }, 1 });
				}

				if (visit[x][y - 1][dir] == 0 && dir == 1 && y - 1 >= 1 && maps[x][y - 1] != '1' && maps[x - 1][y - 1] != '1' && maps[x + 1][y - 1] != '1')//����, ��
				{
					visit[x][y - 1][dir] = 1;
					log1.push_back({ { x, y - 1 }, 1 });
				}

				if (visit[x + 1][y][dir] == 0 && dir == 1 && x + 2 <= N && maps[x + 1][y] != '1'&& maps[x + 2][y] != '1')//����, ��
				{
					visit[x + 1][y][dir] = 1;
					log1.push_back({ { x + 1, y }, 1 });
				}

				if (visit[x - 1][y][dir] == 0 && dir == 1 && x - 2 >= 1 && maps[x - 1][y] != '1' && maps[x - 2][y] != '1')//����, ��
				{
					visit[x - 1][y][dir] = 1;
					log1.push_back({ { x - 1, y }, 1 });
				}
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (dir == 0)
			{
				if (visit[x][y + 1][dir] == 0 && dir == 0 && y + 2 <= N && maps[x][y + 1] != '1' &&  maps[x][y + 2] != '1')//����, ��
				{
					visit[x][y + 1][dir] = 1;
					log1.push_back({ { x, y + 1 },0 });
				}

				if (visit[x][y - 1][dir] == 0 && dir == 0 && y - 2 >= 1 && maps[x][y - 1] != '1' &&  maps[x][y - 2] != '1')//����, ��
				{
					visit[x][y - 1][dir] = 1;
					log1.push_back({ { x, y - 1 },0 });
				}

				if (visit[x + 1][y][dir] == 0 && dir == 0 && x + 1 <= N && maps[x + 1][y - 1] != '1' && maps[x + 1][y] != '1' && maps[x + 1][y + 1] != '1')//���� ��
				{
					visit[x + 1][y][dir] = 1;
					log1.push_back({ { x + 1, y }, 0 });
				}

				if (visit[x - 1][y][dir] == 0 && dir == 0 && x - 1 >= 1 && maps[x - 1][y - 1] != '1' && maps[x - 1][y] != '1' && maps[x - 1][y + 1] != '1')//���� ��
				{
					visit[x - 1][y][dir] = 1;
					log1.push_back({ { x - 1, y }, 0 });
				}
			}

			if (dir == 1)// | -> - ���� ����
			{
				if (visit[x][y][0] == 1 || x <= 1 || x >= N || y <= 1 || y >= N)
					continue;

				if (maps[x - 1][y - 1] == '1' || maps[x][y - 1] == '1' || maps[x + 1][y - 1] == '1' || maps[x - 1][y + 1] == '1' || maps[x][y + 1] == '1' || maps[x + 1][y + 1] == '1')
					continue;

				visit[x][y][0] = 1;
				log1.push_back({ { x, y }, 0 });
			}

			else if (dir == 0)// - -> | ���� ����
			{
				if (visit[x][y][1] == 1 || x <= 1 || x >= N || y <= 1 || y >= N)
					continue;

				if (maps[x - 1][y - 1] == '1' || maps[x - 1][y] == '1' || maps[x - 1][y + 1] == '1' || maps[x + 1][y - 1] == '1' || maps[x + 1][y] == '1' || maps[x + 1][y + 1] == '1')
					continue;

				visit[x][y][1] = 1;
				log1.push_back({ { x, y }, 1 });
			}

		}//while k_size
		cnt++;
	}

	cout << "0" << endl;
	return 0;
}