/**Es9. Data una matrice A di float, determinare un bool che indica se esistono in A 3 elementi, nella
stessa colonna, ma in posizioni distinte, la cui somma è nulla;*/
//*AGGIUNTA: DATO EPSILON, RESITUTIRE IL NUMERO DI COLONNE DI A CONTENENTI 3 VALORI IL CUI PRODOTTO SIA MINORE DI EPSILON
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
//OK! x2

float** Genera(int righe, int colonne){
		float **a= new float*[righe];
		float input;
		for (int i=0;i<righe;i++) a[i] = new float[colonne];
		//********************
		cout << "inserisci i valori della matrice: \n";
		for (int j=0;j<colonne;j++){
			for (int i=0;i<righe;i++){	
			cin >> input;
			a[i][j] = input;
			
			}
	
		}
		return a;
	}

void Stampa(float** a, int N, int M){
	
	for (int j=0;j<M;j++){
		for (int i=0;i<N;i++){	
			cout << a[j][i]<<" ";
			}
		cout << endl;
	}
}

bool Somma(float**a, int rig, int col){

	float somma=0;
	for (int j=0;j<col;j++){
		for (int i=0;i<rig;i++){	
		
			for (int k=0;k<rig;k++){
				for (int l=0;l<rig;l++){
					
				if (i!=k && i!=l && k!=l && a[i][j]	+ a[k][j] + a[l][j] == 0){
			//	cout << "ALLELUJA" << " colonna " << j << "valori: "<< i+1 << " " << 1+k << " " << l+1  <<endl;
			//	cout << a[i][j]	<< " "<<  a[k][j]  << " " << a[l][j] << endl;
				return true;
				}
				
				}
			}	
		}
	}+
	return false;
}
// DATO EPSILON, RESITUTIRE IL NUMERO DI COLONNE DI A CONTENENTI 3 VALORI IL CUI PRODOTTO SIA MINORE DI EPSILON
int Prodotto(float ** a, int rig, int col, float eps){
	int prodotto =0;
	int j=0;
//	for (int j=0;j<col;j++){		
		for (int i=0;i<rig;i++){		//1
			for (int k=0;k<rig;k++){		//2
					for (int l=0;l<rig;l++){	//3
						if(i!=k && i!=l && k!=l){							
							while (j<col){
							
								if(a[i][j] * a[k][j] * a[l][j] < eps){						
									cout << "trovato prodotto\n";
									cout << a[i][j]	<< " "<<  a[k][j]  << " " << a[l][j] << endl;
									prodotto++;
									j++;
								}
							j++;
							}
						}
					}
			}
		}
//	}
	return prodotto;
}

void Delete(float**a,int rig,int col){
	for (int i=0;i<rig;i++)
	delete [] a[i];
	delete [] a;
	return;
}

int main() {
	
	srand(time(0));
	//*******************
	int N=3;
	int M = N;
	float**a=Genera(N,M);
	Stampa(a,N,M);
	cout <<endl<< a[1][2];
	//**********************
	bool esistono = Somma(a,N,M);
/*	float somma=0;
	for (int j=0;j<N;j++){
		for (int i=0;i<N;i++){	
		
			for (int k=0;k<N;k++){
				for (int l=0;l<N;l++){
					
				if (i!=k && i!=l && k!=l && a[i][j]	+ a[k][j] + a[l][j] == 0){
			//	cout << "ALLELUJA" << " colonna " << j << "valori: "<< i+1 << " " << 1+k << " " << l+1  <<endl;
			//	cout << a[i][j]	<< " "<<  a[k][j]  << " " << a[l][j] << endl;
				esistono = true;
				}
				
				}
			}	
		}
	}
*/
	if (esistono) cout << " Esistono (somma)!!";
	
	//********* DATO EPSILON, RESITUTIRE IL NUMERO DI COLONNE DI A CONTENENTI 3 VALORI IL CUI PRODOTTO SIA MINORE DI EPSILON
	float epsilon;
	cout << "\n Inserisci il valore di Epsilon: ";
	cin >> epsilon;
	

	cout << "\n\nEsistono " << Prodotto(a,N,M,epsilon) << " colonne in cui ci sono 3 valori il cui prodotto e' minore di " << epsilon << endl;
	
	for (int i=0;i<N;i++)
	delete [] a[i];
	delete [] a;
	//Delete(a,N,M);
	system("PAUSE");
	return 0;
}
