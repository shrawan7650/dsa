#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at tail
void insertAtTail(Node* &head, int data) {
    Node* newNode = new Node(data);

    if (head == NULL) { // If list is empty, new node becomes head
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // Move to the last node
    }
    
    temp->next = newNode; // Attach the new node at the end
}

// Print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Delete the head node
void deleteHead(Node* &head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next; // Move head to the next node
    delete temp; // Free memory
}

// Delete a node at a specific position
void deleteAtPosition(Node* &head, int position) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (position == 0) { // If deleting the head
        deleteHead(head);
        return;
    }

    Node* temp = head;
    int curr = 0;

    while (temp->next != NULL && curr < position - 1) {
        temp = temp->next;
        curr++;
    }

    if (temp->next == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next; // Skip the target node
    delete nodeToDelete; // Free memory
}

// Delete the tail node
void deleteTail(Node* &head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == NULL) { // If only one node is present
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next; // Free last node
    temp->next = NULL; // Set second last node's next to NULL
}

int main() {
    Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    cout << "Original List: ";
    print(head);

    deleteHead(head);
    cout << "After deleting head: ";
    print(head);

    deleteTail(head);
    cout << "After deleting tail: ";
    print(head);

    deleteAtPosition(head, 1);
    cout << "After deleting node at position 1: ";
    print(head);

    return 0;
}
