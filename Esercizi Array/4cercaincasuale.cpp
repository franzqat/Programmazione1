
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
const int DIM = 10000;
const int RICERCA = 33;
int main(){
	srand(time(0));
	int a[DIM];
	int i = 0;
	// while generatore
	while (i<DIM){

		a[i] = rand() % 1000;
		cout << "\t" << a[i]<< endl ;
		i++;
	}
	// while ricerca
	i=0;
	int r = RICERCA;
	bool c;
	while (i<DIM && !c){
		if (a[i] == r)
		{
		cout << "Esiste un numero:" << a[i]<< " all'interno dell'array nell'indice" << i <<  endl ;
		c = true; //per uscire dal while
		}
		i++;
	}
	
}


