#include <iostream>
#include <cstdio>
using namespace std;

class UnionFind {
private:
	int *id, N;
public:
	UnionFind(int N) {
		this->N = N;
		id = new int[N];
		for (int i = 0; i < N; i++) id[i] = i;
	}

	~UnionFind() {
		delete [] id;
	}

	bool find(int p, int q);
	void uNion(int p, int q);
	int root(int i);
	int size(int i);
	void printArray() {
		for (int i = 0; i < N; i++) cout<<id[i]<<" ";
		cout<<endl;
	}
};

int UnionFind::root(int i) {
	while (i != id[i]) i = id[i];
	return i;
}


bool UnionFind::find(int p, int q) {
	return root(p) == root(q);
}

void UnionFind::uNion(int p, int q) {
	int pid = root(p);
	int qid = root(q);
	id[pid] = qid;
}

int UnionFind::size(int i) {
	int count = 0;
	while (i != id[i]) count++;
	return count;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, V, E, V1, V2, p, q;
	UnionFind *uf = NULL;
	freopen("common_ancestor.txt", "r", stdin);
	cin>>T;
	cout<<T<<endl;
	for(test_case = 1; test_case <= T; ++test_case)	{
		cin>>V>>E>>V1>>V2;
		cout<<V<<" "<<E<<" "<<V1<<" "<<V2<<" "<<endl;
		uf = new UnionFind(V);
		for (int i = 0; i < E; i++) {
			cin>>p>>q;
			cout<<"U("<<p<<", "<<q<<")"<<endl;
			uf->uNion(p-1, q-1);
		}
		cout<<"printing Array\n";
		uf->printArray();
		cout<<"find("<<V1<<", "<<V2<<")"<<endl;
		cout<<uf->find(V1-1, V2-1)<<endl;
		cout<<"root of "<<V1<<": "<<uf->root(V1)<<endl;
		cout<<"root of "<<V2<<": "<<uf->root(V2)<<endl;
		if (uf->find(V1-1, V2-1))
			cout<<uf->root(V1-1)<<" "<<uf->size(V1-1)<<endl;
		else
			cout<<"-1 0"<<endl;
		delete uf;

	}
	return 0;
}