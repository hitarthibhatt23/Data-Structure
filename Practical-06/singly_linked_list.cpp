#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertBeginning(int value) {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = head;
        head = newNode;

        cout << value << " inserted at beginning." << endl;
    }

    // Insert at end
    void insertEnd(int value) {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << value << " inserted at end." << endl;
    }

    // Insert after a given node
    void insertAfter(int key, int value) {
        Node* temp = head;

        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node not found!" << endl;
            return;
        }

        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;

        cout << value << " inserted after " << key << "." << endl;
    }

    // Delete first node
    void deleteFirst() {
        if (head == nullptr) {
            cout << "Linked list is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << temp->data << " deleted from beginning." << endl;

        head = head->next;
        delete temp;
    }

    // Delete last node
    void deleteLast() {
        if (head == nullptr) {
            cout << "Linked list is empty!" << endl;
            return;
        }

        if (head->next == nullptr) {
            cout << head->data << " deleted from end." << endl;
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;

        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        cout << temp->next->data << " deleted from end." << endl;

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete node after a given node
    void deleteAfter(int key) {
        Node* temp = head;

        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Node or next node not found!" << endl;
            return;
        }

        Node* deleteNode = temp->next;

        cout << deleteNode->data
             << " deleted after " << key << "." << endl;

        temp->next = deleteNode->next;
        delete deleteNode;
    }

    // Display all nodes
    void display() {
        if (head == nullptr) {
            cout << "Linked list is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Linked List: ";

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;

    int choice;
    int value;
    int key;

    do {
        cout << "\n--- Singly Linked List ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Delete First Node\n";
        cout << "5. Delete Last Node\n";
        cout << "6. Delete Node After a Given Node\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                break;

            case 3:
                cout << "Enter node value after which to insert: ";
                cin >> key;

                cout << "Enter value to insert: ";
                cin >> value;

                list.insertAfter(key, value);
                break;

            case 4:
                list.deleteFirst();
                break;

            case 5:
                list.deleteLast();
                break;

            case 6:
                cout << "Enter node value after which to delete: ";
                cin >> key;

                list.deleteAfter(key);
                break;

            case 7:
                list.display();
                break;

            case 8:
                cout << "Program terminated." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}
