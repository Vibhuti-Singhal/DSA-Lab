#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void insertAtBeginning(Node*& head, int value) {// Insert at beginning
    Node* newNode = new Node{value, head};
    head = newNode;
}
void insertAtEnd(Node*& head, int value){// Insert at end 
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtPosition(Node*& head, int value, int pos) {// Insert in middle (after given position) 
    if (pos <= 0 || head == nullptr) return;
    Node* newNode = new Node{value, nullptr};
    Node* temp = head;
    for (int i = 1; i < pos && temp->next != nullptr; i++) {
        temp = temp->next;
    }
     newNode->next = temp->next;
    temp->next = newNode;
}
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
 int main() {
    Node* head = nullptr;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    cout << "Initial List: ";
    display(head);
    insertAtBeginning(head, 5);
    cout << "After insertion at beginning (5): ";
    display(head);
    insertAtEnd(head, 40);
    cout << "After insertion at end (40): ";
    display(head);
    insertAtPosition(head, 15, 2);
    cout << "After inserting 15 after position 2: ";
    display(head);
    return 0;
}


