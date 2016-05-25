/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
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
	for (int i = 0; i <= MAX_DISTANCE; i++) {
		for (int j = 0; j <= N; j++) {
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
	for (int i = 0; i <= MAX_DISTANCE; i++) {
		for (int j = 0; j <= N; j++) {
			if (j > 0 && i == 1)
				T[i][j] = T[i][j - i] + fares[i - 1];
			else
				T[i][j] = 0;
		}
	}
	//print(T, N);
	for (int i = 2; i <= MAX_DISTANCE; i++) {
		for (int j = 1; j <= N; j++) {
			if (j == i) {
				T[i][j] = min(fares[i - 1], T[i-1][j]);
			}
			else if (j < i) {
				T[i][j] = T[i - 1][j];
			}			
			else if (j > i) {
				T[i][j] = min(T[i - 1][j], T[i][j - i] + fares[i - 1]);
			}
		}
	}
	//print(T, N);
	result = T[MAX_DISTANCE][N];

	for (int i = 0; i <= MAX_DISTANCE; i++)
		delete[] T[i];
	delete[] T;
	return result;
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	freopen("bus_fares.txt", "r", stdin);

	cin >> T;
	int *fares;
	int N; // KMS which the person has to travel
	for (test_case = 0; test_case < T; test_case++)
	{
		fares = new int[MAX_DISTANCE];
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < MAX_DISTANCE; i++) {
			cin >> fares[i];
		}
		cin >> N;
		Answer = getMinFare(fares, N);

		// Print the answer to standard output(screen).
		//cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;

		delete[] fares;
	}

	return 0;//Your program should return 0 on normal termination.
}
