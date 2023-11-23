#include <iostream>
#include <vector>
using namespace std;
class MaxHeap {
private:
    vector<int> heap;
    void maxHeapify(int i, int heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < heapSize && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heapSize && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest, heapSize);
        }
    }
public:
    void buildMaxHeap() {
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            maxHeapify(i, heap.size());
        }
    }
    void heapSort() {
        buildMaxHeap();
        for (int i = heap.size() - 1; i > 0; i--) {
            swap(heap[0], heap[i]);
            maxHeapify(0, i);
        }
    }
    void insert(int key) {
        heap.push_back(key);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void displayHeap() {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    MaxHeap heap;
    heap.insert(25);
    heap.insert(17);
    heap.insert(36);
    heap.insert(2);
    heap.insert(8);
    heap.insert(19);
    heap.insert(1);
    heap.displayHeap();
    heap.heapSort();
    heap.displayHeap();
    return 0;
}
