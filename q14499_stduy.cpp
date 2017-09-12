/*
 N,M ���� �Ѿ�� ���, ����Լ����� ��� �ݺ��� �� ����
 ->flag�� ���� �־� �ݺ�����
*/
#include <iostream>
#include <cstring>
using namespace std;
int N, M, x, y, K = 0;//N=����, M=����, x, y=�ֻ��� ��ǥ, K= ����� ����
int maps[22][22];
int order[1001];
int flag = 0;			//���� ����� ����Լ��� ��� �ݺ��ؼ� ���� �ɾ���
int dice[4][3] = { { 0, 0, 0 }
				, { 0, 0, 0 }
				, { 0, 0, 0 }
				, { 0, 0, 0 } };

void swap_dice(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void dice_cal(int a, int b, int dir, int cnt)
{
	if (cnt > K)
	{
		flag = 1;
		return;
	}

	if (dir == 1)//��
	{
		if (b + 1 >= M&& flag == 0)
			dice_cal(a, b, order[cnt + 1], cnt + 1);
		else
		{
			swap_dice(&dice[1][0], &dice[3][1]);
			swap_dice(&dice[1][1], &dice[1][2]);
			swap_dice(&dice[1][1], &dice[3][1]);
			b += 1;
		}
	}

	else if (dir == 2)//��
	{
		if (b - 1 < 0 && flag == 0)
			dice_cal(a, b, order[cnt + 1], cnt + 1);
		else
		{
			swap_dice(&dice[1][2], &dice[3][1]);
			swap_dice(&dice[1][0], &dice[3][1]);
			swap_dice(&dice[1][0], &dice[1][1]);
			b -= 1;
		}
	}

	else if (dir == 3)//��
	{
		if (a - 1 < 0 && flag == 0)
			dice_cal(a, b, order[cnt + 1], cnt + 1);
		else
		{
			swap_dice(&dice[0][1], &dice[1][1]);
			swap_dice(&dice[1][1], &dice[2][1]);
			swap_dice(&dice[2][1], &dice[3][1]);
			a -= 1;
		}
	}

	else if (dir == 4)//��
	{
		if (a + 1 >= N&& flag == 0)
			dice_cal(a, b, order[cnt + 1], cnt + 1);
		else
		{
			swap_dice(&dice[0][1], &dice[1][1]);
			swap_dice(&dice[2][1], &dice[3][1]);
			swap_dice(&dice[0][1], &dice[2][1]);
			a += 1;
		}

	}

	if (maps[a][b] == 0 && flag == 0)		//������ 0�� ���
	{
		maps[a][b] = dice[3][1];//�ֻ��� �ظ� ������ ����
		cout << dice[1][1] << endl;			//���� ���
	}

	else if (maps[a][b] > 0 && flag == 0)	//������ 0�� �ƴ� ���
	{
		dice[3][1] = maps[a][b];//���� �ظ� �ֻ����� ����
		maps[a][b] = 0;			//���� 0
		cout << dice[1][1] << endl;
	}

	if (flag == 0)
		dice_cal(a, b, order[cnt + 1], cnt + 1);
	else
		return;
}

int main()
{
	memset(maps, -1, sizeof(maps));
	int dir = 4;
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> maps[i][j];
	}

	for (int i = 1; i <= K; i++)
		cin >> order[i];

	dice_cal(x, y, order[1], 1);	//dice_cal(int a, int b, int dir, int cnt)

	return 0;
}