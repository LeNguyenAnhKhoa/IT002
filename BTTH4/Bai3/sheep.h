#ifndef SHEEP_H
#define SHEEP_H

#include "animal.h"

class Sheep : public Animal {
public:
    /**
     * Constructor
     * Input: so luong cuu ban dau
     */
    Sheep(int initialQuantity);

    /**
     * Tao tieng keu cua cuu
     * Output: void
     */
    void makeSound() override;

    /**
     * Sinh san ngau nhien cho cuu
     * Output: void
     */
    void reproduce() override;

    /**
     * Cho sua ngau nhien (0-5 lit)
     * Output: void
     */
    void giveMilk() override;
};

#endif
