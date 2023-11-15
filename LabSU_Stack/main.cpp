#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	int len = str.size();
	Stack<bool> s;
	bool b1, b2;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '0' || str[i] == '1')s.Push(str[i] - '0');
		else if (str[i] == '^')
		{
			s.Pop(b1);
			s.Pop(b2);
			s.Push(b1&&b2);
		}
			else if (str[i] == 'v')
			{
				s.Pop(b1);
				s.Pop(b2);
				s.Push(b1 || b2);
			}
				else //Операции за отрицание ~
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