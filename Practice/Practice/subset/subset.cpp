//
//  subset.cpp
//  Practice
//
//  Created by Dexter's Lab on 11/19/20.
//

#include <stdio.h>
#include <vector>
#include "common.hpp"

using namespace std;

void findAllSubsets(vector<int> input, vector<vector<int>>& subsets){
    // Add empty subset
    subsets.push_back(vector<int>());
    
    for(int i = 0; i < (int)input.size(); i++)
    {
        int n = (int)subsets.size();
        for(int j = 0; j < n; j++){
            vector<int>set(subsets[j]);
            set.push_back(input[i]);
            subsets.push_back(set);
        }
    }
}



// __MAIN__
void run_subset()
{
    vector<int> set = {1,2,3,4};
    vector<vector<int>>subset;
    findAllSubsets(set, subset);
    common_print_2D_vector(subset);
}
