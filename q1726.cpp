#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
/*
��ǥ�ȿ������� ���� �ٲ�� ����
���� �迭 0~5 ���� 
*/
int M, N = 0;	//M=���� N= ����
int maps[102][102];
int visit[102][102][5];
int s_x, s_y, s_d, e_x, e_y, e_d;
int dx[] = { 0, 0, 0, 1, -1 };
int dy[] = { 0, 1, -1, 0, 0 };
deque < pair <pair<int, int>, pair<int, int>> > robot;	// x, y, dir, cnt

int f_dir(int a)		//�ݴ� ���� ��ǥ ����
{
	if (a == 1)			//��
		return 2;
	else if (a == 2)	//��
		return 1;
	else if (a == 3)	//��
		return 4;
	else if (a == 4)	//��
		return 3;
}
int main()
{
	memset(maps, -1, sizeof(maps));
	memset(visit, 0, sizeof(visit));
	cin >> M >> N;

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> maps[i][j];
	}

	cin >> s_x >> s_y >> s_d;		//������
	visit[s_x][s_y][s_d] = 1;
	robot.push_back({ { s_x, s_y }, { s_d, 0 } });
	cin >> e_x >> e_y >> e_d;		//����

	while (!robot.empty())
	{
		int x = robot.front().first.first;
		int y = robot.front().first.second;
		int dir = robot.front().second.first;
		int cnt = robot.front().second.second;

		robot.pop_front();

		if (e_x == x && e_y == y && e_d == dir)	//������
			cout << cnt<< endl;
		
		for (int i = 1; i <= 3; i++)			//���⸸ŭ �̵��ϴ� ���
		{
			int c_x = x + i*dx[dir];
			int c_y = y + i*dy[dir];

			if (c_x< 1 || c_x > M || c_y < 1 || c_y > N || maps[c_x][c_y] == 1)
				break;

			if (visit[c_x][c_y][dir] == 1)
				continue;

			visit[c_x][c_y][dir] = 1;
			robot.push_back({ { c_x, c_y }, { dir, cnt + 1 } });
		}

		for (int i = 1; i <= 5; i++)				//���� ����
		{
			if (i == dir || i == f_dir(dir) || visit[x][y][i] == 1)	//�ڱ�����̰ų� �ݴ�����ϰ��
				continue;

			if (visit[x][y][i] == 0)
			{
				visit[x][y][i] = 1;
				robot.push_back({ { x, y },{ i, cnt + 1 } });
			}
		}//for
	}

	return 0;
}