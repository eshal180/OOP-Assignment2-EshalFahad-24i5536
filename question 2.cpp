#include <iostream>
#include <string>
using namespace std;


class Feature {
public:
    string Name;

    Feature(string name) : Name(name) {}   
    virtual void analyze() = 0;            
    virtual ~Feature() {}                  
};


class LandFeature : public Feature {
public:
    LandFeature(string n) : Feature(n) {}
    
    void analyze() {
        cout << "Land Feature: " << Name << " detected (could be a forest or desert)." << endl;
    }
};


class WaterFeature : public Feature {
public:
    WaterFeature(string n) : Feature(n) {}
   
    void analyze() {
        cout << "Water Feature: " << Name << " detected (could be a river or ocean)." << endl;
    }
};


struct Node {
    int FeatureID;
    Feature* feature;
    Node* next;

    Node(int fid, Feature* ftr) : FeatureID(fid), feature(ftr), next(NULL) {}
};


class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(NULL) {}

  
    void insertAtEnd(int featureID, Feature* f) {
        Node* newNode = new Node(featureID, f);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

  
    void deleteByID(int featureID) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->FeatureID == featureID) {
            Node* temp = head;
            head = head->next;
            delete temp->feature;
            delete temp;
            cout << "Feature with ID " << featureID << " deleted." << endl;
            return;
        }
        Node* current = head;
        Node* prev = NULL;
        while (current && current->FeatureID != featureID) {
            prev = current;
            current = current->next;
        }
        if (!current) {
            cout << "Feature ID not found." << endl;
            return;
        }
        prev->next = current->next;
        delete current->feature;
        delete current;
        cout << "Feature with ID " << featureID << " deleted." << endl;
    }


    void displayAll() {
        if (!head) {
            cout << "No features to display." << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << "[ID: " << temp->FeatureID << "] ";
            temp->feature->analyze();
            temp = temp->next;
        }
    }

    
    void reverseList() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << "List reversed successfully." << endl;
    }

    
    ~SinglyLinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp->feature;
            delete temp;
        }
    }
};


int main() {
    SinglyLinkedList list;

    
    list.insertAtEnd(1, new LandFeature("Forest"));
    list.insertAtEnd(2, new WaterFeature("River"));
    list.insertAtEnd(3, new LandFeature("Desert"));
    list.insertAtEnd(4, new WaterFeature("Ocean"));

    cout << "All Features"<<endl;
    list.displayAll();

    cout << "Deleting Feature with ID 2"<<endl;
    list.deleteByID(2);
    cout << "After Deletion"<<endl;
    list.displayAll();

    cout <<"Reversing List"<<endl;
    list.reverseList();
    cout <<"After Reversing"<<endl;
    list.displayAll();

    return 0;
}

