/*V]*Es3. Data la matrice A[7][10] di float restituire l'indice di una riga il cui elemento massimo è
strettamente minore dei valori medi della riga sovrastante e di quella sottostante o restituire il valore -1 se
tale riga non esiste (non è possibile usare array ausiliari);
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
//FUNZIONANTE

int main() {
	srand(time(0));
	float a[7][10];
	int risultato;
	int db = 1;  //*** DEBUG: 0 DISABILITATO, 1 ABILITATO;
	for (int i = 0; i<7; i++){
		for (int j = 0; j<10; j++){		
			a[i][j] = (rand()%5);//*(0.33);
			cout << a[i][j] << " ";
		}
	cout << endl;
	}
//*******************	
float max = 0.0;
float mediasup = 0.0, mediainf= 0.0;
	for (int i = 0; i<7; i++){
		for (int j = 0; j<10; j++){		
			//trova massimo
			if (max < a[i][j]) max = a[i][j];	 
			//mediasup
			if (j>0 && i>0) mediasup += a[i-1][j-1];
			else 
			mediasup =0.0;
			
			//mediainf
			if (j<10 && i<7) mediainf += a[i+1][j+1];
			else 
			mediainf = 0.0;
		}
		//**
		if (db==1) 
		{
		mediasup /= 10;
		mediainf /= 10; 
		cout<<"\n\nmediasup:"<< mediasup;	//**
		cout<<"\tmediainf:"<< mediainf;
		cout << "\t max: "<< max << endl;
		}//**
		if (( max < mediasup) && (max < mediainf)) 
		{
		if (db==1) cout << "Risultato  i= " << i<<endl;
		risultato = i;
		}
		else
		risultato = -1;
		
		mediasup = 0.0;
		max = 0.0;
		mediainf=0.0;
	}
	
	cout << "\n\n\tRisultato: "<< risultato<<endl;
	
	
	system("PAUSE");
	return 0;
}
