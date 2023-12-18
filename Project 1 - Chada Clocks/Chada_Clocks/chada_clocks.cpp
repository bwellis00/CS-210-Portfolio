// CS 210
// 11-19-23
// Brandon Ellis

#include <iostream>
#include <iomanip>
using namespace std;

// Function to display the menu options
void displayMenu() {
    cout << "***********************\n";
    cout << "* 1 - Add One Hour    *\n";
    cout << "\n* 2 - Add One Minute  *\n";
    cout << "\n* 3 - Add One Second  *\n";
    cout << "\n* 4 - Exit Program    *\n";
    cout << "***********************\n";
}

// Function to add hours to the time
void addHour(int& hour, bool& isPM) {
    hour = (hour + 1) % 24;
    if (hour == 0 || hour == 12) {
        isPM = !isPM; // Toggle AM/PM if hour becomes 0 or 12
    }
}

// Function to add minutes to the time
void addMinute(int& minute, int& hour, bool& isPM) {
    minute = (minute + 1) % 60;
    if (minute == 0) {
        addHour(hour, isPM); // If minute becomes 0, increment hour
    }
}

// Function to add seconds to the time
void addSecond(int& second, int& minute, int& hour, bool& isPM) {
    second = (second + 1) % 60;
    if (second == 0) {
        addMinute(minute, hour, isPM); // If second becomes 0, increment minute
    }
}

// Function to display time in both 12-hour and 24-hour formats
void displayTime(int hour, int minute, int second, bool isPM) {
    int militaryHour = hour;

    //if time is PM we want to make sure the 24 hour clock has 12 added to the hour
    if (isPM = 0) militaryHour = militaryHour + 12;

    cout << "\n*****************  *****************\n";
    cout << "* 12-Hour Clock *  * 24-Hour Clock *\n";
    cout << "* " << setfill('0') << setw(2) << hour % 12 << ":"
        << setw(2) << minute << ":" << setw(2) << second << " ";
    cout << (isPM ? "PM" : "AM") << "   * ";

    cout << " *    " << setfill('0') << setw(2) << militaryHour << ":"
        << setw(2) << minute << ":" << setw(2) << second << "   *" << endl;
    cout << "*****************  *****************\n";
}

int main() {
    int hour, minute, second; 
    bool isPM;

    cout << "Enter initial time (hour minute second): ";
    cin >> hour >> minute >> second;

    cout << "Enter AM (0) or PM (1): ";
    cin >> isPM;

    displayTime(hour, minute, second, isPM);


    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            addHour(hour, isPM);
            break;
        case 2:
            addMinute(minute, hour, isPM);
            break;
        case 3:
            addSecond(second, minute, hour, isPM);
            break;
        case 4:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Error. Please enter a valid option.\n";
            break;
        }

        displayTime(hour, minute, second, isPM);

        cout << "\n";

    }

    return 0;
}
