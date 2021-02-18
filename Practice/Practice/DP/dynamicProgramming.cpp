//
//  dynamicProgramming.cpp
//  Practice
//
//  Created by Dexter's Lab on 2/17/21.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))

//======================================================================//
//Longest Common Subsequence Problem

class LongestCommonSubseq{
private:
    vector<char>arr1;
    vector<char>arr2;
    
    int LCS_util(int i, int j, vector<vector<int>>&dp){
        if(i >= arr1.size() || j >= arr2.size()){
            dp[i][j] = 0;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        if(arr1[i] == arr2[j]){
            dp[i][j] = 1 + LCS_util(i+1, j+1, dp);
        }
        if(arr1[i] != arr2[j]){
            dp[i][j] = MAX(LCS_util(i+1, j, dp),LCS_util(i, j+1, dp));
        }
        return dp[i][j];
    }
public:
    LongestCommonSubseq(){}
    LongestCommonSubseq(vector<char>ar1, vector<char>ar2)
    :arr1(ar1)
    ,arr2(ar2){
        
    }
    int LongestCommonSubSequence(){
        vector<vector<int>> dp(arr1.size()+1, vector<int>(arr2.size()+1, -1));
        return LCS_util(0,0,dp);
    }
};

//======================================================================//
// __MAIN__
void run_dp()
{
    vector<char> arr1 = {'A', 'B', 'C', 'D'};
    vector<char> arr2 = {'C', 'A', 'B', 'D'};
    LongestCommonSubseq lcs(arr1,arr2);
    cout << lcs.LongestCommonSubSequence()<< endl;
}
