/*
sort�� �ʿ� x
�Է¹��� ���� �迭�� �����ϰ�
num�� �����鼭 �迭�� �ִ��� üũ
printf, scanf���� cin,cout �ᵵ ������
(�ӵ��� �� ����)
*/
#include <iostream>
#include <cstdio>
using namespace std;
int card[20000001];
int num[20000001];
int N, M;	//N=����̰� ������ �ִ� ���� ī���� ����. 

int main()
{
	int x = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		card[x+10000000] = 1;	//�Է¹��� �迭�� 1�� üũ
	}
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &x);
		if (card[x + 10000000] == 1)	//�Է¹��� ���� ������ ���
			num[i] = 1;
		else
			num[i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");

	return 0;
}