/**
 * Find sum of maximum hour glass in a 2D array
 */
 #include <iostream>
 #include <vector>
 #include <limits.h>
 using namespace std;

 int findMaxSum(vector< vector<int> > A) {
 	int sum = 0;
 	int max = INT_MIN;

 	int dx[] = {-1, -1, -1, 0, 1, 1, 1};
 	int dy[] = {-1, 0, 1, 0, -1, 0, 1};

 	for (int i = 1; i <= 4; i++) {
 		for (int j = 1; j <= 4; j++) {
 			for (int k = 0; k < 7; k++) {
 				sum += A[i+dx[k]][j+dy[k]];
 			}
  			if (sum > max) max = sum;
 			sum = 0;
 		}
 	}
 	return max;
 }

 int main() {
 	vector< vector<int> > A(6, vector<int>(6));
 	for (int i = 0; i < 6; i++)
 		for(int j = 0; j < 6; j++)
 			cin>>A[i][j];
 	cout<<findMaxSum(A);
 	return 0;
 }