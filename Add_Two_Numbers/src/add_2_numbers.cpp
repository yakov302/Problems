#include "add_2_numbers.hpp"

static bool valid_value(int val)
{
    return (val >=0 && val <= 9);
}

static bool check_rules(LinkedList& list)
{
    if(list.size() > 100 || list.size() < 1)
    {
        std::cout << "Violation of Rule 1: The number of nodes in each linked list is in the range [1, 100]" << std::endl;
        return false;
    }

    Iterator it = list.start();
    while(it != list.end())
    {
        if(!valid_value(it.data()))
        {
            std::cout << "Violation of Rule 2: 0 <= Node.val <= 9" << std::endl;
            return false;
        }

        ++it;
    }

    if(list.tail_data() <= 0 && list.size() > 1)
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

static void handle_tail(Iterator& it, Iterator end, int& remainder, LinkedList& answer)
{
    while(it != end)
    {
        answer.push_tail(single_sum(it.data(), 0, remainder));
        ++it;
    }
}

void add_two_numbers(LinkedList& first, LinkedList& second, LinkedList& answer)
{
    if(!check_rules(first) || !check_rules(second))
        return;

    answer.clear();

    int remainder = 0;
    Iterator it_f = first.start();
    Iterator it_s = second.start();
    while(it_f != first.end() && it_s != second.end())
    {   
        answer.push_tail(single_sum(it_f.data(), it_s.data(), remainder));
        ++it_f;
        ++it_s;
    }

    handle_tail(it_f, first.end(), remainder, answer);
    handle_tail(it_s, second.end(), remainder, answer);

    if(remainder != 0)
        answer.push_tail(remainder);
}