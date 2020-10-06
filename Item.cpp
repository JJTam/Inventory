#include "Item.h"

/** constructor
 *
 * @param name
 * @param quantity
 */
Item::Item(string name, int quantity) : name(name), quantity(quantity) {}

/** return the item name
 *
 * @return the name
 */
string Item::getName() const {
    return name;
}

/**  return the item quantity
 *
 * @return the quantity
 */
int Item::getQuantity() const {
    return quantity;
}


/** add the specified amount to item quantity
 * @param amount
 */
void Item::add(int amount) {
    if (amount >= 0) {
        quantity = quantity + amount;
    }
}

/** remove the specified amount from item quantity if possible
 * if the removal is possible (i.e. amount is not more than the quantity), do the removal and return true
 * otherwise, do nothing and return false
 */
bool Item::remove(int amount) {
    if (amount <= quantity && amount >= 0) {
        quantity = quantity - amount;
        return true;
    }
    return false;
}
