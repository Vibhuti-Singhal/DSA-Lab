#include <iostream>
using namespace std;
#define MAX 100  // Maximum size of stack
struct Stack {
    int arr[MAX];
    int top;
};
void initStack(Stack &s) {
    s.top = -1;
}
bool isEmpty(Stack &s) {
    return s.top == -1;
}
bool isFull(Stack &s) {
    return s.top == MAX - 1;
}
void push(Stack &s, int value) {
    if (isFull(s)) {
        cout << "Stack Overflow! Cannot push " << value << endl;
        return;
    }
    s.arr[++s.top] = value;
    cout << value << " pushed into stack.\n";
}
int pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow! Cannot pop.\n";
        return -1;
    }
    return s.arr[s.top--];
}
int peek(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return s.arr[s.top];
}
void display(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!\n";
        return;
    }
    cout << "Stack (top to bottom): ";
    for (int i = s.top; i >= 0; i--) {
        cout << s.arr[i] << " ";
    }
    cout << endl;
}
int main() {
    Stack s;
    initStack(s);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    display(s);
    cout << "Top element: " << peek(s) << endl;
    cout << "Popped: " << pop(s) << endl;
    display(s);
    push(s, 40);
    display(s);
    cout << "Popped: " << pop(s) << endl;
    display(s);
    return 0;
}

