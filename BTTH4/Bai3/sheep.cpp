#include "sheep.h"
#include <iostream>
#include <cstdlib>

Sheep::Sheep(int initialQuantity) : Animal(initialQuantity) {}

void Sheep::makeSound() {
    for(int i = 0; i < quantity; i++) {
        std::cout << "Cuu keu: Beee!" << std::endl;
    }
}

void Sheep::reproduce() {
    int newBorn = rand() % 2 + 1; // Sinh ngau nhien 1-2 con
    quantity += newBorn;
    std::cout << "So cuu moi sinh: " << newBorn << std::endl;
}

void Sheep::giveMilk() {
    for(int i = 0; i < quantity; i++) {
        milk += (rand() % 6); // 0-5 lit sua
    }
}
