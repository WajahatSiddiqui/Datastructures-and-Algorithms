#include "Sorting.h"
#include <cstdlib>
#include <ctime>
#include <string.h>

void generateRandomNumber(int d[], int size) {
	for (int i = 0; i < size; i++) {
		d[i] = rand() % (size - i + 1);
	}
}

double executeFunction(void (Sorting::*function)(int*, int), Sorting &sorting, int data[], int size) {
	time_t start, end;
	time(&start);
	(sorting.*function)(data, size);
	time(&end);
	return difftime(end, start);
}

int main() {
	Sorting sorting;
	//Generate datasets
	int d1[2500], d2[5000], d3[10000], d4[20000], d5[40000];
	int bd1[2500], bd2[5000], bd3[10000], bd4[20000], bd5[40000];
	memcpy(bd1, d1, sizeof(d1));
	memcpy(bd2, d2, sizeof(d2));
	memcpy(bd3, d3, sizeof(d3));
	memcpy(bd4, d4, sizeof(d4));
	memcpy(bd5, d5, sizeof(d5));

	generateRandomNumber(d1, 2500);
	generateRandomNumber(d2, 5000);
	generateRandomNumber(d3, 10000);
	generateRandomNumber(d4, 20000);
	generateRandomNumber(d5, 40000);
	//generateRandomNumber(d6, 80000);

	cout<<"selection sort: 2500 values: "<<executeFunction(&Sorting::selection_sort, sorting, d1, 2500)<<"secs"<<endl
	    <<"selection sort: 5000 values: "<<executeFunction(&Sorting::selection_sort, sorting, d2, 5000)<<"secs"<<endl
	    <<"selection sort: 10000 values: "<<executeFunction(&Sorting::selection_sort, sorting, d3, 10000)<<"secs"<<endl
	    <<"selection sort: 20000 values: "<<executeFunction(&Sorting::selection_sort, sorting, d4, 20000)<<"secs"<<endl
	    <<"selection sort: 40000 values: "<<executeFunction(&Sorting::selection_sort, sorting, d5, 40000)<<"secs"<<endl;
	memcpy(d1, bd1, sizeof(d1));
	memcpy(d2, bd2, sizeof(d2));
	memcpy(d3, bd3, sizeof(d3));
	memcpy(d4, bd4, sizeof(d4));
	memcpy(d5, bd5, sizeof(d5));

	cout<<"\nbubble sort: 2500 values: "<<executeFunction(&Sorting::bubble_sort, sorting, d1, 2500)<<"secs"<<endl
	    <<"bubble sort: 5000 values: "<<executeFunction(&Sorting::bubble_sort, sorting, d2, 5000)<<"secs"<<endl
	    <<"bubble sort: 10000 values: "<<executeFunction(&Sorting::bubble_sort, sorting, d3, 10000)<<"secs"<<endl
	    <<"bubble sort: 20000 values: "<<executeFunction(&Sorting::bubble_sort, sorting, d4, 20000)<<"secs"<<endl
	    <<"bubble sort: 40000 values: "<<executeFunction(&Sorting::bubble_sort, sorting, d5, 40000)<<"secs"<<endl;
	memcpy(d1, bd1, sizeof(d1));
	memcpy(d2, bd2, sizeof(d2));
	memcpy(d3, bd3, sizeof(d3));
	memcpy(d4, bd4, sizeof(d4));
	memcpy(d5, bd5, sizeof(d5));

	cout<<"\ninsertion sort: 2500 values: "<<executeFunction(&Sorting::insertion_sort, sorting, d1, 2500)<<"secs"<<endl
	    <<"insertion sort: 5000 values: "<<executeFunction(&Sorting::insertion_sort, sorting, d2, 5000)<<"secs"<<endl
	    <<"insertion sort: 10000 values: "<<executeFunction(&Sorting::insertion_sort, sorting, d3, 10000)<<"secs"<<endl
	    <<"insertion sort: 20000 values: "<<executeFunction(&Sorting::insertion_sort, sorting, d4, 20000)<<"secs"<<endl
	    <<"insertion sort: 40000 values: "<<executeFunction(&Sorting::insertion_sort, sorting, d5, 40000)<<"secs"<<endl;
	memcpy(d1, bd1, sizeof(d1));
	memcpy(d2, bd2, sizeof(d2));
	memcpy(d3, bd3, sizeof(d3));
	memcpy(d4, bd4, sizeof(d4));
	memcpy(d5, bd5, sizeof(d5));

	/*cout<<"\nmerge sort: 2500 values: "<<executeFunction(&Sorting::merge_sort, sorting, d1, 2500)<<"secs"<<endl
	    <<"merge sort: 5000 values: "<<executeFunction(&Sorting::merge_sort, sorting, d2, 5000)<<"secs"<<endl
	    <<"merge sort: 10000 values: "<<executeFunction(&Sorting::merge_sort, sorting, d3, 10000)<<"secs"<<endl
	    <<"merge sort: 20000 values: "<<executeFunction(&Sorting::merge_sort, sorting, d4, 20000)<<"secs"<<endl
	    <<"merge sort: 40000 values: "<<executeFunction(&Sorting::merge_sort, sorting, d5, 40000)<<"secs"<<endl;
*/
	cout<<"\nquick sort: 2500 values: "<<executeFunction(&Sorting::quick_sort, sorting, d1, 2500)<<"secs"<<endl
	    <<"quick sort: 5000 values: "<<executeFunction(&Sorting::quick_sort, sorting, d2, 5000)<<"secs"<<endl
	    <<"quick sort: 10000 values: "<<executeFunction(&Sorting::quick_sort, sorting, d3, 10000)<<"secs"<<endl
	    <<"quick sort: 20000 values: "<<executeFunction(&Sorting::quick_sort, sorting, d4, 20000)<<"secs"<<endl
	    <<"quick sort: 40000 values: "<<executeFunction(&Sorting::quick_sort, sorting, d5, 40000)<<"secs"<<endl;
	memcpy(d1, bd1, sizeof(d1));
	memcpy(d2, bd2, sizeof(d2));
	memcpy(d3, bd3, sizeof(d3));
	memcpy(d4, bd4, sizeof(d4));
	memcpy(d5, bd5, sizeof(d5));

	cout<<"\nshell sort: 2500 values: "<<executeFunction(&Sorting::shell_sort, sorting, d1, 2500)<<"secs"<<endl
	    <<"shell sort: 5000 values: "<<executeFunction(&Sorting::shell_sort, sorting, d2, 5000)<<"secs"<<endl
	    <<"shell sort: 10000 values: "<<executeFunction(&Sorting::shell_sort, sorting, d3, 10000)<<"secs"<<endl
	    <<"shell sort: 20000 values: "<<executeFunction(&Sorting::shell_sort, sorting, d4, 20000)<<"secs"<<endl
	    <<"shell sort: 40000 values: "<<executeFunction(&Sorting::shell_sort, sorting, d5, 40000)<<"secs"<<endl;
	memcpy(d1, bd1, sizeof(d1));
	memcpy(d2, bd2, sizeof(d2));
	memcpy(d3, bd3, sizeof(d3));
	memcpy(d4, bd4, sizeof(d4));
	memcpy(d5, bd5, sizeof(d5));

    return 0;
}