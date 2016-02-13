#include <iostream>
using namespace std;
#ifndef __UNION_FIND__
#define __UNION_FIND__

// Implement Quick Union Datastructure
class UnionFind {
private:
	int *id, n;
public:
	UnionFind(int N) : n(N) {
		id = new int[N];
		for (int i = 0; i < N; i++) id[i] = i;
	}

	~UnionFind() {
		delete [] id;
	}

	int root(int i);
	bool find(int p, int q);
	void quickUnion(int p, int q);
	int size(int i);
	void printArray();
};

#endif // __UNION_FIND__