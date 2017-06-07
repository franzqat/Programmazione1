/*[V]*Es2. Data una matrice A di stringhe, restituire un boolean che indica se esiste una colonna in cui siano
presenti due stringhe l' una l inversa dell altra;
*/
//OK!!*/**
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	
	srand(time(0));
	int N=2;
	string A[N][N];
	
	//generazione matrice 
	for (int i=0; i<N; i++){
	
		for (int j=0; j<N; j++){
			
			for (int k = 0; k<4;k++){
			
				A[i][j] += 65 + (rand() % 10);
				
			}
			cout << A[i][j] << " ";	
		}
	cout << endl;
	}
	
	bool inverso = false;
	//***
	int lung;
	string tmp = "";
	for (int j=0;j<N;j++){
		for (int i=0; i<N; i++){
			lung = A[i][j].length();
			
				for (int k=0; k<lung;k++){
				
					tmp+=A[i][j][(lung-k)-1];//GENERA STRINGA INVERSA
				//	cout << "j " << j << " k: " << k << endl;			
					}//	cout << "tmp: "<< tmp << endl;
			
			for (int k=0;k<N;k++)
				if (tmp==A[k][j] && k !=i) {
					inverso = true;
					//cout << tmp << endl;
					//cout << "Trovate due stringhe corrispondenti nella colonna: " << j+1 << " riga: " << k+1 << endl;
				}  		//stessa J
			tmp = "";
			
			
		}
	
	
			
	}
	if (inverso) cout << "Esistono!\n";
	else cout << "Non esistono!\n"	;	
	
	for (int i=0;i<N;i++)	cout << A[i][0][i] << endl;

	system("pause");
	return 0;
}
