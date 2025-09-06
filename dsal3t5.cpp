#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    string value;
    node* next;
    node(string val):value(val),next(nullptr){}

};
class linkedlist{
    public:
    node* head;
    linkedlist(){
    head=nullptr;
    }
    void insert(string val){
        node* n=new node(val);
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
    bool ispalindrome(){
        vector<string> arr;
        node* temp=head;
        while(temp!=nullptr){
            arr.push_back(temp->value);
            temp=temp->next;
        }
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            if(arr[i]!=arr[j])return false;
            i++;
            j--;
        }
        return true;
    }

};
int main(){
    linkedlist l;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " characters:\n";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        l.insert(s);
    }
    if (l.ispalindrome())
        cout << "The linked list is a palindrome.\n";
    else
        cout << "The linked list is NOT a palindrome.\n";
    return 0;
}