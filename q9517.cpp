#include <iostream>
using namespace std;

int main()
{
	int K = 0, N=0;	//��ź�� ��� �ִ� ����� ��ȣ, ������ ����
	int sec = 0;	//�ҿ�Ǵ� �ð�
	cin >> K >> N;
	for (int i = 1; i <= N; i++)
	{
		int T = 0;//������ ����ϱ���� �ɸ��ð�
		char Z;	//�÷��̾��� ��� (T, N ,P)

		cin >> T >> Z;
		sec += T;

		if (sec >= 210)	//3�� 30��
		{
			cout << K<<endl;
			return 0;
		}

		if (Z == 'T')
		{
			K =  (K + 1) % 8;
			if (K == 0)			//k=7�����ϸ� 8���;� �ϴµ� 0���� �����Ƿ�
				K = 8;
		}
	}
	return 0;
}