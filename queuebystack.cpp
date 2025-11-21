#include <iostream>
using namespace std;
#define MAX 100
struct Stack {
    int arr[MAX];
    int top;
};
void initStack(Stack &s) {// Initialize stack 
    s.top = -1;
}
bool isEmpty(Stack &s) {
    return s.top == -1;
}
void push(Stack &s, int value) {
    if (s.top == MAX - 1) {
        cout << "Stack Overflow!\n";
        return;
    }
    s.arr[++s.top] = value;
}
int pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow!\n";
        return -1;
    }
    return s.arr[s.top--];
}
// -------------------- QUEUE USING TWO STACKS --------------------
struct Queue {
    Stack s1, s2;
};
void enqueue(Queue &q, int value) {
    push(q.s1, value);
}
int dequeue(Queue &q) {
    if (isEmpty(q.s1) && isEmpty(q.s2)) {
        cout << "Queue is empty!\n";
        return -1;
    }
    if (isEmpty(q.s2)) {
        while (!isEmpty(q.s1)) {
            push(q.s2, pop(q.s1));
        }
    }
    return pop(q.s2);
}
void display(Queue &q) {
    if (isEmpty(q.s1) && isEmpty(q.s2)) {
        cout << "Queue is empty!\n";
        return;
    }
     cout << "Queue: ";
     for (int i = q.s2.top; i >= 0; i--) {
        cout << q.s2.arr[i] << " ";
    }
     for (int i = 0; i <= q.s1.top; i++) {
        cout << q.s1.arr[i] << " ";
    }
     cout << endl;
}
int main() {
    Queue q;
    initStack(q.s1);
    initStack(q.s2);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    cout << "After enqueue operations: ";
    display(q);
    cout << "Dequeued: " << dequeue(q) << endl;
    cout << "After one dequeue: ";
    display(q);
    enqueue(q, 40);
    cout << "After enqueue 40: ";
    display(q);
    cout << "Dequeued: " << dequeue(q) << endl;
    cout << "Final queue: ";
    display(q);
     return 0;
}


