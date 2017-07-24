#include <iostream>
#include <cstring>
using namespace std;
int N = 0;		// �������� ����
int A[1000001];	// i�� �����忡 �ִ� �������� ��
int B, C = 0;	// B=�Ѱ������� �� �濡 ������ �� �ִ� ������ �� , C =�ΰ�����
int dp[1000001];

int cal_num(int x)
{
	if (0 > x || x > 1000001)
		return 0;

	if (dp[x] != 0)
		return dp[x];

	int result = 0;

	dp[x] = 1;
	int y = x;
	y -= B;

	while (y > 0)
	{
		y -= C;
		++result;
	}
	return dp[x] += result;
}

int main()
{
	long long sum = 0;
	memset(A, 0, sizeof(A));
	memset(dp, 0, sizeof(dp));
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	cin >> B >> C;

	for (int i = 1; i <= N; i++)
		sum += cal_num(A[i]);

	cout << sum << endl;
	return 0;
}
