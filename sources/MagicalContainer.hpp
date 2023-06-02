#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H
#include <vector>
#include <algorithm>
#include <cmath>
#include "LinkedList.hpp"



namespace ariel
{

    class MagicalContainer
    {
    private:
        LinkedList ascendingVector;
        std::vector<int *> primePointers;
        Node *middle = NULL;

    public:
        void addElement(int element);
        void removeElement(int element);
        size_t size() const;
        bool isPrime(int element);

        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            Node current;

        public:
            AscendingIterator(MagicalContainer &cont) : container(cont), current(*cont.ascendingVector.getHead())
            {
            }

            AscendingIterator(MagicalContainer &cont, Node cur) : container(cont), current(cur)
            {
            }

            AscendingIterator(const AscendingIterator &other) : container(other.container), current(other.current)
            {
            }

            ~AscendingIterator() {}

            AscendingIterator &operator=(const AscendingIterator &other)
            {
                if (this != &other)
                {
                    container = other.container;
                    current = other.current;
                }
                return *this;
            }

            bool operator==(const AscendingIterator &other) const
            {
                return &container == &other.container && current == other.current;
            }

            bool operator!=(const AscendingIterator &other) const
            {
                return !(*this == other);
            }

            int operator*() const
            {
                return current.data;
            }

            AscendingIterator &operator++()
            {
                if (current.next != NULL)
                {
                    current = *current.next;
                }
                else
                    current = NULL;
                return *this;
            }

            AscendingIterator begin() const
            {
                AscendingIterator iter(container);
                return iter;
            }

            AscendingIterator end() const
            {
                AscendingIterator iter(this->container, NULL);

                return iter;
            }
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &container;
            Node *tail;
            Node *head;
            bool odd = false;

        public:
            SideCrossIterator(MagicalContainer &cont, size_t index = 0) : container(cont),
                                                                          tail(cont.ascendingVector.getLast()),
                                                                          head(cont.ascendingVector.getHead()) {}

            SideCrossIterator(const SideCrossIterator &other) : container(other.container), head(other.head), tail(other.tail) {}

            ~SideCrossIterator() {}

            SideCrossIterator &operator=(const SideCrossIterator &other)
            {
                if (this != &other)
                {
                    container = other.container;
                    head = other.head;
                    tail = other.tail;
                }
                return *this;
            }

            bool operator==(const SideCrossIterator &other) const
            {
                return &container == &other.container && head == other.head && tail == other.tail;
            }

            bool operator!=(const SideCrossIterator &other) const
            {
                return !(*this == other);
            }

            int operator*() const
            {
                if (head == nullptr && tail == nullptr)
                {
                    return -1;
                }
                if (odd)
                {
                    return tail->data;
                }
                return head->data;
            }

            SideCrossIterator &operator++()
            {

                if (odd)
                {
                    this->tail = this->tail->back;
                    odd = false;
                }
                else
                {
                    this->head = this->head->next;
                    odd = true;
                }

                if ((this->container.size() % 2 == 0 && head == this->container.middle->back && tail == this->container.middle) ||
                    (this->container.size() % 2 == 1 && head == this->container.middle->next && tail == this->container.middle))
                {
                    head = nullptr;
                    tail = nullptr;
                }
                return *this;
            }

            SideCrossIterator begin() const
            {
                SideCrossIterator iter(container);
                return iter;
            }

            SideCrossIterator end() const
            {
                SideCrossIterator iter(container);
                iter.head = nullptr;
                iter.tail = nullptr;
                if (this->container.size() % 2 == 1)
                {
                    iter.odd = true;
                }
                return iter;
            }
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t currentIndex;

        public:
            PrimeIterator(MagicalContainer &cont, size_t index = 0) : container(cont), currentIndex(index) {}

            PrimeIterator(const PrimeIterator &other) : container(other.container), currentIndex(other.currentIndex) {}

            ~PrimeIterator() {}

            PrimeIterator &operator=(const PrimeIterator &other)
            {
                if (this != &other)
                {
                    container = other.container;
                    currentIndex = other.currentIndex;
                }
                return *this;
            }

            bool operator==(const PrimeIterator &other) const
            {
                return &container == &other.container && currentIndex == other.currentIndex;
            }

            bool operator!=(const PrimeIterator &other) const
            {
                return !(*this == other);
            }

            int operator*() const
            {
                return *this->container.primePointers[currentIndex];
            }

            PrimeIterator &operator++()
            {
                ++currentIndex;
                return *this;
            }

            PrimeIterator begin() const
            {
                PrimeIterator iter(container);
                return iter;
            }

            PrimeIterator end() const
            {
                PrimeIterator iter(container);
                iter.currentIndex = this->container.primePointers.size();
                return iter;
            }
        };
    };
}

#endif //MAGICALCONTAINER_HPP