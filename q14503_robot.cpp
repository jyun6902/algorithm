#include <iostream>
#include <cstring>
using namespace std;

int N, M = 0;	//���� N ���� M
int map[52][52];
int wash[52][52];
int r, c, d = 0;

int check(int x, int y, int dir)	//dir = �ٶ󺸴� ����
{
	wash[x][y] = 1;

	if (wash[x][y + 1] != 0 && wash[x][y - 1] != 0 && wash[x + 1][y] != 0 && wash[x - 1][y] != 0)
	{
		if (dir == 0)	//���� �ٶ�
		{
			if (map[x + 1][y] == 1)
				return 0;

			else
			{
				x++;
				return check(x, y, 0);
			}
		}

		else if (dir == 1)	//���� �ٶ�
		{
			if (map[x][y - 1] == 1)
				return 0;
			else
			{
				y--;
				return check(x, y, 1);
			}
		}


		else if (dir == 2)	//���� �ٶ�
		{
			if (map[x - 1][y] == 1)
				return 0;
			else
			{
				x--;
				return check(x, y, 2);
			}
		}


		else if (dir == 3)	//���� �ٶ�
		{
			if (map[x][y + 1] == 1)
				return 0;
			else
			{
				y++;
				return check(x, y, 3);
			}

		}
	}





	if (dir == 0)	//���ʹٶ�
	{
		y--;
		if (wash[x][y] == 0 && map[x][y] == 0)//���� ����ִٸ�
		{
			return check(x, y, 3);	//�ٶ󺸴� ����
		}

		else // if (wash[x][y - 1] != 0)//û���� ���� ���ٸ�
		{
			y++;
			return check(x, y, 3);
		}

	}

	else if (dir == 1)	//��
	{
		x--;
		if (wash[x][y] == 0 && map[x][y] == 0)
		{
			return check(x, y, 0);
		}

		else //if (wash[x][y - 1] != 0)//û���� ���� ���ٸ�
		{
			x++;
			return check(x, y, 0);
		}
	}

	else if (dir == 2)	//��
	{
		y++;
		if (wash[x][y] == 0 && map[x][y] == 0)
		{
			return check(x, y, 1);
		}

		else //if (wash[x][y - 1] != 0)//û���� ���� ���ٸ�
		{
			y--;//////////////////////////
			return check(x, y, 1);
		}
	}

	else if (dir == 3)  //��
	{
		x++;
		if (wash[x][y] == 0 && map[x][y] == 0)
		{
			return check(x, y, 2);
		}

		else
		{
			x--;
			return check(x, y, 2);////////
		}
	}

}


int main()
{
	cin >> N >> M;
	int result = 0;

	memset(map, 0, sizeof(map));
	memset(wash, 0, sizeof(wash));

	cin >> r >> c >> d;	//û�ұⰡ �ִ� ��ǥ, �ٶ󺸴� ����
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				wash[i][j] = -1;
		}
	}


	check(r, c, d);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{

			if (wash[i][j] == 1)
				result++;
		}
	}
	cout << result;
	return 0;
}