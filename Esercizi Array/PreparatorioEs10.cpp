/*Es10. Due stringhe si dicono simili se esse coincidono in almeno P posizioni, dove P è la metà (troncata)
della lunghezza della stringa più
corta. Scrivere un metodo che prende in input una matrice di stringhe e restituisca un boolean che indichi
se esiste una colonna della matrice
in cui sono presenti almeno 2 stringhe simili.*/

#include <iostream>
#include <ctime>
#include <string.h>
#include <cstdlib>
//OK!
using namespace std;

string ** generatore (int righe, int colonne)
{
	string **g = new string*[righe];
	for (int i=0;i<righe;i++) g[i]= new string[colonne];
	//init a zero
	for (int i=0;i<righe;i++){
		for (int j=0;j<colonne;j++){
			g[i][j] = "";
		}
	}
	//init a stringhe random
	int lung;
	string tmp="";
	//cout << "inserisci le stringhe: \n";
	for (int i=0;i<righe;i++){
		for (int j=0;j<colonne;j++){
			
			lung = rand()%15+10;
			for (int k=0;k<lung;k++) tmp +=65+ rand()%6;
			
			g[i][j] = tmp;
		//	lenght=g[i][j].length()
			cout << g[i][j] << "\t";
			tmp = "";
		}
	
		cout << endl;
	}
	cout << endl;
	return g ;
}

/***********/


bool simile(string** a,int righe, int colonne){


	//**stablisci lunghezza minima
	int P =a[0][0].length();
	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++){
			if(a[i][j].length() < P)
				P = a[i][j].length();
		}
			
	}
	
/*Scrivere un metodo che prende in input una matrice di stringhe e restituisca un boolean che indichi se esiste una colonna della matrice
in cui sono presenti almeno 2 stringhe simili.*/
	P=P/2;
	cout << "la meta' troncata P e': " << P <<endl;
	
	int count=0;
	bool esiste=false;
	//int j =0;
	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++){
		/**/	
			
			for (int l=0;l<righe;l++){
				for (int k=0;k<a[i][j].length();k++){				
					if (i!=l && a[i][j][k] == a[l][j][k] ){
					//	cout << "count++! " <<  a[i][j][k] << " :: "<< a[l][j][k] << " --K: " << k << endl ;
						count++;
						if (count == P) return true;
					}
				}
			}
		
		/**/
			
		}
	}
return false;
}

/*

	for (int j=0;j<colonne;j++){
		
		for (int i=0;i<righe;i++){
			for (int k=0;k<righe;k++){
	
				if (m[i][j] == m[k][j] && i!=k){
					cout << m[i][j] << "   " << m[k][j] << endl; //********COMANDO COMPARA STRINGHE!?!?
					count++;
					if (count == 2) return true;
					}
				
			
			}
			
		}
	}
	return false;
}
*/
int main() {
	
	srand(time(0));
	int N = 3,M=2;
	string **a;
	a=generatore(N,M);
	
		
	bool b = false;
	b= simile(a,N,M);
	if (b) cout << "\n*****Matrice simile!!**********\n";
//	cout <<endl<< a[1][1] << endl;
	
	system ("PAUSE");
	return 0;
}
