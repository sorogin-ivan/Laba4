#include "graphs.h"
#include "priority_queue.h"
#include "algoritms.cpp"

typedef float typ;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "����� ���������� � �����-������ ��������� ��������" << endl << endl;
	cout << "����������, ������ ���������� ������" << endl;
	int n;
	cin >> n;

	cout << "����� ������� ������ ���������� �����" << endl;
	int m;
	cin >> m;
	Graph<typ> *graph = new Graph<typ> (n,m);
		typ *P = new typ[n]; //���������� ����
		for (int i=0; i<=n;i++)
			P[i] = 0;
	cout << "���������� ��������� �����" << endl;
	int l;
	cout << "����� ������������ ���� ��������� ������� (1) ��� ������� (2)?" << endl;
	cin >> l;\
		if (l==1){
	cout << "������� ����������� � ������������ �������� ���� �����, ����������" << endl;
	typ min, max;
	cin >> min;
	cin >> max;
	graph->createGraph(min, max);
	system ("cls");
		}
		if(l==2){
				for (int i=0; i<m;i++)
		{
			cout << "������� ������, ���� � ���" << endl;
			int a,b;
			typ c;
			cin >> a;
			cin >> b;
			cin >> c;
			graph->addEdge(a,b,c);
		}
		}
	cout << "���� �������� ��� ����� �������: " << endl<<endl;
	graph->print();

	cout << "������� �������, �� ������� ��������" << endl;
	int a;
	cin >> a; 
	for (int i=0; i<=n;i++)
			P[i] = a;
	cout << "��������� ��������... ����������, ��������" << endl << endl;
	typ *dist = Algoritm<typ>::deykstra(a,P, graph);

	cout << "�����: " << endl << endl;	
	
	for (int i=0; i<n;i++)
		cout << i << ' ';
	cout << "- ������ ������" <<  endl << endl;
	for (int i = 0; i < n; i++)
		if (dist[i] == MAX_HTYPE)
			cout << 0 << ' ';
		else
			cout << dist[i] << ' ' ;
	cout << "- ���������� ����" <<  endl << endl;
	for (int i=0;i<n;i++)
		cout << P[i] << ' ';
	cout << "- �������������� ������� " <<  endl << endl;

}	
