#include "animal.h"

Animal::Animal(int initialQuantity) {
    quantity = initialQuantity;
    milk = 0;
}

int Animal::getQuantity() const {
    return quantity;
}

float Animal::getMilk() const {
    return milk;
}
