#include <iostream>
using namespace std;

#define MAX 100   // Maximum size of queue
 // Queue structure
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};
void initQueue(Queue &q) {
    q.front = -1;
    q.rear = -1;
}
bool isEmpty(Queue &q) {
    return q.front == -1;
}
bool isFull(Queue &q) {
    return q.rear == MAX - 1;
}
void enqueue(Queue &q, int value) {
    if (isFull(q)) {
        cout << "Queue Overflow! Cannot insert " << value << endl;
        return;
    }
    if (q.front == -1)  // First insertion
        q.front = 0;
    q.arr[++q.rear] = value;
}
int dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue Underflow! Cannot dequeue.\n";
        return -1;
    }
    int value = q.arr[q.front];
    if (q.front == q.rear) {
                q.front = q.rear = -1; // Queue becomes empty
    } 
    else {
        q.front++;
    }
     return value;
}
int peek(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue is empty!\n";
        return -1;
    }
    return q.arr[q.front];
}
void display(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue: ";
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.arr[i] << " ";
    }
    cout << endl;
}
int main() {
    Queue q;
    initQueue(q);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    cout << "After enqueue operations: ";
    display(q);
    cout << "Peek: " << peek(q) << endl;
    cout << "After dequeue: ";
    display(q);
    enqueue(q, 40);
    cout << "After enqueue 40: ";
    display(q);
    cout << "Peek: " << peek(q) << endl;
    return 0;
}


