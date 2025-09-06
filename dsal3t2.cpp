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
    if (!head) {
    head = n;
        return;
    }
    node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=n;
}
 void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
void rotate(int k){
    if(!head||k==0)
        return;
    node* temp=head;
    int length=1;
    while(temp->next!=nullptr){
        temp=temp->next;
        length++;
    }
    node* last=temp;
    if (k >= length) {
        cout << "Invalid rotation: k >= length" << endl;
        return;
    }
    node* newtail=head;
    for(int i=1;i<k;i++){
        newtail=newtail->next;
    }
    node* newhead=newtail->next;
    newtail->next=nullptr;
    last->next=head;
    head=newhead;
}
};
int main(){
linkedlist list;
    list.insert(5);
    list.insert(3);
    list.insert(1);
    list.insert(8);
    list.insert(6);
    list.insert(4);
    list.insert(2);
    cout << "Original list: ";
    list.display();
    int k;
    cout << "Enter the number of elements to move: ";
    cin >> k;
    list.rotate(k);
    cout << "After rotation: ";
    list.display();
    return 0;
}