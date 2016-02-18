// http://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/

#include <iostream>
#include <queue>
using namespace std;

struct rotorg {
	int x, y;
};


bool canMove(int map[][5], int R, int C, int x, int y) {
	return x >= 0 && x < R && y >= 0 && y < C && map[x][y] == 1;
}

/**
 * if any one the cell has 1, it means
 * all of the oranges has not been rotten
 */
bool validate(int map[][5], int R, int C) {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (map[i][j] == 1) return true;
	return false;
}

bool isDelim(rotorg delim) {
	return delim.x == -1 && delim.y == -1;
}

void printQueue(queue<rotorg> &q) {
	cout<<q.size();
	while (!q.empty()) {
		cout<<"("<<q.front().x<<", "<<q.front().y<<") ";
		q.pop();
	}
}

int rotOranges(int map[][5], int R, int C) {	
	queue<rotorg> q;
	rotorg org, neworg;
	rotorg delim;
	delim.x = -1; delim.y = -1;
	int timeframe = 0;
	bool isRottened = false;
	// fill the queue with all rotten oranges
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (map[i][j] == 2) {
				org.x = i;
				org.y = j;
				q.push(org);
			}
		}
	}
	// Push the delim
	q.push(delim);
	//printQueue(q);
	/// Perform BFS
	while (!q.empty()) {
		while (!isDelim(q.front())) {
			rotorg r = q.front();
			// Consider all the 4 directions of x, y
			//                (x-1, y)
			//				    |
			//   (x, y-1)  -- (x, y) -- (x, y+1)
			//					|
			//				  (x+1, y)
			if (canMove(map, R, C, r.x, r.y+1)) {
				map[r.x][r.y+1] = 2;
				neworg.x = r.x;
				neworg.y = r.y+1;
				q.push(neworg);
				if (!isRottened) isRottened = ~isRottened;
			}
			if (canMove(map, R, C, r.x, r.y-1)) {
				map[r.x][r.y-1] = 2;
				neworg.x = r.x;
				neworg.y = r.y-1;
				q.push(neworg);
				if (!isRottened) isRottened = ~isRottened;
			}
			if (canMove(map, R, C, r.x-1, r.y)) {
				map[r.x-1][r.y] = 2;
				neworg.x = r.x-1;
				neworg.y = r.y;
				q.push(neworg);
				if (!isRottened) isRottened = ~isRottened;
			}
			if (canMove(map, R, C, r.x+1, r.y)) {
				map[r.x+1][r.y] = 2;
				neworg.x = r.x+1;
				neworg.y = r.y;
				q.push(neworg);
				if (!isRottened) isRottened = ~isRottened;
			}
			q.pop();
		}
		// pop out the old delim and push the new one 
		q.pop();
		if (!q.empty()) q.push(delim);
		if (isRottened) {
			timeframe++;
			isRottened = ~isRottened;
		}
	}
	return !validate(map, R, C) ? timeframe : -1;
}

int main() {
	int map[][5] = { {2, 1, 0, 1, 1},
					 {1, 0, 1, 1, 1},
					 {1, 0, 0, 1, 2}};
	cout<<"Time required to rotten all oranges is: "<<rotOranges(map, 3, 5)<<endl;
	return 0;
}