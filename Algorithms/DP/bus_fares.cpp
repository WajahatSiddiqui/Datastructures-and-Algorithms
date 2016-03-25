
/**
In a city, a bus stops every kilometer. Also the bus fare is different from 1km to 10km, so you can use each section well to decrease the total fare to get to the destination. 
For example, let’s suppose a bus fare list as below:



According to the list, the minimum fare would be 147 for 15km: 1 ticket for 3km + 2 tickets for 6km. Or 3 tickets for 5km will have the same result. Other ways cost more. When the bus fare and distance are given, calculate the minimum fare that you can move the given distance. 

Time limit: 1 second (java: 2 seconds)

[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ≤ 30) are given in a row. 
The info of the bus fare, 10 integers are given on the first row per each test case. This is the bus fare from 1km to 10km respectively, and the maximum bus fare is 500. In addition, i km fare is not always bigger than (i-1)km. The distance to move, N is given on the second row. (1 ≤ N ≤ 10000)

[Output]
Output the minimum fare to give the given distance on the first row per each test case. 

[I/O Example]
Input
12 21 31 40 49 58 69 79 90 101
15
12 20 30 40 25 60 70 80 90 11
21

Output
Case #1

147
Case #2 

34 

 */
#include <iostream>
#include <cstdio>
using namespace std;
#define MAX_DISTANCE 10

int Answer;

unsigned long min(unsigned long a, unsigned long b) {
	return a < b ? a : b;
}

void print(unsigned long **T, int N) {
	for (int i = 1; i <= MAX_DISTANCE; i++) {
		for (int j = 1; j <= N; j++) {
			cout << T[i][j] << " ";
		}
		cout << endl;
	}
}

unsigned long getMinFare(int *fares, int N) {
	unsigned long result = 0;
	unsigned long **T = new unsigned long*[N + 1];
	for (int i = 0; i <= MAX_DISTANCE; i++) {
		T[i] = new unsigned long[N + 1];
	}
	for (int i = 0; i <= MAX_DISTANCE; i++)
	for (int j = 0; j <= N; j++)
		T[i][j] = 0;
	//print(T, N);
	for (int i = 1; i <= MAX_DISTANCE; i++) {
		for (int j = 1; j <= N; j++) {
			if (j == i) {
				T[i][j] = fares[i - 1];
			}
			else if (j < i) {
				T[i][j] = T[i - 1][j];
			}
			else if (i == 1) {
				T[i][j] = T[i][j - i] + fares[i - 1];
			}
			else if (j > i) {
				T[i][j] = min(T[i - 1][j], T[i][j - i] + fares[i - 1]);
			}
		}
	}
	print(T, N);
	result = T[MAX_DISTANCE][N];

	for (int i = 0; i <= MAX_DISTANCE; i++)
		delete[] T[i];
	delete[] T;
	return result;
}

int main(int argc, char** argv)
{
	int T;
	freopen("bus_fares.txt", "r", stdin);
	cin >> T;
	int fares[MAX_DISTANCE] = {0};
	int N = 5; // KMS which the person has to travel
	for (int test_case = 0; test_case < T; test_case++) {
		for (int i = 0; i < MAX_DISTANCE; i++) {
			cin >> fares[i];
		}
		cin >> N;
		Answer = getMinFare(fares, N);

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
