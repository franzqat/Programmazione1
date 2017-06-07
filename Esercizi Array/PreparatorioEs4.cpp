/*[V]*Es4. Data una matrice quadrata di stringhe, restituire una stringa ottenuta concatenando tutti gli ultimi
caratteri delle stringhe presenti nella diagonale principale;
[V]*Es5. Stesso dell'Es4, però prendere la diagonale secondaria;*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
//OK! 4-5

	string dprincipale(string**g, int righe){
		string str,dp="";
		int lung;
		for (int j=0;j<righe;j++){
		
			for (int i=j;i<righe;i++){		
				if (i==j){
				
					str = g[i][j];
					lung=str.length()-1; //IMPORTANTE -1
					dp+= g[i][j][lung];
					//cout << "last char " << g[i][j][lung] << endl;
				}
			}
	
	}
		return dp;
}



string dsecondaria(string**g,int righe){
		string str,dsecond="";
		int lung;
		for (int j=0;j<righe;j++){
			for (int i=0;i<righe;i++){
				if (i+j==righe-1){  // righe-1 IMPORTANTE
					str = g[i][j];
					lung = str.length()-1;
					dsecond+=g[i][j][lung];
			//		cout << "DS: " << dsecond << endl;
				}	
			}
		}
			return dsecond;
}

int main() {
	
	srand(time(0));
	int N=5;
//	string A[N][N];
	
	string **a=new string*[N];
	for (int i =0;i<N;i++) a[i]=new string[N];
	for (int j=0;j<N;j++){
		for (int i=0;i<N;i++){
			a[i][j]="";
			for (int k=0;k<5;k++)	a[i][j] += 65 + (rand() % 5);
			cout << a[i][j] << "\t";
		}
	cout << endl;
	}
	
//	cin >> a[2][0];
	string dp=dprincipale(a,N);
	string ds=dsecondaria(a,N);
	cout <<"\n*CONCATENAZIONE PRINCIPALE   " << dp << endl;
	cout <<"*CONCATENAZIONE SECONDARIA   " << ds << endl;
/*	//*******************generazione matrice 
	for (int i=0; i<N; i++){
	
		for (int j=0; j<N; j++){
			
			for (int k = 0; k<4;k++){
			
				A[i][j] += 65 + (rand() % 5);
				
			}
			cout << A[i][j] << " ";	
		}
	cout << endl;
	//**************************************
	
	}
	
	*/
	int lung;
	string tmp = "";
	int count =0;
	//**
/*	//cout << "ultimi caratteri: \n"; //ok!
	for (int j=0;j<N;++j){
		for (int i=j; i<N; i++){ //**i=j riduce le volte che il ciclo lavora, da 25 a 15!
			count++;
			lung = A[i][j].length();
			
			if (i==j) tmp += A[i][j][lung-1]; //cout <<A[i][j][lung-1] << " ";	//ultimi caratteri	
			
		}
	cout << endl;					
	}
	cout << "stringa somma ultimi caratteri diagonale princ:  " <<tmp << endl;
	cout << endl << count << endl<< endl;; 
		//***
	//*ESERCIZIO 5:
	/*Es5. Stesso dell'Es4, però prendere la diagonale secondaria;
	count =0;
	tmp ="";

	for (int i =0;i<N;i++){
		for(int j=0;j<N;j++){
			count++;
			lung=A[i][j].length();
			
			if (i+j==(N-1)) tmp +=A[i][j][lung-1];
			
		}
	}
	cout << "stringa somma ultimi caratteri diagonale secondaria:  " <<tmp << endl;
	cout << endl << count << endl<< endl;; 
	
*/
	system("pause");
	return 0;
}
