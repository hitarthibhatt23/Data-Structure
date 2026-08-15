#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }

        cout << value << " inserted at beginning." << endl;
    }

    // Insert at end
    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }

        cout << value << " inserted at end." << endl;
    }

    // Insert after a given node
    void insertAfter(int key, int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        do {
            if (temp->data == key) {
                Node* newNode = new Node();

                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;

                cout << value << " inserted after "
                     << key << "." << endl;
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Node not found!" << endl;
    }

    // Delete first node
    void deleteFirst() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == head) {
            cout << head->data << " deleted." << endl;
            delete head;
            head = nullptr;
            return;
        }

        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        Node* temp = head;

        head = head->next;
        last->next = head;

        cout << temp->data << " deleted from beginning." << endl;

        delete temp;
    }

    // Delete last node
    void deleteLast() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == head) {
            cout << head->data << " deleted." << endl;
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;

        while (temp->next->next != head) {
            temp = temp->next;
        }

        Node* deleteNode = temp->next;

        temp->next = head;

        cout << deleteNode->data
             << " deleted from end." << endl;

        delete deleteNode;
    }

    // Delete node after a given node
    void deleteAfter(int key) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        do {
            if (temp->data == key) {

                Node* deleteNode = temp->next;

                // Only one node exists
                if (deleteNode == head && head->next == head) {
                    cout << deleteNode->data << " deleted." << endl;

                    delete deleteNode;
                    head = nullptr;
                    return;
                }

                // If deleting head
                if (deleteNode == head) {
                    Node* last = head;

                    while (last->next != head) {
                        last = last->next;
                    }

                    head = head->next;
                    last->next = head;
                } else {
                    temp->next = deleteNode->next;
                }

                cout << deleteNode->data
                     << " deleted after " << key << "." << endl;

                delete deleteNode;
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Node not found!" << endl;
    }

    // Display all nodes
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Circular Linked List: ";

        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "HEAD" << endl;
    }
};

int main() {
    CircularLinkedList list;

    int choice;
    int value;
    int key;

    do {
        cout << "\n--- Singly Circular Linked List ---\n";
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
