//esempio 1

#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <cmath>
#include <sstream> //per ostringstream

using namespace std;

class C {
	private:
		float x;
		
	public:
		C(float _x) { x = _x;	}
		virtual double f() = 0;
		float getX() {return x;}
		
		virtual ostream &put (ostream &os) {
			
			return os << "[ " << x;
		}
};

ostream &operator << (ostream &left, C &obj) {
	return obj.put(left);
}

class D : public C {
	private:
		char c;
	
	public:
		D(float _x) : C(_x) { c= 'a' + (int) getX()*100;}
		double f() {return sin(getX() )* sin(getX()); 	}
		char getC() {return c;	}
		
		ostream &put (ostream &os) {
			return C::put(os) << " c = " << c;	}
};

class E : public C{
	private:
	int n;
	
	public:
		E(float _x) : C(_x) {n = (int) getX()*100;	}
		double f() {return cos(getX())*cos(getX());}
		int getN() {return n;}
		
		ostream &put (ostream &os){
			return C::put(os) << " n = " << n ; } 
		
};


class A{
	protected:
		C * obj1;
		C * obj2;
		
	public:
		A(float _x) {	obj1 = new D(_x);
						obj2 = new E(_x);}

		double g() const { return  obj1->f() + obj2->f(); }
		
		virtual ostream &put (ostream & os) const {
		return os << typeid(*this).name() << " " << *obj1 << " : " << *obj2 << " g() =" << g();
	}	

}; //end class A

ostream &operator << (ostream &left, A &obj) {
	return obj.put(left);
}

class B : public A{
	public:
		B(float _x) : A(_x) {}
		string st() const{
			string str ="";
			for (int i=0; i < ((E*) obj2) ->getN() ;i++)
			str += ((D*)obj1)->getC();
			
			ostringstream os;
			os << g();
			
			return os.str() + str;
		}
		
		ostream &put (ostream &os) const {
			return A::put(os) << " st() = " << st();
		}
		
		
};

int main() {
	srand(832748);
	int DIM = 50;
	int somma =0;
	int sum2=0;
	A * vett[50];
	for (int i=0;i<DIM;i++) {
		if (rand()%2==1) vett[i] = new A((float)rand()/INT_MAX);
			else vett[i] = new B((float)rand()/INT_MAX);
	
	cout << i <<"  " <<*vett[i] << endl;			
		
	somma += vett[i].g();	
	
	if (typeid(*vett[i])==typeid(B))
		for(int j=0;j<((B *)vett[i])->st().length();j++)
 		//for(int j=0;j<((B *)vett[i])->st().length();j++){
		 sum2 += ((B*) vett[i])->st()[j];
	
	} 	
	
	cout << "sum " << somma << " somma2" << sum2 <<endl;
	}





