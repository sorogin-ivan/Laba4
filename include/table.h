#ifndef __TABLE_H__
#define __TABLE_H__

#include <iostream>

using namespace std;


template<class TType>
class TabRecord {
protected:
	int key; //ключ
	TType data; //идентификатор
public:
	TabRecord (int a, TType b) {key = a; data = b;};
	int getKey() {return key;};
	TType getData() {return data;};
};


template<class TType>
class Table {
protected:
	int size; //максимальное количество
	int count; //текущее количество записей
	int pos; //указатель
public:
	Table (int);

	virtual TabRecord<TType>* search (int) = 0; //поиск
	virtual void insert (int, TType) = 0; //вставка
	virtual void erase (int) = 0; //удаление
	int	isEmpty (); //проверка на пустоту
	int	isFull (); //проверка на полноту
	virtual int GetCount (); //вернуть текущее количество записей
	virtual void reset (); //указатель в начало
	virtual int	goNext (); //переход к следующей записи
	virtual int isTabEnded ();
};

template <class TType>
Table<TType>::Table (int a)
{
	size = a;
	count = 0;
	pos = 0;
}

template <class TType>
int Table<TType>::isEmpty ()
{
	if (count == 0)
		return 1;
	return 0;
}

template <class TType>
int Table<TType>::isFull ()
{
	if (count == size)
		return 1;
	return 0;
}

template <class TType>
int Table<TType>::GetCount ()
{
	return count;
}

template <class TType>
void Table<TType>::reset()
{
	pos = 0;
}

template <class TType>
int Table<TType>::goNext ()
{
	if (!isTabEnded() )
	{
		pos++;
		return 1;
	}
	return 0;
}

template <class TType>
int Table<TType>::isTabEnded ()
{
	if (pos == count)
		return 1;
	return 0;
}


template<class TType>
class ScanTable : public Table<TType>
{
protected:
	TabRecord<TType>** recs;
public:
	ScanTable (int size) : Table<TType> (size) 
	{
		recs = new TabRecord<TType>*[size];
		for (int i=0; i<size; i++)
		{
			recs[i] = NULL;
		}
	};
	virtual ~ScanTable() 
	{
		for (int i=0; i<size; i++)
			delete recs[i];
		delete[]recs;
	}

	virtual TabRecord<TType>* search (int k)
	{
		for (int i=0; i<count; i++)
			if (k == recs[i]->getKey() )
			{
				pos = i;
				return recs[i];
			}
		return NULL;
	};
	virtual void insert (int k, TType Data)
	{
		if (isFull() )
			throw
			exception ("Таблица полна");;

		recs[count] = new TabRecord<TType>(k, Data);
		count++;
	}
	virtual void erase(int k)
	{
		if (isEmpty () )
			return;
		if (search(k) == NULL)
			return;

		delete recs[pos];
		recs[pos] = recs[count-1];
		count--;
	}
	void print();
	virtual int GetCount()
	{
		return count;
	};
	int getSize();
	TabRecord<TType>** getRecs();
};

template <class TType>
void ScanTable<TType>::print()
{
	for (int i=0; i<count; i++)
	{
		cout << recs[i]->getKey() << "\t" << recs[i]->getData() << endl;
	}
}

template <class TType>
int ScanTable<TType>::getSize()
{
	return size;
}

template <class TType>
TabRecord<TType>** ScanTable<TType>::getRecs()
{
	return recs;
}

template<class TType>
class SortTable : public ScanTable<TType> {	
public:
	SortTable(int size) : ScanTable<TType>(size) {};
	SortTable(ScanTable<TType>& table) : ScanTable<TType>(table) {sort();}
	virtual ~SortTable()
	{
		for (int i=0; i<size; i++)
			delete recs[i];
		delete[]recs;
	}
	
	virtual TabRecord<TType>* search (int key)
	{
		int left = 0;
		int right = count - 1;
		int mid;
		while (left <= right)
		{
		mid = left + (right - left) / 2;
		if (key < recs[mid]->getKey()) {
			right = mid - 1;
			pos = left;
		}
		else if (key > recs[mid]->getKey()) {
			left = mid + 1;
			pos = left;
		}
		else
		{
			pos = mid;
			return recs[mid];
		}
	}
	return 0;
	};
	virtual void insert(int k, TType Data)
	{
		if (isFull() )
			throw
			exception ("Таблица переполнена");
		TabRecord<TType> *tmp;
		tmp = search(k);
		for (int i=count+1; i>=pos+1; i--)
			recs[i] = recs[i-1];
		recs[pos] = new TabRecord<TType>(k,Data);
		count++;
	};
	virtual void erase(int k)
	{
		if (isEmpty() )
			return;
		if (search(k) == NULL)
			throw
			exception ("Элемента нет такого");

		
		for (int i=pos; i<count - 1; i++)
			recs[i] = recs[i+1];
		recs[count] = NULL;
		count--;
	};

	void sort();
	TabRecord<TType>* min ();
};

template <class TType>
void SortTable<TType>::sort ()
{
	TabRecord<TType> *tmp;
	for (int i=0; i<count; i++)
		for (int j = i+1; j<count; j++)
			if (recs[i]->getKey() > recs[j]->getKey() )
			{
				tmp = recs[i];
				recs[i] = recs[j];
				recs[j] = tmp;
			}
};

template <class TType>
TabRecord<TType>* SortTable<TType>::min ()
{
	return recs[0];
};

#endif