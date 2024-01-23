#include "linked_list.hpp"

LinkedList::LinkedList()
: m_head(&m_tail)
, m_tail(m_head, m_head, 0)
, m_num_of_nods(0)
{

}

LinkedList::LinkedList(std::vector<int> numbers)
: m_head(&m_tail)
, m_tail(m_head, m_head, 0)
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
    m_head = new Node(&m_tail, &m_tail, data);
    m_tail.previous(m_head);
    ++m_num_of_nods;
}

void LinkedList::push_head(int data)
{
    if(is_list_empty())
    {
        push_empty_list(data);
        return;
    }

    Node* new_node = new Node(m_head, &m_tail, data);
    m_head->previous(new_node);
    m_head = new_node;
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
    m_tail.previous()->next(new_node) ;
    m_tail.previous(new_node);
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
        throw std::runtime_error("ERROR: empty list!");

    Node* deleted_node = m_head;
    int deleted_node_data = deleted_node->data();
    m_head = m_head->next();
    m_head->previous(&m_tail);
    delete_node(deleted_node);
    return deleted_node_data;
}

void LinkedList::check_if_one_node_case(Node* deleted_node)
{
    if(deleted_node->previous() != &m_tail)
        deleted_node->previous()->next(&m_tail);
    else
        m_head = &m_tail;
}

int LinkedList::pop_tail()
{
    if(is_list_empty())
        throw std::runtime_error("ERROR: empty list!");

    Node* deleted_node = m_tail.previous();
    int deleted_node_data = deleted_node->data();
    m_tail.previous(deleted_node->previous());
    check_if_one_node_case(deleted_node);
    delete_node(deleted_node);
    return deleted_node_data;
}

int LinkedList::head_data() const
{
    if(is_list_empty())
        throw std::runtime_error("ERROR: empty list!");

    return m_head->data();
}

int LinkedList::tail_data() const
{
    if(is_list_empty())
        throw std::runtime_error("ERROR: empty list!");

    return m_tail.previous()->data();
}

int LinkedList::size() const
{
    return m_num_of_nods;
}

Iterator LinkedList::start() 
{
    if(is_list_empty())
        throw std::runtime_error("ERROR: empty list!");

    return Iterator(m_head);

}

Iterator LinkedList::end()
{
    if(is_list_empty())
        throw std::runtime_error("ERROR: empty list!");

    return Iterator(&m_tail);
}

void LinkedList::clear()
{
    while(!is_list_empty())
        pop_head();
}

void LinkedList::print() const 
{
    std::cout << "[";

    Node* node = m_head;
    while(node != &m_tail)
    {
        std::cout << node->data();
        
        node = node->next();
        if(node != &m_tail)
            std::cout << ", ";
    }

    std::cout << "]" << std::endl;
}
