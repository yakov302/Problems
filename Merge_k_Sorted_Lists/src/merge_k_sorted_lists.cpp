#include "merge_k_sorted_lists.hpp"

bool rules(std::vector<LinkedList*>& lists)
{
    const int lists_size = lists.size();
    if(lists_size > MAX)
    {
        std::cout << "Violation of Rule 1: 0 <= k <= 10^4" << std::endl;
        return false;
    }

    int total_sizes = 0;
    for(int i = 0; i < lists_size; ++i)
    {
        int size = lists[i]->size();
        if(size > 500)
        {
            std::cout << "Violation of Rule 2: 0 <= lists[i].length <= 500" << std::endl;
            return false;
        }

        total_sizes += size;
        if(total_sizes > MAX)
        {
            //std::cout << "Violation of Rule 4: The sum of lists[i].length will not exceed 10^4" << std::endl;
            //return false;
        }
    }

    return true;
}

void set_iterators(std::vector<LinkedList*>& lists, std::vector<Iterator>& iterators)
{
    const int size = lists.size();
    iterators.reserve(size);

    for(int i = 0; i < size; ++i)
       iterators.push_back(lists[i]->start());
}

void variables_assignment(int& min_value, std::vector<int>& min_indexes, int& stop_flag, int num_of_lists)
{
    min_indexes.clear();
    min_value = MAX + 1;
    stop_flag = num_of_lists;
}

void push_low_value_to_answer(LinkedList& answer, std::vector<Iterator>& iterators, std::vector<int>& min_indexes, int& min_value, int list_index, bool clear)
{
    answer.push_tail(iterators[list_index].data());
    min_value = iterators[list_index].data();

    if(clear)
        min_indexes.clear();

    min_indexes.push_back(list_index);
    ++iterators[list_index];
}

void delete_previous_low_values(std::vector<int>& min_indexes, std::vector<Iterator>& iterators, LinkedList& answer)
{
    for(size_t i = 0; i < min_indexes.size(); ++i)
    {
        --iterators[min_indexes[i]];
        answer.pop_tail();
    }
}

void value_check(int data)
{
    if(data > MAX || data < -MAX)
    {
        std::cout << "Violation of Rule 3: -10^4 <= lists[i][j] <= 10^4" << std::endl;
        throw std::runtime_error("ERROR: Violation of rules");
    }
}

void merge_lists(std::vector<LinkedList*>& lists, LinkedList& answer)
{
    if(!rules(lists))
        throw std::runtime_error("ERROR: Violation of rules");
    
    int min_value;
    int stop_flag;
    std::vector<int> min_indexes;
    std::vector<Iterator> iterators;

    answer.clear();
    set_iterators(lists, iterators);
    const int num_of_lists = lists.size();
    variables_assignment(min_value, min_indexes, stop_flag, num_of_lists);

    while(stop_flag)//Stop when all lists reached end
    {
        variables_assignment(min_value, min_indexes, stop_flag, num_of_lists);

        for(int i = 0; i < num_of_lists; ++i) //loop for all lists
        {
            if(iterators[i] == lists[i]->end()) //list[i] reach  end
            {
                --stop_flag;
                continue;
            }

            value_check(iterators[i].data());

            if(iterators[i].data() < min_value) //the low value in list[i] up to now
            {
                if(!min_indexes.empty()) //incorrect low value for list[i] was set previously
                    delete_previous_low_values(min_indexes, iterators, answer);
                push_low_value_to_answer(answer, iterators, min_indexes, min_value, i, true);
            }
            else if(iterators[i].data() == min_value) //another identical low value in list[i]
            {
                push_low_value_to_answer(answer, iterators, min_indexes, min_value, i, false);
            }
        }
    }
}

