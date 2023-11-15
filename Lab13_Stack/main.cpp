#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int l = str.size();
	Stack<int>s;
	int x, y;
	for (int i = 0; i < l; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			s.Push(str[i] - '0');
		else
		{
			if (str[i] == 'm')
			{
				s.Pop(x);
				s.Pop(y);
				if (x < y) s.Push(x);
				else s.Push(y);
			}
			else if (str[i]=='M')
			{
				s.Pop(x);
				s.Pop(y);
				if (x > y) s.Push(x);
				else s.Push(y);
			}
		}
	}
	s.Pop(x);
	cout << x << endl;
	system("pause");
	return 0;
}