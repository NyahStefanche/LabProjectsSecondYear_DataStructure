#include "Stack.h"
#include <iostream>
using namespace std;
int prior(char c)
{
	switch (c)
	{
	case'(':return 0;
	case'[':return 1;
	case'{':return 2;
	case'<':return 3;
	}

}
int main()
{
	string str;
	cin >> str;
	int len = str.size();
	bool error = false;
	Stack<char> s;
	char c;
	for (int i = 0; i < len && !error; i++)
	{
		if (str[i] == '{ ' || str[i] == '[' || str[i] == '(' || str[i]=='<')
		{
			if (s.Empty()) s.Push(str[i]);
			else
			{
				s.Top(c);
				if (prior(c) >= prior(str[i])) s.Push(str[i]);
				else error = true;
			}
		}
		else if (s.Empty()) error = true;
		else
		{
			s.Pop(c);
			error = c == '(' && str[i] != ')' || c == '[' && str[i] != ']' || c == '{' && str[i] != '}' || c == '<' && str[i] != '>';
		}
	}
	if (error == false && s.Empty()) cout << "YES" << endl;
	else cout << "NO" << endl;
	system("pause");
	return 0;
}
