#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
const int M = 3;
const int N = 3;
//OK!
int main(){ 
	srand(time(0));
	int j=0, i=0;
	int a[M][N];
	int x;
	cout << "Data una matrice quadrata "<<M<<"*"<<N<<" in input, afferma se essa e' uguale alla matrice identita'\n";
	//********************************Matrice A
	cout << "Matrice A di " << N << " righe e " << M << " colonne\n" ;		
	while (j<M){
		while (i<N){
			cin >> x;
			a[i][j] = x;// i;//rand() % 2; 
		//	cout << a[i][j] << " ";
			i++;
		}
		
	//*/
	cout << endl ;
	j++;
	i=0;
	}
		
	cout << endl ;
	i=0;
	j=0;
	
	//*******************************DICHIARAZIONE I[N][M] identita'
	int I[N][M];
	while (j<M){
		while (i<N){
			if (i==j) //indice uguale
			I[i][j] = 1; 
			else
			I[i][j]=0;
			cout << I[i][j] << " " ;
			i++;
		}
	cout << endl ;
	j++;
	i=0;
	}
	//********************************
	i=0;
	j=0;
	int c;
	// dire se la matrice e' identità.
	while (j<M && c != 1){
		while (i<N){
			if (a[i][j] == I[i][j])		c++;	//
			else	c = 0;				
			i++;
		}
	j++;
	i=0;
	}
	if (c == M*N)	cout << "La matrice e' uguale alla matrice identita'\n";
	else	cout << "La matrice non e' la matrice identita'\n";
return 0;
}
