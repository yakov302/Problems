#include "linked_list.hpp"

LinkedList::LinkedList()
: m_head(&m_tail, nullptr, 0)
, m_tail(nullptr, &m_head, 0)
, m_num_of_nods(0)
{

}

LinkedList::LinkedList(std::vector<int> numbers)
: m_head(&m_tail, nullptr, 0)
, m_tail(nullptr, &m_head, 0)
, m_num_of_nods(0)
{
    const int size = numbers.size();
    for(int i = 0; i < size; ++i)
        push_head(numbers[i]);
}

LinkedList::~LinkedList()
{
    while(!is_list_empty())
        pop_head();
}

bool LinkedList::is_list_empty() const
{
    return (m_num_of_nods <= 0);
}

void LinkedList::push_empty_list(int data)
{
    Node* new_node = new Node(&m_tail, &m_head, data);
    m_head.next(new_node);
    m_tail.previous(new_node);
    ++m_num_of_nods;
}

void LinkedList::push_head(int data)
{
    if(is_list_empty())
    {
        push_empty_list(data);
        return;
    }

    Node* new_node = new Node(m_head.next(), &m_head, data);
    m_head.next()->previous(new_node);
    m_head.next(new_node);
    ++m_num_of_nods;
}

void LinkedList::push_tail(int data)
{
    if(is_list_empty())
    {
        push_empty_list(data);
        return;
    }

    Node* new_node = new Node(&m_tail, m_tail.previous(), data);
    m_tail.previous()->next(new_node);
    m_tail.previous(new_node) ;
    ++m_num_of_nods;
}

void LinkedList::delete_node(Node* node)
{
    node->next(nullptr);
    node->previous(nullptr);
    delete node;
    --m_num_of_nods;  
}

int LinkedList::pop_head()
{
    if(is_list_empty())
    {
        std::cout << "ERROR: empty list!" << std::endl;
        return 0;
    }


    Node* deleted_node = m_head.next();
    int deleted_node_data = deleted_node->data();
    m_head.next(deleted_node->next());
    deleted_node->next()->previous(&m_head);
    delete_node(deleted_node);
    return deleted_node_data;
}

int LinkedList::pop_tail()
{
    if(is_list_empty())
    {
        std::cout << "ERROR: empty list!" << std::endl;
        return 0;
    }

    Node* deleted_node = m_tail.previous();
    int deleted_node_data = deleted_node->data();
    m_tail.previous(deleted_node->previous());
    deleted_node->previous()->next(&m_tail);
    delete_node(deleted_node);
    return deleted_node_data;
}

int LinkedList::head() const
{
    if(is_list_empty())
    {
        std::cout << "ERROR: empty list!" << std::endl;
        return 0;
    }

    return m_head.next()->data();
}

int LinkedList::tail() const
{
    if(is_list_empty())
    {
        std::cout << "ERROR: empty list!" << std::endl;
        return 0;
    }

    return m_tail.previous()->data();
}

int LinkedList::size() const
{
    return m_num_of_nods;
}

Node* LinkedList::head_node() const
{
    if(is_list_empty())
    {
        std::cout << "ERROR: empty list!" << std::endl;
        return 0;
    }

    return m_head.next();

}

Node* LinkedList::tail_node() const
{
    if(is_list_empty())
    {
        std::cout << "ERROR: empty list!" << std::endl;
        return 0;
    }

    return m_tail.previous();
}

void LinkedList::clear()
{
    while(!is_list_empty())
        pop_head();
}

void LinkedList::print() const
{
    std::cout << "[";

    Node* node = m_head.next();
    while(node != &m_tail)
    {
        std::cout << node->data();
        
        node = node->next();
        if(node != &m_tail)
            std::cout << ", ";
    }

    std::cout << "]" << std::endl;
}
