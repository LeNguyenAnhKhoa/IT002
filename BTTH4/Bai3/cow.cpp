#include "cow.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Cow::Cow(int initialQuantity) : Animal(initialQuantity) {}

void Cow::makeSound() {
    for(int i = 0; i < quantity; i++) {
        std::cout << "Bo keu: Mooo!" << std::endl;
    }
}

void Cow::reproduce() {
    int newBorn = rand() % 3 + 1; // Sinh ngau nhien 1-3 con
    quantity += newBorn;
    std::cout << "So bo moi sinh: " << newBorn << std::endl;
}

void Cow::giveMilk() {
    for(int i = 0; i < quantity; i++) {
        milk += (rand() % 21); // 0-20 lit sua
    }
}
