#include "UnionFind.h"

int main() {
	UnionFind *uf = new UnionFind(10);
	uf->printArray();
	uf->quickUnion(6, 5);
	uf->quickUnion(4, 3);
	uf->quickUnion(9, 4);
	uf->quickUnion(2, 1);
	uf->quickUnion(3, 8);
	uf->quickUnion(5, 0);
	uf->quickUnion(7, 2);
	uf->quickUnion(6, 1);
	uf->quickUnion(7, 3);

	uf->printArray();

	cout<<"find(8, 9) = "<<uf->find(8, 9)<<endl;
	cout<<"find(8, 4) = "<<uf->find(8, 4)<<endl;
	cout<<"size(4) = "<<uf->size(4)<<endl;

	delete uf;
	return 0;
}