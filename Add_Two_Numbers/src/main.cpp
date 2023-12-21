#include "add_2_numbers.hpp"

int main()
{
    LinkedList answer;

    std::cout << std::endl << "Example 1: " << std::endl << "Input: l1 = [2,4,3], l2 = [5,6,4]" <<  std::endl << "Output: ";
    LinkedList first_1({3,4,2});
    LinkedList second_1({4,6,5});
    add_two_numbers(first_1, second_1, answer);
    answer.print();

    std::cout << std::endl << "Example 2: " << std::endl << "Input: l1 = [0], l2 = [0]" << std::endl << "Output: ";
    LinkedList first_2({0});
    LinkedList second_2({0});
    add_two_numbers(first_2, second_2, answer);
    answer.print();

    std::cout << std::endl << "Example 3: " << std::endl << "Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]" << std::endl << "Output: ";
    LinkedList first_3({9,9,9,9,9,9,9});
    LinkedList second_3({9,9,9,9});
    add_two_numbers(first_3, second_3, answer);
    answer.print();
    
    return 0;
}
