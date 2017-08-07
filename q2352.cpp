#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0, x = 0;
	deque <int> dq;
	cin >> n;			// n = ��Ʈ ����

	dq.push_back(-987654321);
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (dq.back() < x)
			dq.push_back(x);
		else
		{
			auto it = lower_bound(dq.begin(), dq.end(), x);	//lower_bound ; ������ ������ ���� ������ ũ�ų� ���� ���� ������ ������ ��ġ�� ��ȯ
			*it = x;
		}
	}

	cout << dq.size()-1 << endl;		//ó���� dq�� -���Ѵ� push
	return 0;
}