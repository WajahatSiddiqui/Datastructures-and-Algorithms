// http://www.geeksforgeeks.org/pure-virtual-destructor-c/
// 1) C++ Accepts pure virtual destructors, a Base class needs to provide definition for pure
// virtual destructor as well because it is being called in reverse order and compiler
// looks for its definition
// 2) class contains abstract class if it contains any pure virtual functions
// 3) If a base class has pure virtual functions
// in the derived class to implement it
#include <iostream>
using namespace std;

class Base {
    public:
    virtual ~Base() = 0; // pure virtual destructor
    virtual void foo() = 0;
};

// Definition of destructor
// if this is not defined compiler throws
// linker error
Base :: ~Base() {
    cout<<"Base destructor called\n";
}

class Derived : public Base {
    public:
    ~Derived() {
        cout<<"Derived destructor called\n";
    }
    void foo() {
        cout<<"I am foo\n";
    }
};


int main() {
    // the below is not possible because Base is abstract
    // Derived *d = new Base();
    // Base is inaccessible here when it is not public
    Base *b = new Derived();
    // first calls derived then calls base
    delete b;
    return 0;
}
