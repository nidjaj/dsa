#include <iostream>
#include <vector>
using namespace std;
 
// Data structure for Min Heap
class PriorityQueue
{
    // array to store heap elements
    int *A;
 
    // stores current size of heap
    unsigned size;
 
    // return left child of A[i]
    int LEFT(int i) {
        return (2 * i + 1);
    }
 
    // return right child of A[i]
    int RIGHT(int i) {
        return (2 * i + 2);
    }
 
    // Recursive Heapify-down algorithm
    // the node at index i and its two direct children
    // violates the heap property
    void Heapify(int i)
    {
        // get left and right child of node at index i
        int left = LEFT(i);
        int right = RIGHT(i);
 
        int smallest = i;
 
        // compare A[i] with its left and right child
        // and find smallest value
        if (left < size && A[left] < A[i]) {
            smallest = left;
        }
 
        if (right < size && A[right] < A[smallest]) {
            smallest = right;
        }
 
        // swap with child having lesser value and
        // call heapify-down on the child
        if (smallest != i) {
            swap(A[i], A[smallest]);
            Heapify(smallest);
        }
    }
 
public:
 
    // Constructor (Build-Heap)
    PriorityQueue(vector<int> &arr, int n)
    {
        // allocate memory to heap and initialize it by given array
        A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = arr[i];
        }
 
        // set heap capacity equal to size of the array
        size = n;
 
        // call heapify starting from last internal node all the
        // way upto the root node
        int i = (n - 2) / 2;
        while (i >= 0) {
            Heapify(i--);
        }
    }
 
    // Destructor
    ~PriorityQueue()
    {
        // free memory used by heap nodes
        delete[] A;
    }
 
    // function to check if heap is empty or not
    int empty()
    {
        return size == 0;
    }
 
    // function to remove element with highest priority (present at root)
    int pop()
    {
        // if heap has no elements
        if (size <= 0) {
            return -1;
        }
 
        int top = A[0];
 
        // replace the root of the heap with the last element
        // of the array
        A[0] = A[size-1];
 
        // decrease heap size by 1
        size--;
 
        // call heapify-down on root node
        Heapify(0);
 
        return top;
    }
};
 
// Function to perform heapsort on array A of size n
void HeapSort(vector<int> &A, int n)
{
    // build a priority queue and initialize it by given array
    PriorityQueue pq(A, n);
 
    int i = 0;
 
    // pop repeatedly from the heap till it becomes empty
    while(!pq.empty()) {
        A[i++] = pq.pop();
    }
}
 
// Heap Sort algorithm implementation in C++
int main()
{
    vector<int> A = { 6, 4, 7, 1, 9, -2 };
    int n = A.size();
 
    // perform heapsort on the array
    HeapSort(A, n);
 
    // print the sorted array
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
 
    return 0;
}
