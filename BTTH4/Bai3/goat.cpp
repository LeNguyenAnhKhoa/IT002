#include "goat.h"
#include <iostream>
#include <cstdlib>

Goat::Goat(int initialQuantity) : Animal(initialQuantity) {}

void Goat::makeSound() {
    for(int i = 0; i < quantity; i++) {
        std::cout << "De keu: Eeee!" << std::endl;
    }
}

void Goat::reproduce() {
    int newBorn = rand() % 2 + 1; // Sinh ngau nhien 1-2 con
    quantity += newBorn;
    std::cout << "So de moi sinh: " << newBorn << std::endl;
}

void Goat::giveMilk() {
    for(int i = 0; i < quantity; i++) {
        milk += (rand() % 11); // 0-10 lit sua
    }
}
