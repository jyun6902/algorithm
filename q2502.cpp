#include <iostream>
using namespace std;
int dp_a[100001];
int dp_b[100001];
int dp[100001];

int main()
{
	int A = 1, B = 1;	//A= ó�� ���� �� �� �� ���� B= �� ���� �� �� ���� ����
	int D, K = 0;	//D= �ҸӴϰ� �Ѿ�� �� K=�� �� ȣ���̿��� �� ���� ����
	cin >> D >> K;
	dp_a[1] = 1;
	dp_a[2] = 0;
	dp_a[3] = 1;

	dp_b[1] = 0;
	dp_b[2] = 1;
	dp_b[3] = 1;
	for (int i = 4; i <= D; i++)
	{
		dp_a[i] = dp_a[i - 1] + dp_a[i - 2];
		dp_b[i] = dp_b[i - 1] + dp_b[i - 2];
	}

	while (1)
	{
		A++;
		int temp = K - (dp_a[D] * A);
		if (temp % (dp_b[D] * B) == 0)
		{
			B = temp / dp_b[D];
			break;
		}
	}

	cout << A << endl;
	cout << B << endl;
	return 0;
}