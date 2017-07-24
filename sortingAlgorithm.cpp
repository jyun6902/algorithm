#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Selection_Sort(vector<int> v);
void Insertion_Sort(vector<int> v);
void Bubble_Sort(vector<int> v);
void Merge(vector <int>& v, int s, int e, int m); 
void Merge_Sort(vector<int>& v, int s, int e);
void Quick_Sort(vector<int> &v, int s, int e);
void Print(vector<int>v);
void Selection_Sort(vector<int> v)
{
	for (int i = 0; i < v.size()-1; i++)
	{
		int tmp = i;//�ε����� �� �տ�������
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[tmp] >= v[j])//���� ���� ���� ã����, �� ���� ���� �ε����� ���� �ٲ���
				tmp = j;
		}
		swap(v[i], v[tmp]);
		Print(v);
	}	
	//Print(v);
}

void Insertion_Sort(vector<int> v)
{
	for (int i = 1; i < v.size(); i++)
	{
		int key = v[i];	//�ι�° �ε������� ����, ������ ������ ����
		int j = i - 1;	//�� �ε��� �����ε���-1
		
		while (j >= 0 && key < v[j])	//������ �����ص� ������ �� �ε����� �迭�� ��
		{
			swap(v[j], v[j + 1]);
			j--;						//�� �ε����� -1�Ͽ� �񱳸� �ݺ�
		}
		v[j + 1] = key;				//���� ������ �� Ŭ ���, �� �ε���+1�� ���� ���� ����
		Print(v);
	}
}

void Bubble_Sort(vector<int> v)
{
	for (int i = 0; i < v.size()-1; i++)
	{
		for (int j = 1; j < v.size() -i; j++)
		{
			if (v[j-1] > v[j])
				swap(v[j-1], v[j]);
		}
			Print(v);
	}
}

void Merge(vector <int>& v, int s, int e, int m) //�պ�
{
	vector <int> ret;
	int i = s, j = m + 1, copy = 0;
	
	//����� ������ �迭�� �ϳ��� ���Ͽ� �����Ѵ�.
	while (i <= m && j <= e)
	{
		if (v[i] < v[j])
			ret.push_back(v[i++]);
		else if (v[i] > v[j])
			ret.push_back(v[j++]);
	}

	//���� ������ �ڿ� ä�� �־��ش�
	while (i <= m)
		ret.push_back(v[i++]);
	while (j <= e)
		ret.push_back(v[j++]);

	//���� �迭�� �������ش�.
	for (int k = s; k <= e; k++)
		v[k] = ret[copy++];
}

void Merge_Sort(vector<int>& v, int s, int e)
{
	if (s < e)
	{
		int m = (s + e) / 2;
		////���� divide
		Merge_Sort(v, s, m);	//from s to m
		Merge_Sort(v, m + 1, e);	//from m+1 to e
		////�պ� conquer
		Merge(v, s, e, m);
	//cout << s << " " << e << " " << m << endl;
	//Print(v);
	}

}

void Quick_Sort(vector<int> &v, int s, int e)
{
	int pivot = v[s];
	int bs = s, be = e;
	while (s < e)
	{
		while (pivot <= v[e] && s < e)
			e--;
		if (s > e)
			break;
		while (pivot >= v[s] && s < e)
			s++;
		if (s > e)
			break;
		swap(v[s], v[e]);
	}
	swap(v[bs], v[s]);

	cout << pivot << endl;
	Print(v);
	
	if (bs < s)
		Quick_Sort(v, bs, s - 1);
	if (be > e)
		Quick_Sort(v, s + 1, be);
	
}

void Print(vector<int>v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v.at(i)<< " ";
	cout << endl;
}

int main()
{
	vector <int> v;
	//v = { 3,7,4,5,2,1,9,8,6 };
	v = { 23, 79, 98, 56, 16, 25, 58, 55 };
	//Selection_Sort(v);
	//Insertion_Sort(v);
	//Bubble_Sort(v);
	//Merge_Sort(v,0, v.size()-1);
	Quick_Sort(v, 0, v.size() - 1);
	return 0;
}