#include "Stack.h"
#include <iostream>
using namespace std;
int main()
{
	Stack<int> s;
	int n;
	cin >> n;
	while (n)
	{
		s.Push(n % 2);
		n /= 2;
	}
	while (!s.Empty())
	{
		s.Pop(n);
		cout << n;
	}
	system("pause");
	return 0;
}