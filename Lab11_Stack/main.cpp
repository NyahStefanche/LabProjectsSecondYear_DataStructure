#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;
int main()
{
	string str;
	cin >> str;
	int len = str.size();
	Stack<bool> s;
	bool b1, b2, b3;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '0' || str[i] == '1') s.Push(str[i] - '0');
		else if (str[i] == ' ^ ')
		{
			s.Pop(b1);
			s.Pop(b2);
			s.Push(b1 && b2);
		}
		else if (str[i] == 'v')
		{
			s.Pop(b1);
			s.Pop(b2);
			s.Push(b1 || b2);
		}
		else if (str[i]=='*')
		{
			s.Pop(b1);
			s.Pop(b2);
			s.Pop(b3);
			bool b = b2 || b3;
			s.Push(b == b1);
		}
		else // оперцията е отрицание ~
		{
			s.Pop(b1);
			s.Push(!b1);
		}
	}
	s.Pop(b1);
	cout << b1 << endl;
	system("pause");
	return 0;
}