#include <iostream>
#define N 8
using namespace std;


// A utility function to check the valid indexes
// of N*N chess board
bool isSafe(int x, int y, int sol[N][N]) {
	return (x >= 0 
		&& y >= 0
		&& x < N
		&& y < N
		&& sol[x][y] == -1);
}

/**
 * Print the solution
 */
void printSolution(int sol[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[N], int yMove[N]) {
   int k, next_x, next_y;
   if (movei == N*N)
       return true;
 
   /* Try all next moves from the current coordinate x, y */
   for (k = 0; k < 8; k++)
   {
       next_x = x + xMove[k];
       next_y = y + yMove[k];
       if (isSafe(next_x, next_y, sol))
       {
         sol[next_x][next_y] = movei;
         if (solveKTUtil(next_x, next_y, movei+1, sol,
                         xMove, yMove) == true)
             return true;
         else
             sol[next_x][next_y] = -1;// backtracking
       }
   }
 
   return false;
}

void solveKT() {
	int sol[N][N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sol[i][j] = -1;
		}
	}
	
	/* xMove[] and yMove[] define next move of Knight.
       xMove[] is for next value of x coordinate
       yMove[] is for next value of y coordinate */
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
	sol[0][0] = 0;

  	/* Start from 0,0 and explore all tours using
       solveKTUtil() */
	if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == false) {
		cout<<"Solution does not exists";
		return;
	} else {
		printSolution(sol);
	}
}

int main() {
	solveKT();
	return 0;
}