#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Passenger {
    int id;
    string name;
};

class RailwayReservation {
private:
    queue<Passenger> confirmed;
    queue<Passenger> waitingList;

    int totalSeats;
    int nextId;

public:
    RailwayReservation(int seats) {
        totalSeats = seats;
        nextId = 1;
    }

    // Book a ticket
    void bookTicket(string name) {
        Passenger p;
        p.id = nextId++;
        p.name = name;

        if ((int)confirmed.size() < totalSeats) {
            confirmed.push(p);

            cout << "\nTicket Confirmed!"
                 << "\nPassenger ID: " << p.id
                 << "\nName: " << p.name << endl;
        } else {
            waitingList.push(p);

            cout << "\nAdded to Waiting List!"
                 << "\nPassenger ID: " << p.id
                 << "\nName: " << p.name
                 << "\nWaiting Position: "
                 << waitingList.size() << endl;
        }
    }

    // Cancel a confirmed ticket
    void cancelTicket(int id) {
        queue<Passenger> temp;
        bool found = false;

        while (!confirmed.empty()) {
            Passenger p = confirmed.front();
            confirmed.pop();

            if (p.id == id && !found) {
                found = true;
                cout << "\nTicket cancelled for "
                     << p.name << endl;
            } else {
                temp.push(p);
            }
        }

        confirmed = temp;

        if (!found) {
            cout << "\nConfirmed ticket ID not found."
                 << endl;
            return;
        }

        // Promote the first waiting passenger
        if (!waitingList.empty()) {
            Passenger p = waitingList.front();
            waitingList.pop();
            confirmed.push(p);

            cout << "Waiting passenger promoted!"
                 << "\nPassenger ID: " << p.id
                 << "\nName: " << p.name << endl;
        }
    }

    // Display confirmed passengers
    void displayConfirmed() {
        queue<Passenger> temp = confirmed;

        cout << "\n--- Confirmed Passengers ---\n";

        if (temp.empty()) {
            cout << "No confirmed passengers.\n";
        }

        while (!temp.empty()) {
            Passenger p = temp.front();
            temp.pop();

            cout << "ID: " << p.id
                 << " | Name: " << p.name << endl;
        }
    }

    // Display waiting list
    void displayWaiting() {
        queue<Passenger> temp = waitingList;

        cout << "\n--- Waiting List ---\n";

        if (temp.empty()) {
            cout << "Waiting list is empty.\n";
        }

        int position = 1;

        while (!temp.empty()) {
            Passenger p = temp.front();
            temp.pop();

            cout << "Position: " << position++
                 << " | ID: " << p.id
                 << " | Name: " << p.name << endl;
        }
    }
};

int main() {
    int seats;

    cout << "Enter total number of seats: ";
    cin >> seats;

    if (seats <= 0) {
        cout << "Number of seats must be positive.\n";
        return 0;
    }

    RailwayReservation railway(seats);

    int choice;
    string name;
    int id;

    do {
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. Display Confirmed Passengers\n";
        cout << "4. Display Waiting List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter passenger name: ";
                cin >> ws;
                getline(cin, name);
                railway.bookTicket(name);
                break;

            case 2:
                cout << "Enter passenger ID to cancel: ";
                cin >> id;
                railway.cancelTicket(id);
                break;

            case 3:
                railway.displayConfirmed();
                break;

            case 4:
                railway.displayWaiting();
                break;

            case 5:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
