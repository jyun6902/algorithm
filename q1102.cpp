#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N = 0, P = 0;	//������ ���� 1<=N<=16 // P= ���  P���� �����Ұ� �������� 0<=P<=N
int dp[17][1 << 17];	//[from][���� ��]	//���������� ����
int cost[17][17] = { 0 };
int cal(int cnt, int on)
{
	if (cnt >= P)
		return 0;

	if (dp[cnt][on] >= 0)
		return dp[cnt][on];

	dp[cnt][on] = 987654321;
	for (int i = 0; i < N; i++)
	{
		if ((on & (1 << i)) != 0)	//������ �Ӽ� ���� ���
		{
			for (int j = 0; j < N; j++)
			{
				if (i == j || (on&(1 << j )) != 0)
					continue;
				dp[cnt][on] = min(dp[cnt][on], cal(cnt + 1, (on | 1 << j )) + cost[i][j]);
			}
		}
	}

	return dp[cnt][on];
}

int main()
{
	char turn[17];
	int cnt = 0, on = 0;
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> cost[i][j];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> turn[i];
		if (turn[i] == 'Y')
		{
			on |= (1 << i) ;
			cnt++;
		}
	}
	cin >> P;
	int result = cal(cnt, on);
	if (result == 987654321)
		cout << "-1" << endl;
	else
		cout << result << endl;
	return 0;
}