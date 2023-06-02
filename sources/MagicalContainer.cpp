#include "MagicalContainer.hpp"

namespace ariel {

    void MagicalContainer::addElement(int element) {
        ascendingVector.insert(element);
        if (isPrime(element)) {
            int *primePtr = new int(element);

            auto primeInsertionPoint = std::upper_bound(primePointers.begin(), primePointers.end(), primePtr,
                                                        [](const int *a, const int *b) { return *a < *b; });
            primePointers.insert(primeInsertionPoint, primePtr);
        }
        this->middle = this->ascendingVector.At(this->size() / 2);
    }

    void MagicalContainer::removeElement(int element) {
        this->ascendingVector.removeElement(element);
        for (auto it = primePointers.begin(); it != primePointers.end(); ++it) {
            if (**it == element) {
                primePointers.erase(it);
                break;
            }
        }
        this->middle = this->ascendingVector.At(this->size() / 2);
    }

    size_t MagicalContainer::size() const {
        return ascendingVector.getSize();
    }
    bool MagicalContainer::isPrime(int element)
     {
        if (element == 2 || element == 3) {
            return true;
        }
        if (element < 2 || element % 2 == 0) {
            return false;
        }

        for (int i = 3; i * i <= element; i += 2) {
            if (element % i == 0) {
                return false;
            }
        }

        return true;
    }

}