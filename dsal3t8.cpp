// Task#8:
// Give an efficient algorithm for concatenating two doubly linked lists L and M, with head and tail preserved
// nodes, into a single list that contains all the nodes of L followed by all the nodes of M.

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void concatenate(DoublyLinkedList &M) {
        if (head == nullptr) {
            head = M.head;
            tail = M.tail;
            return;
        }
        if (M.head == nullptr) {
            return;
        }
        tail->next = M.head;
        M.head->prev = tail;
        tail = M.tail;
    }
};
int main() {
    DoublyLinkedList L, M;
    L.insertAtEnd(1);
    L.insertAtEnd(2);
    L.insertAtEnd(3);
    cout << "List L: ";
    L.display();
    M.insertAtEnd(4);
    M.insertAtEnd(5);
    M.insertAtEnd(6);
    cout << "List M: ";
    M.display();
    L.concatenate(M);
    cout << "After Concatenation (L + M): ";
    L.display();
    return 0;
}
