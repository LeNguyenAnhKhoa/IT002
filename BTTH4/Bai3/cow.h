#ifndef COW_H
#define COW_H

#include "animal.h"

class Cow : public Animal {
public:
    /**
     * Constructor
     * Input: so luong bo ban dau
     */
    Cow(int initialQuantity);

    /**
     * Tao tieng keu cua bo
     * Output: void
     */
    void makeSound() override;

    /**
     * Sinh san ngau nhien cho bo
     * Output: void
     */
    void reproduce() override;

    /**
     * Cho sua ngau nhien (0-20 lit)
     * Output: void
     */
    void giveMilk() override;
};

#endif
