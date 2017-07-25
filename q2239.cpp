/*
exit(0)�Ⱦ��� return �� ��� �������� ����
exit()�Լ��� �ٷ� ���μ��� ����.
return �� �� ������ �����ϸ� ����.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int maps[10][10];
bool height[10][10] = { false, };//��
bool wide[10][10] = { false, };	//��
bool square[10][10] = { false, };//�簢��
#define cal(x, y) (3*(x/3)+(y/3))	//�Ź� node�� ���� �ش簪 ����

void sdoku(int k)
{
	if (k == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << maps[i][j];
			cout << endl;
		}
		exit(0);			////return ���� �ϸ� error // return�� �ϰ� �� ��� main()�� ȣ���� ��Ʈ������Ʈ�ڵ��� �޺κ��� ����˴ϴ�.
	}
	int x = k / 9;
	int y = k % 9;

	if (maps[x][y] != 0)
		sdoku(k + 1);

	else
	{
		for (int num = 1; num <= 9; num++)
		{
			if (!height[x][num] && !wide[y][num] && !square[cal(x, y)][num])
			{
				height[x][num] = wide[y][num] = square[cal(x, y)][num] = true;

				maps[x][y] = num;
				sdoku(k+1);

				maps[x][y] = 0;
				height[x][num] = wide[y][num] = square[cal(x, y)][num] = false;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%1d", &maps[i][j]);
			//if (maps[i][j] != 0)
				height[i][maps[i][j]] = wide[j][maps[i][j]] = square[cal(i, j)][maps[i][j]] = true;
		}
	}
	sdoku(0);
	return 0;
}