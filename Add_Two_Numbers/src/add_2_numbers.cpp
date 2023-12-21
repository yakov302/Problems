#include "add_2_numbers.hpp"

static bool valid_value(int val)
{
    return (val >=0 && val <= 9);
}

static bool check_rules(const LinkedList& list)
{
    if(list.size() > 100 || list.size() < 1)
    {
        std::cout << "Violation of Rule 1: The number of nodes in each linked list is in the range [1, 100]" << std::endl;
        return false;
    }

    int const size = list.size();
    Node* node = list.head_node();
    for(int i = 0; i < size; ++i)
    {
        if(!valid_value(node->data()))
        {
            std::cout << "Violation of Rule 2: 0 <= Node.val <= 9" << std::endl;
            return false;
        }

        node = node->next();
    }

    if(list.tail() <= 0 && list.size() > 1)
    {
        std::cout << "Violation of Rule 3: It is guaranteed that the list represents a number that does not have leading zeros." << std::endl;
        return false;
    }

    return true;
}

static int single_sum(int first, int second, int& remainder)
{
    int sum = first + second + remainder;
    if(sum > 9)
    {
        remainder = 1;
        return sum%10;
    }
    
    remainder = 0;
    return sum;
}

static void handle_tail(Node* node, int& remainder, LinkedList& answer)
{
    while(node->next() != nullptr)
    {
        answer.push_tail(single_sum(node->data(), 0, remainder));
        node = node->next();
    }
}

void add_two_numbers(const LinkedList& first, const LinkedList& second, LinkedList& answer)
{
    if(!check_rules(first) || !check_rules(second))
        return;

    answer.clear();

    int remainder = 0;
    Node* node_f = first.head_node();
    Node* node_s = second.head_node();
    while(node_f->next() != nullptr && node_s->next() != nullptr)
    {
        answer.push_tail(single_sum(node_f->data(), node_s->data(), remainder));
        node_f = node_f->next();
        node_s = node_s->next();
    }

    handle_tail(node_f, remainder, answer);
    handle_tail(node_s, remainder, answer);

    if(remainder != 0)
        answer.push_tail(remainder);
}