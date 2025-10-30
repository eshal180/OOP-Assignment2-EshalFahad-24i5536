#include <iostream>
#include <string>
using namespace std;


class Customer {
public:
    int id;
    string name;
    int tickets;
    Customer* next;

    Customer(int i, string n, int t) {
        id = i;
        name = n;
        tickets = t;
        next = NULL;
    }
};


class Queue {
private:
    Customer* front;
    Customer* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    ~Queue() {
        while (front != NULL)
            dequeue();
    }

    void enqueue(int id, string name, int tickets) {
        Customer* newCustomer = new Customer(id, name, tickets);

        if (rear == NULL) {
            front = rear = newCustomer;
        } else {
            rear->next = newCustomer;
            rear = newCustomer;
        }
        cout << "Customer added: " << name << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }

        Customer* temp = front;
        cout << "Serving " << temp->name << " (ID: " << temp->id << ")" << endl;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "\nPeople in queue:\n";
        Customer* temp = front;
        while (temp != NULL) {
            cout << "ID: " << temp->id
                 << ", Name: " << temp->name
                 << ", Tickets: " << temp->tickets << endl;
            temp = temp->next;
        }
    }
};


int main() {
    Queue q;

    q.enqueue(1, "Ali", 2);
    q.enqueue(2, "Sara", 4);
    q.enqueue(3, "Ahmed", 1);

    cout << "After adding customers";
    q.display();

    cout << "\nNow serving one customer...\n";
    q.dequeue();

    cout << "\nQueue after serving:\n";
    q.display();

    return 0;
}

