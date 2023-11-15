#include <iostream>
#include "List.h"
using namespace std;
int main()
{
	List<int> plus, minus;
	int n;
	int k, m;
	int sp = plus.Size();
	int sm = minus.Size();
	do
	{
		cin >> n;
		if (n > 0) plus.InsEnd(n);
		/*if (n < 0)*/ else minus.InsEnd(n);
	} while (n != 0);
	for (int i = 0; i <= sp - 1; i++)
	{
		int c;
		plus.GetPos(i, c);
		cout << c << " ";
	}
	for (int i = 0; i <= sm - 1; i++)
	{
		int c;
		minus.GetPos(i, c);
		cout << c << " ";
	}
	cin >> k >> m;
	if (k > 0 || k < 0)
	{
		plus.DelVal(k);
		minus.DelVal(k);
	}
	if (m > 0) plus.InsEnd(m);
	else if (m < 0) minus.InsEnd(m);
	else cout << "ÃÐÅØÊÀ" << endl;
	for (int i = 0; i <= sp - 1; i++)
	{
		int c;
		plus.GetPos(i, c);
		cout << c << " ";
	}
	for (int i = 0; i <= sm - 1; i++)
	{
		int c;
		minus.GetPos(i, c);
		cout << c << " ";
	}
	/*if (k > 0) plus.DelVal(k);
	if (k < 0) minus.DelVal(k);
	if (m > 0) plus.InsEnd(n);
	if (m < 0) minus.InsEnd(n);*/
	system("pause");
	return 0;
}