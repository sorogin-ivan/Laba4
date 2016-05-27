#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "d_heap.h"
#include "bintree.h"
#include "table.h"

template <class TType>
class PQueue
{
public:
	PQueue(void) {};
	virtual ~PQueue() {};

	virtual void push(const TType) = 0;
	virtual void pop() = 0;
	virtual int isEmpty() = 0;
	virtual int GetSize() = 0;
	virtual TType top() = 0;
};

template <class TType>
class DQueue : public PQueue<TType>
{
private:
	DHeap<TType> *heap;
public:
	DQueue(int);
	virtual ~DQueue() {delete heap;}

	void push(const TType);
	void pop();
	TType top();
	int isEmpty();
	virtual int GetSize() {return heap->getKolvo();};
};

template <class TType>
DQueue<TType>::DQueue (int a)
{
	if (a < 0)
		throw
		exception ("AS");

	heap = new DHeap<TType>(a, 0);
}

template <class TType>
void DQueue<TType>::pop()
{
	if (isEmpty())
		throw
		exception ("очередь пуста");
	heap->delet();
}

template <class TType>
int DQueue<TType>::isEmpty()
{
	return heap->getKolvo() == 0;
};

template <class TType>
void DQueue<TType>::push(const TType a)
{
	heap->push(a);
	heap->Sort();
}

template <class TType>
TType DQueue<TType>::top ()
{
	if (isEmpty())
		throw
		exception ("очередь пуста");
	return heap->getKey(0)->pr;
}

////////////////////////////////////////////////////////////////////////////////

template <class TType>
class BQueue : public PQueue <TType>
{
private:
	bintree<TType> *tree;
public:
	BQueue();
	virtual ~BQueue() {delete tree;};

	virtual void push(const TType a) {Node<TType> *tmp = new Node<TType>(a); tree->insert(tree->root, tmp);};
	virtual void pop() {tree->Delete(tree->root, tree->root->key);};
	virtual int isEmpty() {return tree->getSize() == 0;};
	virtual TType top() {return tree->root->key;};
	virtual int GetSize() {return tree->getSize();};
	int operator==(const BQueue<TType>&)const;
};

template <class TType>
BQueue<TType>::BQueue ()
{
	tree = new bintree<TType>;
}

template <class TType>
int BQueue<TType>::operator==(const BQueue<TType>& a)const
{
	return *tree == *a.tree;
}


//////////////////////////////////////////////////////////////////
template <class TType>
class TQueue : public PQueue <TType>
{
private:
	SortTable<TType>* table;
	int s;
public:
	TQueue(int);
	~TQueue();

	void push(TType a);
	void pop();
	TType top ();
	int isEmpty ();
	int GetSize();
};

template <class TType>
TQueue<TType>::TQueue (int a)
{
	if (a < 0)
		throw 
		exception ("neverno");
	table = new SortTable<TType>(a);
	s = 0;
}

template <class TType>
TQueue<TType>::~TQueue()
{
	delete table;
}

template <class TType>
void TQueue<TType>::push (TType a)
{
	table->insert(s, a);
	s++;
}

template <class TType>
void TQueue<TType>::pop()
{
	if (isEmpty() )
		throw
		exception ("neverno");
	table->erase(table->min()->getKey() );
	s--;
}

template <class TType>
TType TQueue<TType>::top ()
{
	return table->min()->getData();
}

template <class TType>
int TQueue<TType>::GetSize ()
{
	return table->GetCount();
}

template <class TType>
int TQueue<TType>::isEmpty()
{
	if (table->GetCount() == 0)
		return 1;
	return 0;
}

template <class TType>
class make_queue
{
public:
	static bool makeQueue(PQueue<TType>*&, const int, const int);
};

template <class TType>
bool make_queue<TType>::makeQueue (PQueue<TType>*& q, const int a, const int b)
{
	if (a == 1)
	{
		q = new DQueue<TType>(b);
		return true;
	}
	if (a == 2)
	{
		q = new BQueue<TType>();
		return true;
	}
	if (a == 3)
	{
		q = new TQueue<TType>(b);
		return true;
	}
	return false;
}

#endif