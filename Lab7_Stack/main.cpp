#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;
int main()
{
	string str;
	int i = 0;
	Stack<char>s;
	cin >> str;
	char c;
	int len = str.size();
	while (str[i]!='c')
	{
		s.Push(str[i]);
		i++;
	}
	i++;
	bool flag = true;
	while (i < len && flag && !s.Empty())
	{
		s.Pop(c);
		if (c != str[i]) flag = false;
		i++;
	}
	if (i == len && flag && s.Empty()) cout << "Yes" << endl;
	else cout << "No" << endl;
	system("pause");
	return 0;
}