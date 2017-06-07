/*[V]*Es6. Data una matrice quadrata (es. 5x5) contenente bool, monaco su montagna.*/

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
	
	int N = 5, M=N;
	int i,j;
	int x = 3-1, y = 2; //2 2 significa elemento 3 3

	//*init matrice
	cout << "Questa e' la mappa:\n\n";
	cout << "\t1 2 3 4 5 \n\n";

	//**********
	bool **a;	
	a = new bool*[N];
	////////////////////****************mappa come pdoppio
	for (int i=0;i<N;i++){
		a[i]=new bool[M];
	}
	
	for (i = 0; i<N; i++){
		cout  <<i+1 << "\t"; // stampa indice colonne
		for (j=0;j<M;j++)
	
			{
			if ((rand()) % 2 == 0) a[i][j] = true;
			else a[i][j] = false;
			cout << a[i][j] << " ";
			}
		cout << endl;
	} 

	//init monaco
	bool monaco = a[x][y];
	int perla = 0, vita = 100;
	
	int count = 0;
	int *salti= & count;
	
	cout << "\nIl monaco si trova sul cocuzzolo e va alla ricerca delle perle di saggezza.\n";
	
	if (monaco == true) {
			perla++;
			a[x][y]=0;
	
			}
	int	mossa;
	/*
	cout<< "Muovi il monaco.";
	cout<< "\nDigita:\n";
	cout<< "\t 1 per farlo andare verso SU" << endl;
	cout<< "\t 2 per farlo andare verso DX" << endl;
	cout<< "\t 3 per farlo andare verso GIU" << endl;
	cout<< "\t 4 per farlo andare verso SX" << endl;
	cout<< "\t 100 per USCIRE" << endl;
	*/
//	stampamappa(a,N,M);

	while (vita > 0)
	{
	
		
		mossa = salto(*salti);
/****** sposta il monaco
1 - su -N
2 - destra +M
3 - giu +N
4 - sx -M	*************/
		 
		if (mossa == 1) {
				
			if ((x-1)<0) vita = 0;	
			else	x-=1;
			monaco = a[x][y];
		}	
		
		if (mossa == 2)	//monaco = a[x][y+1];
		{
			if ((y+1)>4) vita = 0;
			else	y+=1;
			monaco = a[x][y];
		}
		
		if (mossa == 3){ //monaco = a[x+1][y];
			if ((x+1)>4) vita = 0;	
			else	x+=1;
			monaco = a[x][y];
		}
		
		
		if (mossa == 4){// monaco = a[x][y-1];
			if ((y-1)<0) vita = 0;	
			else	y-=1;
			monaco = a[x][y];
		}
		
		
		if (monaco == true) {
			perla++;
			a[x][y] =0;
			cout << "\t* Il monaco ha trovato una perla di saggezza in:  " << x+1 << " " << y+1 << endl;
			}

	//	stampamappa(a,N,M);
		}
	
	cout << "\nIl monaco ha perso l'equilibrio dopo " << count << " passi e ai suoi eredi lascia " << perla << " perle.\n"; 
	/*****delete******/
	for (int i=0;i<N;i++)
		delete [] a[i];
		delete a;



	system ("PAUSE");
	return 0;
}
