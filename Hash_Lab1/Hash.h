//Има грешки.
#include <iostream>
template<class T>
struct elem { int key; T info; };

const int nilkey = 0;

template<class T>
class Hash
{
public:
	Hash(int n);
	~Hash();

	bool Add(int k, T data);
	bool Del(int k);
	bool Find(int k);
	bool GetInfo(int k, T& data);
	bool UpdateInfo(int k, T data);

private:
	elem<T>* ht;
	bool* kt;
	int free;
	int size;
	int Findp(int k);
	int hf(int k) { return k % size; }
	int rf(int i) { return (i + 1) % size; }
};





template<class T>
Hash<T>::Hash(int n)
{
	size = free = n;
	ht = new element<T>[n];
	kt = new bool[n];
	for (int i = 0; i < n; i++)
	{
		ht[i].key = nilkey;
		kt[i] = false;
	}
}

template<class T>
Hash<T>::~Hash()
{
	delete[] ht;
	delete[] kt;
}

template<class T>
int Hash<T>::Findp(int k)
{
	int pos = hf(k);
	int begin = pos;
	bool b = false;
	while (b == false && ht[pos].key != k && kt[pos] == true)
	{
		pos = r(pos);
		b = pos == begin;
	}
	if (ht[pos].key == k) return pos;
	return -1;
}

template<class T>
bool Hash<T>::Add(int k, T data)
{
	if (free == 0 || Findp(k) >= 0) return false;
	int pos = hf(k);
	while (ht[pos].key != nilkey)
	{
		kt[pos] = true;
		pos = rf(pos);
	}
	ht[pos].key = k;
	ht[pos].info = data;
	free--;
	return true;
}

template<class T>
bool Hash<T>::Del(int k)
{
	int pos = Findp(k);
	if (pos == -1) return false;
	ht[pos].key = nilkey;
	free++;
	return true;
}


template<class T>
bool Hash<T>::Find(int k)
{
	return Findp(k) >= 0;
}

template<class T>
bool Hash<T>::GetInfo(int k, T& data)
{
	int pos = Findp(k);
	if (pos == -1) return false;
	data = ht[pos].info;
	return true;
}

template<class T>
bool Hash<T>::UpdateInfo(int k, T data)
{
	pos = Findp(k);
	if (pos == -1) return false;
	ht[pos].info = data;
	return true;
}