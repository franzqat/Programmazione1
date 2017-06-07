/***Es12. Generare una matrice NxN in cui il generico elemento è (i+5)^(j+2). Senza utilizzare la funzione
pow().*/

#include <iostream>
#include <ctime>

#include <cstdlib>


//OK!
using namespace std;

double ** Genera(int righe, int colonne){
	
	double **m=new double*[righe];
	for (int i=0;i<righe;i++) m[i]= new double[colonne];

	
	double tmp;
	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++){
			m[i][j]=i+5;
				for (int k=1;k<j+2;k++) m[i][j]*=i+5; //k=1 	1<k<j+2
		cout << m[i][j] << " ";
		}
	cout << endl;
	}
	return m;
}
	

	
/*	double tmp;
	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++){
		tmp = (i+5);
		for (int k=1;k<(j+2);k++) tmp *= (i+5);
		m[i][j]=tmp;
		
		}
	cout << endl;
	
	}
	return m;
}*/

int main (){
	
	int N=5;
	double **a;
	a= Genera(N,N);	
	
	system("PAUSE");
	return 0;
}
