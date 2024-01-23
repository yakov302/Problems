#include"iterator.hpp"

Iterator::Iterator(Node* node)
: m_node(node)
{

}

Iterator& Iterator::operator=(const Iterator& other)
{
    m_node = other.m_node;
    return *this;
}

int Iterator::data() const
{
    return m_node->data();
}

void Iterator::data(int data)
{
    m_node->data(data);
}

Iterator Iterator::next()
{
    return Iterator(m_node->next());
}

Iterator Iterator::previous()
{
    return Iterator(m_node->previous());
}

bool Iterator::operator!=(const Iterator& other)
{
    return (other.m_node != m_node);
}

bool Iterator::operator==(const Iterator& other)
{
    return (other.m_node == m_node);
}

void Iterator::operator++()
{
    m_node = m_node->next();
}

Iterator Iterator::operator++(int)
{
    Iterator current(m_node);
    m_node = m_node->next();
    return current;
}

void Iterator::operator--()
{
    m_node = m_node->previous();
}

Iterator Iterator::operator--(int)
{
    Iterator current(m_node);
    m_node = m_node->previous();
    return current;
}
