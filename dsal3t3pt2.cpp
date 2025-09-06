#include<iostream>
using namespace std;
class Passenger {
public:
    string name;
    Passenger *next;
    Passenger(string n): name(n), next(nullptr) {}
};
class Flight {
public:
    string flightNo;
    Passenger *head;
    Flight *next;

    Flight(string no): flightNo(no), head(nullptr), next(nullptr) {}

    void reserve(string name) {
        Passenger *p = new Passenger(name);
        if (!head || name < head->name) {
            p->next = head;
            head = p;
            cout << name << " reserved on flight " << flightNo << endl;
            return;
        }
        Passenger *temp = head;
        while (temp->next && temp->next->name < name) {
            temp = temp->next;
        }
        if (temp->next && temp->next->name == name) {
            cout << name << " already reserved on flight " << flightNo << endl;
            delete p;
            return;
        }
        p->next = temp->next;
        temp->next = p;
        cout << name << " reserved successfully on flight " << flightNo << endl;
    }

    void cancel(string name) {
        if (!head) {
            cout << "No reservation yet.\n";
            return;
        }
        if (head->name == name) {
            Passenger *del = head;
            head = head->next;
            delete del;
            cout << name << " reservation cancelled on flight " << flightNo << endl;
            return;
        }
        Passenger *temp = head;
        while (temp->next && temp->next->name != name) {
            temp = temp->next;
        }
        if (!temp->next) {
            cout << "Reservation does not exist.\n";
            return;
        }
        Passenger *del = temp->next;
        temp->next = temp->next->next;
        delete del;
        cout << name << " reservation cancelled on flight " << flightNo << endl;
    }

    void check(string name) {
        Passenger *temp = head;
        while (temp) {
            if (temp->name == name) {
                cout << name << " has a reservation on flight " << flightNo << endl;
                return;
            }
            temp = temp->next;
        }
        cout << name << " has no reservation on flight " << flightNo << endl;
    }

    void displayPassengers() {
        if (!head) {
            cout << "No passengers reserved on flight " << flightNo << endl;
            return;
        }
        cout << "Passenger list for flight " << flightNo << ":\n";
        Passenger *temp = head;
        while (temp) {
            cout << "- " << temp->name << endl;
            temp = temp->next;
        }
    }
};

class AirlineSystem {
public:
    Flight *flights;

    AirlineSystem(): flights(nullptr) {}

    Flight* findFlight(string no) {
        Flight *temp = flights;
        while (temp) {
            if (temp->flightNo == no) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    Flight* addFlight(string no) {
        Flight *existing = findFlight(no);
        if (existing) return existing;
        Flight *f = new Flight(no);
        f->next = flights;
        flights = f;
        cout << "Flight " << no << " added.\n";
        return f;
    }

    void displayFlights() {
        if (!flights) {
            cout << "No flights available.\n";
            return;
        }
        cout << "Flights:\n";
        Flight *temp = flights;
        while (temp) {
            cout << "- " << temp->flightNo << endl;
            temp = temp->next;
        }
    }
};

int main() {
    AirlineSystem system;
    int choice;
    string flightNo, name;

    do {
        cout << "\n Airline Reservation Menu \n";
        cout << "1. Add Flight\n";
        cout << "2. Reserve a ticket\n";
        cout << "3. Cancel a reservation\n";
        cout << "4. Check reservation\n";
        cout << "5. Display passengers\n";
        cout << "6. Display flights\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter flight number: ";
            cin >> flightNo;
            system.addFlight(flightNo);
            break;
        case 2:
            cout << "Enter flight number: ";
            cin >> flightNo;
            cout << "Enter passenger name: ";
            cin >> name;
            system.addFlight(flightNo)->reserve(name);
            break;
        case 3:
            cout << "Enter flight number: ";
            cin >> flightNo;
            cout << "Enter passenger name: ";
            cin >> name;
            if (system.findFlight(flightNo)) system.findFlight(flightNo)->cancel(name);
            else cout << "Flight not found.\n";
            break;
        case 4:
            cout << "Enter flight number: ";
            cin >> flightNo;
            cout << "Enter passenger name: ";
            cin >> name;
            if (system.findFlight(flightNo)) system.findFlight(flightNo)->check(name);
            else cout << "Flight not found.\n";
            break;
        case 5:
            cout << "Enter flight number: ";
            cin >> flightNo;
            if (system.findFlight(flightNo)) system.findFlight(flightNo)->displayPassengers();
            else cout << "Flight not found.\n";
            break;
        case 6:
            system.displayFlights();
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);
    return 0;
}
