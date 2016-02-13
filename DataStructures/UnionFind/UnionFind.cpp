#include "UnionFind.h"

int UnionFind::root(int i) {
	while (i != id[i]) i = id[i];
	return i;
}

bool UnionFind::find(int p, int q) {
	return root(p) == root(q);
}

void UnionFind::quickUnion(int p, int q) {
	int rootp = root(p);
	int rootq = root(q);
	id[rootp] = rootq;
}

int UnionFind::size(int i) {
	int count = 0;
	while (i != id[i]) {
		count++;
		i = id[i];
	}
	return count;
}

void UnionFind::printArray() {
	for (int i = 0; i < n; i++) cout<<id[i]<<" ";
	cout<<endl;
}