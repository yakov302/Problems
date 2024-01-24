#include "test.hpp"

int get_random_number(int min, int max) 
{
    return min + std::rand() % (max - min + 1);
}

LinkedList* make_list(int n, int max, int min)
{
    LinkedList* list = new LinkedList() ;
    int base = get_random_number(0, 100);
    for(int i = 0; i < n; ++i)
    {
        list->push_tail(base);
        base += get_random_number(0, 10);
        if(base > MAX)
            return nullptr;
    }

    return list;
}

void free_lists(std::vector<LinkedList*>& vector)
{
    const int size = vector.size();
    for(int i = 0; i < size; ++i)
        delete vector[i];
}

void make_vector_of_lists(int n, int num_of_lists, std::vector<LinkedList*>& vector)
{
    vector.reserve(num_of_lists);
    for(int i = 0; i < num_of_lists; ++i)
    {
        LinkedList* list = make_list(n, MAX, -MAX);
        while(list == nullptr)
            list = make_list(n, MAX, -MAX);
        vector.push_back(list);
    }
}

void validate(LinkedList& answer, int num_of_list, int n)
{
    const int size = answer.size();
    if(size != num_of_list*n)
    {
        std::cout << "ERROR: Missing members!!!" << std::endl;
        return;
    }

    Iterator it = answer.start();
    Iterator end = answer.end();
    while(it != end)
    {
        if(it.next().data() < it.data())
        {
            if(it.next() != end)
            {
                std::cout << "ERROR: Not sorted it = " << it.data() << " it.next = " << it.next().data() << "!!!" << std::endl;
                return;
            }
        }
        
        ++it;
    }

    std::cout << "Validate OK!!!" << std::endl;
}
