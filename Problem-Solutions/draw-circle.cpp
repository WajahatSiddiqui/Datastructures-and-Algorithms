/**
 * Program to draw circle with radius r
 * uses the concept if (x,y) lies satisfies
 * x^2 + y^2 = r^2 then there is point else 
 * there is a space.
 * http://geeksquiz.com/draw-circle-without-floating-point-arithmetic/
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

void drawCircle(int r) {
    int N = 2*r + 1; // define the square boundary
    int x, y; // co-ordinates in the boundary
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            x = i - r;
            y = j - r;

            // point lies inside the circle print the pixel
            if (x*x + y*y <= r*r + 1)
                cout<<".";
            else // lies outside the circle print space
                cout<<" ";
            cout<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) return 0;

    drawCircle(atoi(argv[1]));
    return 0;
}
