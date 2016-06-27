#include <priority_queue.h>
#include <ctime>

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Добро пожаловать в альфа-версию пиромидальной сортировки" << endl;
	cout << "Пожалуйста, введите арность кучи" << endl;
	int a;
	cin >> a;
	DHeap<float> *heap = new DHeap <float> (a,0);
	cout << "Будте любезны теперь ввести количество" << endl;
	int b;
	cin >> b;
	int c;
	srand(time(NULL));
	for (int i=0;i<b;i++)
	{
		c = 1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(10 - 1)));
		heap->push(c);
	}
	system("cls");
	cout << "Изначально куча выглядит таким образом: " << endl;
	heap->vyvod();
	cout<<endl;
	cout<<endl;
	cout << "После сортировки уже вот так: " << endl;
	heap->okych();
	heap->Sort();
	heap->vyvod();

}
