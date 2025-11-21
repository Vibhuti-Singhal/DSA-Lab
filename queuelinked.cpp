#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
struct Queue {
    Node* front;
    Node* rear;
};
void initQueue(Queue &q) {
    q.front = q.rear = nullptr;
}
void enqueue(Queue &q, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (q.rear == nullptr) {
        q.front = q.rear = newNode;
        return;
    }
    q.rear->next = newNode;
    q.rear = newNode;
}
int dequeue(Queue &q) {
    if (q.front == nullptr) {
        cout << "Queue is empty!\n";
        return -1;
    }
    Node* temp = q.front;
    int value = temp->data;
    q.front = q.front->next;
        if (q.front == nullptr) // If queue becomes empty
        q.rear = nullptr;
    delete temp;
    return value;
}
void display(Queue &q) {
    if (q.front == nullptr) {
        cout << "Queue is empty!\n";
        return;
    }
    Node* temp = q.front;
    cout << "Queue: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
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
    cout << "Dequeued: " << dequeue(q) << endl;
    cout << "After dequeue: ";
    display(q);
    enqueue(q, 40);
    cout << "After enqueue 40: ";
    display(q);
    cout << "Dequeued: " << dequeue(q) << endl;
    cout << "Final queue: ";
    display(q);
    return 0;
}
