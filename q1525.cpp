#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
/*
to_string() �Լ� ;  int�� ���� ���ڿ��� ��ȯ
stoi() : ���ڿ��� ���ڷ� ��ȯ�ϴ� �����Լ�
0�� 9�� ����
string, int ��ȯ ���ϱ�
*/

int main()
{
	queue <int> q;
	map <int, int> m;
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	int result = 0;

	for (int i = 0; i < 9; i++)
	{
		int temp = 0;
		cin >> temp;
		if (temp == 0)
			temp = 9;
		result = 10 * result + temp;
	}

	m[result] = 0;
	q.push(result);

	while (!q.empty())
	{
		int num = q.front();
		string s_num = to_string(num);//int�� string���� ��ȯ

		q.pop();
		int zero = s_num.find('9');
		int z_x = zero / 3;
		int z_y = zero % 3;

		for (int i = 0; i< 4; i++)
		{
			int x = z_x + dx[i];
			int y = z_y + dy[i];

			if (x >= 3 || x < 0 || y >= 3 || y < 0)
				continue;

			string next = s_num;
			swap(next[z_x * 3 + z_y], next[3 * x + y]);	//��ǥ 1�������� ����
			int next_num = stoi(next);					//stoi() ; ���ڿ��� ���ڷ� ��ȯ�ϴ� �����Լ�
			if (m.count(next_num) == 0)					//map.count (key) ; key�� �����ϴ��� Ȯ��// ������ ��� ; 1, ����x ; 0
			{
				m[next_num] = m[num] + 1;
				q.push(next_num);
			}
		}
	}

	if (m.count(123456789) == 0)
		cout << "-1" << endl;
	else
		cout << m[123456789] << endl;
	return 0;
}