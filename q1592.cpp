#include <iostream>
using namespace std;

int main()
{
	int N, M, L = 0;	//N=����� M=���� M���޾� ������ �� L=L����ŭ �¿�� �̵�
	int arr[1001] = { 0 };	//ī��Ʈ����
	int now = 1, cnt = 0;
	arr[1] = 1;	//1������ ����
	cin >> N >> M >> L;

	while (1)
	{
		if (arr[now] == M)
			break;

		if (arr[now] % 2 == 1)	//Ȧ���� ��� -> ���������� L��ŭ �̵�
		{
			if (now + L > N)
				now = (now + L) - N;

			else
				now += L;
		}

		else //¦���� ��� -> �������� L��ŭ �̵�
		{
			if (now - L <= 0)
				now = N + (now - L);

			else
				now -= L;
		}

		arr[now] ++;
		cnt++;
	}

	cout << cnt << endl;
	return 0;
}