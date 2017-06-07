/* Esercizio 5
Scrivere un metodo Genera che prenda come parametri formali un intero e restituisca in output una
stringa ottenuta dalla concatenazione di vocali casuali, ognuna estratta mediante il seguente
procedimento: si lancia una moneta non truccata e se esce testa si sceglie uniformemente una vocale
tra ‘a’ ed ‘o’, altrimenti se ne sceglie una tra ‘e’, ’i’ ed ’u’.*/

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
int main (){
	srand(time(0));
	int N=8;
	string *g=GeneratoreArray(N);
	string *b=output(g,N);
	string *c=esercizio4(g,N);
	string d = Genera(10);
	
	int *bis = new int[10];
	for (int i=0;i<10;i++) bis[i] = rand()%10;
	
	string *f = GeneraBis(bis, N);
	

delete [] g;
delete [] b;
delete [] c;
delete [] bis;
  	system("PAUSE");
	return 0;
}
