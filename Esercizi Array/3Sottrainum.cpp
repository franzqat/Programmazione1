#include <iostream>
using namespace std;
const int DIM = 100;
const int m=1321;

int main (){
	int i=DIM;
	int a[DIM];
	int num=m;

	while (i>0){
		a[i-1] = num;
		num-=3;
		i--;
		
		cout << "\t" << a[i]<< endl ;
			}
	}
