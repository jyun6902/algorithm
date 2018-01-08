#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;
//endl �ð��ʰ��ɶ��� '\n' �� �ٲٱ�
/*
map���� set�� �ӵ� �� ����

- map
key, value �ѽ���
Ʈ��������
���� �ڵ� ������ ��
�˻��ӵ��� �Ϸ� ���(list, vector)���� ����
�������δ� ���� ������ ����ϸ� �ȵ�!!!(�Ҷ����� �����ϰ� ����.)

-set
map�� ���� ��� ������ map���� �ٸ��� key�� ����(���... Ʈ�� ����?)
key�� �ż��ϰ� ã��, �� key�� ���ĵǱ⸦ ���Ҷ� ����.
*/
int main()
{
	int n = 0;
	string name;
	string el;//e=enter ; l=leave
	set <string> s;
	set<string>::reverse_iterator iter;
	cin >> n;

	while (n--)
	{
		cin >> name >> el;
		if (el == "enter")
			s.insert(name);

		else //el == "leave"
			s.erase(name);//s.erase(s.find(name));
	}
	
	for (iter = s.rbegin(); iter != s.rend(); iter++)
			cout << (*iter) <<'\n';

	return 0;
}