/*[V]*EsBonus(vecchio compito). Scrivere un metodo che prenda in input una matrice S di stringhe, e
restituisca una copia S' di S in cui ogni stringa di lunghezza x:
- resta identica, se x=8;
- subisce l'inserimento a sinistra di (8-x) caratteri '*', se x<8;
- subisce l'eliminazione dei primi (x-8) caratteri, se x>8;*/

//CON: *GENERATORE STRINGHE CASUALI DI LUNGHEZZA CASUALE
#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <string.h>
//
using namespace std;

string ** GeneratoreCasuale (int righe, int colonne)	//GENERA STRINGHE CASUALI DI LUNGHEZZA CASUALE
{
	string **g = new string*[righe];
	for (int i=0;i<righe;i++) g[i]= new string[colonne];
	//*init a zero
	for (int i=0;i<righe;i++){
		for (int j=0;j<colonne;j++){
			g[i][j] = "";
		}
	}

	int lung;
	string tmp="";

	for (int i=0;i<righe;i++){
		for (int j=0;j<colonne;j++){
			
			lung = rand()%8+5;
			for (int k=0;k<lung;k++) tmp +=65+ rand()%6;
			g[i][j] = tmp;
			cout << g[i][j] << "\t";
			tmp = "";
		}
	
		cout << endl;
	}

	cout << endl;
	
	return g ;
}

/*[V]*EsBonus(vecchio compito). Scrivere un metodo che prenda in input una matrice S di stringhe, e
restituisca una copia S' di S in cui ogni stringa di lunghezza x:
- resta identica, se x=8;
- subisce l'inserimento a sinistra di (8-x) caratteri '*', se x<8;
- subisce l'eliminazione dei primi (x-8) caratteri, se x>8;*/

string ** Copia(string**g, int righe, int colonne){
	
	string tmp = "";
	string ** copia=GeneratoreCasuale(righe, colonne);
	
	
	cout << "Matrice copia generata \n";
	
	int x;
	string str;
	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;++i){
			x=g[i][j].length();
			
			if(x==8) copia[i][j]=g[i][j];
			if (x<8) {
				str=g[i][j];
				
				str.insert(8-x, 1, '*');
				copia[i][j]= str;
				}	
			
			if (x>8) {
				str=g[i][j];
				str.erase (str.begin(), str.end()-8);
				copia[i][j]=str;		
			}
			
			
		}
	}
	return copia;
}





int main (){
	int N=4,M=9;
	string **g=GeneratoreCasuale(N,M);
	cout << "\n********************************************\n***SONO PIGRO, IGNORA QUESTA PARTE **********************";

	string **b=Copia(g,N,M);
	cout << "\n********************************************\n";

	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			cout << b[i][j] << "\t";
		}
		cout << endl;
		}




	for (int i=0;i<N; i++)	delete [] g[i];
	delete [] g;
	
	for (int i=0;i<N; i++)	delete [] b[i];
	delete [] b;

	system("PAUSE");
	return 0;
}
