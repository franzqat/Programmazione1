/* Esercizio 5
Scrivere un metodo Genera che prenda come parametri formali un intero e restituisca in output una
stringa ottenuta dalla concatenazione di vocali casuali, ognuna estratta mediante il seguente
procedimento: si lancia una moneta non truccata e se esce testa si sceglie uniformemente una vocale
tra ‘a’ ed ‘o’, altrimenti se ne sceglie una tra ‘e’, ’i’ ed ’u’.*/

//ES 2 2013 DICEMBRE
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
	cout << endl << "inserisci le righe 1 2 3\n";
	cin >> g[1];
	cin >> g[2];
	cin >> g[3];
		
	return g ;
}


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
/* Esercizio 5
Scrivere un metodo Genera che prenda come parametri formali un intero e restituisca in output una
stringa ottenuta dalla concatenazione di vocali casuali, ognuna estratta mediante il seguente
procedimento:
 si lancia una moneta non truccata e se esce testa si sceglie uniformemente una vocale
tra ‘a’ ed ‘o’, altrimenti se ne sceglie una tra ‘e’, ’i’ ed ’u’.*/

string Genera (int num){
	
	
	string b ="";
	string testa = "ao", croce = "eiu";
	for (int i=0;i<num;i++){
	
		switch (rand()%2){
			case(0): //testa
				if (rand()%1==0) b+=testa[0];
				else b+=testa[1]; 
				break;
		 case(1):
				if (rand()%3==0) b+=croce[0];
				else if (rand()%2==1) b+=croce[1];
				else b+=croce[2];
		 	break;
		}
	}	
	cout << "stringa: " << b << endl;
	return b;
	
	
}

/*
string Genera (int num){
	
	string b ="";
	string testa = "ao", croce = "eiu";
	int moneta;
	
	for (int i=0;i<num;i++){
	
		moneta = rand()%2;
		
			if (moneta==0)
			{ //testa
				if (rand()%2==0) b+=testa[0];
				else b+=testa[1]; 
				
			}
			if (moneta ==1){
		
				if (rand()%3==0) b+=croce[0];
				else if (rand()%2==1) b+=croce[1];
				else b+=croce[2];
			}
		}
	
	cout << "stringa: " << b << endl;
	return b;
	//testa = rand()%1;
	
	
}
*/

/*Esercizio 5 bis
Scrivere un metodo che prenda come parametri formali un array di interi A e restituisca in output un
corrispondente array di stringhe, in cui la i-esima stringa di lunghezza (m+A[i]) è restituita dal
metodo Genera, e dove m è la media dei valori in A.*/
string * GeneraBis(int*g,int righe){
	
	//calcolo media di g
	float media =0;
	for (int i=0;i<righe;i++) media+=g[i];
	media /= righe;
	cout << "media : " << media << "\n**\n";
	//init array
	string * output= new string[righe];
	
	for (int i=0;i<righe;i++){
		string str = Genera(media+g[i]);
		output[i] = str;
		
	}
	
	return output;
	
	
}










/*Esercizio 2:
Scrivere un metodo che prenda in input un array A di stringhe, e restituisca una stringa ottenuta
concatenando i primi 4 caratteri di tre stringhe in A che abbiano la stessa desinenza di due lettere o
restituisca la stringa vuota se le tre stringhe non esistono.*/

string Esercizio2(string * g, int righe){
	string str,strj; //variabile per usare le funzioni delle stringhe, altrimenti il dev si bugga
	for (int i=0;i<righe;i++){
		str =g[i];	
		cout << endl<<  g[i][str.length()-2]<< " _ "<<  g[i][str.length()-1] << "\n";		
		for (int j=0;j<righe;j++){
			strj=g[j];	
			if (i!=j && g[i][str.length()-1]==g[j][strj.length()-1] && g[i][str.length()-2]==g[j][strj.length()-2]){								
				for (int k=0;k<righe;k++){
					if (i!=k && k!=j && g[i][str.length()-1]==g[k][strj.length()-1] && g[i][str.length()-2]==g[k][strj.length()-2]){					
						//***
							tmp = "";
							for (int l=0;l<4;l++) tmp += g[i][l];
							for (int l=0;l<4;l++) tmp += g[j][l];
							for (int l=0;l<4;l++) tmp += g[k][l];								
						//***											
					cout << "Successo in " << g[i] << ":" << g[k] << ":" << g[j] <<" con tmp: "  << tmp << endl;
					return tmp;
					}	
				}
			}

		}
	}
			tmp = "";
			cout << "fallimento";
		return tmp;
}


int main (){
	srand(time(0));
	int N=8;
	/*
	
	string *g=GeneratoreArray(N);
	string *b=output(g,N);
	string *c=esercizio4(g,N);
	string d = Genera(10);
	
	
	*/
	string *f=GeneratoreArray(N);
	
	string es2=Esercizio2(f,N);
	cout << "\nEsercizio 2: " << es2 << endl;
/*	
	int *bis = new int[10];
	for (int i=0;i<10;i++) bis[i] = rand()%10;
	
	string *f = GeneraBis(bis, N);
	

delete [] g;
delete [] b;
delete [] c;
delete [] bis;
*/
delete [] f;
  	system("PAUSE");
	return 0;
}
