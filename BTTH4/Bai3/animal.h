#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
protected:
    int quantity;  // So luong gia suc
    float milk;    // Luong sua

public:
    /**
     * Constructor
     * Input: so luong gia suc ban dau
     */
    Animal(int initialQuantity);

    /**
     * Ham ao thuan tuy de tao tieng keu
     * Output: void
     */
    virtual void makeSound() = 0;

    /**
     * Ham sinh san ngau nhien
     * Output: void
     */
    virtual void reproduce() = 0;

    /**
     * Ham cho sua ngau nhien
     * Output: void
     */
    virtual void giveMilk() = 0;

    /**
     * Lay so luong gia suc
     * Output: so luong gia suc hien tai
     */
    int getQuantity() const;

    /**
     * Lay luong sua
     * Output: luong sua da cho
     */
    float getMilk() const;
};

#endif
