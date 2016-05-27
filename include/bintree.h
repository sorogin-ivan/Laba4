#ifndef __bintree_h__
#define __bintree_h__

#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;


template <class TType>
class Node
{
public:
	int balance; //баланс поддерева
	TType key; //ключ
	Node<TType> *left; //левый ук-ль
	Node<TType> *right; //правый ук-ль
	Node<TType> *parent; //родитель
	Node() {left = NULL; right = NULL; parent = NULL; balance = 0; };
	Node(const TType& k) {key = k; left = NULL; right = NULL; parent = NULL; balance = 0;};
};

template <class TType>
class bintree
{	
public:
	int size; //количество элементов в дереве
	Node<TType> *root;
	bintree ();
	~bintree ();
	bintree (const bintree<TType> &);

	Node<TType>* CopyTree (Node<TType> *); //копирование
	virtual void insert (Node<TType>*&, const Node<TType> *); //вставка
	virtual void Delete (Node<TType>*&, const TType &); //удаление
	
	Node<TType>* Findkey (Node<TType>*, const TType &); // поиск по ключу
	Node<TType>* FindMax (Node<TType>*); //поиск максимума
	Node<TType>* FindMin (Node<TType>*); // поиск минимума
	Node<TType>* FindNext (Node<TType>*, Node<TType>*); //поиск следующего за заданным
	Node<TType>* FindPrevious (Node<TType>*, Node<TType>*); //поиск предыдущего за заданным

	void workAroundAcross (Node<TType>*); // вывод (через обход в ширину с помощью очереди)
	void workAroundForward (Node<TType>*); //вывод (через обход в прямом порядке)
	void workAroundReverse (Node<TType>*); //вывод (через обход в обратном порядке)
	void workAroundSymmetr (Node<TType>*); //вывод (через обход в симметричном порядке)
	void workAroundDepth (Node<TType>*); //вывод (через обход в глубину с помощью стека)

	int operator== (const bintree<TType>&)const;
	int getSize();
	int getHeight(Node<TType>*); //высота дерева
};

template <class TType>
bintree<TType>::bintree ()
{
	root = NULL;
	size = 0;
};

template <class TType>
bintree<TType>::bintree (const bintree<TType> &a)
{
	root = CopyTree(a.root);
	size = a.size;
};

template <class TType>
bintree<TType>::~bintree ()
{
	delete root;
};

template <class TType>
Node<TType>* bintree<TType>::CopyTree (Node<TType> *rot)
{
	if (rot == NULL)
        return NULL;

	Node<TType>* l = CopyTree (rot->left);
	Node<TType>* r = CopyTree (rot->right);
	Node<TType>* tr = new Node<TType>;
	tr->key = rot->key;
	tr->left = l;
	tr->right = r;
	root = tr;
	return tr;
};

template <class TType>
int bintree<TType>::getSize()
{
	return size;
}

template <class TType>
void bintree<TType>::insert (Node<TType>* &tr, const Node<TType> *node)
{
	TType a = node->key;
	if (tr == NULL)
	{
		tr = new Node<TType>;
		tr -> key = a;
		size++;
		return;
	}
	Node<TType>* tmp = tr;
	Node<TType>* prev = new Node<TType>;
	while(tmp != NULL)
	{
		prev = tmp;
		if	(tmp->key <= a)
			tmp = tmp->right;
		else 
			tmp = tmp->left;
	}
	if (prev->key <= a) 
		prev->right = new Node<TType>(a);
	else prev->left = new Node<TType>(a);
	size++;
};

template <class TType>
void bintree<TType>::Delete (Node<TType>*& tr, const TType &k)
{
	Node<TType>* x = Findkey(tr, k);
	if (x == NULL)
		return;

	if ((x->left == NULL) && (x->right == NULL))
	{
		delete x;
		return;
	};
	if ((x->left == NULL) && (x->right != NULL))
	{
		Node<TType>* y = x->right;
		y->parent = x->parent;
		if (x->parent == NULL)
		{			
			tr = y;
			return;
		}
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;	
		tr = y;
		return;
	}
	if ((x->left != NULL) && (x->right == NULL))
	{
		Node<TType>* y = x->left;
		y->parent = x->parent;
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;
		delete x;
		return;
	}
	Node<TType>* y = FindMin(x->right);
	x->key = y->key;
	y->parent->left = y->right;
	if (y->right != NULL)
		y->right->parent = y->parent;
	delete y;
};

template <class TType>
Node<TType>* bintree<TType>::Findkey (Node<TType> *tr, const TType &k)
{
	while ((tr != NULL) && (tr -> key != k))
	{
		if (k < tr->key)
			tr = tr ->left;
		if (k > tr ->key)
			tr = tr -> right;
	}
	if (tr == NULL)
		return NULL;
	return tr;
};

template <class TType>
Node<TType>* bintree<TType>::FindMin (Node<TType> *tr)
{
	if (tr == NULL)
		throw
		exception("pustoe");
	while (tr -> left != NULL)
		tr = tr -> left;
	return tr;
};

template <class TType>
Node<TType>* bintree<TType>::FindMax (Node<TType> *tr)
{
	if (tr == NULL)
		throw
		exception ("А дерево то пустое");
	while (tr -> right != NULL)
		tr = tr -> right;
	return tr;
};

template <class TType>
Node<TType>* bintree<TType>::FindNext (Node<TType> *tr, Node<TType> *node)
{
	if (tr == NULL)
		throw
		exception("А дерево то пустое");
	if (node == NULL)
		throw
		exception("Надо бы ключ не пустой");

	node = Findkey(tr, node->key);
	if (node -> right != NULL)
		return FindMin (node -> right);
	while ((node -> parent != NULL) && (node->parent->right == node))
		node = node -> parent;
	if (node->parent == NULL)
		throw
		exception("нету");

	return node -> parent;
};

template <class TType>
Node<TType>* bintree<TType>::FindPrevious (Node<TType> *tr, Node<TType> *node)
{
	if (tr == NULL)
		throw
		exception ("Дерево пусто");
	if (node == NULL)
		throw
		exception ("Ключ пустой");

	node = Findkey(tr, node->key);
	if (node->right != NULL)
		return FindMax(node->left);
	while ((node->parent != NULL) && (node->parent->left == node))
		node = node -> parent;
	if (node->parent == NULL)
		throw
		exception("нету");

	return node->parent;
}

template <class TType>
void bintree<TType>::workAroundAcross (Node<TType> *tr)
{
	if (tr == NULL)
		return;

	queue <Node<TType>*> q;
	q.push(tr);	
	while (q.empty() == 0)
	{
		Node<TType>* tmp = q.front();
		cout << tmp->key << '(' << tmp->balance << ") ";
		q.pop();		
		if (tmp->left != NULL)
			q.push (tmp->left);
		if (tmp->right != NULL)
			q.push (tmp->right);		
	}
}

template <class TType>
int bintree<TType>::operator== (const bintree<TType>& a)const
{
	if ((root == NULL) && (a.root == NULL))
		return 1;
	if (size != a.size)
		return 0;
	int *z = new int[size];
	int *b = new int[a.size];
	queue <Node<TType>*> q;
	queue <Node<TType>*> p;
	q.push(root);
	int tmp1=0,tmp2=0;
	while (q.empty() == 0)
	{
		Node<TType>* tmp = q.front();
		z[tmp1] = tmp->key;
		q.pop();
		if (tmp->left != NULL)
			q.push (tmp->left);
		if (tmp->right != NULL)
			q.push(tmp->right);
		tmp1++;
	}
	p.push(a.root);
	while (p.empty() == 0)
	{
		Node<TType>* tmp3 = p.front();
		b[tmp2] = tmp3->key;
		p.pop();
		if (tmp3->left != NULL)
			p.push (tmp3->left);
		if (tmp3->right != NULL)
			p.push(tmp3->right);
		tmp2++;
	}
	for (int i=0; i<size; i++)
		if (z[i] != b[i])
			return 0;
	return 1;
}

template <class TType>
void bintree<TType>::workAroundDepth (Node<TType> *tr)
{
	if (tr == NULL)
		return;

	stack<Node<TType>*> s;
	s.push(tr);
	while (!s.empty() )
	{
		Node<TType>* tmp = s.top();
	cout << tmp->key << '(' << tmp->balance << ") ";
		s.pop();
		if (tmp->right != NULL)
			s.push(tmp->right);
		if (tmp->left != NULL)
			s.push(tmp->left);
	}
}

template <class TType>
void bintree<TType>::workAroundForward (Node<TType> *tr)
{
	if (tr == NULL)
		return;
	cout << tr->key << '(' << tr->balance << ") ";
	workAroundForward(tr->left);
	workAroundForward(tr->right);
}

template <class TType>
void bintree<TType>::workAroundSymmetr (Node<TType> *tr)
{
	if (tr == NULL)
		return;

	workAroundSymmetr(tr->left);
	cout << tr->key << '(' << tr->balance << ") ";
	workAroundSymmetr(tr->right);
}

template <class TType>
void bintree<TType>::workAroundReverse (Node<TType> *tr)
{
	if (tr == NULL)
		return;

	workAroundReverse(tr->left);
	workAroundReverse(tr->right);
	cout << tr->key << '(' << tr->balance << ") ";
}

template <class TType>
int bintree<TType>::getHeight (Node<TType> *tr)
{
	if (tr == NULL)
        return 0;

    int l, r;
    if (tr->left != NULL) 
	{
        l = getHeight(tr->left);
    }
	else 
        l = -1;
    if (tr->right != NULL) 
	{
        r = getHeight(tr->right);
    }
	else 
        r = -1;
    int max = l > r ? l : r;
    return max+1;
};


#endif