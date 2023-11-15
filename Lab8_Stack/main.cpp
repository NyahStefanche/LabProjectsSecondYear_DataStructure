#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
	system("chcp 1251");
	int n;
	int sredno = 0;
	Stack<int>s;
	int br = 0;
	int n1 = 0;
	do
	{
		cin >> n;
		if (n!=0) s.Push(n);
	} while (n);
	while (!s.Empty())
	{
		s.Pop(n);
		br++;
		n1 += n;
	}
	sredno = n1 / br;
	cout <<"Средно аритментичното е: "<<sredno << endl;
	system("pause");
	return 0;
}