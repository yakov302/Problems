
#include "test.hpp"
#include "merge_k_sorted_lists.hpp"

#define N 500
#define NUM_OF_LISTS 10000

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    LinkedList answer;
    std::vector<LinkedList*> vector;

    make_vector_of_lists(N, NUM_OF_LISTS, vector);
    merge_lists(vector, answer);
    validate(answer, NUM_OF_LISTS, N);

    free_lists(vector);
    return 0;
}
