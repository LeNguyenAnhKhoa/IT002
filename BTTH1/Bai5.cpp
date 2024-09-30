#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Checks if a given year is a leap year.
 * @param year The year to check
 * @return true if it's a leap year, false otherwise
 */
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * Determines the number of days in a specific month of a given year.
 * @param month The month (1-12)
 * @param year The year
 * @return The number of days in the month
 */
int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month - 1];
}

/**
 * Calculates the next day of a given date.
 * @param day The current day (reference)
 * @param month The current month (reference)
 * @param year The current year (reference)
 */
void nextDay(int& day, int& month, int& year) {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

/**
 * Calculates the previous day of a given date.
 * @param day The current day (reference)
 * @param month The current month (reference)
 * @param year The current year (reference)
 */
void previousDay(int& day, int& month, int& year) {
    day--;
    if (day == 0) {
        month--;
        if (month == 0) {
            month = 12;
            year--;
        }
        day = daysInMonth(month, year);
    }
}

/**
 * Calculates the day of the year for a given date.
 * @param day The day
 * @param month The month
 * @param year The year
 * @return The day number of the year
 */
int dayOfYear(int day, int month, int year) {
    int days = day;
    for (int i = 1; i < month; i++) {
        days += daysInMonth(i, year);
    }
    return days;
}

int main() {
    int day, month, year;

    cout << "Nhap ngay (dd mm yyyy): ";
    cin >> day >> month >> year;

    cout << "Ngay da nhap: " << setfill('0') << setw(2) << day << "/"
         << setw(2) << month << "/" << year << endl;

    int nextDay_d = day, nextDay_m = month, nextDay_y = year;
    nextDay(nextDay_d, nextDay_m, nextDay_y);
    cout << "Ngay ke tiep: " << setfill('0') << setw(2) << nextDay_d << "/"
         << setw(2) << nextDay_m << "/" << nextDay_y << endl;

    int prevDay_d = day, prevDay_m = month, prevDay_y = year;
    previousDay(prevDay_d, prevDay_m, prevDay_y);
    cout << "Ngay truoc do: " << setfill('0') << setw(2) << prevDay_d << "/"
         << setw(2) << prevDay_m << "/" << prevDay_y << endl;

    int dayNumber = dayOfYear(day, month, year);
    cout << "Ngay thu " << dayNumber << " trong nam" << endl;

    return 0;
}
