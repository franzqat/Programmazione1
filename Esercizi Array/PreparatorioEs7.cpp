/*[V]*Es7. Data una matrice di float, dire se esistono due colonne le cui somme sono uguali, utilizzando un
margine di errore e non utilizzando array ausiliari;*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
//ok

bool uguali(float**g,int righe, int colonne){
	float somma1=0,somma2=0;
	int k;
	for (int j=0;j<colonne;j++){	
		for (int i=0;i<righe;i++){
			somma1+=g[i][j];
		}
	//	for (int k=j;k<colonne;k++){
		k=j+1;		
		while (k<colonne){
		
			for (int i=0;i<righe;i++)	somma2+=g[i][k];
			if (somma1==somma2&&k!=j){
				cout << "trovato " << k+1 << ":"<<j+1 << endl; 
				return true;	
			} 
			else { 
				somma2=0;
				k++;
			}
		}
	}
	return false;
}
	




int main(){
	
	srand(time(0));
	
	///******************************************
	int N=4, M=10;									//
	float **a;									//	
	a=new float*[N];							//
	for (int i =0;i<N;i++)	a[i]=new float[M];	//
	//******************************************	
	
	//*init a
	for (int j=0;j<M;j++){
		for (int i=0;i<N; i++){
			a[i][j]= (rand()% 10)/5.0;
			cout<<  a[i][j] << "\t";
		}
		cout << endl;
	}
	//*******
	
	bool funziona = uguali(a,N,M);
	if (funziona) cout << "FUNZIONA!*\n";
	
	/*
	float margine = 0.1;
		
	float somma=0.0;


	for (int j=0;j<N; j++){
		for (int i=0;i<N;i++){
			somma+= a[i][j]; 
		}
		if(somma)
		
	}
	
	float rangepiu=0,rangemeno=0;
	int count=0;
	*/
	//****DELETE
	for (int i=0;i<N;i++)	delete [] a[i];
	delete [] a;
	
	system("Pause");
	return 0;
	
}
