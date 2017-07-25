#include <iostream>
#include <cstring>
using namespace std;
int maps[2000000];	//���� -999~999�̹Ƿ� 
int dice[1002];

int main()
{
	int N, M = 0;	//1~Nĭ ���� ����, M=����̰� �ֻ����� ���� Ƚ��
	int cnt = 0;
	int now = 1;
	memset(maps, 0, sizeof(maps));
	memset(dice, 0, sizeof(dice));
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> maps[1000000 + i];

	for (int i = 1; i <= M; i++)
		cin >> dice[i];

	for (int i = 1; i <= M + 1; i++)
	{
		if (now >= N)
		{
			cout << cnt << endl;
			return 0;
		}

		now += dice[i];
		now += maps[1000000 + now];
		cnt++;
	}

	return 0;
}