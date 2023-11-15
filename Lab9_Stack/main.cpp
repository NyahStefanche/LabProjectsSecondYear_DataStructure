#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
	system("chcp 1251");
	Stack<int> s;
	int n;
	cout << "Въведете цяло число: ";
	cin >>n;
	int suma = 0;
	do
	{
		s.Push(n % 10);
		n = n / 10;
	} while (n);
	while (!s.Empty())
	{
		s.Pop(n);
		suma = suma + n;
	}
	cout <<"Сумата е: "<<suma << endl;
	system("pause");
	return 0;
}