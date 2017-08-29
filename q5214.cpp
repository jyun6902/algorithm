#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
/*���� �ȵ��ִ� ��� ���ѷ�Ʈ ���Ե�
�ݺ������� 1000ȸ�� ��쿡�� for���� while�� ���� �� ����
1000�̻��� ��� while���� for�� ���� ����
while() ->for()�� �ٲ㼭 98%���� �ð��ʰ� ���� �� �ذ�
*/
int tube[100003] = {};
deque <vector<int>> dq;
vector <int>connect;
int main()
{
	int N, K, M = 0;	//N = ���Ǽ�, K= �� ������Ʃ�갡 ���� �����ϴ� ���� ��, M= ������Ʃ���� ����
	cin >> N >> K >> M;	// (1 �� N �� 100,000, 1 �� K, M �� 1000)
	int a = 0;

	for (int i = 1; i <= N; i++)
		tube[i] = 987654321;

	tube[1] = 1;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			cin >> a;
			connect.push_back(a);
		}
		dq.push_back(connect);
		connect.clear();
	}

	while (!dq.empty())
	{
		int d_size = dq.size();
		for (int t = 0; t < d_size; t++)//while�� �� ��� �ð��ʰ�
		{
			connect = dq.front();
			dq.pop_front();
			int flag = 0;
			int result = 987654321;
			int key = 0;

			for (int i = 0; i < K; i++)
			{
				if (tube[connect[i]] < result)//����Ʈ�Ȱ� �߿� ���� ���� �� ã��
				{
					result = tube[connect[i]];
					key = i;
					flag = 1;
				}
			}

			if (flag == 0)						//����Ʈ �ȉ��� ��� deque�� �ٽ� ����
				dq.push_back(connect);

			else
			{
				for (int j = 0; j < K; j++)
				{
					if (key == j)
						continue;

					if (tube[connect[key]] + 1 < tube[connect[j]])	//����Ʈ �ȰͿ��� �� ���� ��� ������Ʈ
						tube[connect[j]] = tube[connect[key]] + 1;
				}
			}

		}//while d_size
		if (d_size == dq.size())		//�� �̻� ������� �ʾ��� ���
			break;
	}//while 

	if (tube[N] == 987654321)
		cout << "-1" << endl;

	else
		cout << tube[N] << endl;
	return 0;
}