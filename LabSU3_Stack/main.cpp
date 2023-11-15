#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;
void value(char op, Stack<bool>& s)
{
	bool b1, b2;
	if (op == '~')
	{
		s.Pop(b1);
		s.Push(!b1);
	}
	else
	{
		s.Pop(b1);
		s.Pop(b2);
		if (op == '^') s.Push(b1 && b2);
		else s.Push(b1 || b2);
	}
}
int prior(char op)
{
	switch (op)
	{
	case '(': return 0;
	case 'v': return 1;
	case '^': return 2;
	case '~': return 3;
	}
}
int main()
{
	string expr;
	cin >> expr;
	int len = expr.size();
	Stack<char> sop; //Стек за операции
	Stack<bool> sres; // Стек за операнди
	for (int i = 0; i < len; i++)
	{
		char c = expr[i];
		if (c == '1' || c == '0') sres.Push(c - '0');
		else if (c == '(') sop.Push(c);
		else if (c == ')')
		{
			char item;
			sop.Pop(item);
			while (item != '(')
			{
				value(item, sres);
				sop.Pop(item);
			}
		}
		else if (sop.Empty()) sop.Push(c);
		else
		{
			char  top;
			sop.Top(top);
			if (prior(c) > prior(top)) sop.Push(c);
			else
			{
				sop.Pop(top);
				value(top , sres);
				sop.Push(c);
			}
		}
	}
	bool  b;
	sres.Pop(b);
	cout << b << endl;
	system("pause");
	return 0;
}