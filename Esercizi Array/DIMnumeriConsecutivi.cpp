#include <iostream>

// inserire in un vettore di dim 100 i numeri da 0 a 99
using namespace std;

const int DIM = 10;
int main()
{
	int a[DIM];
	int i=0, k=0;
	while (i<DIM)
		{
		a[i] = i;
		
		cout << "Il numero nell'indice i:" << i << " " << a[i] << endl;
		i++;
		}
		
	system("PAUSE");
}
