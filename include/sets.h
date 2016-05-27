#ifndef __SETS_H__
#define __SETS_H__

#include <stack>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include "d_heap.h"

using namespace std;

template <class HType>
class sets
{
private:
	int *parent;
	int *height;
	int n;
public:
	sets(int);
	~sets();

	void makesets (int);
	int findsets (int);
	void unionsets (int, int);
	void vyvod();

	int* getsets(int);
};

template <class HType>
sets<HType>::sets(int a)
{
	if (a < 0)
		throw
		exception ("a < 0");
	parent = new int[a];
	for (int i = 0; i < a; i++)
		parent[i] = -1;
	height = new int[a];
	n = a;
}

template <class HType>
sets<HType>::~sets()
{
	delete[] parent;
	delete[] height;
}

template <class HType> 
void sets<HType>::makesets(int a)
{
	if ((a > n) || (a < 0))
		throw 
		exception ("Некорректный элемент");
	
	if (parent[a] != -1)
		return;

	parent[a] = a;
	height[a] = 0;
}

template <class HType>
int sets<HType>::findsets (int a)
{
	if ((a > n) || (a < 0))
		throw 
		exception ("Некорректный элемент");
	if (parent[a] == -1)
		return -1;

	while (parent[a] != a)
		a = parent[a];
	return a;	
}

template <class HType>
void sets<HType>::unionsets (int a, int b)
{
	if ((a > n) || (a < 0) || (b > n) || (b < 0))
		throw 
		exception ("Некорректный элемент");
	if ((parent[a] == -1) || (parent[b] == -1))
		throw
		exception ("Пустое множество");

	a = findsets (a);
	b = findsets (b);
	if (height[a] > height[b])
		parent[b] = a;
	else if (height[a] < height[b])
		parent[a] = b;
	else
	{
		parent[b] = a;
		height[a]++;
	}
}

template <class HType>
int* sets<HType>::getsets (int a)
{
	if ((a > n) || (a < 0))
		throw 
		exception ("Некорректный элемент");
	if (parent[a] != a)
		throw 
		exception ("Нужен главный элемент");
	
	stack<int> st;
	int *res = new int;
	for (int i=0; i<n; i++)
	{
		if (parent[i] == a)
			st.push(i);
	}
	res[0] = st.size();
	int j=1;
	while (!st.empty())
	{
		res[j] = st.top();
		st.pop();
		j++;
	}
	return res;
}

template <class HType>
void sets<HType>::vyvod ()
{
	HType*tmp = new HType;
	for (int i=0; i<n;i++)
	{
		if (parent[i] == i)
		{
			tmp = getsets(i);

			if (tmp[0] > 1)
			{
				cout << '{';
				for (int k = 1; k<=tmp[0]; k++)
					cout << tmp[k] << ' ';
				cout << "} ";
			}
			else 
				cout << '{' << tmp[1] << "} ";
		}
	}
	cout << endl;
}

template <class HType>
class DataEdge : public Prior<HType>
{
public:
	DataEdge (edge<HType>*);
	edge<HType> *e;
};

template <class HType>
DataEdge<HType>::DataEdge (edge<HType> *a)
{
	e = a;
	pr = e->weight;
}



#endif