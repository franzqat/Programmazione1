//ESAME6

#include <cstdlib>
#include <iostream>
#include <typeinfo>

using namespace std;

 class A{
	private: 
		int x;
	
	public:	
		A (int _x) {x = _x; } // ;
		virtual  int f( int _x) =0;
		int getX () {return x;	}
};

class E{
	private:
		float coeff;
	
	public:
		E (double _c) { coeff = _c;	}
		double getCoeff () {return coeff;	}
		int somma (int *v, int len){
			int s=0;
			for (int i=0;i<len;i++) s+=v[i];
			return s;
			}
	
};

class B: public A{ //public A
	private:
		E *e;
	
	public:
		B (int _x, double _d) : A (_x) {e= new E(_d); }// non serve richiamare il costruttore E(_d) fuori dalle {}
		float getCoef()	{return e->getCoeff();	}
		E* getE() {return e;	} //E*
};

class C: public B {
	
	private:
		int *z;
	
	public:
		C(int _x, double _d, int _q) : B(_x, _d) { 
			z = new int [_x];
			for (int i=0;i<_x;i++)
				z[i] = (2*_q+i+1);
			}
		
		int f( int _x) 	{return getE()->somma(z, _x);}	 //getX()
		int ultimo() {return z[getX()-1];}
		
};

class D : public B{
	
	public:
		D (int _x, double _d) : B(_x,_d) {}
		
		int f(int _x)  {return _x + getCoef() + 100;}
		
};

int main(){
	srand(7645544);
	int len = 100;
	A* vett[len];
	

	
	int somma=0;
	int massimo =0;
	int ist=0;
	for (int i =0; i<len;i++){
		int x = rand()%10 + 1;
		double d = rand() * 40;
		int z = rand()%30;
		
		if (rand()%2 == 1) vett[i] = new C(x, d, z);
			else	vett[i] = new D(x,d);
	
		x=rand()%50;
		somma += vett[i]->f(x);
		
	//	if ((C*) vett[i]->ultimo() > massimo)
	//			massimo = (*C)vett[i]->ultimo();
		
		if (typeid (*vett[i] )== typeid (C)) {
			ist++;
		if ( ((C*) vett[i])->ultimo() > massimo)
				massimo = ((C*)vett[i])->ultimo();
		}
	}
	
	cout << "somma: " << somma << ", max : " << massimo << " ,  istanze: " << ist << endl;	
	
	
	
}

