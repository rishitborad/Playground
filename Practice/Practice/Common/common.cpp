//
//  common.cpp
//  Practice
//
//  Created by Dexter's Lab on 11/19/20.
//

#include "common.hpp"

using namespace std;

template<typename T>
void common_print_1D_vector(vector<T> in)
{
    for(int i = 0; i < in.size(); i++){
        cout << in[i] << "\t";
    }
}

template void common_print_1D_vector<int>(vector<int> input);


template<typename T>
void common_print_2D_vector(vector<vector<T>> in)
{
    for(int i = 0; i < in.size(); i++){
        for(int j = 0; j < in[i].size(); j++){
            cout << in[i][j] << "\t";
        }
        cout << endl;
    }
}

template void common_print_2D_vector<int>(vector<vector<int>> input);




template<typename T>
void common_swap(T *item1, T *item2){
    T temp = *item1;
    *item1 = *item2;
    *item2 =  temp;
}
template void common_swap<int>(int* item1, int* item2);
template void common_swap<unsigned int>(unsigned * item1, unsigned int* item2);
