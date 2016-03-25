/**
Tops of Heads
N numbers of staffs stand in a row. Their heights are various. Some staffs can see top of heads of colleagues but other can’t. The same height can’t see their top of the heads each other.﻿





Various heights of 6 staffs in the   are given. Once everyone stand in a row and they watch the person  their right side. The First staff can see the second, the third and the 4th peoples top of the heads but he cannot see 6th person's head. 

﻿

Find out how many staffs can see top of heads for his right side people  in the given staff's height.

Time limit: 1 second (jave: 2 seconds)

[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ≤ 30) are given in a row. 
N, the number of staffs is given in the first row of each test case. (1 ≤ N ≤ 80000)
H, the height of each staff is given from the second row to the number of N. (1 ≤ H ≤ 1,000,000,000)

[Output]
For each test case, you should print "Case #T" in the first line where T means the case number. For each test case, you should output the sum number of staffs who can see other staffs’ tops of heads in the first row of each test case. 

[I/O Example] 

Input 
2
6
10
3
7
4
12
2
10
999999999
2
999999999
2
999999999
2
999999999
2
999999999
2

Output
Case #1

5

Case #2
5 

 */
#include <iostream>
#include <cstdio>
using namespace std;

unsigned long getTopOfHeads(unsigned long H[], unsigned long N) {
	unsigned long count = 0;
	for (unsigned long i = 0; i < N; i++) {
		for (unsigned long j = i+1; j < N; j++) {
			if (H[i] > H[j])
				count++;
			else
				break;
		}
	}
	return count;
}

unsigned long getTopOfHeadsEfficient(unsigned long H[], unsigned long N) {
	unsigned long count = 0;
	for (unsigned long i = 0; i < N-1; i++) {
		if (H[i] > H[i+1]) {
			if (i+2 < N && H[i+1] > H[i+2]) {
				for (unsigned long j = i+1; j < N; j++) {
					if (H[i] > H[j])
						count++;
					else
					break;
				}
			}
			int t = H[i];
			H[i] = H[i+1];
			H[i+1] = t;
			count++;
		}
	}
	return count;
}


int main() {
	unsigned long T, N;
	freopen("top_of_heads.txt", "r", stdin);
	cin>>T;
	for (unsigned long t = 1; t <= T; t++) {	
		cin>>N;
		unsigned long *H = new unsigned long[N]; // heights
		for (unsigned long i = 0; i < N; i++)
			cin>>H[i];
		cout << "Case #" << t << endl;
		cout << getTopOfHeadsEfficient(H, N) << endl;
		delete [] H;
	}
	return 0;
}