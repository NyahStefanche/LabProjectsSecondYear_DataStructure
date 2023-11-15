/*
#include<iostream>
#include <string>
#include "Stack.h"
using namespace std;
int main()
{
 Stack<char>s;
 string str;
 cin>>str;
 int l=str.size();
 int i=0;
 char c;
 while(str[i] !='c')
	{
		if (str[i]=='a') s.Push('a');
		i++;
	}
	i++;
	while(i< l && !s.Empty())
	{
		if (str[i]=='n') s.Pop(c);
		i++;
	}
	if (i==1 && s.Empty()) cout<<"yes";
	else cout<<"No";
	system("pause");
	return 0;
}
*/