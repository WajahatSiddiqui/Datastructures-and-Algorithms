#include <iostream>
#include <map>
#include <ctime>
using namespace std;

class Timer
{
public:
    Timer() { clock_gettime(CLOCK_REALTIME, &beg_); }

    double elapsed() {
        clock_gettime(CLOCK_REALTIME, &end_);
        return end_.tv_sec - beg_.tv_sec +
            (end_.tv_nsec - beg_.tv_nsec) / 1000000000.;
    }

    void reset() { clock_gettime(CLOCK_REALTIME, &beg_); }

private:
    timespec beg_, end_;
};

// T(n) = O(n^2)
// S(n) = O(n)
static int getUnique(int A[], int size) {
    int i, j, count = 0;
    for (i = 0; i < size; i++) {
        for (j = i; j < size; j++)
            if (i != j && A[i] == A[j]) break;
        if (A[i] != A[j])
            count++;
    }
    return count;
}

// T(n) = O(n)
// S(n) = O(n)
static int getUniqueUsingMap(int A[], int size) {
    map<int, int> mapObj;
    for (int i = 0; i < size; i++)
        mapObj.insert(pair<int, int>(A[i], i));
    return mapObj.size();
}


int main() {
    Timer t;
    int A[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 3, 3, 3, 3, 3, 3, 3, 1};
    int size = sizeof(A)/sizeof(A[0]);

    cout<<"Unique elements: "<<getUnique(A, size)<<endl;
    cout<<t.elapsed()<<endl;
    t.reset();
    cout<<"Unique elements: "<<getUniqueUsingMap(A, size)<<endl;
    cout<<t.elapsed()<<endl;
    return 0;
}

