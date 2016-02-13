#include <iostream>
using namespace std;

int main() {
	int N = 4;
	char items[] = {'a', 'b', 'c', 'd'};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout<<items[i^j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}