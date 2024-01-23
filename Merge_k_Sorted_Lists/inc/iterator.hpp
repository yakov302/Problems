#pragma once

#include "node.hpp"

class Iterator
{
public:
    Iterator(Node* node);

    Iterator& operator=(const Iterator& other);

    int data() const;
    void data(int data);

    Iterator next();
    Iterator previous();

    void operator++();
    void operator--();
    Iterator operator++(int);
    Iterator operator--(int);
    bool operator!=(const Iterator& other);
    bool operator==(const Iterator& other);

private:
    Node* m_node;
};
