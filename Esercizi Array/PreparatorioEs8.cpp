/*Es8. Generare una stringa casuale di lunghezza 3<n<8, in cui ogni carattere è estratto tra (a,b,c,d)
-a con probabilità 1/7;
-b 3/7;
-c 2/7;
-d 1/7;*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;
//OK!
int main(){
	srand(time(0));
	int min = 3;
	int max = 8;
	int N = rand()%6+3;
	string a = "";
	int r;
	
	for (int i=0;i<N;i++){
	
		r = rand()%7+1;
		cout << r << endl;
		
		if (r==1) a+=65;
		if (r==2 || r==3 || r== 4) a+=66;
		if (r==5 || r==6) a+=67;
		if (r==7) a+=68;
		
	}

	
		cout  << a<<  endl;
	
	
	system("PAUSE");
	return 0;
	
	}


