/*[V]*Es1. Scrivere un metodo che prenda in input due array A e B di int di lunghezza n ed m rispettivamente,
e restituisca una matrice di dimensione nxm di int contenente il prodotto AxB se in A tutti gli elementi sono
distinti e la matrice identità altrimenti
*/

#include <iostream>
using namespace std;
const int N = 5;
const int M = 3;

int main() {
	int a[N];// = {1,2,3,4,5};
	int b[M];// = {4,5,6};
	int c[N][M];
	int i,in, dist;
	int j=0;
	bool bol;
	cout << "Input A:";
	for (i=0;i<N;i++){
		cin >> in;
		a[i] = in;		
	}
	i = 0;
	while (i < N){
	
		if (a[i] != a[0]){
			cout << "\nGli elementi di A sono distinti\n";
			break;
		}
		i++;
	}
	
	cout << "Input B:";
	for (i=0;i<M;i++){
		cin >> in;
		b[i] = in; 
	}
	cout <<endl << "VETTORE A: ";
	//stampa vettore
	for ( i=0; i<N; i++ ) cout << a[i] << " ";
	cout << endl;
	//*****
	cout <<endl << "VETTORE B: ";
	//stampa vettore
	for ( i=0; i<M; i++ ) cout << b[i] << " ";
	cout << endl;
	
	//Prodotto tra matrici
	for (i=0; i<N; i++){
		for(j=0; j<M; j++){
			c[i][j]=a[i]*b[j];
			cout << c[i][j] << " ";			
		}
		cout << endl;
	}
	//dichiarazione identità
	int id[N][M];
	int (*I)[M];
	I=id;
	for (i=0; i<M;i++){
		for(j=0;j<M;j++){
			if (i==j) I[i][j] = 1;
			else			
			I[i][j] = 0;
			cout << I[i][j] << " ";
		}
		cout << endl;
	}
	
	
	




}
