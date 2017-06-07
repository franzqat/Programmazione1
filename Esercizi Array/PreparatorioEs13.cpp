/**Es13. Data una matrice di stringhe, dire se esiste una riga contenente due stringhe congruenti di ordine
3.
Due stringhe si dicono congruenti di ordine N se il prefisso di lunghezza N della prima, e' uguale al
suffisso di lunghezza N della seconda;*/

//TESTO INCOMPRSO!


/* *Es14. Dire se una stringa è palindroma; */


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
			
			lung = rand()%8+4;
			for (int k=0;k<lung;k++) tmp +=65+ rand()%6;
			g[i][j] = tmp;
			cout << g[i][j] << "\t";
			tmp = "";
		}
	
		cout << endl;
	}

/* //PRINT	
	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++)	{
			cout << g[i][j] << "\t\t";
		}	
		cout << endl;
	}
*/
	cout << endl;
	return g ;
}









int main (){
	int N=2,M=3;
	string **a=GeneratoreCasuale(N,M);


	
	system("PAUSE");
	return 0;
}
