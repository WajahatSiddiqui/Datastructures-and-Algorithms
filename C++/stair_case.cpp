#include <stdio.h>
#include <iostream>
using namespace std;

void printArray(char A[], int size) {
  for (int i = 0; i < size; i++) cout<<A[i];
  cout<<endl;
}
void printStairCase(int height) {
  char *A = new char[height];
  for (int i = 0; i < height; i++) A[i] = ' ';
  int right = height-1;
  for (int i = 0, right = height-1; i < height && right >= 0; i++, right--) {
    A[right] = '#';
    printArray(A, height);
  }
  delete [] A;
}

int main() {
  int n = 100;
  printStairCase(n);
  return 0;
}