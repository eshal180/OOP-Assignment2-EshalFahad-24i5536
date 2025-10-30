#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int id;
    string title;
	string author;
    Node* next;
    Node* prev;

    Node(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        next = NULL;
        prev = NULL;
    }
};

class Library {
public:
    Node* head;
    Node* tail;

    Library() {
        head = tail = NULL;
    }

    
    void addBook(int id, string title, string author) {
        Node* n = new Node(id, title, author);
        if (head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        cout <<"Book added"<<endl;
    }

    
    void deleteBook(int id) {
        Node* temp = head;
        while (temp != NULL && temp->id != id)
            temp = temp->next;

        if (temp == NULL) {
            cout <<"Book not found"<<endl;
            return;
        }

        if (temp == head) head = head->next;
        if (temp == tail) tail = tail->prev;
        if (temp->prev != NULL) temp->prev->next = temp->next;
        if (temp->next != NULL) temp->next->prev = temp->prev;

        delete temp;
        cout << "Book deleted"<<endl;
    }

    
    void showForward() {
        Node* temp = head;
        cout << "Books (Forward)"<<endl;
        while (temp != NULL) {
            cout << temp->id << " | " << temp->title << " | " << temp->author << endl;
            temp = temp->next;
        }
    }

    
    void showBackward() {
        Node* temp = tail;
        cout << "Books (Backward)"<<endl;
        while (temp != NULL) {
            cout << temp->id << " | " << temp->title << " | " << temp->author << endl;
            temp = temp->prev;
        }
    }
};


int main() {
    Library lib;

    lib.addBook(1, "Harry Potter", "ali");
    lib.addBook(2, "The Hobbit", "asim");
    lib.addBook(3, "1984", "abdullah");

    lib.showForward();    
    lib.showBackward();   
    lib.deleteBook(2);    
    lib.showForward();   

    return 0;
}

