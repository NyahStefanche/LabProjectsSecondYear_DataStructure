#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
	int n;
	Stack<int>s;
	do 
	{
		cin >> n;
		if(n!=0) s.Push(n);
	} while (n);
	while (!s.Empty())
	{
		s.Pop(n);
		cout << n;
	}
	system("pause");
	return 0;
}