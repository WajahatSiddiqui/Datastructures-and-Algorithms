/**
 * Rotate an image represented by NxN matrix by 90 degrees
 * Each pixel in the image is represented by int (4 bytes)
 */

 #include <iostream>
 using namespace std;
 #define SIZE 4

void rotate(int image[][SIZE], int size) {
	for (int layer = 0; layer < size/2; ++layer) {
		int first = layer;
		int last = size-1-layer;
		for (int i = first; i < last; ++i) {
			int offset = i - first;

			// save top
			int top = image[first][i];

			// left -> top
			image[first][i] = image[last-offset][first];

			// bottom -> left
			image[last-offset][first] = image[last][last-offset];

			// right -> bottom
			image[last][last-offset] = image[i][last];

			// top -> right
			image[i][last] = top;
		}
	}
}

void printArray(int image[][SIZE], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout<<image[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main() {
	int image[][SIZE] = { {1, 2, 3, 4},
					   {5, 6, 7, 8},
					   {9, 10, 11, 12},
					   {13, 14, 15, 16}};
	int size = sizeof(image)/(SIZE*sizeof(image[0][0]));
	printArray(image, size);
	rotate(image, size);
	printArray(image, size);
}