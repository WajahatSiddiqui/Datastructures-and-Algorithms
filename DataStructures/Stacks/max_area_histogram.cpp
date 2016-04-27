// Program to evaluate the maximum area under the given histogram
#include <iostream>
#include <stack>
using namespace std;

int getMaxArea(int A[], int N) {
	stack<int> s;
	int max = -1, top_area = 0, top = 0, i = 0;
	while (i < N) {
		if (s.empty() || A[s.top()] <= A[i])
			s.push(i++);
		else {
			top = s.top();
			s.pop();
			if (s.empty()) {
				top_area = A[top] * i;
			} else {
				top_area = A[top] * (i - s.top() - 1);
			}
			if (top_area > max) max = top_area;
		}
	}
	while (!s.empty()) {
			top = s.top();
			s.pop();
			if (s.empty()) {
				top_area = A[top] * i;
			} else {
				top_area = A[top] * (i - s.top() - 1);
			}
			if (top_area > max) max = top_area;

	}
	return max;
}

int main() {
	int A[] = {6, 2, 5, 4, 5, 6, 7};
	int size = sizeof(A)/sizeof(A[0]);
	cout<<getMaxArea(A, size)<<endl;

	return 0;
}