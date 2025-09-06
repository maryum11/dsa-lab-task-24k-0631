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
        void insert(int val) {
        node* n = new node(val);
        if (!head) {
            head = n;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = n;
    }
    void deletenode(int val){
        if (head == nullptr){ return;}
        if (head->value == val) {
        node* todelete = head;
        head = head->next;
        delete todelete;
        return;
        }
        node* temp=head;
        while(temp->next!=nullptr&&temp->next->value!=val){
        temp=temp->next;
        }
        if (temp->next== nullptr) return;
        node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
    }
    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    linkedlist l;
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);
    cout << "Before deletion: ";
    l.display();
    int n;
    cout<<"enter node to delete: ";
    cin>>n;
    l.deletenode(n);
    cout << "After deletion: ";
    l.display();

    return 0;
}