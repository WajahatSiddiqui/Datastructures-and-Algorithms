#include <iostream>
using namespace std;

struct Heap {
    int size, count;
    int *array;
}

int leftChild(int i) {
    if (h->count <= h->size)
        return (2*i + 1);
    return -1;
}

int rightChild(int i) {
    if (h->count <= h->size)
        return (2*i + 2);
    return -1;
}

int parent(int i) {
    if (h->count <= h->size)
        return (i-1)/2;
    return -1;
}

static void max_heapify(struct Heap *h, int max) {
}

static void min_heapify(struct Heap *h, int min) {
}

static void insert(struct Heap *h, int data) {
}

static void delete_min(struct Heap *h) {
}

static void delete_min(struct Heap *h) {
}

static struct Heap* create_heap(int A[], int size) {
    struct Heap *h = new Heap();
    if (h == NULL) return NULL;
    h->size = size;
    h->count = 0;
    h->array = new int(size);
    return h;
}

static void build_heap(struct Heap *h, int A[], int size) {
}

static void heap_sort(int A[], int size) {
    struct Heap *h = create_heap(A, size);
    if (!h) return;

    build_heap(h, A, size);
    for (int i = size-1; i>=0; i--) {
        A[i] = h->array[0];
        h->array[0] = h->array[h->count-1];
        h->count--;
        max_heapify(h, 0);
    }
}

int main() {
    int A[] = {5, 6, 8, 1, -1, 0, 11, 100, -5, 0, 1, 0, 6, 1, 2, 3, 5, 10000};
    int size = sizeof(A)/sizeof(int);
    cout<<"Size = "<<size<<endl;
    cout<<"Input Array: \n";
    for (int i = 0; i < size; i++) {
        cout<<A[i]<<" ";
    }
    heap_sort(A, size-1);
    cout<<"\nHeap Sorted Array: \n";
    for (int i = 0; i < size; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

