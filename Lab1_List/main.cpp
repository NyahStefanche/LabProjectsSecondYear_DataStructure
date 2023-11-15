//������ �� �� ������� ���� ���������� ������ Sort �� �� ��������� ������� ��������� �� ��������
#include <iostream>
#include "List.h"
using namespace std;
void printList(List<int> list)
{
	int s = list.Size();
	for (int i = 0; i < s; i++)
	{
		int n;
		list.GetPos(i, n);
		cout << n << " ";
	}
	cout << endl;
}

int main()
{
	List<int> good, bad;
	int n;
	cin >> n;
	while (n != 0)
	{
		int num;
		//�������� ���� � � ������ � ������� �����
		if (good.Find(n, num))
		{
			cout << "bad" << endl;
			good.DelVal(n);
			bad.InsEnd(n);
		}
		else if (bad.Find(n, num))
		{
			cout << "bad" << endl;
		}
		else //������� �� �������� � ���� ���� �� ��������� good, bad 
		{
			cout << "good" << endl;
			good.InsEnd(n);
		}
		cin >> n;
	}
	cout << "good:" << endl;
	printList(good);
	cout << "bad:" << endl;
	printList(bad);
	system("pause");
	return 0;
}
