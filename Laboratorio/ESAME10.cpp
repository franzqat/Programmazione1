#include <iostream>
#include <cstring>
#include <cmath>
#include <typeinfo>
#include <cstdlib>


//OK
using namespace std;

class A{
	private:
		double x;
		
	public: 
	A  (double _x) {x = _x;}
	double getX() {return x;}
	bool grande() {return (( x > 0.5 ) ? true : false);}		  //{if (x>0.5) return true;
						//				else false;}
	string toString() {}
	virtual double calcola () = 0;
	
	virtual ostream &put(ostream &os) { return os << " x = " << x;}
	
	
};

ostream &operator << (ostream &left, const A &obj) {
	return obj.put(left);
}

class B : public A{
	private:
		double y;
		
	public:
		B(double _x, double _y) : A(_x) {y= _y;}
		double calcola(double m) { return pow((getX()+m),y);
		}
	string toString();
	
	ostream &put(ostream &os){
		return A::put(os) << " y = " << y;
 	}
	
};

class D : public A{
	private:
		double w;
	
	public:
		D(double _x, double _w) : A(_x) {w=_w;}
		bool grande() { return (getX() > (0.5-w)) ? true : false;}
		double calcola() {return getX() * w;}
		string toString();
	
	ostream &put(ostream &os) {
		return A::put(os) << " w = " << w;
	}
};

class C : public B{
	private:
		double z;
	public:
		C(double _x, double _y, double _z) : B(_x, _y) {z = _z;	}
		double calcola() {return pow(getX(),z);
		}
	string toString();
	
	ostream &put(ostream &os) {
		return B::put(os) << " z = " << z;
	}	
};

int main () {
	srand(1987234111);
	A * vett[100];
	int numero =0;
	double max = 0;
	double somma =0;
	
	for (int i=0;i<100;i++){  //STATIC CAST!?!?!? 
		double a =  static_cast <double> (rand() )/ (static_cast <double> (RAND_MAX));
		double b =static_cast <double> (rand() )/ (static_cast <double> (RAND_MAX));
		if (rand()%2 == 1) {
			double c = static_cast <double> (rand() )/ (static_cast <double> (RAND_MAX));
			vett[i] = new C (a,b,c);
		}
		else vett[i] = new D(a,b);
		
		
		if (typeid (*vett[i]) == typeid (C) && ((B*) vett[i])->grande()) 
			numero++;
			
		if (typeid (* vett[i]) == typeid (D) )		
			if (((D*)vett[i])->grande()) numero++; //numero oggetti grandi
			
			
	
		if (vett[i]-> calcola() > max) max = vett[i]-> calcola();		
		if (typeid(*vett[i]) == typeid(C))
			somma+=	((B*) vett[i])->calcola(vett[i]->calcola());
			
			
		cout << *vett[i] << endl;	
		}
		
	
	cout << "grandi: " << numero << " max: " << max << " calcola: "  << somma << endl;
	
	system("PAUSE");
	return 0;



}
