
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
const int N = 5;
//Dato un vettore di numeri in input, essi vengono ordinati in maniera crescente
//OK!
int main(){ 
	srand(time(0));
	int a[N];
	int in;
	int i;
	cout << "VETTORE A\nInserisci i numeri della matrice\n";
		for(i=0; i<N; i++)
			{
			cin >> in;
			a[i] = in; 
			}
	//stampa vettore
	cout << endl;
	for ( i=0; i<N; i++ ) cout << a[i] << " ";
	cout << endl;
	//**
	int tmp=0;
	//ordinatore:
		for (i=0; i < N; i++){
			for (int j=0; j<N;j++)				
			if (a[i]<a[j]){
			tmp = a[j];
			a[j]=a[i];
			
			a[i]=tmp;	
			}		
		}
		cout << "Il vettore ordinato:" << endl ;
			for (i=0; i<N; i++ ) cout << a[i] << " ";
			cout <<endl;
	system("PAUSE");
	return 0;
	}

