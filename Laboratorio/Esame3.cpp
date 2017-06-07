#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;

class A{	//class nomeclasse {parentesi

	protected:
		int x;
		
	public:
		A(int _x)  { x = _x; }//costruttore di A
	//	Nomeclasse(parametri)	{corpofunzione _par = attrib}
	
		virtual int f()=0; //abstract -> VIRTUALE PURA -> VIRTUAL .. =0;
};

class D{
	private:
		double z;
	public:
		D( double _z) {z = _z;}	
		double getZ() {return z;}
		};

class B:public A,public D{ // composizione D
	protected:
		int y;
		
	private:
		D * d; //nella soluzione è D * d;
	
	public:
		B( int _x, int _y, double _z) : A(_x), D(_z) { d = new D(_z); y=_y;}   //la x la chiama il costruttore di A, la z quello di D
		int f() { return x*x;	}
		int f(D *p1) { return p1->getZ()+d->getZ();	}

};

class C : public B{
	
	public:
		C( int _x, int _y, double _z) : B(_x, _y ,_z) {} //A e D non sono tipi base per C ma B si
		
		int f() {return 7*y; }
};


int main() {
	
	srand(6353433);
	
	
	int DIM = 100;
	A *vett [DIM];	
	int somma = 0;
	int ist =0;
	int somma2 = 0;
	
	for (int i=0; i<DIM; i++) {
		int x = rand()%10;
		int y = rand()%100;
		int z = rand()%30;	
		
		if(rand()%2 == 1) vett[i] = new B(x,y,z);
		else vett[i] = new C(x,y,z);
		
		D *obj = new D (rand()%47);
		somma2 += ((B*) vett[i])->f(obj);
		delete obj;
		
		if (typeid (*vett[i] ) == typeid (B) ) //puntatore a vett[i]
			ist++;
		
		
		
		somma += vett[i]->f();
	} 
	

	
	cout << "\nsomma: " << somma << "  <<  f(obj):" << somma2 << "   <<   Instanze: " << ist << endl;
	cout << "\n*******************\n******************** \t NNOCCA\n";
	system("PAUSE");
	return 0;

	
}
