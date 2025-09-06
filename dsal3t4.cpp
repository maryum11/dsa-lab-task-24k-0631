// Solve the following problem using a Singly Linked List.
// Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear
// before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.
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
    void insert(int val){
    node* n = new node(val);
    if(!head){
    head=n;
        return;
    }    
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = n;
    }
    void display() {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

    void modify(){
    node* eventail=nullptr;
    node* oddtail=nullptr;
    node* evenhead=nullptr;
    node* oddhead=nullptr;
    node* temp=head;
    while(temp!=nullptr){
        if(temp->value%2==0){
        if (evenhead==nullptr) {
            evenhead = temp;
            eventail=temp;
        }else{
            eventail->next=temp;
            eventail=temp;
        }
        } else {
        if (oddhead==nullptr) {
            oddhead=temp;
            oddtail=temp;
        } else{
            oddtail->next=temp;
            oddtail=temp;
        }
    }
        temp=temp->next;
    }
    if (evenhead==nullptr) {
        head=oddhead;
    } else if (oddhead==nullptr) {
        head=evenhead;
    } else {
    eventail->next=oddhead;
    oddtail->next=nullptr;
    head=evenhead;
}
}

};
int main() {
    linkedlist list;

    // Insert values
    list.insert(17);
    list.insert(15);
    list.insert(8);
    list.insert(12);
    list.insert(10);
    list.insert(5);
    list.insert(4);
    list.insert(1);
    list.insert(7);
    list.insert(6);

    cout << "Original list: ";
    list.display();

    list.modify();

    cout << "Modified list: ";
    list.display();

    return 0;
}
