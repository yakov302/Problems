# pragma once

#include <ctime> 
#include <cstdlib> 
#include <iostream>

#include "merge_k_sorted_lists.hpp"

void validate(LinkedList& answer, int num_of_list, int n);

void make_vector_of_lists(int n, int num_of_lists, std::vector<LinkedList*>& vector);


