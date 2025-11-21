#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
struct Stack {
    Node* top;
};
void initStack(Stack &s) {
    s.top = nullptr;
}
 void push(Stack &s, int value) {
    Node* newNode = new Node;   // dynamic memory allocation
    newNode->data = value;
    newNode->next = s.top;
    s.top = newNode;
    cout << value << " pushed into stack.\n";
}
int pop(Stack &s) {
    if (s.top == nullptr) {
        cout << "Stack Underflow!\n";
        return -1;
    }
    Node* temp = s.top;
    int value = temp->data;
    s.top = s.top->next;
    delete temp;   // free memory
    return value;
}
int peek(Stack &s) {
    if (s.top == nullptr) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return s.top->data;
}
void display(Stack &s) {
    if (s.top == nullptr) {
        cout << "Stack is empty!\n";
        return;
    }
    cout << "Stack (top to bottom): ";
    Node* temp = s.top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
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
 

