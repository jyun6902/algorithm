#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string S, S_rever;
	cin >> S;
	int len = S.length();
	int cnt = 0;

	while (1)
	{
		S_rever= S;
		reverse(S_rever.begin(), S_rever.end());//���ڿ� ������
		if (S.compare(S_rever) == 0)			//���ڿ��� ���� ���
			break;

		else									//�ٸ� ���
		{
			S.erase(len, len + cnt);				//�߰��ߴ� ��ŭ ����
			string cp = S_rever.substr(S_rever.length()-cnt-1, S_rever.length());	//�߰��� �κ� (������ �迭�� ������ �ϳ��� ����)
			S.insert(len, cp);					//�߰�
		}
		cnt++;
	}

	cout << S.length() << endl;
	return 0;
}