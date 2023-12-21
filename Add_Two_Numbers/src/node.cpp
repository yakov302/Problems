#include "node.hpp"

Node::Node(Node* next, Node* previous, int data)
: m_data(data)
, m_next(next)
, m_previous(previous)
{

}

int Node::data() const
{
    return m_data;
}

void Node::data(int data)
{
    m_data = data;
}

Node* Node::next() const
{
    return m_next;
}

void Node::next(Node* next)
{
    m_next = next;
}

Node* Node::previous() const
{
    return m_previous;
}

void Node::previous(Node* previous)
{
    m_previous = previous;
}
