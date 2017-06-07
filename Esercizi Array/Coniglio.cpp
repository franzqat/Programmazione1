/*[V]*Es6. Data una matrice quadrata (es. 5x5) contenente bool, vi sarà un coniglio inizialmente al centro di
questa matrice, che si sposterà di cella in cella, e li dove ci sarà una carota (bool true), la mangia,
trasformando il bool da true in false. Il coniglio parte da una vita pari a 100, e facendo salti casuali nella 4
direzioni si muove nella mappa, perdendo 1 di vita ogni salto, ed acquistando 10 di vita per ogni carota
mangiata. Nel bordo della matrice, possiamo decidere se porre delle limitazioni, non facendo fuoriuscire il
coniglio dalla matrice, oppure possiamo porre dei "teletrasporti" facendo ricomparire il coniglio dalla parte
opposta della matrice (es. esce di sotto e rispunta nella parte superiore della matrice). Contare i salti
effettuati dal coniglio, fino alla sua morte.*/

#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int salto(int &nsalti){
	/*
	1 - su -N
	2 - destra +M
	3 - giu +N
	4 - sx -M
	*/
	int dir = rand() % 4 + 1;
	nsalti++;
	return dir;
} 

void stampamappa (bool **mappa, int righe, int colonne) {
	for (int i = 0; i<righe; i++){
			for (int j=0;j<colonne;j++)	cout << mappa[i][j] << " ";
				
			cout << endl;
		}
	
	}

int main () {
	srand(time(0));
	
	int N = 5;
	int M = N;
	//bool a[N][M];
	int i,j;
	int x = 3-1, y = 2; //2 2 significa elemento 3 3

	//*init matrice
	cout << "Questa e' la mappa prima della razzia del coniglio:\n\n";
	cout << "\t1 2 3 4 5 \n\n";
/*	for (i = 0; i<N; i++){
			cout  <<i+1 << "\t";
		for (j=0;j<M;j++)
	
			{
			if ((rand()) % 2 == 0) a[i][j] = true;
			else a[i][j] = false;
			cout << a[i][j] << " ";
			}
		cout << endl;
	}
*/	

	//**********
	bool **a;	
	a = new bool*[N];
	////////////////////****************mappa come pdoppio
	for (int i=0;i<N;i++){
		a[i]=new bool[M];
	}
	
	for (i = 0; i<N; i++){
		cout  <<i+1 << "\t";
		for (j=0;j<M;j++)
	
			{
			if ((rand()) % 2 == 0) a[i][j] = true;
			else a[i][j] = false;
			cout << a[i][j] << " ";
			}
		cout << endl;
	} 

	//init coniglio
	bool coniglio = a[x][y];
	int vita = 100;
	
	int count = 0;
	
	
	cout << "\nIl coniglio comincia al centro. Se trova una carota, la mangia e guadagna 10hp.\n";
	cout << "Se non trova nulla, muore lentamente di fame.\n";
	
	if (coniglio == true) {
			vita+=10;
			a[x][y] =0;
	
			}
	
	int	mossa;
	cout<< "Muovi il coniglio.";
	cout<< "\nDigita:\n";
	cout<< "\t 1 per farlo andare verso SU" << endl;
	cout<< "\t 2 per farlo andare verso DX" << endl;
	cout<< "\t 3 per farlo andare verso GIU" << endl;
	cout<< "\t 4 per farlo andare verso SX" << endl;
	cout<< "\t 100 per USCIRE" << endl;
	stampamappa(a,N,M);
	while (vita > 0)
	{
	
		
		cin >> mossa;
/****** sposta il coniglio
1 - su -N
2 - destra +M
3 - giu +N
4 - sx -M	*************/
		 
		if (mossa == 1) {
				
			if ((x-1)<0) x=4;	
			else	x-=1;
			coniglio = a[x][y];
		}	
		
		if (mossa == 2)	//coniglio = a[x][y+1];
		{
			if ((y+1)>4) 	y=0;
			else	y+=1;
			coniglio = a[x][y];
		}
		
		if (mossa == 3){ //coniglio = a[x+1][y];
			if ((x+1)>4) x=0;	
			else	x+=1;
			coniglio = a[x][y];
		}
		
		
		if (mossa == 4){// coniglio = a[x][y-1];
			if ((y-1)<0) y=4;		
			else	y-=1;
			coniglio = a[x][y];
		}// coniglio = a[x][y-1];
		
		if (mossa==100) vita = 0;
		
		vita--;
		if (coniglio == true) {
			vita+=10;
			a[x][y] =0;
			cout << "\t*Om Nom* Mangio nella posizione " << x+1 << " " << y+1 << endl;
			}

		stampamappa(a,N,M);
		}
		
	/*****delete******/
	for (int i=0;i<N;i++)
		delete [] a[i];
		delete a;



	system ("PAUSE");
	return 0;
}
