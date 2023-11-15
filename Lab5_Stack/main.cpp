#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int len = str.size();
	Stack<char> s;
	int i = 0;
	while (str[i] != 'c')
	{
		if (str[i] == 'a') s.Push(str[i]);
		i++;
	}
	i++;
	while (str[i] == 'c')
	{
		if (str[i] == 'b') s.Pop(str[i]);
		i++;
	}
	while (i < len && !s.Empty())
	{
		char c;
		s.Pop(c);
		i++;
	}
	if (i == len && s.Empty()) cout << "YES" << endl;
	else cout << "NO" << endl;
	system("pause");
	return 0;
}