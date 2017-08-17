#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n = 0, m = 0;	//n=���� m=����
int result = 0;
int dp[1001][1001];	//d[i][j] ; (ū��)i�� (������)j������ ��Ī �������� �ּ� ��������
vector<int> man;
vector<int> woman;
vector<int> big;
vector<int> small;

int min_2(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int min_a = 987654321, min_key = 0;
	int a, b = 0;
	memset(dp, 0, sizeof(dp));
	cin >> n >> m;
	man.push_back(-1);
	woman.push_back(-1);
	for (int i = 0; i < n; i++)		//����
	{
		cin >> a;
		man.push_back(a);
	}

	for (int i = 0; i < m; i++)		//����
	{
		cin >> a;
		woman.push_back(a);
	}

	sort(man.begin(), man.end());
	sort(woman.begin(), woman.end());

	if (n == m)		//���� ���� ��� ���� ���
	{
		for (int i = 1; i <= n; i++)
			result += abs(man[i] - woman[i]);
	}

	else
	{
		if (n > m)
		{
			big = man;
			small = woman;
		}

		else
		{
			big = woman;
			small = man;
		}

		for (int i = 1; i < big.size(); i++)
		{
			for (int j = 1; j < small.size(); j++)
			{
				dp[i][j] = dp[i - 1][j - 1] + abs(big[i] - small[j]);	//dp�� �������տ� ���簪 ���� ���� 
				if (i > j && dp[i][j] > dp[i - 1][j])//���簪���� �����̶� ������ �� �� ������ dp ������Ʈ
					dp[i][j] = dp[i - 1][j];
				else if (i < j && dp[i][j] > dp[i][j - 1])	
					dp[i][j] = dp[i][j - 1];
			}
		}
	}//else

	cout << dp[big.size() - 1][small.size() - 1] <<" " ;
	return 0;
}