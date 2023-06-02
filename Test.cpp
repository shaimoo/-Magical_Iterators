
#include "doctest.h"
#include "sources/MagicalContainer.hpp"


using namespace ariel;

TEST_CASE("Test MagicalContainer")
{
    ariel::MagicalContainer container;

    SUBCASE("Test adding elements")
    {
        CHECK(container.size() == 0);

        container.addElement(5);
        CHECK(container.size() == 1);

        container.addElement(3);
        CHECK(container.size() == 2);

        container.addElement(7);
        CHECK(container.size() == 3);

        container.addElement(2);
        CHECK(container.size() == 4);
    }

    SUBCASE("Test removing elements")
    {
        container.addElement(5);
        container.addElement(3);
        container.addElement(7);
        container.addElement(2);

        container.removeElement(3);
        CHECK(container.size() == 3);
        container.removeElement(2);
        CHECK(container.size() == 2);
    }

    SUBCASE("Test iterating over the ascending order")
    {
        container.addElement(5);
        container.addElement(3);
        container.addElement(7);
        container.addElement(2);
        container.addElement(11);

        std::vector<int> expected = {2, 3, 5, 7, 11};
        std::vector<int> result;
        MagicalContainer::AscendingIterator ascending(container);

        for (const auto& element : ascending)
        {
            result.push_back(element);
        }

        CHECK(result == expected);
    }

    SUBCASE("Test iterating over the side cross order")
    {
        container.addElement(5);
        container.addElement(3);
        container.addElement(7);
        container.addElement(2);
        container.addElement(11);

        std::vector<int> expected = {2, 11, 3, 7, 5};
        std::vector<int> result;
        MagicalContainer::SideCrossIterator sidecross(container);

        for (const auto& element : sidecross)
        {
            result.push_back(element);
        }

        CHECK(result == expected);
    }

    SUBCASE("Test iterating over the prime numbers")
    {
        container.addElement(5);
        container.addElement(3);
        container.addElement(7);
        container.addElement(2);
        container.addElement(11);

        std::vector<int> expected = {2, 3, 5, 7, 11};
        std::vector<int> result;
        MagicalContainer::PrimeIterator prime(container);

        for (const auto& element : prime)
        {
            result.push_back(element);
        }

        CHECK(result == expected);
    }



    SUBCASE("Test adding and removing multiple elements")
    {
        for (int i = 1; i <= 100; ++i)
        {
            container.addElement(i);
        }

        CHECK(container.size() == 100);

        for (int i = 1; i <= 50; ++i)
        {
            container.removeElement(i);
        }

        CHECK(container.size() == 50);

        std::vector<int> expected;
        for (int i = 51; i <= 100; ++i)
        {
            expected.push_back(i);
        }

        std::vector<int> result;
        MagicalContainer::AscendingIterator ascending(container);

        for (const auto& element : ascending)
        {
            result.push_back(element);
        }

        CHECK(result == expected);
    }

    SUBCASE("Test iterating over the side cross order with duplicates")
    {
        container.addElement(5);
        container.addElement(3);
        container.addElement(7);
        container.addElement(2);
        container.addElement(11);
        container.addElement(5);

        std::vector<int> expected = {2, 11, 3, 7, 5, 5};
        std::vector<int> result;
        MagicalContainer::SideCrossIterator sidecross(container);

        for (const auto& element : sidecross)
        {
            result.push_back(element);
        }

        CHECK(result == expected);
    }

    SUBCASE("Test iterating over prime numbers with duplicates")
    {
        container.addElement(5);
        container.addElement(3);
        container.addElement(7);
        container.addElement(2);
        container.addElement(11);
        container.addElement(5);

        std::vector<int> expected = {2, 3, 5, 7, 11, 5};
        std::vector<int> result;
        MagicalContainer::PrimeIterator prime(container);

        for (const auto& element : prime)
        {
            result.push_back(element);
        }

        CHECK(result == expected);
    }

    SUBCASE("Test iterating over the ascending order with a large number of elements")
    {
        for (int i = 1; i <= 1000; ++i)
        {
            container.addElement(i);
        }

        std::vector<int> expected;
        for (int i = 1; i <= 1000; ++i)
        {
            expected.push_back(i);
        }

        std::vector<int> result;
        MagicalContainer::AscendingIterator ascending(container);

        for (const auto& element : ascending)
        {
            result.push_back(element);
        }

        CHECK(result == expected);
    }

    SUBCASE("Test iterating over the side cross order with a large number of elements")
    {
        for (int i = 1; i <= 1000; ++i)
        {
            container.addElement(i);
        }

        std::vector<int> expected;
        for (int i = 1; i <= 1000; ++i)
        {
            if (i % 2 == 0)
            {
                expected.push_back(i);
            }
        }
        for (int i = 1000; i >= 1; --i)
        {
            if (i % 2 != 0)
            {
                expected.push_back(i);
            }
        }

        std::vector<int> result;
        MagicalContainer::SideCrossIterator sidecross(container);

        for (const auto& element : sidecross)
        {
            result.push_back(element);
        }

        CHECK(result == expected);
    }


    SUBCASE("Test adding elements in ascending order")
    {
        for (int i = 1; i <= 100; ++i)
        {
            container.addElement(i);
        }

        CHECK(container.size() == 100);
        container.removeElement(22);
        CHECK(container.size() == 99);
    }

    SUBCASE("Test removing elements in descending order")
    {
        for (int i = 1; i <= 100; ++i)
        {
            container.addElement(i);
        }

        for (int i = 100; i >= 1; --i)
        {
            container.removeElement(i);
        }

        CHECK(container.size() == 0);
    }


}



