#include <iostream>
#include <string>
#include "Stack.h"
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
		s.Push(str[i]);
		s.Push(str[i]);
		i++;
	}
	i++;
	while (i < len && !s.Empty())
	{
		char c;
		s.Pop(c);
		i++;
	}
	if (i == len && s.Empty()) cout << "YES" << endl;
	else if (i <= len && !s.Empty()) cout << "LESS" << endl;
	else /*(i >= len && !s.Empty())*/ cout << "GREAT" << endl;
	system("pause");
	return 0;
}