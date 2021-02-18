//
//  greedy.cpp
//  Practice
//
//  Created by Dexter's Lab on 2/17/21.
//
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

typedef pair<int,int>  iPair ;

//======================================================================//
//INPUT
//    vector<iPair>activity = {{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}};
//    vector<iPair>Ans = activitySelection(activity);
//    for(int i =0 ;i < Ans.size(); i++){
//        cout << Ans[i].first << " " << Ans[i].second << endl;
//    }


struct comp{
    bool operator()(const iPair& a, const iPair& b){
        return (a.second == b.second) ?  a.first < b.first : a.second < b.second;
    }
};

vector<iPair> activitySelection(vector<iPair>& activity){
    vector<iPair>ans;
    int startTime = 0;
    int endTime = 0;
    sort(activity.begin(), activity.end(), comp());
    for(int i = 0;i < activity.size(); i++){
        if(activity[i].first > endTime){
            startTime = activity[i].first;
            endTime = activity[i].second;
            ans.push_back(activity[i]);
        }
    }
    
    return ans;
}


//======================================================================//
// __MAIN__
void run_greedy()
{
   
}

