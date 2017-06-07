/**Scrivere un metodo che prenda come parametri formali un array di stringhe A e restituisca in output
un array B di m stringhe, dove:
• m è la lunghezza media delle stringhe in A di lunghezza maggiore di 5, e
• la i-esima stringa di B è ottenuta concatenando (m*i) asterischi.*/
/*Esercizio 4
Scrivere un metodo che prenda come parametri formali un array di stringhe A e restituisca in output
un array B di h stringhe, dove:
• h è la lunghezza massima delle stringhe in A di lunghezza maggiore di 2, e
• la i-esima stringa di B è ottenuta concatenando i volte il carattere ‘a’.*/

//CON: *GENERATORE STRINGHE CASUALI DI LUNGHEZZA CASUALE
#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <string.h>
//OK
using namespace std;

string * GeneratoreArray (int righe)	//GENERA array di STRINGHE CASUALI DI LUNGHEZZA CASUALE
{
	string *g = new string[righe];

	for (int i=0;i<righe;i++)	g[i] = "";
	int lung;
	string tmp="";

	for (int i=0;i<righe;i++){			
		lung = rand()%8+5;
		for (int k=0;k<lung;k++) tmp +=65+ rand()%6;
		g[i] = tmp;
		cout << g[i] << "\n";
		tmp = "";
	}	
	cout << endl;
	
	return g ;
}

/**Scrivere un metodo che prenda come parametri formali un array di stringhe A e restituisca in output
un array B di m stringhe, dove:
• m è la lunghezza media delle stringhe in A di lunghezza maggiore di 5, e
• la i-esima stringa di B è ottenuta concatenando (m*i) asterischi.*/

string * output(string*g,  int righe){
	
	int media=0;
	int count =0;
	for (int i=0;i<righe;++i)	if (g[i].length() > 5) count+=g[i].length();

	media = count / righe;	
	
	string *b = new string[media];
	cout << "Matrice B: \n" << endl;
	
	string iesima ="";
cout << "media: " << media << endl;
	b[0] = iesima;
	for (int i=0;i<media;i++){ 
		for (int j=1;j<i*media;j++) iesima += '*'; 
	b[i] = iesima;
	iesima = "";
	
	cout << b[i] << endl;	
	}
	
	
	return b ;
}


/*Esercizio 4
Scrivere un metodo che prenda come parametri formali un array di stringhe A e restituisca in output
un array B di h stringhe, dove:
• h è la lunghezza massima delle stringhe in A di lunghezza maggiore di 2, e
• la i-esima stringa di B è ottenuta concatenando i volte il carattere ‘a’.*/

string * esercizio4(string *g, int righe){
	
	int high=2;
	for (int i=0;i<righe;i++) 
		if (g[i].length() > high) high = g[i].length();
	
	string *b = new string[high];
	cout << "\n**Esercizio 4**\n";
	string iesima ="";
	b[0] = "";
	for (int i=0;i<high;i++){
		for (int j=0;j<i;j++) iesima += 'a';
		b[i] = iesima;
		iesima = "";
		cout << b[i] << endl;
		}
	return b;
}

int main (){//srand missing
	int N=4;
	string *g=GeneratoreArray(N);
	string *b=output(g,N);
	string *c=esercizio4(g,N);


delete [] g;
delete [] b;
delete [] c;
  	system("PAUSE");
	return 0;
}
