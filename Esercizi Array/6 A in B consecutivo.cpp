
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
const int N = 5; //a[N]
const int M = 3;//b[M]

//dire se gli elementi di B sono contenuti in A consecutivamente.
int main(){ 
srand(time(0));
int j=0, i=0;
int a[N] = {1,2,3,4,5};
int b[M];
int in;

	
	cout << "Inserisci i dati del vettore B:\n";
	while (j<M){
		cin >> in;
		b[j] = in;//rand() % (27-13)+13; //rand()%(max-min)+min range tra max e min
		//cout << b[j] << endl;
		j++;
	}
		cout<<endl << "VETTORE A: ";
	//stampa vettore
	for ( i=0; i<N; i++ ) cout << a[i] << " ";
	cout << endl;
	//*****
	cout <<endl << "VETTORE B: ";
	//stampa vettore
	for ( i=0; i<N; i++ ) cout << a[i] << " ";
	cout << endl;
	//*****
	i=0;
	j= 0;
	int uguale = 0;
	int tmp;
	//check elementi b in a
	while (j < M){		
		while (i < N)
		{			
			if (b[j] == a[i] )	{				
				uguale++;
				i = tmp;
			
				cout << "Elementi uguali: "<<uguale << endl;							
				break;
			}
			
						
			i++;
		}	
		
	
		if (uguale == N)	break;
		j++;	
	}
	
	
	
	if (uguale < M) 
		cout << "\t Purtroppo B non e' contenuto in A'." << endl ;
	else		cout << "\t B e' contenuto in A'." << endl ;
	
	system ("PAUSE");
	return 0;
	}

