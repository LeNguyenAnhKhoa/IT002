#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>

using namespace std;

struct Date {
    int day, month, year;
};

struct SavingsAccount {
    string accountCode;
    string savingsType;
    string customerName;
    long long idNumber;
    Date openDate;
    double balance;
};

/**
 * Check if a string contains only alphanumeric characters.
 * Input: str - the string to check
 * Output: true if the string contains only alphanumeric characters, false otherwise
 */
bool isAlphanumeric(const string& str) {
    return all_of(str.begin(), str.end(), [](char c) {
        return isalnum(c);
    });
}

/**
 * Check if a string contains only alphabetic characters.
 * Input: str - the string to check
 * Output: true if the string contains only alphabetic characters or spaces, false otherwise
 */
bool isAlphabetic(const string& str) {
    return all_of(str.begin(), str.end(), [](char c) {
        return isalpha(c) || c == ' ';
    });
}

/**
 * Check if a date is valid.
 * Input: date - the Date struct to check
 * Output: true if the date is valid, false otherwise
 */
bool isValidDate(const Date& date) {
    if (date.year < 1900 || date.month < 1 || date.month > 12 || date.day < 1)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0))
        daysInMonth[1] = 29;

    return date.day <= daysInMonth[date.month - 1];
}

/**
 * Input data for a savings account.
 * Input: account - reference to a SavingsAccount struct to be filled
 * Output: None (modifies the input account)
 */
void inputSavingsAccount(SavingsAccount& account) {
    do {
        cout << "Nhap ma so (toi da 5 ky tu, khong chua khoang trang hoac ky tu dac biet): ";
        cin >> account.accountCode;
    } while (account.accountCode.length() > 5 || !isAlphanumeric(account.accountCode));

    cout << "Nhap loai tiet kiem (toi da 10 ky tu): ";
    cin.ignore();
    getline(cin, account.savingsType);

    do {
        cout << "Nhap ho ten khach hang (toi da 30 ky tu, khong chua so hoac ky tu dac biet): ";
        getline(cin, account.customerName);
    } while (account.customerName.length() > 30 || !isAlphabetic(account.customerName));

    do {
        cout << "Nhap CMND (9 hoac 12 chu so): ";
        cin >> account.idNumber;
    } while (to_string(account.idNumber).length() != 9 && to_string(account.idNumber).length() != 12);

    do {
        cout << "Nhap ngay mo so (ngay thang nam): ";
        cin >> account.openDate.day >> account.openDate.month >> account.openDate.year;
    } while (!isValidDate(account.openDate));

    do {
        cout << "Nhap so tien gui: ";
        cin >> account.balance;
    } while (account.balance <= 0);
}

/**
 * Display data of a savings account.
 * Input: account - const reference to a SavingsAccount struct to be displayed
 * Output: None (prints account information to console)
 */
void displaySavingsAccount(const SavingsAccount& account) {
    cout << "Ma so: " << account.accountCode << endl;
    cout << "Loai tiet kiem: " << account.savingsType << endl;
    cout << "Ho ten khach hang: " << account.customerName << endl;
    cout << "CMND: " << account.idNumber << endl;
    cout << "Ngay mo so: " << account.openDate.day << "/" << account.openDate.month << "/" << account.openDate.year << endl;
    cout << "So tien gui: " << fixed << setprecision(2) << account.balance << endl;
}

/**
 * Calculate interest based on savings type and duration.
 * Input: account - const reference to a SavingsAccount struct
 *        interestRate - annual interest rate as a percentage
 *        currentDate - the current date for calculation
 * Output: The calculated interest amount
 */
double calculateInterest(const SavingsAccount& account, double interestRate, const Date& currentDate) {
    int durationInDays = (currentDate.year - account.openDate.year) * 365 +
                         (currentDate.month - account.openDate.month) * 30 +
                         (currentDate.day - account.openDate.day);

    double annualInterestRate = interestRate / 100.0;
    double interest = account.balance * annualInterestRate * (durationInDays / 365.0);

    if (account.savingsType == "ngan han" && durationInDays > 180) {
        interest *= 0.5;  // Reduce interest for short-term accounts after 6 months
    }

    return interest;
}

/**
 * Withdraw money from a savings account.
 * Input: account - reference to a SavingsAccount struct
 *        amount - amount to withdraw
 *        currentDate - the current date for calculation
 * Output: None (modifies the input account and prints result to console)
 */
void withdrawMoney(SavingsAccount& account, double amount, const Date& currentDate) {
    if (amount > account.balance) {
        cout << "So tien rut vuot qua so du. Khong the thuc hien giao dich." << endl;
        return;
    }

    int durationInDays = (currentDate.year - account.openDate.year) * 365 +
                         (currentDate.month - account.openDate.month) * 30 +
                         (currentDate.day - account.openDate.day);

    if (durationInDays < 30) {
        cout << "Canh bao: Rut tien truoc han. Lai suat se duoc tinh lai voi muc 0.5%/nam." << endl;
        double interest = calculateInterest(account, 0.5, currentDate);
        account.balance += interest;
    }

    account.balance -= amount;
    cout << "Rut tien thanh cong. So du moi: " << fixed << setprecision(2) << account.balance << endl;
}

/**
 * Search for a savings account by ID number or account code.
 * Input: accounts - vector of SavingsAccount to search in
 *        searchTerm - string to search for (ID number or account code)
 * Output: Pointer to found SavingsAccount or nullptr if not found
 */
SavingsAccount* searchAccount(vector<SavingsAccount>& accounts, const string& searchTerm) {
    for (auto& account : accounts) {
        if (account.accountCode == searchTerm || to_string(account.idNumber) == searchTerm) {
            return &account;
        }
    }
    return nullptr;
}

/**
 * List all savings accounts opened within a specific date range.
 * Input: accounts - const vector of SavingsAccount to search in
 *        startDate - start of the date range
 *        endDate - end of the date range
 * Output: Vector of SavingsAccount that fall within the date range
 */
vector<SavingsAccount> listAccountsInDateRange(const vector<SavingsAccount>& accounts, const Date& startDate, const Date& endDate) {
    vector<SavingsAccount> result;
    for (const auto& account : accounts) {
        if (account.openDate.year > startDate.year && account.openDate.year < endDate.year) {
            result.push_back(account);
        } else if (account.openDate.year == startDate.year && account.openDate.year == endDate.year) {
            if (account.openDate.month > startDate.month && account.openDate.month < endDate.month) {
                result.push_back(account);
            } else if (account.openDate.month == startDate.month && account.openDate.month == endDate.month) {
                if (account.openDate.day >= startDate.day && account.openDate.day <= endDate.day) {
                    result.push_back(account);
                }
            }
        }
    }
    return result;
}

/**
 * Sort accounts by balance in descending order.
 * Input: accounts - vector of SavingsAccount to be sorted
 * Output: None (modifies the input vector)
 */
void sortAccountsByBalance(vector<SavingsAccount>& accounts) {
    sort(accounts.begin(), accounts.end(), [](const SavingsAccount& a, const SavingsAccount& b) {
        return a.balance > b.balance;
    });
}

/**
 * Sort accounts by open date in ascending order.
 * Input: accounts - vector of SavingsAccount to be sorted
 * Output: None (modifies the input vector)
 */
void sortAccountsByOpenDate(vector<SavingsAccount>& accounts) {
    sort(accounts.begin(), accounts.end(), [](const SavingsAccount& a, const SavingsAccount& b) {
        if (a.openDate.year != b.openDate.year) return a.openDate.year < b.openDate.year;
        if (a.openDate.month != b.openDate.month) return a.openDate.month < b.openDate.month;
        return a.openDate.day < b.openDate.day;
    });
}

int main() {
    vector<SavingsAccount> accounts;
    int choice;

    do {
        cout << "\n--- QUAN LY SO TIET KIEM ---" << endl;
        cout << "1. Them so tiet kiem moi" << endl;
        cout << "2. Hien thi danh sach so tiet kiem" << endl;
        cout << "3. Cap nhat lai suat" << endl;
        cout << "4. Rut tien" << endl;
        cout << "5. Tim kiem so tiet kiem" << endl;
        cout << "6. Liet ke so tiet kiem trong khoang thoi gian" << endl;
        cout << "7. Sap xep theo so tien gui giam dan" << endl;
        cout << "8. Sap xep theo ngay mo so tang dan" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                SavingsAccount newAccount;
                inputSavingsAccount(newAccount);
                accounts.push_back(newAccount);
                cout << "Them so tiet kiem thanh cong!" << endl;
                break;
            }
            case 2: {
                cout << "\nDanh sach so tiet kiem:" << endl;
                for (const auto& account : accounts) {
                    displaySavingsAccount(account);
                    cout << "----------------------" << endl;
                }
                break;
            }
            case 3: {
                double interestRate;
                cout << "Nhap lai suat moi (%/nam): ";
                cin >> interestRate;
                Date currentDate;
                cout << "Nhap ngay hien tai (ngay thang nam): ";
                cin >> currentDate.day >> currentDate.month >> currentDate.year;
                for (auto& account : accounts) {
                    double interest = calculateInterest(account, interestRate, currentDate);
                    cout << "So tiet kiem " << account.accountCode << " - Lai: " << fixed << setprecision(2) << interest << endl;
                }
                break;
            }
            case 4: {
                string accountCode;
                double amount;
                cout << "Nhap ma so tiet kiem can rut tien: ";
                cin >> accountCode;
                auto it = find_if(accounts.begin(), accounts.end(), [&](const SavingsAccount& acc) {
                    return acc.accountCode == accountCode;
                });
                if (it != accounts.end()) {
                    cout << "Nhap so tien can rut: ";
                    cin >> amount;
                    Date currentDate;
                    cout << "Nhap ngay hien tai (ngay thang nam): ";
                    cin >> currentDate.day >> currentDate.month >> currentDate.year;
                    withdrawMoney(*it, amount, currentDate);
                } else {
                    cout << "Khong tim thay so tiet kiem!" << endl;
                }
                break;
            }
            case 5: {
                string searchTerm;
                cout << "Nhap ma so hoac CMND can tim: ";
                cin >> searchTerm;
                SavingsAccount* foundAccount = searchAccount(accounts, searchTerm);
                if (foundAccount) {
                    cout << "Tim thay so tiet kiem:" << endl;
                    displaySavingsAccount(*foundAccount);
                } else {
                    cout << "Khong tim thay so tiet kiem!" << endl;
                }
                break;
            }
            case 6: {
                Date startDate, endDate;
                cout << "Nhap ngay bat dau (ngay thang nam): ";
                cin >> startDate.day >> startDate.month >> startDate.year;
                cout << "Nhap ngay ket thuc (ngay thang nam): ";
                cin >> endDate.day >> endDate.month >> endDate.year;
                vector<SavingsAccount> filteredAccounts = listAccountsInDateRange(accounts, startDate, endDate);
                cout << "Cac so tiet kiem trong khoang thoi gian:" << endl;
                for (const auto& account : filteredAccounts) {
                    displaySavingsAccount(account);
                    cout << "----------------------" << endl;
                }
                break;
            }
            case 7: {
                sortAccountsByBalance(accounts);
                cout << "Da sap xep danh sach theo so tien gui giam dan." << endl;
                break;
            }
            case 8: {
                sortAccountsByOpenDate(accounts);
                cout << "Da sap xep danh sach theo ngay mo so tang dan." << endl;
                break;
            }
            case 0:
                cout << "Cam on ban da su dung chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    } while (choice != 0);

    return 0;
}
