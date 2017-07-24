#include <iostream>	//�ٸ� �����
#include <cstring>
#include <deque>
using namespace std;
int N = 0;
int maps[103][103];
int maps_count[103][103];
int dis[103][103];
int main()
{
	cin >> N;
	memset(maps, 0, sizeof(maps));
	memset(maps_count, 0, sizeof(maps_count));
	deque <pair<int, int>> land;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> maps[i][j];
	}

	int connect = 0;		//�������� ���� ī��Ʈ
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (maps[i][j] == 1 && maps_count[i][j] == 0)
			{
				maps_count[i][j] = ++connect;	//�������� ��?connect++ (x) 
				land.push_back({ i,j });
				while (!land.empty())
				{
					int x = land.front().first;
					int y = land.front().second;
					land.pop_front();

					if (y < N && maps[x][y + 1] == 1 && maps_count[x][y + 1] == 0)		//��
					{
						maps_count[x][y + 1] = connect;
						land.push_back({ x, y + 1 });
					}
					if (y > 1 && maps[x][y - 1] == 1 && maps_count[x][y - 1] == 0)		//��
					{
						maps_count[x][y - 1] = connect;
						land.push_back({ x, y - 1 });
					}
					if (x < N && maps[x + 1][y] == 1 && maps_count[x + 1][y] == 0)		//��
					{
						maps_count[x + 1][y] = connect;
						land.push_back({ x + 1, y });
					}
					if (x > 1 && maps[x - 1][y] == 1 && maps_count[x - 1][y] == 0)		//��
					{
						maps_count[x - 1][y] = connect;
						land.push_back({ x - 1, y });
					}

				}	//while
			}		//if
		}
	}

	int result = -1;
	for (int cnt = 1; cnt <= connect; cnt++)	//maps���� 1�� �κ� �Ÿ��迭 0���� ����
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				dis[i][j] = -1;
				if (maps_count[i][j] == cnt)
				{
					land.push_back({ i,j });	//maps���� 1�κκ� push
					dis[i][j] = 0;				//dis = 0
				}
			}
		}	//for i 

		while (!land.empty())					//maps���� 0�� �κ� �Ÿ� ���
		{
			int x = land.front().first;
			int y = land.front().second;
			land.pop_front();

			if (y < N && dis[x][y + 1] == -1)		//��
			{
				dis[x][y + 1] = dis[x][y] + 1;
				land.push_back({ x, y + 1 });
			}
			if (y > 1 && dis[x][y - 1] == -1)		//��
			{
				dis[x][y - 1] = dis[x][y] + 1;
				land.push_back({ x, y - 1 });
			}
			if (x < N && dis[x + 1][y] == -1)		//��
			{
				dis[x + 1][y] = dis[x][y] + 1;
				land.push_back({ x + 1, y });
			}
			if (x > 1 && dis[x - 1][y] == -1)		//��
			{
				dis[x - 1][y] = dis[x][y] + 1;
				land.push_back({ x - 1, y });
			}
		}	//while

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (maps[i][j] == 1 && maps_count[i][j] != cnt)
				{
					if (result == -1 || dis[i][j] - 1 < result)
						result = dis[i][j] - 1;
				}
			}
		}
	/*	
		cout << "----------------------------------" << endl;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << dis[i][j] << " ";
			}
			cout << endl;
		}
		*/
	}
	
	cout << result << endl;
	return 0;
}