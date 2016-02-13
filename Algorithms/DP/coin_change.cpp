#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin>>N>>M;
	int i = 0;
	int *C = new int[M];
	if (!C) return 0;

	// Get the coin denomination
	while (i != M) cin>>C[i++];

	delete [] C;
	
	return 0;
}