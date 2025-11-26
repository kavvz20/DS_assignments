#include <iostream>
using namespace std;

class PriorityQueue {
    int a[100], n;
public:
    PriorityQueue() { n = 0; }

    void insert(int x) {
        int i = n++;
        a[i] = x;
        while (i > 0 && a[(i-1)/2] < a[i]) {
            swap(a[i], a[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    int removeMax() {
        int max = a[0];
        a[0] = a[--n];
        heapify(0);
        return max;
    }

    void heapify(int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && a[left] > a[largest]) largest = left;
        if (right < n && a[right] > a[largest]) largest = right;

        if (largest != i) {
            swap(a[i], a[largest]);
            heapify(largest);
        }
    }

    bool isEmpty() { return n == 0; }

    void display() {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(30);
    pq.insert(10);
    pq.insert(50);
    pq.insert(40);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Removed Max: " << pq.removeMax() << endl;

    cout << "After delete: ";
    pq.display();
}
