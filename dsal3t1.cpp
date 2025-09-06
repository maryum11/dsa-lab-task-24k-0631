#include<iostream>
using namespace std;
class node{
public:
int value;
node* next;
node(int val) : value(val), next(nullptr) {}
};
class linkedlist{
public:
    node* head;
linkedlist(){
head=nullptr;
}
void insertatend(int val){
node* n = new node(val);
if(!head){
head=n;
return;
}
node* temp=head;
while(temp->next!=nullptr){
temp=temp->next;
}
temp->next=n;
}
void insertathead(int val){
node* n=new node(val);
if(!head){
head=n;
return;
}
n->next=head;
head=n;
}
void insertatindex(int val, int pos) {
        node* n = new node(val);
        if (pos == 1) {
            n->next = head;
            head = n;
            return;
        }
        node* temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of range!" << endl;
            delete n;
            return;
        }
        n->next = temp->next;
        temp->next = n;
    }
    void deletenodes(int val){
        if(!head){
            cout<<"list is empty"<<endl;
            return;
        }
        while (head != nullptr && head->value == val) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
        node* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->value == val) {
                node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
    }
    void print() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
int arr[5]={3,1,5,2,8};
for(int i=0;i<5;i++){
cout<<arr[i]<<" ";
}
    linkedlist ll;
    for (int i = 0; i < 5; i++) {
        ll.insertatend(arr[i]);
    }
    ll.insertatend(9);
    ll.insertatindex(11, 3);
    ll.insertathead(4);
    ll.deletenodes(1);
    ll.deletenodes(2);
    ll.deletenodes(5);
    cout << "Final linked list: ";
    ll.print();
    return 0;
}
