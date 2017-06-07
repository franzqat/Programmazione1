/* *Es14. Dire se una stringa è palindroma; */


//CON: *GENERATORE STRINGHE CASUALI DI LUNGHEZZA CASUALE
#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <string.h>
//
using namespace std;


bool Palindroma (string a){
	string tmp = "";
	string inv="";
	for (int i=0;i<a.length(); i++)
		if (a[i] != ' ') tmp+=a[i]; //itopinonavevanonipoti senza spazi ok
	
	for (int j=a.length()-1;j>-1;j--) //a.lenght() - 1 e' importante ,altrimenti non va
	if (a[j] != ' ') inv+=a[j];		// crea inverso ok
	cout << tmp << "\t" << inv << endl;

	
	if (inv==tmp) 	return true;
	else return false;
	
}


int main (){
	int N=2,M=3;
	string a="i topi non avevano nipoti";
	cout << a << endl;
//	for (int i=0;i<a.length(); i++) cout << a[i] << " ";
	
	
	bool pal = Palindroma (a);
	if (pal) cout << "**PALINDROMA!*\n";
	else cout << "** non e' palindroma\n";



	
	system("PAUSE");
	return 0;
}
