#pragma once

#include <vector>
#include <iostream>

#include "node.hpp"
#include "iterator.hpp"

class LinkedList
{
public:
    LinkedList();
    LinkedList(std::vector<int> numbers);
    
    ~LinkedList();

    void push_head(int data);
    void push_tail(int data);

    int pop_head();
    int pop_tail();

    int size() const;
    int head_data() const;
    int tail_data() const;
    
    Iterator start();
    Iterator end();
    
    void clear();
    void print() const;

private:
    bool is_list_empty() const;
    void delete_node(Node* node);
    void push_empty_list(int data);
    void check_if_one_node_case(Node* deleted_node);

private:
    Node* m_head;
    Node m_tail;
    int m_num_of_nods;
};