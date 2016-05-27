#ifndef __DHEAP_H__
#define __DHEAP_H__

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "graphs.h"

#define MAX_HTYPE 10000

using namespace std;

template <class HType>
class Prior
{
public:
	HType pr;
};


template <class HType>
class Dist : public Prior<HType> //��������� (��� ���������)
{
public:
	int v; //�������

	Dist (int, HType);
};

template <class HType>
class DHeap
{
private:
	int d; //�������
	Prior<HType>** keys; // ������
	int kolvo; //����������
public:
	DHeap (int, int);
	DHeap (const DHeap<HType>&);
	~DHeap ();

	int getidx (int); //������ ��������
	void trans (const int, const int); //���������������� ���� ���������
	void vsplyt (int); // ��������
	void pogryzh (int); // ����������
	int minchild (int); // ����������� ����
	void delet (); //�������� ������������ ��������
	void deletzadan (int); //�������� ��������� ��������
	void push (HType); // ������� �������
	void okych (); // ����������
	void vyvod (); // ����� ����

	int operator == (const DHeap<HType>&)const;
	DHeap& operator=(const DHeap<HType>&);
	int getKolvo(); //���������� ���������� ���������
	Prior<HType>* getKey(int); // ���������� ����

	void Sort(); //������������� ����������
};

template <class HType>
Dist<HType>::Dist (int a, HType d)
{
	v = a; //�������
	pr = d; //���
}

template <class HType>
DHeap<HType>::DHeap (const int arnost, const int size)
{
	if ((arnost <= 0) || (size < 0) || (size > MAX_HTYPE))
	throw
	exception ("������� ���������� ������");
	d = arnost; 
	kolvo = size;
	keys = new Prior<HType>*[MAX_HTYPE];
}

template <class HType>
DHeap<HType>::DHeap (const DHeap &a)
{	
	d = a.d;
	kolvo = a.kolvo;
	keys = new Prior<HType>*[MAX_HTYPE];
	for (int i=0;i<=kolvo-1;i++)
		keys[i] = a.keys[i];
}

template <class HType>
DHeap<HType>::~DHeap ()
{
	delete []keys;
}

template <class HType>
int DHeap<HType>::getidx (int a)
{
	int p;
	return p = (a-1)/d;
}

template <class HType>
void DHeap<HType>::trans (const int a, const int b) 
{
	if ((a > kolvo-1) || (b > kolvo-1))
	throw
	exception ("������� ���������� ������");

	Prior<HType> *tmp = new Prior<HType>;
	tmp->pr = keys[a]->pr;
	keys[a]->pr = keys[b]->pr;
	keys[b]->pr = tmp->pr;
}

template <class HType>
void DHeap<HType>::vsplyt (int a) 
{
	if (a > kolvo-1)
	throw
	exception ("������� ���������� ������");

	int p = getidx (a);
	while ((p >= 0) && (keys[p]->pr > keys[a]->pr))
	{
		if (p == 0)
		{
			trans(a,p);
			return;
		}
		trans(a,p);
		a = p;
		p = getidx (a);
	}
}

template <class HType>
int DHeap<HType>::minchild (int a) 
{
	if (a*d+1> kolvo-1) 
		return -1;

    int minCh = a*d+1;
    int maxCh;
	if (a*d+d < kolvo - 1)
		maxCh = a*d + d;
	else maxCh = kolvo - 1;

    for (int i = minCh; i <= maxCh; i++) {
        if (keys[i]->pr < keys[minCh]->pr) {
            minCh = i;
        }
    }
    return minCh;
}

template <class HType>
void DHeap<HType>::pogryzh (int a)
{
	if (a > kolvo)
	throw
	exception ("������� ���������� ������");

	int c = minchild(a);
	while ((c!=-1) && (keys[c]->pr < keys[a]->pr))
	{
		trans (c,a);
		a = c;
		c = minchild (a);
	}
}

template <class HType>
void DHeap<HType>::delet ()
{
	keys[0] = keys[kolvo - 1];
	kolvo --;
	pogryzh(0);
}

template <class HType>
void DHeap<HType>::deletzadan (int a)
{
	if (a >= kolvo)
		throw
		exception ("������ �������");
	trans(a, kolvo - 1);

	kolvo--;
	if (keys[a]->pr < keys[getidx(a)]->pr)
		vsplyt(a);
	else pogryzh(a);
}

template <class HType>
void DHeap<HType>::push (HType a)
{
	Prior<HType>* tmp2 = new Prior<HType>;
	tmp2->pr = a;

	kolvo ++;
	if (kolvo > MAX_HTYPE)
		throw
		exception ("�������");

	Prior<HType>** tmp = new Prior<HType>*[MAX_HTYPE];
	for (int i=0; i<kolvo-1 ; i++)
		tmp[i] = keys[i];
	tmp[kolvo - 1] = tmp2;
	keys = tmp;
}

template <class HType>
void DHeap<HType>::okych ()
{
	if (kolvo == 0)
		throw
		exception ("D-���� �����");
	for (int i=kolvo-1; i>=0;i--)
		pogryzh(i);
}

template <class HType>
int DHeap<HType>::operator==(const DHeap<HType>& a)const
{
	if (a.kolvo != kolvo)
		return 0;
	for (int i=0;i<a.kolvo;i++)
	{
		if (keys[i]->pr != a.keys[i]->pr)
			return 0;
	}
	return 1;
}

template <class HType>
void DHeap<HType>::vyvod()
{
	int level=0, tmp = 0;
	while (tmp < kolvo)
	{
		tmp += pow (d,level);
		level++;
	}
	int k=1, z=0;
	cout << "\t" << keys[0]->pr << endl;
	for (int i = 1; i < level;i++)
	{
		for (int j = k; (j<k+pow(d,i)) && (j < kolvo); j++)
			cout << keys[j]->pr << "\t";
		cout << endl;
		if (k + pow(d,i) > kolvo)
				k = kolvo;
			else k += pow(d,i);
	}
}

template <class HType>
DHeap<HType>& DHeap<HType>::operator=(const DHeap<HType>& a)
{
	d = a.d;
	kolvo = a.kolvo;
	for (int i=0;i<kolvo;i++)
		keys[i] = a.keys[i];
	return *this;
}

template <class HType>
int DHeap<HType>::getKolvo ()
{
	return kolvo;
}

template <class HType>
Prior<HType>* DHeap<HType>::getKey (int a)
{
	return keys[a];
}

template <class HType>
void DHeap<HType>::Sort () 
{
	int tmp = kolvo;
	for (int i= kolvo-1; i >0; i--)
		deletzadan(0);
	kolvo = tmp;

	tmp = 0;
	int tmp2 = kolvo-1;
	while (tmp <= tmp2)
	{
		trans(tmp2,tmp);
		tmp++;
		tmp2--;
	}	
}

#endif