#include "list.h"
#include <iostream>

int main() {
    List list;
    int n;
    double x, y;

    while (true) {
        std::cout << "Enter command (0: Add, 1: Remove first, 2: Remove all, 3: Replace, -1: Exit): ";
        std::cin >> n;

        if (n == -1) {
            break;
        }

        switch (n) {
            case 0:
                std::cout << "Enter value to add: ";
                std::cin >> x;
                list.add(x);
                break;
            case 1:
                std::cout << "Enter value to remove (first occurrence): ";
                std::cin >> x;
                list.removeFirst(x);
                break;
            case 2:
                std::cout << "Enter value to remove (all occurrences): ";
                std::cin >> x;
                list.removeAll(x);
                break;
            case 3:
                std::cout << "Enter index and new value: ";
                std::cin >> x >> y;
                list.replace(static_cast<unsigned int>(x), y);
                break;
            default:
                std::cout << "Invalid command." << std::endl;
        }
    }

    std::cout << "Final list: ";
    list.print();

    return 0;
}
