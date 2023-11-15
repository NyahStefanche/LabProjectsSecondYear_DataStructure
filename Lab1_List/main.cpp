//Трябва да се довърши като използваме метода Sort да се отпечатат числата подредени по големина
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
		//проверка дали е в списък с добрите числа
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
		else //числото не фигурира в нито един от списъците good, bad 
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
