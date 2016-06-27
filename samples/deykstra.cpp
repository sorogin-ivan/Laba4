#include "graphs.h"
#include "priority_queue.h"
#include "algoritms.cpp"

typedef float typ;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Добро пожаловать в альфа-версию алгоритма Дейкстры" << endl << endl;
	cout << "Пожалуйста, ведите количество вершин" << endl;
	int n;
	cin >> n;

	cout << "Будте любезны ввести количество ребер" << endl;
	int m;
	cin >> m;
	Graph<typ> *graph = new Graph<typ> (n,m);
		typ *P = new typ[n]; //кратчайший путь
		for (int i=0; i<=n;i++)
			P[i] = 0;
	cout << "Начинается генерация графа" << endl;
	int l;
	cout << "Будем генерировать граф случайным образом (1) или вручную (2)?" << endl;
	cin >> l;\
		if (l==1){
	cout << "Введите минимальное и максимальное значение веса графа, пожалуйста" << endl;
	typ min, max;
	cin >> min;
	cin >> max;
	graph->createGraph(min, max);
	system ("cls");
		}
		if(l==2){
				for (int i=0; i<m;i++)
		{
			cout << "Введите откуда, куда и вес" << endl;
			int a,b;
			typ c;
			cin >> a;
			cin >> b;
			cin >> c;
			graph->addEdge(a,b,c);
		}
		}
	cout << "Граф выглядит вот таким образом: " << endl<<endl;
	graph->print();

	cout << "Введите вершину, от которой начинаем" << endl;
	int a;
	cin >> a; 
	for (int i=0; i<=n;i++)
			P[i] = a;
	cout << "Применяем алгоритм... Пожалуйста, ожидайте" << endl << endl;
	typ *dist = Algoritm<typ>::deykstra(a,P, graph);

	cout << "Ответ: " << endl << endl;	
	
	for (int i=0; i<n;i++)
		cout << i << ' ';
	cout << "- номера вершин" <<  endl << endl;
	for (int i = 0; i < n; i++)
		if (dist[i] == MAX_HTYPE)
			cout << 0 << ' ';
		else
			cout << dist[i] << ' ' ;
	cout << "- кратчайшие пути" <<  endl << endl;
	for (int i=0;i<n;i++)
		cout << P[i] << ' ';
	cout << "- предшествующие вершины " <<  endl << endl;

}	
