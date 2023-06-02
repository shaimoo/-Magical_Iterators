#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node* back;

    Node(int value) : data(value), next(nullptr), back(nullptr) {}

    bool operator==(const Node& other) const
    {
        return other.data == data && other.next == next && other.back == back;
    }
};

class LinkedList
{
private:
    Node* head;
    Node* tail;
    size_t size;

public:
    LinkedList();
    ~LinkedList();

    void insert(int value);
    void removeElement(int element);
    size_t getSize() const;
    Node* getLast();
    Node* getHead();
    Node* At(size_t index);
    void display();
};

#endif // LINKEDLIST_H
