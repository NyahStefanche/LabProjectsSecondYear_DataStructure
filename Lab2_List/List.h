template<class T>
struct element { T info; element<T>* next; };

template<class T>
class List
{
public:
	List();
	~List();

	bool  Empty();
	int Size();
	void InsBegin(T data); //добавя в началото елемент с информационна част data
	void InsEnd(T data); //добавя в края елемент с информационна част data
	bool InsAfter(T x, T data); //добавя елемент с инфо част data след елемента х
	bool InsBefore(T x, T data); //добавя елемент с инфо част data преди елемента х
	bool InsPos(int pos, T data); // добавя елемент с инфо част data на позиция с номер pos
					// номерата на позициите започват от 0.
	bool DelVal(T data); //изтрива елемент с инфо част data. Ако има няколко такива, се
				// изтрива първият срещнат
	bool DelPos(int pos); //изтрива елемента от позиция pos
	bool DelAll(T data); //изтрива всички срещания на елемент с инфо част data
	bool Find(T data, int& pos); // връща true, ако в списъка има елемент с инфо част data и
					// запазва в променливата pos номера на позицията, където
					// е намерен елемента. Ако елемент с инфо част data не
					// съществува в списъка, ф-ята връща false, а в pos се запазва -1
	bool GetPos(int pos, T& data); //извлича информационната част в променливата data от елемента
// на позиция pos 
	bool UpdatePos(int pos, T data); // променя инфо частта на елемента от позиция pos

private:
	element<T>* first; //указател към началото на списъка
	element<T>* last; //указател към края на списъка
	int count; //брой на елементите в списъка
	element<T>* FindP(T data);//връща физическия адрес на елемент с инфо част data, ако такъв има в
	// списъка, или NULL, ако в списъка няма такъв елемент
};

template<class T>
List<T>::List()
{
	first = NULL;
	last = NULL;
	count = 0;
}

template<class T>
List<T>::~List()
{
	T n;
	while (count != 0)
	{
		GetPos(0, n);
		while (DelVal(n));
	}
}
template<class T>
bool List<T>::Empty()
{
	return count == 0;
}

template<class T>
int List<T>::Size()
{
	return count;
}

template<class T>
element<T>* List<T>::FindP(T data)
{
	element<T>* p = first;
	while (p != NULL && p->info != data)
	{
		p = p->next;     //преминаване към следващ елемент
	}
	return p;
}

template<class T>
void List<T>::InsBegin(T data)
{
	element<T>* p = new element<T>;
	p->info = data;
	p->next = NULL;
	if (count == 0) first = last = p;
	else
	{
		p->next = first;
		first = p;
	}
	count++;
}

template<class T>
void List<T>::InsEnd(T data)
{
	element<T>* p = new element<T>;
	p->info = data;
	p->next = NULL;
	if (count == 0) first = last = p;
	else
	{
		last->next = p;
		last = p;
	}
	count++;
}

template<class T>
bool List<T>::InsAfter(T x, T data)
{
	element<T>* p = FindP(x);
	if (p == NULL) return false; //х не е елемент на списъка
	if (p == last) //вмъкване след последния елемент, т.е. добавяне в края
	{
		InsEnd(data);
		return true;
	}
	element<T>* q = new element<T>;
	q->info = data;
	q->next = p->next;
	p->next = q;
	count++;
	return true;
}

template<class T>
bool List<T>::InsBefore(T x, T data)
{
	element<T>* p = FindP(x);
	if (p == NULL) return false; //х не е елемент на списъка
	element<T>* q = new element<T>;
	*q = *p;
	p->info = data;
	p->next = q;
	if (p == last) last = q;
	count++;
	return true;
}

template<class T>
bool List<T>::InsPos(int pos, T data)
{
	if (pos < 0 || pos >= count) return false;
	if (pos == 0)
	{
		InsBegin(data);
		return true;
	}
	element<T>* q = new element<T>;
	q->info = data;
	element<T>* p = first;

	for (int i = 0; i < pos - 1; i++) p = p->next;
	q->next = p->next;
	p->next = q;
	count++;
	return true;
}

template<class T>
bool List<T>::DelPos(int pos)
{
	if (pos < 0 || pos >= count) return false;
	if (pos == 0)
	{
		element<T>* p = first;
		first = first->next;
		delete p;
		count--;
		return true;
	}
	element<T>* p = first;
	for (int i = 0; i < pos - 1; i++) p = p->next;
	element<T>* q = p->next;
	p->next = q->next;
	if (q == last) last = p;
	delete q;
	count--;
	return true;
}

template<class T>
bool List<T>::DelVal(T data)
{
	if (first->info == data)
	{
		element<T>* p = first;
		first = first->next;
		delete p;
		count--;
		return true;
	}
	element<T>* p = first;
	element<T>* q = p->next;
	while (q != NULL && q->info != data)
	{
		p = q;
		q = q->next;
	}
	if (q == NULL) return false;
	p->next = q->next;
	if (q == last) last = p;
	delete q;
	count--;
	return true;
}

template<class T>
bool List<T>::DelAll(T data)
{
	bool  b = false;
	while (DelVal(data))
	{
		b = true;
	}
	return b;
}

template<class T>
bool List<T>::Find(T data, int& pos)
{
	element<T>* p = first;
	pos = 0;
	while (p != NULL && p->info != data)
	{
		p = p->next;
		pos++;
	}
	if (p != NULL) return true;
	pos = -1;
	return false;
}

template<class T>
bool List<T>::GetPos(int pos, T& data)
{
	if (pos < 0 || pos >= count) return false;
	element<T>* p = first;
	for (int i = 0; i < pos; i++) p = p->next;
	data = p->info;
	return true;
}

template<class T>
bool List<T>::UpdatePos(int pos, T data)
{
	if (pos < 0 || pos >= count) return false;
	element<T>* p = first;
	for (int i = 0; i < pos; i++) p = p->next;
	p->info = data;
	return true;
}
