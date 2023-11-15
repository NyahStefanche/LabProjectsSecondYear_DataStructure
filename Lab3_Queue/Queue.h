#include<iostream>
template<class T>
struct element { T info; element<T>* next; };

template<class T>
class Queue
{
public:
	Queue();
	~Queue();

	void PushBack(T data);
	bool PopFront(T& data);
	bool Empty();
	int Size();
	bool PopBack(T& data);

private:
	element<T>* first;
	element<T>* last;
	int count;
};
template<class T>
Queue<T>::Queue()
{
	first = last = NULL;
	count = 0;
}

template<class T>
bool Queue<T>::Empty()
{
	return count == 0;
}

template<class T>
int Queue<T>::Size()
{
	return count;
}
template<class T>
void Queue<T>::PushBack(T data)
{
	element<T>* p = new element<T>;
	p->info = data;
	p->next = NULL;
	if (count == 0) //опашката е празна
	{
		first = last = p;
	}
	else //в опашката има елементи и last е различно от NULL
	{
		last->next = p;
		last = p;
	}
	count++;
}
template<class T>
bool Queue<T>::PopFront(T& data)
{
	if (count == 0) return false;
	data = first->info;
	element<T>* p = first;
	first = first->next;
	delete p;
	count--;
	return true;
}

template<class T>
Queue<T>::~Queue()
{
	T data;
	while (PopFront(data));
}
template <class T>
bool Queue<T>::PopBack(T& data)
{
	if (count == 0)return false;
	data = last->info;
	element<T>* p = first;
	while (p->next != last)
		p = p->next;
	delete last;
	count--;
	last = p;
	return true;
}
