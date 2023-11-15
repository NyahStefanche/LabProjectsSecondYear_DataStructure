//Задача 1-ва от protokol_list_2, Г подоточка недовършена
#pragma once
#include "List.h"
#include <iostream>
using namespace std;
int main()
{
    List<int> l;
    int n, m, br = 0;
    cin >> m >> n;
    cout << m << n;
    while (n)
    {
        if (n > m) l.InsEnd(n);
        else l.InsBegin(n);
        cin >> n;
    }
    l.GetPos(l.Size() - 1, n);
    int i = 0;
    do
    {
        l.GetPos(i, m);
        i++;
    } while (n < m);
    cout << n << " " << m << " " << i << endl;
    system("pause");
    return 0;
}