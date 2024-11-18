#ifndef GOAT_H
#define GOAT_H

#include "animal.h"

class Goat : public Animal {
public:
    /**
     * Constructor
     * Input: so luong de ban dau
     */
    Goat(int initialQuantity);

    /**
     * Tao tieng keu cua de
     * Output: void
     */
    void makeSound() override;

    /**
     * Sinh san ngau nhien cho de
     * Output: void
     */
    void reproduce() override;

    /**
     * Cho sua ngau nhien (0-10 lit)
     * Output: void
     */
    void giveMilk() override;
};

#endif
