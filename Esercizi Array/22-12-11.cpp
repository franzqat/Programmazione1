/*Esercizio 1:
Scrivere un metodo che prenda in input due array A e B di int di lunghezza n ed m rispettivamente,
e restituisca una matrice di dimensione nxm di int contenente il prodotto AxB se in A tutti gli
elementi sono distinti e la matrice identità altrimenti.*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//OK ENTRAMBI
int * Genera(int righe){
	int *g =new int[righe];
	for (int i=0;i<righe;i++) {
		g[i] = rand()%25;
		cout << g[i] << " ";
	}
cout << endl;

return g;
}
int ** GeneraIdentita(int righe, int colonne){
	//ok
	int **g =new int*[righe];
	for (int i=0;i<righe;i++) g[i] = new int[colonne];
	
	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++) {
			if (i!=j)	g[i][j] = 0;
			else g[i][j] = 1;
			cout << g[i][j] << " ";
		}
		cout << endl;
		
	}
	return g;
}
/*Esercizio 1:
Scrivere un metodo che prenda in input due array A e B di int di lunghezza n ed m rispettivamente,
e restituisca una matrice di dimensione nxm di int contenente il prodotto AxB se in A tutti gli
elementi sono distinti e la matrice identità altrimenti.*/


int ** Prodotto(int*a,int righe, int*b, int colonne){

	//controlla elementi A
	for (int i=0;i<righe;i++){	
		for (int j=i+1;j<righe;j++ ){	
			if ( a[i]==a[j]) {
				return GeneraIdentita(righe, colonne);
			}	
		}
	}
	//matrice righexcolonne AxB
	int**p=new int*[righe];
	for (int i=0;i<righe;i++) p[i]=new int[colonne];
	cout << endl << "Matrice prodotto: \n";
	for (int i=0;i<righe;i++){
		for (int j=0;j<colonne;j++){
			p[i][j]=a[i]*b[j];
			
			cout << p[i][j] << "\t";
			
		}
		cout << endl;
	}

	
	

	return p;
}
//*****************************************************************************************************************************


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

	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++){
			
		//	lung = rand()%8+4;
			for (int k=0;k<5;k++) tmp +=65+ rand()%6;
			g[i][j] = tmp;
			cout << g[i][j] << "\t";
			tmp = "";
		}
	
		cout << endl;
	}


//	cin >> g[2][1];
//	cin >> g[2][2];
//	cin >> g[2][3];
	cout << endl;
	return g ;
}

/*Esercizio 2:
Scrivere un metodo che prenda in input una matrice A di stringhe, e restituisca un boolean che
indichi se esiste una colonna in cui siano presenti due stringhe l'una inversa dell'altra*/

bool inverso (string**g,int righe, int colonne){
	string tmp="";
	int lung1,lunginv;
	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++){
			lung1=g[i][j].length();
	
			for(int k=j;k<colonne;k++){
				for (int l=0;l<righe;l++){	
					if (l!=i){				
						lunginv = g[l][k].length();		
								
						for (int n=lunginv-1;n>-1;n--)	tmp += g[l][k][n];
						//cout << tmp << endl;
						if (tmp==g[i][j]){
							cout << "Trovato riscontro: " << tmp << " : "<< g[i][j] << endl << "pos: " << i+1 << " " << j+1
							<< " " << l+1 << " " << k+1 << endl; 	
							return true;
						}
						else tmp="";
					}							
				}
			}
		
		
		}
		
	}
	return false;
}


int main(){ 

	srand(time(0));
	bool esercizio1=false;
	if (esercizio1){
		int lungA, lungB;
		cout << "inserisci la lunghezza di A: ";
		cin >> lungA;
			cout << "\ninserisci la lunghezza di B: ";
		cin >> lungB;
		int *g=Genera(lungA);
		int *f=Genera(lungB);
		
		int**prodotto=Prodotto(g,lungA,f,lungB);
	}
	
	string **g=GeneratoreCasuale(5,4);
	bool b = inverso(g,5,4);
	if (b) cout << "\n\n**SUCCESS\n";
return 0;
}
