//Има грешки при изчисленията със случайното число и двата while цикъла не трябва да ги има queue_prokotol.docx зад3 (моя вариант)
/*#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Queue.h"
using namespace std;

int main()
{
	system("chcp 1251");
	int systime = (int)time(0); //системното време се преобразува в цяло число 
	srand(systime); //инициализира генератора на случайни числа
	Queue<int> kasa1,kasa2;
	int t = 0;
	int br1=0, br2=0;
	int number = rand() % 500;
	int k = rand() % 9;
	int suma1 = 0,suma2=0;
	for (int klient = 0; klient <= 30; klient++)
	{
		
		if (number == 0 && number <= 100) return 0;
		else if (number >= 101 && number <= 200 && kasa1.Empty())
		{
			kasa1.PopBack(number);
			br1++;
		}
		else if (number >= 201 && number <= 300 && kasa2.Empty())
		{
			kasa2.PopBack(number);
			br2++;
		}
		else if (number >= 301 && number <= 500)
		{
			if (kasa1.Size() > kasa2.Size())
			{
				kasa2.PushBack(number);
				klient++;
			}
			else
			{
				kasa1.PushBack(number);
				klient++;
			}
		}
	}
	while (kasa1.Empty())
	{
		t = (number % 3 + 1) * number / 15;
		suma1=suma1 + 1 + number / 100 * k;
		int c;
		kasa1.PopFront(c);
	}
	while (kasa2.Empty())
	{
		t = (number % 3 + 1) * number / 15;
		suma2=suma2 + 1 + number / 100 * k;
		int c;
		kasa2.PopFront(c);
	}
	cout << "Сумата на покупките е: " << suma1 + suma2 << endl;
	cout << "Брой клиенти отказали се от първа каса: " << br1 << endl;
	cout << "Брой клиенти отказали се от втора каса: " << br2 << endl;
	system("pause");
	return 0;
}*/
//Вариант на госпожата
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include "Queue.h"

using namespace std;

int main()
{
	system("chcp 1251");
	int systime = (int)time(0); //системното време се преобразува в цяло число 
	srand(systime); //инициализира генератора на случайни числа
	Queue<int> k1, k2;
	int t1 = 0, t2 = 0, sum = 0, br = 0, m, otk = 0;
	while (br != 30)
	{
		m = rand() % 501;
		if (m > 300)
		{
			if (k1.Size() > k2.Size())
				k1.PushBack(m);
			else k2.PushBack(m);
		}
		else if (m > 200) {
			k2.PopBack(m); otk++;
		}
		else if (m > 100) {
			k1.PopBack(m); otk++;
		}
		if (t1 == 0)
		{
			if (!k1.Empty())
			{
				k1.PopFront(m);
				br++;
				t1 = (m % 3 + 1) * m / 15;
				sum += 1 + m / 100 * (rand() % 10);
			}
		}
		else t1--;
		if (t2 == 0)
		{
			if (!k2.Empty())
			{
				k2.PopFront(m);
				br++;
				t2 = (m % 3 + 1) * m / 15;
				sum += 1 + m / 100 * (rand() % 10);
			}
		}
		else t2--;


	}
	cout << "Сума:" << sum << endl;
	cout << "Отказали се:" << otk << endl;
	system("pause");
	return 0;
}
