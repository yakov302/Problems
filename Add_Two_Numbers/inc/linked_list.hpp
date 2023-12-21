#pragma once

#include <vector>
#include <iostream>

#include "node.hpp"

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

    int head() const;
    int tail() const;
    int size() const;
    
    Node* head_node() const;
    Node* tail_node() const;
    
    void clear();
    void print() const;

private:
    bool is_list_empty() const;
    void delete_node(Node* node);
    void push_empty_list(int data);

private:
    Node m_head;
    Node m_tail;
    int m_num_of_nods;
};