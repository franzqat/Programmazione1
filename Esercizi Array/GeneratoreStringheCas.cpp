using namespace std;

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
			
			lung = rand()%8+5;
			for (int k=0;k<lung;k++) tmp +=65+ rand()%6;
			g[i][j] = tmp;
			cout << g[i][j] << "\t";
			tmp = "";
		}
	
		cout << endl;
	}

	cout << endl;
	
	return g ;
}
