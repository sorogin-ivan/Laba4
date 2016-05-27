#include "algoritms.h"

template <class TType>
Graph<TType>* Algoritm<TType>::kruskal (Graph<TType>*& gr, PQueue<TType>*& queue)
{
	int n = gr->getKolvo();
	int m = gr->getRealSize();
	Graph<TType> *tree = new Graph<TType>(n,m);
	sets<TType> *set = new sets<TType>(n);
	for (int i=0; i<n; i++)
		set->makesets(i);
	
	for (int i=0; i<m;i++)
		queue->push(gr->getEdge(i)->weight);

	int treeEdgeSize = 0; 
	int x = 0;
	TType tmp;

	while (treeEdgeSize < n-1)
	{
		tmp = queue->top();
		queue->pop();

		int u = gr->getEdge(x)->o;
		int v = gr->getEdge(x)->k;
		TType weight = tmp;

		int An = set->findsets(u);
		int Ak = set->findsets(v);
		if (An != Ak)
		{
			set->unionsets(An, Ak);
			tree->addEdge(u, v, weight);
			treeEdgeSize++;
		}
		x++;
	}

	return tree;
};

template <class TType>
TType* Algoritm<TType>::deykstra (int s, TType *&P, Graph<TType>*& gr)
{
	int n = gr->getKolvo();
	int m = gr->getRealSize();
	if ((s < 0) || (s >= n))
		throw 
		exception ("“акой нет");
	
	TType **graph = new TType*[n];
	for (int i=0;i<n;i++)
		graph[i] = new TType[n];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			graph[i][j] = -1;

	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			if ((gr->getEdge(j)->o == i) || (gr->getEdge(j)->k == i))
			{
				graph[gr->getEdge(j)->o][gr->getEdge(j)->k] = gr->getEdge(j)->weight;
				graph[gr->getEdge(j)->k][gr->getEdge(j)->o] = gr->getEdge(j)->weight;
			}
		}

	TType *dist = new TType[n]; //рассто€ние
	int *vis = new int[n]; //массив посещенных вершин
	for (int i=0; i<n;i++)
		vis[i] = -1;
	vis[0] = s;
	int pyt;
	int w, min;
//////////////////////////////////////////////////////////////
	for (int i=0; i<n; i++) 
	{                       
		if (graph[s][i] == -1)
			dist[i]=MAX_HTYPE;
			else dist[i]=graph[s][i];
	}
	for (int i=1; i<n-1; i++) 
	{
		min=MAX_HTYPE;
		for (int k=0; k<n; k++) {
			if (dist[k] < min && k!=s && !gr->visit(k, vis) ) 
			{
				w=k;
				min=dist[k];
			}
		}
		if (min == MAX_HTYPE) break;
		vis[i]=w;
		for (int j=0; j < n; j++) {
			if (!gr->visit(j,vis) && graph[w][j] != -1 && (dist[w]+graph[w][j])<=dist[j]) 
			{
				P[j]=w;
				dist[j]=dist[w]+graph[w][j];
			}
		}
	}

	dist[s] = 0;
	return dist;
}
