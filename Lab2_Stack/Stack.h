#include <iostream>
template<class T>
struct element { T info; element<T>* next; };

template<class T>
class Stack
{
public:
	Stack();
	~Stack();

	void Push(T data);
	void Pop(T& data);
	void Top(T& data);
	bool Empty();

private:
	element<T>* top;
};

template<class T>
Stack<T>::Stack()
{
	top = NULL;
}

template<class T>
void Stack<T>::Push(T data)
{
	element<T>* temp = new element<T>;
	temp->info = data;
	temp->next = top;
	top = temp;
}

template<class T>
void Stack<T>::Pop(T& data)
{
	data = top->info;
	element<T>* temp = top;
	top = top->next;
	delete temp;
}

template<class T>
void Stack<T>::Top(T& data)
{
	data = top->info;
}

template<class T>
bool Stack<T>::Empty()
{
	return top == NULL;
}

template<class T>
Stack<T>::~Stack()
{
	element<T>* temp = top;
	top = top->next;
	delete temp;
}
