#include <iostream> 
using namespace std; 
struct Node { 
    int data;      // Value stored in node 
    Node* next;    // Pointer to next node 
}; 
// Insert at end
void insertEnd(Node*& head, int value) {
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
// Display the list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void deleteByValue(Node*& head, int value) {
    if (!head) return;
     // If head is the node to delete
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
     Node* curr = head;
    while (curr->next != nullptr && curr->next->data != value) {
        curr = curr->next;
    }
     if (curr->next != nullptr) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
}

void deleteByPosition(Node*& head, int pos) {
    if (!head || pos <= 0) return;
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
     Node* curr = head;
    for (int i = 1; curr != nullptr && i < pos - 1; i++) {
        curr = curr->next;
    }
     if (curr == nullptr || curr->next == nullptr) return;
     Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
}
int main() {
    Node* head = nullptr;
     // Create list: 10 -> 20 -> 30 -> 40 -> 50
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);
    cout << "Original List: ";
    display(head);
    deleteByValue(head, 30);
    cout << "After deleting value 30: ";
    display(head);
    deleteByPosition(head, 2);
    cout << "After deleting position 2: ";
    display(head);
    return 0;
}
