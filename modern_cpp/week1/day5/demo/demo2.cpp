// C++ program to show how to call parameterized Constructor 
// of base class when derived class's Constructor is called 

#include <iostream> 
using namespace std; 

// base class 
class Base { 
	int x; 

public: 
	// base class's parameterized constructor 
	Base() 
	{ 
 
		cout << "Base"
			<< endl; 
	} 
    ~Base() {
        cout<<"Base destructor \n";
    }
}; 

class Base1 { 
	int x; 

public: 
	// base class's parameterized constructor 
	Base1() 
	{ 

		cout << "Base1"
			<< endl; 
	} 

    ~Base1() {
        cout<<"Base1 destructor \n";
    }
}; 

class Base2 { 
	int x; 

public: 
	// base class's parameterized constructor 
	Base2() 
	{ 

		cout << "Base2"
			<< endl; 
	} 

    ~Base2() {
        cout<<"Base2 destructor \n";
    }
};


// sub class 
class Child : public Base, public Base1, public Base2{ 
public: 
	// sub class's parameterized constructor 
	Child()
	{ 
		cout << "Inside sub class's parameterized "
				"constructor"
			<< endl; 
	} 

    ~Child() {
        cout<<"Child destructor \n";
    }
}; 

// main function 
int main() 
{ 

	// creating object of class Child 
	Child obj1; 
    cout<<"\n\n";
	return 0; 
}
