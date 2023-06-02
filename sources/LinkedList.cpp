#include "LinkedList.hpp"

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

LinkedList::~LinkedList()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::insert(int value)
{
    Node* newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else if (value < head->data)
    {
        head->back = newNode;
        newNode->next = head;
        head = newNode;
    }
    else if (value >= tail->data)
    {
        newNode->back = tail;
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        Node* current = head;
        while (value >= current->next->data)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next->back = newNode;
        current->next = newNode;
        newNode->back = current;
    }

    size++;
}

void LinkedList::removeElement(int element)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->data == element)
    {
        Node* temp = head;
        head = head->next;

        if (head == nullptr)
        {
            tail = nullptr;
        }

        delete temp;
        size--;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != element)
    {
        current = current->next;
    }

    if (current->next != nullptr)
    {
        Node* temp = current->next;
        current->next = current->next->next;

        if (current->next == nullptr)
        {
            tail = current;
        }

        delete temp;
        size--;
    }
}

size_t LinkedList::getSize() const
{
    return size;
}

Node* LinkedList::getLast()
{
    return tail;
}

Node* LinkedList::getHead()
{
    return head;
}

Node* LinkedList::At(size_t index)
{
    if (index >= size)
    {
        std::cout << "Error: Index out of range" << std::endl;
        return nullptr;
    }

    Node* current = head;
    for (size_t i = 0; i < index; ++i)
    {
        current = current->next;
    }

    return current;
}

void LinkedList::display()
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}
