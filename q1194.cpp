#include <iostream>
#include <deque>
#include <string>
using namespace std;
/*��Ʈ����ũ!!
string�� memset �ʱ�ȭx ������
*/
int N = 0, M = 0;	//N=���� M=����
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visit[52][52][1 << 7];
bool find = false;
string maps[52];
deque <pair<pair<int, int>, int>> minsik;	//minsik_x, minsik_y, key
int sec = 0;
int bfs()
{
	while (minsik.size())
	{
		int minsik_s = minsik.size();
		for (int t_case = 0; t_case < minsik_s; t_case++)
		{
			int x = minsik.front().first.first;
			int y = minsik.front().first.second;
			int key1 = minsik.front().second;
			minsik.pop_front();

			if (maps[x][y] == '1')    //Ż��
				return sec;

			for (int i = 0; i < 4; i++)
			{
				int px = x + dx[i];
				int py = y + dy[i];

				if (px > N || px < 1 || py > M || py < 1 || maps[px][py] == '#')
					continue;

				if (maps[px][py] >= 'a' && maps[px][py] <= 'f')// a - f ������ ���
				{
					int pz = key1 | (1 << (maps[px][py] - 'a'));	//a|b ������ �����������ִ� ����� ��ħ
					if (visit[px][py][pz] == true)
						continue;
					visit[px][py][pz] = true;
					minsik.push_back({ { px, py }, pz });//a|b ; ������ px,py��ǥ���� ������ �ִ� ���� �����
				}

				else if (maps[px][py] >= 'A' && maps[px][py] <= 'F' && visit[px][py][key1] == false)// �湮���� A - F
				{
					if (key1&(1 << maps[px][py] - 'A'))//Ű �ִ��� �˻�
					{
						visit[px][py][key1] = true;
						minsik.push_back({ { px,py }, key1 });
					}
				}

				else if (visit[px][py][key1] == false)
				{
					visit[px][py][key1] = true;
					minsik.push_back({ { px,py }, key1 });
				}
			}//for ����
		}// for minsik_size
		sec++;
	}//while
	return -1;
}
int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> maps[i];
		maps[i] = '!' + maps[i] + '!';
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (maps[i][j] == '0')
			{
				minsik.push_back({ { i,j }, 0 });
				visit[i][j][0] = true;
			}
		}
	}

	cout << bfs() << endl;
	return 0;
}