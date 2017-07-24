#include <iostream>
#include <cstring>
using namespace std;

int map[505][505];
int N, M = 0;	//N ���� M ����
int result = 0, max_result;
int main()
{
	memset(map, 0, sizeof(map));

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++)		//���η� 1��
	{

		for (int j = 1; j <= M - 3; j++)
		{
			if (result < map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3])
				result = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
		}
	}

	for (int i = 1; i <= N - 3; i++)
	{
		for (int j = 1; j <= M; j++)		//���η� 1��
		{
			if (max_result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j])
				max_result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//���簢��
	{

		for (int j = 1; j <= M - 1; j++)
		{
			if (result < map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1])
				result = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)		//L���
	{

		for (int j = 1; j <= M - 1; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1])
				result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)		//L | -l �ݴ���
	{

		for (int j = 2; j <= M; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j - 1])
				result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j - 1];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)		//L | _|��� ��
	{
		for (int j = 2; j <= M; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j - 1])
				result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j - 1];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)		//L | i- �ݴ���
	{

		for (int j = 1; j <= M - 1; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1])
				result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//�� |___���
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2])
				result = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 2; i <= N; i++)		//���ݴ�___l ���
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 2])
				result = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 2];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//|--- ���
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2])
				result = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//---| ���
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i + 1][j + 2] + map[i][j + 1] + map[i][j + 2])
				result = map[i][j] + map[i + 1][j + 2] + map[i][j + 1] + map[i][j + 2];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//�̸��
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1])
				result = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 2; i <= N; i++)		//�Ǹ�� 13
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1])
				result = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1];
		}
	}


	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 1; j <= M - 1; j++)		//����� 14	/////////////////////////////////////////
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1])
				result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
		}
	}


	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 2; j <= M; j++)		//�ø�� 15	/////////////////////////////////////////

		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j - 1])
				result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j - 1];
		}
	}


	if (max_result < result)
		max_result = result;

	/*
	��
	����
	  ��
	*/
	for (int i = 1; i <= N - 2; i++)		//|-|��� 16
	{
		for (int j = 1; j <= M - 1; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1])
				result = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
		}
	}


	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)		//|-|��� 17
	{

		for (int j = 2; j <= M; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j - 1])
				result = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j - 1];
		}
	}


	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//-|_��� 18
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2])
				result = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//|-|��� 19
	{

		for (int j = 3; j <= M; j++)
		{
			if (result < map[i][j] + map[i][j - 1] + map[i + 1][j - 1] + map[i + 1][j - 2])
				result = map[i][j] + map[i][j - 1] + map[i + 1][j - 1] + map[i + 1][j - 2];
		}
	}


	if (max_result < result)
		max_result = result;
	cout << max_result;

	return 0;
}