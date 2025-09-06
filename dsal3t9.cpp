#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void rearrangeAltReverse() {
        if (!head || !head->next) return;
        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;
        while (odd->next && even->next) {
            odd->next = even->next;
            odd = odd->next;
            if (odd->next) {
                even->next = odd->next;
                even = even->next;
            } else {
                even->next = nullptr;
            }
        }
        Node* prev = nullptr;
        Node* curr = evenHead;
        Node* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        odd->next = prev;
    }
};
int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(4);
    list.insertAtEnd(9);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(5);
    list.insertAtEnd(9);
    list.insertAtEnd(4);
    cout << "Original List: ";
    list.display();
    list.rearrangeAltReverse();
    cout << "Modified List: ";
    list.display();
    return 0;
}
