#include <iostream>
#include <deque>
#include <cmath>
#include <climits>
using namespace std;
#define LLONG_MIN(X,Y) ((X) < (Y) ? (X) : (Y))   
#define LLONG_MAX(X,Y) ((X) > (Y) ? (X) : (Y))  

int main()
{
	long long  L = 0, N = 0;	//L= map ũ�� (2L+1)// N=�Ӹ� ���� �� �� ȸ���ϴ���	
	long long sec = 0;
	long long t[1002] = { 0 };	//t�ʰ� dir��������
	int dir = 0, flag = 0;
	long long min_k = 3000000000, k = 0;
	long long  x = 0, y = 0;
	char d[1001];

	deque <pair<pair<long long, long long >, pair<long long, long long >>> h, w;// ������_x, ������_y, ������_x, ������_y// h=���� w=����
	cin >> L >> N;

	for (long i = 1; i <= N; i++)
		cin >> t[i] >> d[i];
	t[N + 1] = 30000000000;

	for (long long  case_T = 1; case_T <= N + 1; case_T++)
	{
		min_k = 3000000000;

		if (flag == 1)
		{
			cout << sec << endl;
			return 0;
		}

		if ( dir == 0)	//��
		{
			if (!w.empty())	//���μ��� ������
			{
				for (long long i = 0; i < w.size(); i++)
				{
					if (w[i].first.second == y && LLONG_MIN(w[i].first.first, w[i].second.first) >= x && LLONG_MIN(w[i].first.first, w[i].second.first) <= x + t[case_T])
					{
						k = abs(LLONG_MIN(w[i].first.first, w[i].second.first) - x);
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}
			}
			if (!h.empty())	//���� ���� ������
			{
				for (long long  i = 0; i < h.size() - 1; i++)
				{
					if (h[i].first.first >= x && h[i].first.first <= x + t[case_T] && LLONG_MIN(h[i].first.second, h[i].second.second) <= y && LLONG_MAX(h[i].first.second, h[i].second.second) >= y)
					{
						k = abs(h[i].first.first - x);
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}//for
			}

			if (x + t[case_T] > L)	//���� �Ѿ ��
			{
				k = abs(L + 1 - x); 
				min_k = LLONG_MIN(k, min_k);
				flag = 1;
			}

			if (flag == 1)
			{
				sec +=abs( min_k);
				break;
			}

			else if (flag == 0)					//�̵����� ���
			{
				w.push_back({ { x, y }, { x + t[case_T], y } });
				x += t[case_T];
				sec += t[case_T];
			}
		}//dir==0

		else if (dir == 2)	//��
		{
			if (!w.empty())	//���μ��� ������
			{
				for (long long  i = 0; i < w.size(); i++)
				{
					if (w[i].first.second == y && LLONG_MAX(w[i].first.first, w[i].second.first) <= x && LLONG_MAX(w[i].first.first, w[i].second.first) >= x - t[case_T])
					{
						k = abs(x - LLONG_MAX(w[i].first.first, w[i].second.first)); 
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}
			}

			if (!h.empty())	//���� ���� ������
			{
				for (long long  i = 0; i < h.size() - 1; i++)
				{
					if (h[i].first.first >= x - t[case_T] && h[i].first.first <= x  && LLONG_MIN(h[i].first.second, h[i].second.second) <= y && LLONG_MAX(h[i].first.second, h[i].second.second) >= y)
					{
						k = abs(h[i].first.first - x);
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}//for
			}

			if ( x - t[case_T] < -L)	//���� �Ѿ ��
			{
				k = abs(-L - 1 - x);
				min_k = LLONG_MIN(k, min_k);
				flag = 1;
			}

			if (flag == 1)
			{
				sec += abs(min_k);
				break;
			}

			else if (flag == 0)					//�̵����� ���
			{
				w.push_back({ { x, y },{ x - t[case_T], y } });
				x -= t[case_T];
				sec += t[case_T];
			}
		}//dir==2

		else if ( dir == 3)	//��
		{
			if (!h.empty())	//���μ��� ������
			{
				for (long long i = 0; i < h.size(); i++)
				{
					if (h[i].first.first == x && LLONG_MIN(h[i].first.second, w[i].second.second) >= y && LLONG_MIN(w[i].first.second, w[i].second.second) <= y + t[case_T])
					{
						k = abs(LLONG_MIN(h[i].first.second, h[i].second.second) - y);
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}
			}

			if (!w.empty())	//���� ���� ������
			{
				for (long long  i = 0; i < w.size() - 1; i++)
				{
					if (w[i].first.second >= y && w[i].first.second <= y + t[case_T] && LLONG_MIN(w[i].first.first, w[i].second.first) <= x && LLONG_MAX(w[i].first.first, w[i].second.first) >= x)
					{
						k = abs(w[i].first.second - y);//�ּҷ� �ϴ� �� ã��
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}//for
			}

			if (y + t[case_T] > L)	//���� �Ѿ ��
			{
				k = abs(L + 1 - y);
				min_k = LLONG_MIN(k, min_k);
				flag = 1;
			}

			if (flag == 1)
			{
				sec += abs(min_k);
				break;
			}

			else if (flag == 0)					//�̵����� ���
			{
				h.push_back({ { x, y },{ x, y + t[case_T] } });
				y += t[case_T];
				sec += t[case_T];
			}
		}//dir==3��

		else if ( dir == 1)	//��
		{
			if (!h.empty())	//���μ��� ������
			{
				for (long long  i = 0; i < h.size(); i++)
				{
					if (h[i].first.first == x && LLONG_MAX(h[i].first.second, w[i].second.second) <= y && LLONG_MAX(w[i].first.second, w[i].second.second) <= y - t[case_T])
					{
						k = abs(y - LLONG_MAX(h[i].first.second, h[i].second.second));
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}
			}
			
			if (!w.empty())	//���� ���� ������
			{
				for (long long  i = 0; i < w.size() - 1; i++)
				{
					if (w[i].first.second <= y && w[i].first.second >= y - t[case_T] && LLONG_MIN(w[i].first.first, w[i].second.first) <= x && LLONG_MAX(w[i].first.first, w[i].second.first) >= x)
					{
						k = abs(w[i].first.second - y);//�ּҷ� �ϴ� �� ã��
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}//for
			}

			if (y - t[case_T] < -L)	//���� �Ѿ ��
			{
				k = abs(-L - 1 - y);
				flag = 1; 
				min_k = LLONG_MIN(k, min_k);
			}

			if (flag == 1)
			{
				sec += abs(min_k);
				break;
			}

			else if (flag == 0)					//�̵����� ���
			{
				h.push_back({ { x, y },{ x, y - t[case_T] } });
				y -= t[case_T];
				sec += t[case_T];
			}
		}//dir==1��

		if (d[case_T] == 'L')
			dir = (dir + 3) % 4;

		else if (d[case_T] == 'R')
			dir = (dir + 1) % 4;
	}

	if (flag == 0 && dir == 0)	//��
		sec += abs(L + 1 - x);
	else if (flag == 0 && dir == 1)	//��
		sec += abs(-L - 1 - y);
	else if (flag == 0 && dir == 2)//��
		sec += abs(-L - 1 - x);
	else if (flag == 0 && dir == 3)	//��
		sec += abs(L + 1 - y);

	cout << sec << endl;
	return 0;
}