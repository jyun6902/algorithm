#include <iostream>
using namespace std;

int main()
{
	int N = 0, m = 0, M = 0, T = 0, R = 0; //N=� �ð�, m=ó�� �ƹ�, M= �ִ� �ö� �� �ִ� �ƹ�, T= ��ŭ ����. R= ��ŭ ����
	cin >> N >> m >> M >> T >> R;
	int min = 0, X = m, exercise = 0; //min = �ɸ��� �ð� X= ���� �ƹ�

	if (T > M - m)	//1�� ��Ҷ� �����ϴ� �ƹ� > �ִ�-�ּ� �ɹڼ�����
	{
		cout << "-1" << endl;
		return 0;
	}

	while (1)
	{
		while (X + T <= M)	//��ð�
		{
			X += T;
			exercise++;
			min++;

			if (exercise == N)
			{
				cout << min << endl;
				return 0;
			}
		}

		if (X + T > M)//�ִ� �ö󰥼� �ִ� �ƹ� ���� ū���
		{
			X -= R;
			min++;

			if (X <= m)
				X = m;
		}
	}
	return 0;
}