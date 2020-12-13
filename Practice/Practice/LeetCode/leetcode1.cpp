//
//  leetcode1.cpp
//  Practice
//
//  Created by Dexter's Lab on 11/30/20.
//

#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "common.hpp"

using namespace std;

//======================================================================//

//690. Employee Importance
//Input:
//    Employee a(1, 5, {2,3});
//    Employee b(2, 3, {});
//    Employee c(3, 3, {});
//    Employee d(4, 5, {});
//    vector<Employee*> employee_data;
//    employee_data.push_back(&a);
//    employee_data.push_back(&b);
//    employee_data.push_back(&c);
//    employee_data.push_back(&d);
//    Solution s;
//    printf("Importance of employee 1 is %d\r\n", s.getImportance(employee_data, 1));

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
    Employee();
    Employee(int id, int imp, vector<int>subO)
    : id(id)
    , importance(imp)
    , subordinates(subO){
        
    }
};

class Solution {
public:
    int getImportance(vector<Employee*> emp, int id) {

        int i = 0;
        int weight = 0;
        
        while(i < emp.size()){
            if(emp[i]->id == id){
                for(int j = 0; j < emp[i]->subordinates.size(); j++){
                    weight += getImportance(emp, emp[i]->subordinates[j]);
                }
                return weight + emp[i]->importance;
            }
            i++;
        }
        return 0;
    }
};

//======================================================================//

//169. Majority Element
//Input:
//    vector<int> vec = {1,2,2,1,2,1,1};
//    printf("MajorityElement is %d\r\n", majorityElement(vec));
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int mid = (int)nums.size()/2;
    return nums[mid];
}

//======================================================================//
//1277. Count Square Submatrices with All Ones
//INPUT:
//    vector<vector<int>> matrix = {{1,0,1},{1,1,0},{1,1,0}};
//    vector<vector<int>> matrix = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
//    printf("Number of subSquareMatrix is %d \r\n", countSquares(matrix));

int countSubMatrix(vector<vector<int>>& matrix, int i, int j, int size){
    printf("Processing arr[%d][%d] = %d for size %d\r\n", i, j , matrix[i][j], size);
    for(int k = i; k < i+size; k++){
        for(int l = j; l < j+size; l++){
            if(matrix[k][l] != 1){
                return 0;
            }
        }
    }
    printf("PASSED arr[%d][%d] = %d for size %d\r\n", i, j , matrix[i][j], size);
    return  1;
}

int countSquares(vector<vector<int>>& matrix) {
    int count = 0;
    int maxRows = (int)matrix.size();
    int maxCols = (int)matrix[0].size();
    printf("%d %d\r\n", maxRows, maxCols);
    for(int i = 0; i < maxRows; i++){
        for(int j = 0; j < maxCols; j++){
            if(matrix[i][j] == 1){
                printf("min is %d\r\n", min(maxRows-i, maxCols-j));
                for(int k = 1 ; k < min(maxRows-i, maxCols-j)+1; k++){
                    count += countSubMatrix(matrix, i, j, k);
                }
            }
        }
    }
    return count;
}
//======================================================================//

void printSpiralMatrix(vector<vector<int>>& matrix){

    int left = 0;
    int right = (int)matrix[0].size()-1;
    int top = 0;
    int bottom = (int)matrix.size()-1;

    while(1){

        if(left > right)
            break;
        for(int i = left; i <= right; i++){
            printf("%d ",matrix[top][i]);
        }
        top++;

        if(top > bottom)
            break;

        for(int i = top; i <= bottom; i++){
            printf("%d ",matrix[i][right]);
        }
        right--;

        if(right < left)
            break;

        for(int i = right; i >= left; i--){
            printf("%d ", matrix[bottom][i]);
        }
        bottom--;

        if(bottom < top)
            break;

        for(int i = bottom; i >= top; i--){
            printf("%d ",matrix[i][left]);
        }
        left++;
    }
    printf("\r\n");
}


void createSpiralMatrix(vector<vector<int>>&matrix, vector<int>data, int M, int N){
  int left = 0;
  int right = N-1;
  int top = 0;
  int bottom = M-1;
  int idx = 0;

  while(1){

    if(left > right)
      break;
    for(int i = left; i <= right; i++){
      matrix[top][i] = data[idx++];
    }
    top++;

    if(top > bottom)
      break;

    for(int i = top; i <= bottom; i++){

      matrix[i][right] = data[idx++];
    }
    right--;

    if(right < left)
      break;

    for(int i = right; i >= left; i--){
      matrix[bottom][i] = data[idx++];
        printf("\r\n3: %d %d data[%d] %d\r\n", bottom, i, idx, data[idx]);
    }
    bottom--;
    if(bottom < top)
      break;

    for(int i = bottom; i >= top; i--){
        printf("\r\n4: %d %d data[%d] %d\r\n", i, left, idx, data[idx]);
      matrix[i][left] = data[idx++];
    }
    left++;
  }
}

//======================================================================//
//======================================================================//
//======================================================================//

// __MAIN__
void run_leetcode1()
{

    vector<vector<int>> matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    printSpiralMatrix(matrix);

    vector<vector<int>> M(5);
    for (int i = 0; i < 5; ++i)
      M[i].resize(4);

    vector<int> data = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    createSpiralMatrix(M,data,5,4);
    for(int i = 0; i < (int)M.size(); i++){
      for(int j = 0; j < (int)M[0].size(); j++){
        printf("%d\t",M[i][j]);
      }
      printf("\r\n");
    }

}
