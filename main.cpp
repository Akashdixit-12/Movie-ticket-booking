// Movie Ticket Booking Queue System in C++
#include <iostream>
#include <string>
#define MAX 10

using namespace std;

struct Customer {
    string name;
    int seatNumber;
};

class TicketQueue {
private:
    Customer queue[MAX];
    int front, rear;
    int seatCounter;

public:
    TicketQueue() {
        front = rear = -1;
        seatCounter = 1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void bookTicket(string customerName) {
        if (isFull()) {
            cout << "\nQueue is full! No more bookings allowed.\n";
            return;
        }

        if (isEmpty()) front = 0;
        rear++;
        queue[rear].name = customerName;
        queue[rear].seatNumber = seatCounter++;

        cout << "\nBooking successful for " << customerName << " | Seat No: " << queue[rear].seatNumber << endl;
    }

    void issueTicket() {
        if (isEmpty()) {
            cout << "\nNo bookings found.\n";
            return;
        }

        cout << "\nTicket issued to: " << queue[front].name << " | Seat No: " << queue[front].seatNumber << endl;
        front++;
    }

    void showQueue() {
        if (isEmpty()) {
            cout << "\nBooking queue is empty.\n";
            return;
        }

        cout << "\n--- Current Booking Queue ---\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << queue[i].name << " | Seat No: " << queue[i].seatNumber << endl;
        }
    }
};

int main() {
    TicketQueue tq;
    int choice;
    string name;

    do {
        cout << "\n\n===== Movie Ticket Booking System =====\n";
        cout << "1. Book Ticket\n";
        cout << "2. Issue Ticket\n";
        cout << "3. Show Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> ws;
                getline(cin, name);
                tq.bookTicket(name);
                break;
            case 2:
                tq.issueTicket();
                break;
            case 3:
                tq.showQueue();
                break;
            case 4:
                cout << "\nExiting system. Thank you!\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
