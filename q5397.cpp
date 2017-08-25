#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
//���� first in last out
int main()
{
	int T = 0;//�׽�Ʈ ���̽�
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		string letter1;
		cin >> letter1;
		deque <char> left;
		deque <char> right;

		for (int i = 0; i < letter1.length(); i++)
		{
			if (letter1[i] == '<')			//�������� Ŀ�� �̵�
			{
				if (!left.empty())
				{
					char t = left.back();
					right.push_front(t);
					left.pop_back();
				}
			}
			else if (letter1[i] == '>')		//���������� Ŀ�� �̵�
			{
				if (!right.empty())
				{
					char t = right.front();
					left.push_back(t);
					right.pop_front();
				}
			}
			else if (letter1[i] == '-')
			{
				if (!left.empty())
					left.pop_back();
			}
			else							//������ ���
				left.push_back(letter1[i]);
		}// for 

		for (auto iter = left.begin(); iter != left.end(); iter++)
			cout << *iter;
		
		for (auto iter = right.begin(); iter != right.end(); iter++)
			cout << *iter;
		cout << endl;
	}// for test_case
	return 0;
}