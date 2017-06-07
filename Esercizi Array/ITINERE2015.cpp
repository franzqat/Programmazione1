/*Esercizio 1:
Scrivere un metodo che prenda in input una matrice quadrata di stringhe nxn e restituisca true se
esiste una stringa nella diagonale secondaria avente i primi tre caratteri coincidenti con gli ultimi tre
di una qualunque stringa nella diagonale principale, false altrimenti.


Esercizio 2:
Scrivere un metodo che prenda in input un vettore di interi e restituisca un bool che indichi se
esistono due numeri “più vicini” (cioè differenza in valore assoluto minima) la cui somma è un
multiplo di 7.*/

//OKOK
#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
//
using namespace std;

string ** GeneratoreInput (int righe, int colonne)	//GENERA STRINGHE CASUALI DI LUNGHEZZA CASUALE
{
	string **g = new string*[righe];
	for (int i=0;i<righe;i++) g[i]= new string[colonne];


	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++){		
			cin >> g[i][j];
		}
	
		cout << endl;
	}

	cout << endl;
	
	return g ;
}



string ** GeneratoreCasuale (int righe, int colonne)	//GENERA STRINGHE CASUALI DI LUNGHEZZA CASUALE
{
	string **g = new string*[righe];
	for (int i=0;i<righe;i++) g[i]= new string[colonne];
	//*init a zero
	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++){
			g[i][j] = "";
		}
	}

	int lung;
	string tmp="";

	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++){
			
			lung = rand()%8+4;
			for (int k=0;k<lung;k++) tmp +=65+ rand()%6;
			g[i][j] = tmp;
			cout << g[i][j] << "\t\t\t";
			tmp = "";
		}
	
		cout << endl;
	}

	cout << endl;
	
	return g ;
}
/*/*Esercizio 1:
Scrivere un metodo che prenda in input una matrice quadrata di stringhe nxn e restituisca true se
esiste una stringa nella diagonale secondaria avente i primi tre caratteri coincidenti con gli ultimi tre
di una qualunque stringa nella diagonale principale, false altrimenti.*/

bool esercizio1(string**g,int righe, int colonne){
	
	string primi ="", ultimi="";
	for (int j=0;j<colonne;j++){
		for (int i=0;i<righe;i++){
			//diagonale secondaria			
			if (i+j==righe-1){						//******************<<-------------RIGHE - 1!!!!!!!
				for(int l=0;l<3;l++)  primi += g[i][j][l];
			}	 		
		//	cout << "PRIMI 3 char : " << primi << endl;
			for (int f=0;f<colonne;f++){
				for (int k=0;k<righe;k++){
					for (int h=g[k][f].length()-3;h<g[k][f].length();h++) ultimi+=g[k][f][h];
				//	cout << "ultimi: "<<ultimi << endl;
					if (primi == ultimi){
					cout << "ultimi: "<<ultimi << "in pos " << k+1 << ":" << f+1<< endl;
					cout << endl<< primi << "in pos " << i+1 << ":" << j+1 << endl;
					 return true;
					}
					else ultimi = "";
					
				}
			}
			primi = "";
	
		}
	}
	
return false;
}

/*Esercizio 2:
Scrivere un metodo che prenda in input un vettore di interi e restituisca un bool che indichi se
esistono due numeri “più vicini” (cioè differenza in valore assoluto minima) la cui somma è un
multiplo di 7.*/



bool esercizio2(int *g, int righe){
	int minimo, dist, c;
		
	for (int i=0;i<righe;i++){
		if (i==0) minimo =g[i];		
			if (i!=0){
				dist=abs(g[i-1]-g[i]);		
				
				if (dist<minimo)
				c=g[i-1]+g[i];			
			}
		
		if (c%7==0) return true;
	}
	return false;
}


int main(){
	srand(time(0));
	int righe = 3;
	int colonne = 3;
	
	string **a=GeneratoreCasuale(righe,colonne);//Input(righe, colonne);
	
	bool ex1=esercizio1(a,righe,colonne);
	if (ex1) cout << "I primi saranno gli ultimi\n " << endl;
	else cout << "no\n\n";
	
	int *bis = new int[10];
	for (int i=0;i<10;i++) {
		bis[i] = rand()%100;
		cout << bis[i] << " ";
	}
	cout << endl;
	
	
	bool ex2=esercizio2(bis, 10);
	if (ex2)	cout << "Funzia"<< endl;
	else cout << "no\n";
	
	
	
	system("PAUSE");
	return 0;
}
