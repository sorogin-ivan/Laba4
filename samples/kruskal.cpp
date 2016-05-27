#include <conio.h>
#include "algoritms.cpp"

typedef float typ;

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	int z;
	FILE *myfile;
	cout << "Добро пожаловать в альфа-версию алгоритма Крускала" << endl;
	cout << "Выбирите тип приоритетной очереди: " << endl;
	cout << "1) d-куча" << endl;
	cout << "2) Бинарное деревo" << endl;
	cout << "3) таблица" << endl;
	cin >> z;
	system ("cls");
	int n;
	cout << "Введите количество вершин, пожалуйста" << endl;		
	cin >> n;		
	cout << "Введите количество ребер, пожалуйста" << endl;
	int m;
	cin >> m;

	Graph<typ> *graph = new Graph<typ> (n,m);
		
	int l;
	cout << "Будем генерировать граф случайным образом (1), вручную (2) или читать с файла (3)?" << endl;
	cin >> l;
	switch (l)
		{
	case 1:
		{
		cout << "Введите минимальное и максимальное значение веса" << endl;
		typ min, max;
		cin >> min;
		cin >> max;
		graph->createGraph(min, max);
		break;
		}
	case 2:
		{
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
		break;	
		}
	case 3:
		{
			myfile = fopen ("C:\\file.txt", "r");
			int a = 0, b = 0 ,i = 0, tmp1 = 0, tmp2 = 0;
			typ c = 0;
			while (i < m)
			{
				fscanf (myfile, "%d%d%f\n", &a, &b, &c);
				if ((tmp1 == a) && (tmp2 == b))
					break;
				tmp1 = a;
				tmp2 = b;
				graph->addEdge (a,b,c);
				i++;
			}
			fclose(myfile);
		}
		break;
	}
	
	system ("cls");

	cout << "Граф выглядит вот так: " << endl<<endl;
	graph->print();
		
	cout << "Применяем алгоритм Крускала... Пожалуйста ожидайте..." << endl;
	Graph<typ> *res = new Graph<typ> (n,m);
	graph->sort();
	
	PQueue<typ>* queue;
	int tmp2 = 0;
	if (z == 1)
		tmp2 = n;
	if (z == 3)
		tmp2 = m;
	make_queue<typ>::makeQueue(queue, z, tmp2);

	res = Algoritm<typ>::kruskal(graph, queue);
	cout << endl << endl;
	res->print();
}
