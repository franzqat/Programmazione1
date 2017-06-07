/*[V]*Es11. Scrivere un metodo che prenda in input una matrice A e un'array B, entrambe di stringhe, e
restituisca un boolean che indichi se esiste in A una coppia di stringhe la cui concatenazione, privata delle
occorrenze del carattere 'a', sia presente in B.*/

#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <string.h>
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
	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++)	{
			
			cin >> g[i][j];
			}
	}	
	
	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++)	{
			cout << g[i][j] << "\t\t";
		}	
		cout << endl;
	}
	
	cout << endl;
	return g ;
}
int main (){
	int N=2,M=3;
	string **a=generatore(N,M);
	string **b=generatore(N,1);
	bool risultato =concatena(a,N,M,b,N);
	if (risultato) cout << "trovato!" << endl;
	
	system("PAUSE");
	return 0;
}
bool concatena(string **a,int righe,int colonne, string **b,int rig){
	string somma="";
	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++){
			for (int l=0;l<righe;++l){
				if (i!=l){
				
					for (int k=0;k<a[i][j].length();++k)	if(a[i][j][k] !='a') somma+=a[i][j][k];
					
				
					for (int k=0;k<a[l][j].length();++k)	if(a[l][j][k] != 'a') somma+=a[l][j][k];
					cout << "somma: " << somma << endl;
					for (int h=0;h<rig;h++){
						if (b[h][0] == somma ){
							cout << " true!!";
							 return true;
						}
						
			 		else somma="";
					}	
				}
			}
		}
	}
	
	return false;
}

int main (){
	int N=2,M=3;
	string **a=generatore(N,M);
	string **b=generatore(N,1);
	bool risultato =concatena(a,N,M,b,N);
	if (risultato) cout << "trovato!" << endl;
	
	system("PAUSE");
	return 0;
}
