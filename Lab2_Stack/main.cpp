#include<iostream>
#include "Stack.h"
using namespace std;
int main()
{

	Stack<int> s,s1;
	long n;
	cin >> n;
	s.Push(n % 10);
	int k;
	while (n)
	{
		s.Top(k);
		if (k != n % 10) s.Push(n % 10);
		n /= 10;
	}
	while (!s.Empty())
	{
		s.Pop(k);
		cout << k;
		s1.Push(k);
	}
	while (!s1.Empty())
	{
		s1.Pop(k);
		cout << k;
	}
	system("pause");
	return 0;
}
