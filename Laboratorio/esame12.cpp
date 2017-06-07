//ESAME12

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <typeinfo>

using namespace std;


class A{
	private:
		string x;
	
	public: 
	A(string _x) {x = _x;}
	string getX() {return x;	}
	
	virtual string guess() =0;
	bool doppia(){ 
		for (int i=0;i<x.length()-1;i++)
			for (int j=i+1; j<x.length(); j++)  
				if (x[j] == x[i]) return true;
		return false;
	}
	string toString() {};	
};

class B : public A{
	string y;
	int pos;
};
