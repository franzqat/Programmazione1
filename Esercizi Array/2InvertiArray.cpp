#include <iostream>
using namespace std;
const int DIM = 10;

int main (){
	int i=0;
	int a[DIM];
	cout << "Inserisco i numeri da 1 a 10;" << endl;
	
	while (i<DIM)
	{
		a[i]=i+1;
		cout <<"\t\t" << a[i] << endl;
		i++;	
	}
	int tmp;
	int j=0;
	cout << "Inversione:" << endl;
	while (j<DIM/2)
	{	
		tmp = a[j];
		a[j] = a[DIM-j-1];
		a[DIM-j-1 ]=tmp;  //-1 perchè arrivi all'indice 9 
		//cout <<"\t\t" << a[j] << endl;
		j++;
	}
	i = 0;
		while (i<DIM)
	{
		cout <<"\t\t" << a[i] << endl;
		i++;	
	}
	system("PAUSE");
}
