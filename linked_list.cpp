#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {

    // Create 3 nodes
    Node* first = new Node;
    Node* second = new Node;
    Node* third = new Node;

    // Put data in nodes
    first->data = 10;
    second->data = 20;
    third->data = 30;

    // Connect the nodes
    first->next = second;
    second->next = third;
    third->next = nullptr;

    // Print the linked list
    Node* temp = first;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL";

    return 0;
}
