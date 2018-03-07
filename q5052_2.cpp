#include <cstdio>
#include <cstring>
#include <iostream>
#define D_NUM 10
using namespace std;
//char s���� 10����!!!
struct Trie
{
	bool finish;    //������ ������ ǥ������
	Trie* next[D_NUM];
	Trie() : finish(false)
	{
		memset(next, 0, sizeof(next));
	}
	~Trie()
	{
		for (int i = 0; i < D_NUM; i++)
			if (next[i] != NULL)
				delete next[i];
	}
	void insert(const char* key)
	{
		if (*key == 0)
			finish = true;    //���ڿ��� ������ ������ ��� ǥ��
		else
		{
			int curr = *key - '0';
			if (next[curr] == NULL)
				next[curr] = new Trie();    //Ž���� ó���Ǵ� ������ ��� �����Ҵ�
			next[curr]->insert(key + 1);    //���� ���� ����

		}
	}

	bool find(const char* key)
	{
		if (*key == '\0')
		{
			return false;//���ڿ��� ������ ��ġ��	
		}

		if (finish == 1)
		{
			return true;
		}
		int curr = *key - '0';
		return next[curr]->find(key + 1); //���� ���ڸ� Ž��
	}
};

int main()
{
	int N = 0, K = 0;
	scanf("%d", &N);
	for (int t_c = 0; t_c < N; t_c++)
	{
		scanf("%d", &K);
		char s[10000][11] = {};
		Trie* ptn = new Trie();
		int flag = 0;

		memset(s, 0, sizeof(s));
		for (int i = 0; i < K; i++)
		{
			cin >> s[i];
			ptn->insert(s[i]);
		}

		for (int i = 0; i < K; i++)
		{
			if (ptn->find(s[i]))
			{
				flag = 1;
				printf("NO\n");
				break;
			}
		}
		if (flag == 0)
			printf("YES\n");
	}//t_c

	return 0;
}