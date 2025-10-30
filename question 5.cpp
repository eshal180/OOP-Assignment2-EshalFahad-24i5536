#include <iostream>
using namespace std;

class ArrayStack {
    char* arr;
    int top;
    int capacity;
public:
    ArrayStack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }
     void push(char val) {
        if (top == capacity - 1) {
            cout << "Stack Overflow"<<endl;
            return;
        }
        arr[++top] = val;
    }
    char pop() {
        if (top == -1) {
            cout << "Stack Underflow"<<endl;
            return 0;
        }
        return arr[top--];
    }
    bool isEmpty() {
        return top == -1;
    }

    ~ArrayStack() {
        delete[] arr;
    }
};

//stack using linked list
class Node {
public:
    char data;
    Node* next;
    Node(char val) {
        data = val;
        next = NULL;
    }
};
class LinkedListStack {
    Node* top;
public:
    LinkedListStack() {
        top = NULL;
    }

    void push(char val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
char pop() {
        if (top == NULL) {
            cout << "Stack Underflow"<<endl;
            return 0;
        }
        char val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    bool isEmpty() {
        return top == NULL;
    }

    ~LinkedListStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

void ChangeLocationIterative(char* Array, int b1, int b2, int size) {
    ArrayStack stack(size);  

    
    for (int i = b1; i <= b2; i++) {
        stack.push(Array[i]);
    }

    
    for (int i = b1; i <= b2; i++) {
        Array[i] = stack.pop();
    }
}
void PrintPatternIterative(int n) {
    LinkedListStack stack;
    int temp = n;

    cout << "Pattern"<<endl;
    while (temp >= 1) {
        for (int i = 0; i < n - temp; i++)
            cout << "1 ";
        for (int j = 0; j < temp - (n - temp); j++)
            cout << temp << " ";
        cout << endl;
        temp--;
    }
}
int main() {
     char Array[8] = {'C', 'O', 'M', 'P', 'U', 'T', 'E', 'R'};
    int b1 = 2, b2 = 6;
    cout << "Original Array: ";
    for (int i = 0; i < 8; i++)
        cout << Array[i] << " ";
    cout << endl;

    ChangeLocationIterative(Array, b1, b2, 8);

    cout << "After ChangeLocationIterative: ";
    for (int i = 0; i < 8; i++)
        cout << Array[i] << " ";
    cout << endl << endl;

    // Part (b) — using linked list stack
    int n = 4;
    PrintPatternIterative(n);
    
    return 0; 
}
