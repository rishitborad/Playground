//
//  common.cpp
//  Practice
//
//  Created by Dexter's Lab on 11/19/20.
//

#include "common.hpp"

using namespace std;

template<typename T>
void common_print_2D_vector(vector<vector<T>> in)
{
    for(int i = 0; i < in.size(); i++){
        for(int j = 0; j < in[i].size(); j++){
            cout << in[i][j] << " ";
        }
        cout << endl;
    }
}

template void common_print_2D_vector<int>(vector<vector<int>> input);
