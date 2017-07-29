/*
ġ�� 1�ʸ��� ���� ��츦 ����ؼ� ó���� ġ��� �̸� �����س�����
*/
#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int main()
{
	int N, M, result = 0; //N= height M=wide
	int maps[102][102];
	deque <pair<int, int>> cheese;
	int last_cheese=0;
	memset(maps, -1, sizeof(maps));
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 1)
				last_cheese++;
		}
	}
	cheese.push_back({ 1,1 });	//�����ڸ��� ġ��x
	maps[1][1] = 2;
	while (!cheese.empty())
	{
		int x = cheese.back().first;
		int y = cheese.back().second;
		cheese.pop_back();
		maps[x][y] = 2;

		if (x<0 || x> N || y< 0 || y> M)
			continue;

		else
		{
			if (maps[x][y + 1] == 0)
				cheese.push_back({ x, y + 1 });
			if (maps[x][y - 1] == 0)
				cheese.push_back({ x, y - 1 });
			if (maps[x + 1][y] == 0)
				cheese.push_back({ x + 1, y });
			if (maps[x - 1][y] == 0)
				cheese.push_back({ x - 1, y });
		}
	}

	while (1)
	{
		result++;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				int part = 0;
				if (maps[i][j] == 1)
				{
					if (maps[i][j + 1] == 2)
						part++;
					if (maps[i][j - 1] == 2)
						part++;
					if (maps[i + 1][j] == 2)
						part++;
					if (maps[i - 1][j] == 2)
						part++;
				}
				if (part >= 1)
					maps[i][j] = 3;
			}//for
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (maps[i][j] == 3)
				{
					cheese.push_back({ i,j });
					maps[i][j] = 2;
					while (!cheese.empty())
					{
						int x = cheese.back().first;
						int y = cheese.back().second;
						cheese.pop_back();
						maps[x][y] = 2;
						if (x<0 || x> N || y< 0 || y> M)
							continue;
						else
						{
							if (maps[x][y + 1] == 0)
								cheese.push_back({ x, y + 1 });
							if (maps[x][y - 1] == 0)
								cheese.push_back({ x, y - 1 });
							if (maps[x + 1][y] == 0)
								cheese.push_back({ x + 1, y });
							if (maps[x - 1][y] == 0)
								cheese.push_back({ x - 1, y });
						}
					}//while 
				}//if
			}
		}//for

		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (maps[i][j] == 2)
					cnt++;
			}
		}
		
		if (cnt == M*N)
		{
			break;
		}
		else if ( result !=1)
		last_cheese= (M*N) - cnt;
	}
	cout << result << endl;
	cout << last_cheese << endl;
	return 0;
}