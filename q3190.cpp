#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int maps[101][101] = { 0 };
	int X[101] = { 0 };				//���⺯ȯ ���� ����
	char C[101] = { 0 };	//���⺯ȯ ���� ���� L = ���� D = ������
	int N = 0, K = 0, L = 0;//N= ���� ũ��, K = ��� ����, L = ���� ��ȯ ����
	int sec = 0;
	deque <pair <int, int>> snake;

	cin >> N >> K;
	snake.push_back({ 1,1 });	//ó�� ������ ��
	for (int i = 1; i <= K; i++)
	{
		int a, b = 0;
		cin >> a >> b;
		maps[a][b] = 2;	//����� ���� ��� 2
	}

	cin >> L;
	for (int i = 1; i <= L; i++)
		cin >> X[i] >> C[i];

	int x = 1, y = 1, dir = 0, cnt = 1;

	while (++sec)
	{
		
		if (dir == 0)			//��
			y++;
		else if (dir == 1)		//��
			x++;
		else if (dir == 2)		//��
			y--;
		else if (dir == 3)		//��
			x--;

		if (x< 1 || x> N || y< 1 || y> N)	//�ٱ����� ������ ���
		{
			cout << sec << endl;
			return 0;
		}

		for (int i = 0; i < snake.size(); i++)		//�ڱ� �ڽ� �ε����� ���  
		{
			if (snake[i].first == x && snake[i].second == y)
			{
				cout << sec << endl;
				return 0;
			}
		}

		if (maps[x][y] != 2)	//����� ���� ���
			snake.pop_back();	//���� ������

		if (maps[x][y] == 2)	//��� ���� ���
			maps[x][y] = 0;

		snake.push_front({ x,y });

		if (X[cnt] == sec)			//��� �ʸ�ŭ �̵����� ���
		{
			if (C[cnt] == 'D')	//�������� ��� 
				dir = (dir + 1) % 4;
			else if (C[cnt] == 'L')
				dir = (dir + 3) % 4;
			cnt++;
		}

	}

	cout << sec << endl;
	return 0;
}