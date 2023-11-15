//NOT SURE IF ITS RIGHT Queue_Protokol.docx Zad 1, trqbva da napravq nova promenliva za vremeto pri else if
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include "Queue.h"

using namespace std;

int main()
{
	int systime = (int)time(0); //системното време се преобразува в цяло число 
	srand(systime); //инициализира генератора на случайни числа
	Queue<int> cars;
	int t = 0; //автомивката е свободна
	for (int time = 0; time < 700; time++)
	{
		int number = rand() % 600;
		if (number < 150) cars.PushBack(number);
		if (t > 0) //в момента се мие кола
		{
			t--;
		}
		else if (cars.Size()>10 && t>10)
		{
			int num;
			cars.PopBack(num);
			cout << num << " ";
			t = 0;
		}
		else // мивката е свободна и ако има наредени коли, първата може да влезе 
		{
			if (!cars.Empty())
			{
				int num;
				cars.PopFront(num);
				cout << num << " ";
				t = 80;
			}
		}

	}
	cout << endl << cars.Size() << endl;
	system("pause");
	return 0;
}
