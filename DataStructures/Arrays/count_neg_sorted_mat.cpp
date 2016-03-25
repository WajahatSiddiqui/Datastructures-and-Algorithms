// Count negative numbers in row-wise col-wise sorted matrix
#include <iostream>
using namespace std;

void print(int mat[][4], int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int countNeg(int mat[][4], int N, int M) {
	int i = 0, j = M-1, count = 0;
	while (i < N && j >= 0) {		
		if (mat[i][j] < 0) {
			count += j + 1;
			i++;
		} else {
			j--;
		} 
	}
	return count;
}

int main() {	
	int mat[3][4] = { {-4, -3, -2, -1},
					 { -3, -2, -1, 0},
					 { 1, 1, 2, 1}};

	print(mat, 3, 4);
	cout<<"Negative nos = "<<countNeg(mat, 3, 4);
	return 0;
}