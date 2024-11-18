#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cow.h"
#include "sheep.h"
#include "goat.h"

/**
 * Chuong trinh quan ly nong trai
 * Input: So luong bo, cuu, de ban dau
 * Output: Thong ke so luong gia suc va luong sua sau khi sinh san va cho sua
 */

int main() {
    srand(time(nullptr)); // Khoi tao bo sinh so ngau nhien

    int numCows, numSheep, numGoats;

    // Nhap so luong gia suc ban dau
    std::cout << "Nhap so luong bo ban dau: ";
    std::cin >> numCows;
    std::cout << "Nhap so luong cuu ban dau: ";
    std::cin >> numSheep;
    std::cout << "Nhap so luong de ban dau: ";
    std::cin >> numGoats;

    // Tao doi tuong cho tung loai gia suc
    Cow cows(numCows);
    Sheep sheep(numSheep);
    Goat goats(numGoats);

    std::cout << "\nKhi doi, tat ca gia suc keu:\n";
    cows.makeSound();
    sheep.makeSound();
    goats.makeSound();

    std::cout << "\nSau khi sinh san:\n";
    cows.reproduce();
    sheep.reproduce();
    goats.reproduce();

    // Cho sua
    cows.giveMilk();
    sheep.giveMilk();
    goats.giveMilk();

    // Thong ke
    std::cout << "\nThong ke nong trai:\n";
    std::cout << "So luong bo: " << cows.getQuantity() << std::endl;
    std::cout << "So luong cuu: " << sheep.getQuantity() << std::endl;
    std::cout << "So luong de: " << goats.getQuantity() << std::endl;

    float totalMilk = cows.getMilk() + sheep.getMilk() + goats.getMilk();
    std::cout << "Tong luong sua: " << totalMilk << " lit" << std::endl;

    return 0;
}
