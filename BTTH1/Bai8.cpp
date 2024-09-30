#include <bits/stdc++.h>
using namespace std;

struct Date {
    int day, month, year;
};

struct Time {
    int hour, minute;
};

struct Flight {
    string flightCode;
    Date departureDate;
    Time departureTime;
    string origin;
    string destination;
};

// Check if a year is a leap year
// Input: An integer representing a year
// Output: Boolean value (true if leap year, false otherwise)
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Check if a date is valid
// Input: A Date object containing day, month, year
// Output: Boolean value (true if date is valid, false otherwise)
bool isValidDate(const Date& date) {
    if (date.year < 1900 || date.year > 2100) return false;
    if (date.month < 1 || date.month > 12) return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(date.year)) daysInMonth[1] = 29;
    return date.day >= 1 && date.day <= daysInMonth[date.month - 1];
}

// Check if a time is valid
// Input: A Time object containing hour and minute
// Output: Boolean value (true if time is valid, false otherwise)
bool isValidTime(const Time& time) {
    return time.hour >= 0 && time.hour < 24 && time.minute >= 0 && time.minute < 60;
}

// Check if a flight code is valid
// Input: A string representing a flight code
// Output: Boolean value (true if flight code is valid, false otherwise)
bool isValidFlightCode(const string& code) {
    if (code.length() > 5) return false;
    for (char c : code) {
        if (!isalnum(c)) return false;
    }
    return true;
}

// Check if a place name is valid
// Input: A string representing a place name
// Output: Boolean value (true if place name is valid, false otherwise)
bool isValidPlace(const string& place) {
    if (place.length() > 20) return false;
    for (char c : place) {
        if (!isalpha(c) && c != ' ') return false;
    }
    return true;
}

// Input flight information
// Input: User inputs flight information from keyboard
// Output: A Flight object containing the input flight information
Flight inputFlight() {
    Flight flight;
    string input;
    do {
        cout << "Nhap ma chuyen bay (toi da 5 ky tu, khong khoang trang/ky tu dac biet): ";
        getline(cin >> ws, input);
        input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
        input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);
        flight.flightCode = input;
        if (input.empty()) {
            cout << "Ma chuyen bay khong duoc de trong. Vui long nhap lai.\n";
        }
    } while (input.empty() || !isValidFlightCode(flight.flightCode));
    do {
        cout << "Nhap ngay bay (dd mm yyyy): ";
        cin >> flight.departureDate.day >> flight.departureDate.month >> flight.departureDate.year;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ngay khong hop le. Vui long nhap lai.\n";
        }
    } while (!isValidDate(flight.departureDate));
    do {
        cout << "Nhap gio bay (hh:mm): ";
        char colon;
        cin >> flight.departureTime.hour >> colon >> flight.departureTime.minute;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Gio khong hop le. Vui long nhap lai.\n";
        }
    } while (!isValidTime(flight.departureTime));
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    do {
        cout << "Nhap noi di (toi da 20 ky tu, khong so/ky tu dac biet): ";
        getline(cin, flight.origin);
    } while (!isValidPlace(flight.origin));

    do {
        cout << "Nhap noi den (toi da 20 ky tu, khong so/ky tu dac biet): ";
        getline(cin, flight.destination);
    } while (!isValidPlace(flight.destination));
    return flight;
}

// Output flight information
// Input: A Flight object containing flight information
// Output: Prints flight information to the console
void outputFlight(const Flight& flight) {
    cout << "Ma chuyen bay: " << flight.flightCode << endl;
    cout << "Ngay bay: " << setfill('0') << setw(2) << flight.departureDate.day << "/"
         << setw(2) << flight.departureDate.month << "/" << flight.departureDate.year << endl;
    cout << "Gio bay: " << setw(2) << flight.departureTime.hour << ":"
         << setw(2) << flight.departureTime.minute << endl;
    cout << "Noi di: " << flight.origin << endl;
    cout << "Noi den: " << flight.destination << endl;
    cout << "------------------------" << endl;
}

// Search for flights
// Input: A vector of Flight objects and a search keyword
// Output: A vector of Flight objects matching the search keyword
vector<Flight> searchFlights(const vector<Flight>& flights, const string& keyword) {
    vector<Flight> results;
    for (const auto& flight : flights) {
        if (flight.flightCode == keyword || flight.origin == keyword || flight.destination == keyword) {
            results.push_back(flight);
        }
    }
    return results;
}

// Compare function for sorting flights
// Input: Two Flight objects to be compared
// Output: Boolean value (true if flight a should be before flight b, false otherwise)
bool compareFlight(const Flight& a, const Flight& b) {
    if (a.departureDate.year != b.departureDate.year)
        return a.departureDate.year < b.departureDate.year;
    if (a.departureDate.month != b.departureDate.month)
        return a.departureDate.month < b.departureDate.month;
    if (a.departureDate.day != b.departureDate.day)
        return a.departureDate.day < b.departureDate.day;
    if (a.departureTime.hour != b.departureTime.hour)
        return a.departureTime.hour < b.departureTime.hour;
    return a.departureTime.minute < b.departureTime.minute;
}

// Display flights from a specific origin on a given date
// Input: A vector of Flight objects, a string representing the origin, and a Date object
// Output: Prints to console all flights from the specified origin on the given date
void displayFlightsFromOriginOnDate(const vector<Flight>& flights, const string& origin, const Date& date) {
    for (const auto& flight : flights) {
        if (flight.origin == origin &&
            flight.departureDate.day == date.day &&
            flight.departureDate.month == date.month &&
            flight.departureDate.year == date.year) {
            outputFlight(flight);
        }
    }
}

// Count flights between two locations
// Input: A vector of Flight objects, strings representing origin and destination
// Output: An integer representing the number of flights between the two locations
int countFlightsBetween(const vector<Flight>& flights, const string& origin, const string& destination) {
    int count = 0;
    for (const auto& flight : flights) {
        if (flight.origin == origin && flight.destination == destination) {
            count++;
        }
    }
    return count;
}

// Main function
// Input: User selects options from menu and inputs corresponding information
// Output: Executes selected functions and displays results on the console
int main() {
    vector<Flight> flights;
    int choice;
    do {
        cout << "\n--- QUAN LY CHUYEN BAY ---\n";
        cout << "1. Nhap thong tin chuyen bay\n";
        cout << "2. Hien thi tat ca chuyen bay\n";
        cout << "3. Tim kiem chuyen bay\n";
        cout << "4. Sap xep chuyen bay\n";
        cout << "5. Hien thi chuyen bay tu mot noi trong mot ngay\n";
        cout << "6. Dem so chuyen bay giua hai dia diem\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                flights.push_back(inputFlight());
                break;
            }
            case 2: {
                for (const auto& flight : flights) {
                    outputFlight(flight);
                }
                break;
            }
            case 3: {
                string keyword;
                cout << "Nhap tu khoa tim kiem: ";
                cin >> keyword;
                auto results = searchFlights(flights, keyword);
                for (const auto& flight : results) {
                    outputFlight(flight);
                }
                break;
            }
            case 4: {
                sort(flights.begin(), flights.end(), compareFlight);
                cout << "Da sap xep chuyen bay.\n";
                break;
            }
            case 5: {
                string origin;
                Date date;
                cin.ignore();
                cout << "Nhap noi di: ";
                getline(cin, origin);
                cout << "Nhap ngay (dd mm yyyy): ";
                cin >> date.day >> date.month >> date.year;
                displayFlightsFromOriginOnDate(flights, origin, date);
                break;
            }
            case 6: {
                string origin, destination;
                cin.ignore();
                cout << "Nhap noi di: ";
                getline(cin, origin);
                cout << "Nhap noi den: ";
                getline(cin, destination);
                int count = countFlightsBetween(flights, origin, destination);
                cout << "So chuyen bay tu " << origin << " den " << destination << ": " << count << endl;
                break;
            }
            case 0:
                cout << "Cam on ban da su dung chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (choice != 0);
}
