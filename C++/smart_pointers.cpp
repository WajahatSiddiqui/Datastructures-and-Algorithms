
#include <iostream>
using namespace std;

template <class T>
class SmartPointer {
private:
	T *ptr;
public:
	explicit SmartPointer(T *p = NULL) {
		ptr = p;
	}
	~SmartPointer() {
		cout<<"deleting the object\n";
		delete ptr;
	}
	T & operator * () { return *ptr; }
	T * operator -> () { return ptr; }
};

int main() {
	SmartPointer<int> sm(new int());
	*sm = 10;
	cout << *sm;
	return 0;
}