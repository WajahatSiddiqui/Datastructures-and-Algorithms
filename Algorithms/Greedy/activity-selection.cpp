//Activity Selection 
//http://www.geeksforgeeks.org/greedy-algorithms-set-1-activity-selection-problem/
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

// sort based on finish time
// uses insertion sort
void sort(int s[], int f[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (f[j] < f[i]) {
                swap(&f[j], &f[i]);
                swap(&s[j], &s[i]);
            }
        }
    }
}

// (1) select the activity based on finish time
// (2) if start time of next activity is greater than
// or equal to previous activity finish time then select this
// activity
// Build the solution piece by piece by selecting the activities
// as per (2)
void printMaxActivities(int s[], int f[], int size) {
    int i, j;
    i = 0; // first activity is selected by default
    cout<<"Job# "<<i<<" -> "<<s[i]<<"-"<<f[i]<<endl;
    for (j = 1; j < size; j++) {
        if (s[j] >= f[i]) {
            cout<<"Job# "<<j<<" -> "<<s[j]<<"-"<<f[j]<<endl;
            i = j;
        }
    }
}

int main() {
    int s[] = {1, 5, 13, 14, 8, 3};
    int f[] = {10, 6, 15, 17, 14, 12};
    int size = sizeof(s)/sizeof(s[0]);
    sort(s, f, size);
    cout<<"Print S: ";
    print(s, size);
    cout<<"Print F: ";
    print(f, size);
    printMaxActivities(s, f, size);

    return 0;
}
