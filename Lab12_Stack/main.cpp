#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;
int prior(char op)
{
	switch (op)
	{
	case '(': return 0;
	case '|': return 1;
	case 'v': return 2;
	case '^': return 3;
	case '~': return 4;
	}
}
/*
Ако текущата операция има по - висок приоритет от тази на върха на стека, тя се поставя в стека.
Ако текущата операция има по - нисък или равен приоритет от тази на върха на стека, от стека се изключва операцията от върха и текущата се поставя в стека.
( се поставя в стека
) – от стека се изключват всички операции до (
*/

int main()
{
	string str_yellow, str_green = "";
	cin >> str_yellow;
	int len = str_yellow.size();
	Stack<char> s;
	for (int i = 0; i < len; i++)
	{
		char c = str_yellow[i];
		if (c == '0' || c == '1') str_green += c;
		else if (c == '(') s.Push(c);
		else if (c == ')')
		{
			char item;
			s.Pop(item);
			while (item != '(')
			{
				str_green += item;
				s.Pop(item);
			}
		}
		else if (s.Empty()) s.Push(c); // означава, че c е знак за операция
		else
		{
			char top;
			s.Top(top);
			if (prior(c) > prior(top)) s.Push(c);
			else
			{
				s.Pop(top);
				str_green += top;
				s.Push(c);
			}
		}
	}
	cout << str_green << endl;
	system("pause");
	return 0;
}