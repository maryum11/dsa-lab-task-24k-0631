// Task 3:
// write a simple airline ticket reservation program. The program should display a menu with the following options:
// reserve a ticket, cancel a reservation, check whether a ticket is reserved for particular person, and display the
// passengers. the information is maintained on a alphabetized linked list of names. in simple version of the
// program, assume that tickets are reserved for only one flight. In a fuller version, place no limit on the number of
// flights. create a linked list of flights with each node including a pointer to a linked list of passengers
#include<iostream>
using namespace std;
class passenger{
    public:
    string name;
    passenger *next;
    passenger(string n):name(n),next(nullptr){}
};
class airline{
    public:
    passenger* head;
    airline(){
        head=nullptr;
    }
void reserve(string name){
passenger* p=new passenger(name);
if(!head||name<head->name){
    p->next=head;
    head=p;
    cout<<name<<" reserved"<<endl;
    return;
}
passenger* temp=head;
while(temp->next&&temp->next->name<name){
    temp=temp->next;
}
if (temp->next && temp->next->name == name) {
cout << name << " already has a reservation!\n";
delete p;
return;
}
p->next=temp->next;
temp->next=p;
cout<<name<<" reserved successfully."<<endl;
}
void cancel(string name){
    if(!head){
        cout<<"no reservation yet."<<endl;
        return;
    }
    if(head->name==name){
        passenger* del=head;
        head=head->next;
        delete del;
        cout<<"reservation cancelled."<<endl;
        return;
    }
    passenger* temp=head;
    while(temp->next&&temp->next->name!=name){
        temp=temp->next;
    }
    if(!temp->next){
        cout<<"reservation does not exist."<<endl;
        return;
    }
    passenger* del=temp->next;
    temp->next=temp->next->next;
    delete del;
    cout<<name<<" reservation cancelled."<<endl;
}
void check(string name){
    passenger* temp = head;
    while (temp) {
        if (temp->name == name) {
            cout << name << " has a reservation.\n";
            return;
        }
        temp = temp->next;
        }
     cout << name << " has no reservation.\n";
}
void displayPassengers() {
    if (!head) {
        cout << "No passengers reserved yet.\n";
        return;
    }
    cout << "Passenger List:\n";
    passenger* temp = head;
    while (temp) {
        cout << "- " << temp->name << endl;
        temp = temp->next;
    }
}
};
int main(){
airline flight;
    int choice;
    string name;

    do {
        cout << "\n Airline Reservation Menu \n";
        cout << "1. Reserve a ticket\n";
        cout << "2. Cancel a reservation\n";
        cout << "3. Check reservation\n";
        cout << "4. Display passengers\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter passenger name: ";
            cin >> name;
            flight.reserve(name);
            break;
        case 2:
            cout << "Enter passenger name: ";
            cin >> name;
            flight.cancel(name);
            break;
        case 3:
            cout << "Enter passenger name: ";
            cin >> name;
            flight.check(name);
            break;
        case 4:
            flight.displayPassengers();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
    return 0;
}