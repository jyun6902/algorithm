/*
���ѽð� : 1��
�޸����� : 128MB
�׽�Ʈ���̽� : 1

*/
#include <iostream>

using namespace std;
int N = 0, M = 0, X = 0;
int T[1002][1002];

int main()
{
	cin >> N >> M >> X;		//�л���, ���μ�, ������
	int x, y = 0, t = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			T[i][j] = 987654321;
			if (i== j)
			{
				T[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> x >> y >> t;	//������, ����, �ҿ�ð�
		if (T[x][y] > t)
		T[x][y] = t;
	}

	for (int k = 1; k <= N; k++)	//floyd k = �����ϴ� ���� !!
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (T[i][k] +T[k][j] < T[i][j])
					T[i][j] = T[i][k] + T[k][j];
			}
		}
	}

	int max_result = 0;
	for (int i = 1; i <= N; i++)
	{
		if (T[X][i] + T[i][X] > max_result)
			max_result = T[X][i] + T[i][X];
	}

	cout << max_result << endl;
	return 0;
}