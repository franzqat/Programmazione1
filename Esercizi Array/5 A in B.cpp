
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
const int M = 2;
const int N = 5;

int main(){ 
srand(time(0));
int j=0, i=0;
int a[N], b[M];
int in;
//fill random con while
	cout << "VETTORE A\nInserisci i numeri della matrice\n";
	while (i<N){
		
		cin >> in;
		a[i] = in; //rand() % (27-13)+13; //rand()%(max-min)+min range tra max e min
		//cout << a[i] << endl;
		i++;
	}
	cout << "VETTORE B\n";
	while (j<M){
		cin >> in;
		b[j] = in;//rand() % (27-13)+13; //rand()%(max-min)+min range tra max e min
		//cout << b[j] << endl;
		j++;
	}
	i=0;
	j= 0;
	int uguale = 0;
	//check elementi b in a
	while (j < M){
		
		while (i < N)
		{			
			if (b[j] == a[i] )	{
				
			uguale++;
				cout << "Elementi uguali: "<<uguale << endl;							
				break;
			}
		i++;
		}	
	j++;
	}
	cout << "\n\n\tHo trovato " << uguale <<  " valori uguali\n" << endl ;
	if (uguale < M) 
		cout << "\t Purtroppo B non e' contenuto in A'." << endl ;
	else		cout << "\t B e' contenuto in A'." << endl ;
	
//	system "PAUSE";
	return 0;
	}

