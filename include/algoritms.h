#pragma once
#include "priority_queue.h"
#include "bintree.h"
#include "sets.h"
#include "d_heap.h"
#include "table.h"
#include "graphs.h"

using namespace std;

template <class TType>
class Algoritm
{
public:
	static Graph<TType>* kruskal(Graph<TType>*&, PQueue<TType>*&);
	static TType* deykstra(int, TType *&, Graph<TType>*&);
};