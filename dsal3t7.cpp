// Create a circular link list and perform the mentioned tasks.
// a. Insert a new node at the end of the list.
// b. Insert a new node at the beginning of list.
// c. Insert a new node at given position.
// d. Delete any node.
// e. Print the complete circular link list.
#include<iostream>
using namespace std;
class node{
    public:
    int value;
    node* next;
    node(int val):value(val),next(nullptr){}
};
class linkedlist{
    public:
    node* head;
    linkedlist(){
        head=nullptr;
    }
    void insertattail(int val){
    node* n=new node(val);
    if(head==nullptr){
        head=n;
        head->next=head;
        return;
    }
    node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;

    }
    void insertathead(int val){
        node* n=new node(val);
        if(!head){
            head=n;
            head->next=head;
            return;
        }
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        n->next=head;
        temp->next=n;
        head=n;
    }
    void insertatpos(int pos,int val){
        if(pos<1){
            insertathead(val);
        }
        node* n=new node(val);
        node* temp=head;
        int count=1;
        while(count<pos-1&&temp->next!=head){
            temp=temp->next;
            count++;
        }
        n->next=temp->next;
        temp->next=n;
    }
    void deletenode(int val){ if (head == nullptr) return;
        node* curr = head;
        node* prev = nullptr;
        if (head->value == val && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        do {
            if (curr->value == val) break;
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        if (curr->value != val) {
            cout << "Value not found!" << endl;
            return;
        }
        if (curr == head) {
            node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            head = head->next;
            delete curr;
        } else {
            prev->next = curr->next;
            delete curr;
        }
    }
        void printList() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        node* temp = head;
        do {
            cout << temp->value << " ";
            temp = temp->next;
        } while (temp != head);
        cout<<endl;
    } 
};
int main(){
    linkedlist cll;
    cll.insertattail(10);
    cll.insertattail(20);
    cll.insertattail(30);
    cout << "After inserting at end: ";
    cll.printList();
    cll.insertathead(5);
    cout << "After inserting at beginning: ";
    cll.printList();
    cll.insertatpos(3, 15);
    cout << "After inserting 15 at position 3: ";
    cll.printList();
    cll.deletenode(20);
    cout << "After deleting 20: ";
    cll.printList();
    cout << "Final Circular Linked List: ";
    cll.printList();
}