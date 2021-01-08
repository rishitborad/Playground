//
//  common.hpp
//  Practice
//
//  Created by Dexter's Lab on 11/19/20.
//

#ifndef common_hpp
#define common_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void common_print_2D_vector(vector<vector<T>> in);

template<typename T>
void common_print_1D_vector(vector<T> in);

template<typename T>
void common_swap(T *item1, T *item2);

#endif /* common_hpp */
