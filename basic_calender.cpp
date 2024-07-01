#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Structure to represent a date
struct Date {
    int day;
    int month;
    int year;
};

// Structure to represent an event
struct Event {
    string description;
    Date date;
};

// Function to display the calendar for a given month and year
void displayCalendar(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
        daysInMonth[1] = 29;

    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
    int dayOfWeek = (5 * ((year - 1) % 4) + 4) % 7;
    for (int i = 1; i < month; i++)
        dayOfWeek = (dayOfWeek + daysInMonth[i - 1] % 7) % 7;

    for (int i = 0; i < dayOfWeek; i++)
        cout << "     ";
    for (int i = 1; i <= daysInMonth[month - 1]; i++) {
        cout << " " << i << " ";
    
        if ((dayOfWeek + i - 1) % 7 == 6)
            cout << endl;
    }
    cout << endl;
}

// Function to add an event to the calendar
void addEvent(vector<Event>& events, Date date, string description) {
    Event event;
    event.date = date;
    event.description = description;
    events.push_back(event);
}

// Function to view events for a specific date
void viewEvents(const vector<Event>& events, Date date) {
    cout << "Events for " << date.day << "/" << date.month << "/" << date.year << ":" << endl;
    for (const Event& event : events) {
        if (event.date.day == date.day && event.date.month == date.month && event.date.year == date.year)
            cout << "- " << event.description << endl;
    }
}

int main() {
    vector<Event> events;
    int choice;
    Date date;
    string description;

    while (true) {
        cout << "Calendar Application" << endl;
        cout << "1. Display Calendar" << endl;
        cout << "2. Add Event" << endl;
        cout << "3. View Events" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter month (1-12): ";
                cin >> date.month;
                cout << "Enter year: ";
                cin >> date.year;
                displayCalendar(date.month, date.year);
                break;
            case 2:
                cout << "Enter day (1-31): ";
                cin >> date.day;
                cout << "Enter month (1-12): ";
                cin >> date.month;
                cout << "Enter year: ";
                cin >> date.year;
                cout << "Enter event description: ";
                cin.ignore();
                getline(cin, description);
                addEvent(events, date, description);
                break;
            case 3:
                cout << "Enter day (1-31): ";
                cin >> date.day;
                cout << "Enter month (1-12): ";
                cin >> date.month;
                cout << "Enter year: ";
                cin >> date.year;
                viewEvents(events, date);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}