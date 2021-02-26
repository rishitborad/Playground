//
//  dynamicProgramming.cpp
//  Practice
//
//  Created by Dexter's Lab on 2/17/21.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include "common.hpp"

using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))

//======================================================================//
//Longest Common Subsequence Problem
//vector<char> arr1 = {'A', 'B', 'C', 'D'};
//vector<char> arr2 = {'C', 'A', 'B', 'D'};
//LongestCommonSubseq lcs(arr1,arr2);
//cout << lcs.LongestCommonSubSequence()<< endl;
class LongestCommonSubseq{
private:
    vector<char>arr1;
    vector<char>arr2;
    
    int LCS_util(int i, int j, vector<vector<int>>&dp){
        if(i >= arr1.size() || j >= arr2.size()){
            dp[i][j] = 0;
            return 0;
        }
        if(dp[i][j] != 0){
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
        vector<vector<int>> dp(arr1.size()+1, vector<int>(arr2.size()+1, 0));
        int ans =  LCS_util(0,0,dp);
//        common_print_2D_vector(dp);
        return ans;
    }
    
    int longestCommonSubsequence(){
        int maxLen = 0;
        vector<vector<int>> dp(arr1.size()+1, vector<int> (arr2.size()+1, 0));
        
        for(int i = 1; i <= arr1.size(); i++){
            for(int j = 1; j <= arr2.size(); j++){
                if(arr1[i-1] == arr2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
                }
                maxLen = MAX(maxLen,dp[i][j]);
            }
        }
        common_print_2D_vector(dp);
        return maxLen;
    }
};

//======================================================================//
//INPUT:
//    cout << "LCS"<<endl;
//    cout << longestCommonSubstring("ABCCA", "BCA") << endl;
int longestCommonSubstring(string s1, string s2){
    int maxLen = 0;
    vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1, 0));
    
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                maxLen = MAX(maxLen,dp[i][j]);
            }
        }
    }
    
    return maxLen;
}

//======================================================================//
//cout << longestPalindromicSubString("ABBDCACB") << endl;
int longestPalindromicSubString(string s){
    vector<vector<int>>dp(s.size()+1, vector<int>(s.size()+1, 0));
    int max = 0;
    int n = (int)s.size();
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= s.size(); j++){
            if(s[i-1] == s[n-j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = MAX(dp[i-1][j],dp[i][j-1]);
            }
            max = MAX(dp[i][j],max);
        }
    }
    
//    common_print_2D_vector(dp);
    return max;
}

//======================================================================//
//INPUT
//    vector<string>ans = diffChecker("Rishit", "BoradRishit");
//    for(int i= 0 ;i < (int)ans.size(); i++){
//        cout << ans[i];
//    }

void diffCheckerUtil(string s1, string s2, int i, int j, vector<string>&ans){
    int s1len = (int)s1.size();
    int s2len = (int)s2.size();
//    cout << i << j<<endl;
    if(i >= s1len && j >= s2len ){
        return;
    }
    
    if(s1[i] == s2[j]){
        ans.push_back(s1.substr(i,1));
        return diffCheckerUtil(s1, s2, i+1, j+1, ans);
    }
    if(s1[i+1] == s2[j]){
        ans.push_back("-"+s1.substr(i,1));
        ans.push_back(s2.substr(j,1));
        return diffCheckerUtil(s1, s2, i+2, j+1, ans);
    }else{
        ans.push_back("+"+s2.substr(j,1));
        return diffCheckerUtil(s1, s2, i, j+1, ans);
    }
}

void diffCheckerUtil2(string s1, string s2, int i, int j, vector<string>&ans){
    if(i >= (int)s1.size() || j >= (int)s2.size()){
        return;
    }
    if(s1[i] == s2[i]){
        ans.push_back(s1.substr(i,1));
        diffCheckerUtil2(s1, s2, i+1, j+1, ans);
    }
    diffCheckerUtil2(s1, s2, i, j+1, ans);
    diffCheckerUtil2(s1, s2, i+1, j, ans);
}

vector<string> diffChecker(string s1, string s2){
    vector<string>ans;
    
    // Building up on LCSubsequence problem DP solution
    diffCheckerUtil2(s1, s2, 0, 0, ans);
    
    // Recursive Approach
    diffCheckerUtil(s1, s2, 0, 0, ans);
    
    // iterative Approach
    /*vector<string>ans;
    int s1len = (int)s1.size();
    int s2len = (int)s2.size();
    int i = 0, j = 0;
    while (i < s1len && j < s2len) {
        if(s1[i] == s2[j]){
            ans.push_back(s1.substr(i,1));
            i++;
            j++;
        }else{
            if(s1[i+1] == s2[j]){
                ans.push_back("-"+s1.substr(i,1));
                ans.push_back(s2.substr(j,1));
                i += 2;
                j++;
            }else{
                ans.push_back("+"+s2.substr(j,1));
                j++;
            }
        }
    }
    */
    return ans;
}
//======================================================================//
//cout << SCSLength_topDown("ABCBDAB", "BDCABA", 7, 6)<< endl;
//cout << SCSLength_bottomUp("ABCBDAB", "BDCABA", 7, 6)<< endl;

// Find shortest common subsequence
int SCSLength_topDown_util(string X, string Y, int m, int n, vector<vector<int>>&dp){
    if(m == 0 || n == 0){
        return m+n;
    }
    if(dp[m][n] != 0){
        return dp[m][n];
    }
    if(X[m-1] == Y[n-1]){
        dp[m][n] = SCSLength_topDown_util(X, Y, m-1, n-1, dp)+1;
    }else{
        dp[m][n] = MIN(SCSLength_topDown_util(X, Y, m-1, n, dp)+1, SCSLength_topDown_util(X, Y, m, n-1, dp)+1) ;
    }
    return dp[m][n];
}
int SCSLength_topDown(string X, string Y, int m, int n){
    vector<vector<int>>dp(X.size()+1, vector<int>(Y.size(),0));
    return SCSLength_topDown_util(X, Y, m, n, dp);
}

int SCSLength_bottomUp(string X, string Y, int m, int n){
    vector<vector<int>>dp(X.size()+1, vector<int>(Y.size()+1,0));
    int max = 0;
    for(int i = 1; i <= (int)X.size(); i++){
        dp[i][0] = i;
    }
    for(int j = 1; j <= (int)Y.size(); j++){
        dp[0][j] = j;
    }
    for(int i = 1; i <= (int)X.size(); i++){
        for(int j = 1; j <= (int)Y.size(); j++){
            if(X[i-1] == Y[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = MIN(dp[i-1][j]+1,dp[i][j-1]+1);
            }
            max = MAX(max,dp[i][j]);
        }
    }
    return max;
}

//======================================================================//

int maximumValueContiguousSubseq(vector<int> arr){
    vector<int>dp(arr.size()+1,-1);
    int sumsofar = 0;
    int sumMax = INT_MIN;
    
    for(int i = 0; i < arr.size(); i++){
        sumsofar += arr[i];
        sumMax = MAX(sumsofar, sumMax);
        if(sumsofar < 0){
            sumsofar = 0;
        }
    }
    
    return sumMax;
}

//======================================================================//

// __MAIN__
void run_dp()
{
    vector<int> arr = {2,-1,4,-4};
    cout << maximumValueContiguousSubseq(arr) << endl;
}
