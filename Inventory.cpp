#include "Inventory.h"

/** default constructor
 * set itemCount to 0
 * set items to nullptr
 */
Inventory::Inventory() : items(nullptr), itemCount(0) {}


/** deep copy constructor
 * @param another Inventory Object
 */
Inventory::Inventory(const Inventory& another) {
	this->itemCount = another.itemCount;
	this->items = new Item *[itemCount];
	for (int i = 0; i < this->itemCount; ++i) {  // deep copying
		items[i] = new Item(another.items[i]->getName(), another.items[i]->getQuantity());
	}
}

/** destructor
 * make use of emptyInventory()
 */
Inventory::~Inventory() {
    emptyInventory();  // call this function to do deallocating
}


/** empty the inventory
 * called by destructor
 * delete all items, set itemCount to 0, set items to nullptr
 */
void Inventory::emptyInventory() {
    if (items) {   // must have the items array to be deleted
        for (int i = 0; i < itemCount; ++i) {
            if (items[i]) {  // must have the items to be deleted
                delete items[i];  // delete the items
                items[i] = nullptr;
            }
        }
        delete [] items;   // delete the items array
        items = nullptr;
        itemCount = 0;
    }
}



/** add an item with the specified name and quantity
 *  there are two scenarios:
 *  (A) the item doesn't exist in the current inventory
 *  (B) the item is already in the current inventory
 *  for scenario (A), you need to create a new item with the specified name and quantity
 *  you must store the new item at the very end of the items array
 *  the items array must be just big enough to contain all items
 *  therefore you must increase the size of the current items array (if any) by 1
 *  remember to update the itemCount
 *  for scenario (B), just add the quantity to the existing item
 * @param name
 * @param quantity
 */
void Inventory::addItem(string name, int quantity) {
    Item** createNewItems = new Item* [itemCount + 1];  // create a new larger array
    for (int i = 0; i < itemCount; ++i) {
        if (items[i]->getName() == name) {   // is already in the current inventory
            items[i]->add(quantity);  // just add the quantity to the existing item
            delete [] createNewItems;  // deallocate the createNewItems
            return;
        }
        createNewItems[i] = items[i]; // shallow copying the original one
    }

    createNewItems[itemCount++] = new Item(name, quantity);  // add the new one at the end
    if (itemCount != 1) {
        delete [] items;  // deallocate the original 2D array
    }
    items = createNewItems; // now it points to the newly created one
}


/** remove the specified quantity from the item of the specified name if possible
 * if there is no item with the specified name, simply do nothing and return false
 * otherwise, try to remove the given quantity from the item:
 * if the removal cannot be done (i.e. quantity to remove is more than the quantity of the item), do nothing and return false
 * if the removal can be done, then do the removal and return true
 * if, after removal, the quantity of the item becomes 0,
 * you need to also remove the item completely from the items array (one of our sample output illustrates that)
 * @param name
 * @param quantity
 * @return true/false
 */
bool Inventory::removeItem(string name, int quantity) {
    int index = getItemIndex(name);  // call getItemIndex() to get the index
    if (index != -1) { // item can be found
        if (items[index]->remove(quantity)) {   // true, if quantity to remove less than original quantity
            if (items[index]->getQuantity() == 0) {  // after removal, the quantity of the item becomes 0
                Item** createNewItems = new Item* [--itemCount];  // create a new smaller array
                for (int i = 0; i < index; ++i) {  // shallow copying from the original
                    createNewItems[i] = items[i]; // the upper half
                }
                for (int j = index; j < itemCount; ++j) {
                    createNewItems[j] = items[j + 1];  // the lower half
                }

                delete items[index];  // completely delete the item
                items[index] = nullptr;
                delete [] items; // deallocate the original 2D array
                items = createNewItems; // now it points to the newly created one
            }
            return true;
        }
    }
    return false;
}



/** add another inventory to this inventory
 * all items from another are added to this inventory
 * existing items in this inventory are always kept in their current order at the front of the items array
 * new items from another are added one by one in order to the end of this inventory's items array
 * @param another inventory's items
 */
void Inventory::addInventory(const Inventory& another) {
	for (int i = 0; i < another.itemCount; ++i) {
		for (int j = 0; j < this->itemCount; ++j) {
			if (this->items[j]->getName() == another.items[i]->getName()) { // existing items, then add the quantity up
				this->items[j]->add(another.items[i]->getQuantity());
			}
			else {  // new items from another are added
				this->addItem(another.items[i]->getName(), another.items[i]->getQuantity());
			}
			break;
		}
	}
}



/** return the quantity of the item with the given name
 * simply return 0 if no item of that name is found
 * @param name
 * @return quantity
 */
int Inventory::getQuantity(string name) const {
    if (items) {    // must have items
        for (int i = 0; i < itemCount; ++i) {
            if (items[i]->getName() == name) {   // item found
                return items[i]->getQuantity();
            }
        }
    }
    return 0;
}



/** return the sum of quantities of all items
 * @return the sum
 */
int Inventory::getTotalUsedSpace() const {
    int totalSum = 0;
    if (items) {  // must have items
        for (int i = 0; i < itemCount; ++i) {
            totalSum += items[i]->getQuantity();
        }
    }
    return totalSum;
}



/** return the index of the element in the items array that represents the item of the given name
 * return -1 if the item is not found
 * @param name
 * @return the index
 */
int Inventory::getItemIndex(string name) const {
    if (items) {  // must have items
        for (int i = 0; i < itemCount; ++i) {
            if (items[i]->getName() == name) {  // item found
                return i;
            }
        }
    }
    return -1;
}


/** create the union of this inventory (this) and another inventory (another), and return it
 * Union:
 * 1. only if an item exists in either this or another or both, it also exists in the union
 * 2. the quantity of an item in the union is the higher value of "item quantity in this" and "item quantity in another"
 * existing items in this inventory are put in the resulting inventory first, and they are always kept in their original order
 * new items from another are added one by one in order to the end
 * @param another
 * @return the Union of this Inventory pointer
 */
Inventory* Inventory::getUnion(const Inventory& another) const {
    Inventory* createUnion = new Inventory(*this);  // call copy constructor
	for (int i = 0; i < another.itemCount; ++i) {
		for (int j = 0; j < createUnion->itemCount; ++j) {
			if (createUnion->items[j]->getName() == another.items[i]->getName()) { // item is the same and then making union
				if (createUnion->items[j]->getQuantity() < another.items[i]->getQuantity()) {
					int differQuantity = another.items[i]->getQuantity() - createUnion->items[j]->getQuantity();
					createUnion->items[j]->add(differQuantity);  // change to the bigger quantity
				}
				break;
			}
			if (j == createUnion->itemCount - 1) {  // add the new union to the end
				createUnion->addItem(another.items[i]->getName(), another.items[i]->getQuantity());
			}
		}
	}
    return createUnion;
}



/** create the intersection of this inventory (this) and another inventory (another), and return it
 * Intersection:
 * 1. only if an item exists in both this and another, it also exists in the union
 * 2. the quantity of an item in the intersection is the lower value of "item quantity in this" and "item quantity in another"
 * the item ordering follows the original item ordering in this inventory
 * @param another
 * @return the Intersection of this Inventory pointer
 */
Inventory* Inventory::getIntersection(const Inventory& another) const {
    Inventory* createIntersect = new Inventory;   // call default constructor
	for (int i = 0; i < another.itemCount; ++i) {
		for (int j = 0; j < this->itemCount; ++j) {
			if (this->items[j]->getName() == another.items[i]->getName()) {   // item is the same and then making intersection
				if (this->items[j]->getQuantity() <= another.items[i]->getQuantity()) {
					createIntersect->addItem(this->items[j]->getName(), this->items[j]->getQuantity());  // add this one to the intersection
				}
				else {
					createIntersect->addItem(another.items[i]->getName(), another.items[i]->getQuantity()); // add another one to the intersection
				}
				break;
			}
		}
	}
    return createIntersect;
}


/** create the difference of this inventory (this) from another inventory (another), and return it
 * Difference:
 * 1. only if an item exists in this inventory and its resulting quantity (see next point) is larger than 0, it also exists in the difference
 * 2. the resulting quantity of the item = item quantity in this - item quantity in another
 * the item ordering follows this inventory's
 * @param another
 * @return  the Difference of this Inventory pointer
 */
Inventory* Inventory::getDifference(const Inventory& another) const {
    Inventory* createDifference = new Inventory(*this);   // call copy constructor
	for (int i = 0; i < another.itemCount; ++i) {
		for (int j = 0; j < createDifference->itemCount; ++j) {
			if (createDifference->items[j]->getName() == another.items[i]->getName()) { // item is the same and then making difference
				if (createDifference->items[j]->remove(another.items[i]->getQuantity())) {  // remove successfully, just do remove the amount of quantity
				}
				else {   // removal fail, then delete the whole item
					createDifference->removeItem(createDifference->items[j]->getName(),createDifference->items[j]->getQuantity());
				}
				break;
			}
		}
	}
    return createDifference;
}



/** print the inventory
 * use the online grader Zinc to verify your output format well before the submission
 */
void Inventory::print() const {
    cout << "{";
    for (int i = 0; i < this->itemCount; ++i) {
        cout << "\"" << items[i]->getName() << "\":" << items[i]->getQuantity();
        if (i != itemCount - 1) {
            cout << ",";
        }
    }
    cout << "}\n";
}
