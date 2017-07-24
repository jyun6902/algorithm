/*
���� ��,�� �ݴ�������� ����
�������� �� �� ; ��->��->��->��
���������� �� �� ; ��->��->��->��

���� ���� ���ߴ� �� ; ���� L,R �� ���
ī��Ʈ�� ���� ������ x!!!!!!
ī��Ʈ��ŭ while�� ������ �ٲ��� ok
*/
#include <iostream>
#include <cstring>
#include <deque>
#include <vector>
using namespace std;
int A, B = 0;		// A = ����, B = ����
int N, M = 0;		// N = �κ� ���� M = ��� ����
int maps[103][103];

vector <pair<int, pair<int, int>>> robot[102];	//�κ� ����, x,y ��ǥ
int main()
{
	memset(maps, 0, sizeof(maps));

	cin >> A >> B >> N >> M;	// A = ����, B = ����, N = �κ� ���� M = ��� ����

	for (int i = 1; i <= N; i++)	//�κ� �ʱ� ����
	{
		char char_dir;
		int w, h = 0;
		cin >> w >> h >> char_dir;
		maps[h][w] = i;			//���� ���� index

		if (char_dir == 'E')		//�� = 0
			robot[i].push_back({ 0 , { h,w } });

		else if (char_dir == 'W')	//�� = 2
			robot[i].push_back({ 2 ,{ h, w} });

		else if (char_dir == 'S')	//�� = 1
			robot[i].push_back({ 1 ,{ h, w } });

		else if (char_dir == 'N')	//�� = 3
			robot[i].push_back({ 3 ,{ h, w } });
	}


	for (int i = 1; i <= M; i++)
	{
		char char_dir;
		int cnt = 0, robot_num = 0;
		cin >> robot_num >> char_dir >> cnt;
		int dir = robot[robot_num][0].first;
		int x = robot[robot_num][0].second.first;
		int y = robot[robot_num][0].second.second;
		/*
				cout << "==========================" << endl;

				for (int h = 1; h <= B; h++)	//�κ� �ʱ� ����
				{
					for (int w = 1; w <= A; w++)

						cout << maps[h][w] << " ";
					cout << endl;
				}
				*/
		if (char_dir == 'L')
		{
			int t = 0;
			while (cnt != t)	//////////////////////�߿�
			{
				dir = (dir + 3) % 4;
				t++;
			}
			robot[robot_num][0].first = dir;
		}

		else if (char_dir == 'R')
		{
			int  t = 0;
			while (cnt != t)
			{
				dir = (dir + 1) % 4;
				t++;
			}
			robot[robot_num][0].first = dir;
		}

		else if (char_dir == 'F')
		{
			maps[x][y] = 0;
			if (dir == 0)	// ��
			{

				for (int i = 1; i <= cnt; i++)
				{
					if (maps[x][y + i] != 0)
					{
						cout << "Robot " << robot_num << " crashes into robot " << maps[x][y + i] << endl;
						return 0;
					}

					if (y + i > A)
					{
						cout << "Robot " << robot_num << " crashes into the wall" << endl;
						return 0;
					}
				}
				maps[x][y + cnt] = robot_num;
				robot[robot_num][0].second.second = y + cnt;
			}	//if (dir== 0)

			else if (dir == 2)// ��
			{
				for (int i = 1; i <= cnt; i++)
				{
					if (maps[x][y - i] != 0)
					{
						cout << "Robot " << robot_num << " crashes into robot " << maps[x][y - i] << endl;
						return 0;
					}

					if (y - i < 1)
					{
						cout << "Robot " << robot_num << " crashes into the wall" << endl;
						return 0;
					}
				}

				maps[x][y - cnt] = robot_num;
				robot[robot_num][0].second.second = y - cnt;
			}	//if (dir== 2)

			else if (dir == 1)// ��
			{
				for (int i = 1; i <= cnt; i++)
				{
					if (maps[x - i][y] != 0)
					{
						cout << "Robot " << robot_num << " crashes into robot " << maps[x - i][y] << endl;
						return 0;
					}

					if (x - i < 1)
					{
						cout << "Robot " << robot_num << " crashes into the wall" << endl;
						return 0;
					}
				}

				maps[x - cnt][y] = robot_num;
				robot[robot_num][0].second.first = x - cnt;
			}	//if (dir== 1)

			else if (dir == 3)// ��
			{
				for (int i = 1; i <= cnt; i++)
				{
					if (maps[x + i][y] != 0)
					{
						cout << "Robot " << robot_num << " crashes into robot " << maps[x + i][y] << endl;
						return 0;
					}

					if (x + i > B)
					{
						cout << "Robot " << robot_num << " crashes into the wall" << endl;
						return 0;
					}
				}

				maps[x + cnt][y] = robot_num;
				robot[robot_num][0].second.first = x + cnt;
			}	//if (dir== 1)

		}//else if ( char_dir == 'F')
	}

	cout << "OK" << endl;
	return 0;
}