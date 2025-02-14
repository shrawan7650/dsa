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

// Insert at Head
void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

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

// Insert at Any Position
void insertAtAnyPosition(Node* &head, int data, int position) {
    Node* newNode = new Node(data);

    if (position == 0) { // Insert at head
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int curr = 0;

    while (temp != NULL && curr < position - 1) {
        temp = temp->next;
        curr++;
    }

    if (temp == NULL) { // If position is out of bounds
        cout << "Position out of bounds!" << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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

// Delete Head Node
void deleteHead(Node* &head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete Node at a Given Position
void deleteAtPosition(Node* &head, int position) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (position == 0) { // Delete head
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
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Delete Tail Node
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

    delete temp->next;
    temp->next = NULL;
}

// Main Function
int main() {
    Node* head = NULL;
   insertAtHead(head, 5);
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

    insertAtAnyPosition(head, 25, 1);
    cout << "After inserting 25 at position 1: ";
    print(head);

    deleteAtPosition(head, 1);
    cout << "After deleting node at position 1: ";
    print(head);

    return 0;
}
