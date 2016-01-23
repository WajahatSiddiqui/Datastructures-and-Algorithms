/**
 * Rat in Maze
 */
 #include <iostream>
 #include <string.h>
 #define N 4
 using namespace std;

void printSolution(int sol[N][N]) {
	for (int i = 0; i < N; i++) {
 		for (int j = 0; j < N; j++) {
 			cout<<sol[i][j]<<" ";
 		}
 		cout<<endl;
 	}
}

 /**
  * Check if we can make a next move
  * if there is a 1 in the maze
  */
bool isSafe(int x, int y, int maze[N][N]) {
	return x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1;
}

/**
 * if next move is safe to move
 * make a move in forward direction
 * make a move in down direction
 * set the solution matrix to 1
 * if this is not the case BACKTRACK and set the solution matrix to 0
 * T(n) = O(n^2) in worst case
 */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
	if (x == N-1 && y == N-1) {
		sol[x][y] = 1;
		return true;
	}

	if (isSafe(x, y, maze)) {
		sol[x][y] = 1;
		if (solveMazeUtil(maze, x+1, y, sol)) return true;
		if (solveMazeUtil(maze, x, y+1, sol)) return true;
		sol[x][y] = 0;
		return false;
	} else {
		return false;
	}
	return false;
}

/**
 * Solve the given maze problem by using
 * SolveMazeUtil
 */
void solveMaze(int maze[N][N]) {
	int sol[N][N];
 	memset(sol, 0, N*N*sizeof(sol[N][N]));

 	if (!solveMazeUtil(maze, 0, 0, sol)) {
 		cout<<"Solution does not exists\n";
 		return;
 	} else {
 		printSolution(sol);
 	}
}

int main() {
	int maze[N][N] = { {1, 0, 0, 0},
 					   {1, 1, 0, 1},
 					   {0, 1, 0, 0},
 					   {1, 1, 1, 1}};

	/*int maze[N][N] = { {1, 1, 1, 1},
 					   {0, 0, 0, 1},
 					   {0, 0, 0, 0},
 					   {0, 0, 0, 1}};*/
 	solveMaze(maze);
 	return 0;
}