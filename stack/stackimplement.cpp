#include <iostream>
using namespace std;

class Stack {
private:
    int size;
    int* arr;
    int top;

public:
    // Constructor
    Stack(int s) {
        size = s;
        arr = new int[s];
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push element
    void pushElement(int data) {
        if (size - top > 1) {
            top++;
            arr[top] = data;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    // Pop element
    void popElement() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    // Get top element
    int topElement() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s(5);
    s.pushElement(1);
    s.pushElement(2);
    s.pushElement(3);
    s.pushElement(4);
    s.pushElement(5);

    cout << "Top element: " << s.topElement() << endl;

    return 0;
}
