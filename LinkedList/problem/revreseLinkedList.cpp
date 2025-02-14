#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at Tail
void insertAtTail(Node* &head, int data) {
    Node* newNode = new Node(data);
    
    if (head == NULL) { // If list is empty
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
}

 void reverseLinkedList(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    
    while (curr != NULL) {
        forward = curr->next;  // Store next node
        curr->next = prev;     // Reverse current node's pointer
        prev = curr;           // Move prev forward
        curr = forward;        // Move curr forward
    }
    
    head = prev;  // Update head to new first node
}


// Print Linked List
void print(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main Function
int main() {
    Node* head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    
    cout << "Original List: ";
    print(head);
    reverseLinkedList(head);
    print(head);


    return 0;
}
