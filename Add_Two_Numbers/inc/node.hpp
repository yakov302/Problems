#pragma once

class Node
{
public:
    Node(Node* next = nullptr, Node* previous = nullptr, int data = 0);

    int data() const;
    void data(int data);

    Node* next() const;
    void next(Node* next);

    Node* previous() const;
    void previous(Node* previous);

private:
    int m_data;
    Node* m_next;
    Node* m_previous;
};
