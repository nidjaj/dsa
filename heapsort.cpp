#include <iostream>
#include <vector>
using namespace std;
class PriorityQueue
{
    int *A;
    unsigned size;
    int LEFT(int i) {
        return (2 * i + 1);
    }
    int RIGHT(int i) {
        return (2 * i + 2);
    }
    void Heapify(int i)
    {
        int left = LEFT(i);
        int right = RIGHT(i);
 
        int smallest = i;
        if (left < size && A[left] < A[i]) {
            smallest = left;
        }
 
        if (right < size && A[right] < A[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(A[i], A[smallest]);
            Heapify(smallest);
        }
    }
 
public:

    PriorityQueue(vector<int> &arr, int n)
    {
        A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = arr[i];
        }
        size = n;
        int i = (n - 2) / 2;
        while (i >= 0) {
            Heapify(i--);
        }
    }
    ~PriorityQueue()
    {
        delete[] A;
    }
    int empty()
    {
        return size == 0;
    }

    int pop()
    {
    
        if (size <= 0) {
            return -1;
        }
 
        int top = A[0];
        A[0] = A[size-1];
        size--;
        Heapify(0);
 
        return top;
    }
};
 
void HeapSort(vector<int> &A, int n)
{

    PriorityQueue pq(A, n);
 
    int i = 0;
    while(!pq.empty()) {
        A[i++] = pq.pop();
    }
}
int main()
{
    vector<int> A = { 6, 4, 7, 1, 9, -2 };
    int n = A.size();
    HeapSort(A, n);
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
 
    return 0;
}
