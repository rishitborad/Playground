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
#include <queue>
#include <set>
#include <stack>
#include "common.hpp"

using namespace std;
#define MAX(A,B) ((A>B)? (A) : (B))
#define MIN(A,B) ((A<B)? (A) : (B))

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
// TechieDelight
//INPUT:
//  vector<vector<int>> matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
//  printSpiralMatrix(matrix);

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

//======================================================================//
// TechieDelight
// INPUT:
//      vector<vector<int>> M(5);
//      for (int i = 0; i < 5; ++i)
//          M[i].resize(4);
//
//      vector<int> data = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
//      createSpiralMatrix(M,data,5,4);
//      for(int i = 0; i < (int)M.size(); i++){
//          for(int j = 0; j < (int)M[0].size(); j++){
//              printf("%d\t",M[i][j]);
//          }
//          printf("\r\n");
//      }
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
// TechieDelight
// Shift all matrix by one element to the right
// INTPUT:
//      vector<vector<int>>matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
//      common_print_2D_vector(matrix);
//      printf("\r\n");
//      shiftElementsSpiralOrder(matrix);
//      common_print_2D_vector(matrix);
void shiftElementsSpiralOrder(vector<vector<int>>&M){
    int left = 0;
    int right = (int)M[0].size()-1;
    int top = 0;
    int bottom = (int)M.size()-1;
    int temp = M[0][0];
    
    while(1){
        
        if(left > right){
            break;
        }
        for(int i = left; i < right; i++){
            common_swap(&temp, &M[top][i+1]);
        }
        top++;
        common_swap(&M[top][right], &temp);
        
        
        if(top > bottom){
            break;
        }
        for(int i = top; i < bottom; i++){
            common_swap(&temp, &M[i+1][right]);
        }
        right--;
        common_swap(&temp, &M[bottom][right]);
        
        if(left > right){
            break;
        }
        for(int i = right; i > left; i--){
            common_swap(&temp, &M[bottom][i-1]);
        }
        bottom--;
        common_swap(&temp, &M[bottom][left]);
        
        if(bottom < top){
            break;
        }
        for(int i = bottom; i > top; i--){
            common_swap(&temp, &M[i-1][left]);
        }
        left++;
        common_swap(&temp, &M[top][left]);
    }
    common_swap(&temp, &M[bottom][left]);
    M[0][0] = temp;
}
//======================================================================//
/*
void findShortestPathToEnd(vector<vector<int>> matrix, int i, int j, vector<pair<int,int>>&log){
    static int steps = INT_MAX;
    int curr = matrix[i][j];
    int maxRow = (int) matrix.size()-1;
    int maxCol = (int) matrix[0].size()-1;
    
    if(i == maxRow && j == maxCol){
        steps = min(steps, (int)log.size());
        return;
    }else{
        if(i+curr <= maxCol){  // Go right
            log.push_back({i+curr,j});
            findShortestPathToEnd(matrix, i+curr, j, log);
            log.pop_back();
        }
        if(i-curr >= 0){        // Go left
            log.push_back({i-curr,j});
            findShortestPathToEnd(matrix, i-curr, j, log);
            log.pop_back();
        }
        if(j+curr <= maxRow){   // Go down
            log.push_back({i,j+curr});
            findShortestPathToEnd(matrix, i, j+curr, log);
            log.pop_back();
        }
        if(j-curr >= 0){        // Go up
            log.push_back({i,j-curr});
            findShortestPathToEnd(matrix, i, j-curr, log);
            log.pop_back();
        }
    }
}
*/

// This doesnt work, there is a problem in finding element from the Set. Gives true even if element is not in the set.
//INPUT:
//    vector<pair<int,int>>answer;
//    vector<vector<int>> matrix = {
//        {7,1,3,5,3,6,1,1,7,5},
//        {2,3,6,1,1,6,6,6,1,2},
//        {6,1,7,2,1,4,7,6,6,2},
//        {6,6,7,1,3,3,5,1,3,4},
//        {5,5,6,1,5,4,6,1,7,4},
//        {3,5,5,2,7,5,3,4,3,6},
//        {4,1,4,3,6,4,5,3,2,6},
//        {4,4,1,7,4,3,3,1,4,2},
//        {4,4,5,1,5,2,3,5,3,5},
//        {3,6,3,5,2,2,6,4,2,1}
//    };
//    shortestPath s;
//
//    printf("Path len %d\r\n", s.findShortestPath(matrix,0,0));

typedef struct node{
    int x;
    int y;
    vector<node> parents;
    
    // These operator ovelrloading is need to allow node to be added to set. It requires this to perform set operations.
//    bool const operator==(const node& ob) const{
//        return x == ob.x && y == ob.y;
//    }
    bool operator<(const node& ob)const{
        return x < ob.x || (x < ob.x && y < ob.y);
    }
}NODE_t;

void printSet(set<NODE_t> visited){
    for(auto i = visited.begin(); i != visited.end(); i++){
        printf("Set: %d %d\r\n", i->x, i->y);
    }
}

class shortestPath{
private:
    bool isValidPath(vector<vector<int>>matrix, int i, int j){
        if((i < (int)matrix.size() && i >=0) && j < (int)matrix[0].size() && j >= 0)
            return true;
        return false;
    }
    
    int printNodes(NODE_t node){
        
        if(node.parents.size() == 0)
            return 0;
        printf("(%d %d)-->",node.x, node.y);
        int len = printNodes(node.parents[0])+1;
        return len;
        
    }

    int shortestPathBFS(vector<vector<int>>matrix, int x, int y){
        NODE_t node = {x,y};
        set<NODE_t> visited;
        visited.insert(node);
        q.push(node);
        
        while(!q.empty()){
            
            NODE_t curr = q.front();
            printf("curr %d %d\t", curr.x, curr.y);
            q.pop();
            if(curr.x == (int)matrix.size()-1 && curr.y == (int)matrix[0].size()-1){
                printf("Found end");
                return printNodes(curr)-1;
            }
            
            int curr_step = matrix[curr.x][curr.y];
            printf("CurrStep %d\t",curr_step);
            for(int i = 0 ; i < (int)direction[0].size(); i++){
                printSet(visited);
                int x_dir = node.x + direction[0][i] * curr_step;
                int y_dir = node.y + direction[1][i] * curr_step;
                printf("xdir %d ydir%d\r\n", x_dir, y_dir);
                if(isValidPath(matrix, x_dir, y_dir)){
                    printf("Valid\r\n");
                    NODE_t newNode = {x_dir,y_dir,{curr}};
                    if(visited.find(newNode) == visited.end()){
                        printf("Pushed\r\n");
                        visited.insert(newNode);
                        q.push(newNode);
                    }
                    else{
                        printf("NotPushed\r\n");
                    }
                }
            }
        }
        return 0;
    }

    vector<vector<int>> direction = {{-1,0,0,1},{0,-1,1,0}};
    queue<NODE_t> q;
    
    
public:
    int findShortestPath(vector<vector<int>>matrix, int i, int j){
        return shortestPathBFS(matrix, i,j);
    }
};

//======================================================================//
//TechieDelight: Change all elements of row i and column j in a matrix to 0 if cell (i, j) has value 0
//INPUT:
//    int mat[5][5] =
//        {
//            { 1, 1, 0, 1, 1 },
//            { 1, 1, 1, 1, 1 },
//            { 1, 1, 0, 1, 1 },
//            { 1, 1, 1, 1, 1 },
//            { 0, 1, 1, 1, 1 }
//        };
//    convert(mat);
//    for(int i = 0; i < 5; i++){
//        for(int j = 0 ; j < 5; j++){
//            printf("%d ", mat[i][j]);
//        }
//        printf("\r\n");
//    }
// Function to convert the matrix
void convert(int mat[5][5]){
    bool rowZero = false;
    bool colZero = false;
    for(int i = 0; i < 5; i++){
        if(mat[i][0]==0){
            rowZero = true;
        }
        if(mat[0][i]== 0){
            colZero = true;
        }
    }
    
    // Set first row and col of corresponding 0 element to 0
    for(int i = 1; i < 5; i++){
        for(int j = 1; j < 5; j++){
            if(!mat[i][j]){
                mat[i][0] = mat[0][j] = 0;
            }
        }
    }
    
    // Based on first col and row, set all the element in row and cols to 0 where associated row or col value is 0
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(mat[i][0] == 0 || mat[0][j] == 0){
                mat[i][j] = 0;
            }
        }
    }
    
    for(int i = 0; i < 5; i++){
        if(rowZero){
            mat[0][i] = 0;
        }
        if(colZero){
            mat[i][0] = 0;
        }
    }
}

//======================================================================//
//695. Max Area of Island
//vector<vector<int>> geography = {   {1,0,0,0,1,1},
//                                    {0,0,1,0,1,0},
//                                    {0,1,1,0,1,1},
//                                    {0,1,0,1,0,1},
//                                    {0,0,0,1,1,1},
//                                    {1,1,1,0,0,0}
//                                };
//printf("Max Area of island is %d\r\n", maxAreaOfIsland(geography));
int maxAreaOfIslandUtil(vector<vector<int>>& grid, int i, int j){
    int island = 0;
    if(grid[i][j] == 1){
        grid[i][j] = -1;
        island++;
        if(i < grid.size()-1 && grid[i+1][j] == 1){
            island += maxAreaOfIslandUtil(grid, i+1, j);
        }

        if(j < grid[i].size()-1 && grid[i][j+1] == 1){
            island += maxAreaOfIslandUtil(grid, i, j+1);
        }

        if(i > 0 && grid[i-1][j] == 1){
            island += maxAreaOfIslandUtil(grid, i-1, j);
        }

        if(j > 0 && grid[i][j-1] == 1){
            island += maxAreaOfIslandUtil(grid, i, j-1);
        }
        printf("island %d %d %d\r\n", i, j ,island);
    }
    return island;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max = 0;
    for(int i = 0; i < (int)grid.size(); i++){
        for(int j = 0; j < (int)grid[i].size(); j++){
            int island = maxAreaOfIslandUtil(grid, i, j);
            max = MAX(max, island);
        }
    }
    return max;
}

//======================================================================//
//Some Good Advanced problems with simalr logic in Matrix here: https://leetcode.com/problems/count-submatrices-with-all-ones/discuss/722594/C%2B%2B-Solution-Similar-types-of-questions-included-along-with-solution.


//84. Largest Rectangle in Histogram
// INPUT:
//    vector<int>histeresis = {2,1,5,6,2,3};
//    printf("Largest Area = %d\r\n", largestRectangleAreaBinarySearch(histeresis, 0 , (int)histeresis.size()-1));
int largestRectangleAreaBinarySearch(vector<int>& heights, int start, int end) {
    if(start>end)
        return 0;
    int minidx = start;
    for(int i = start; i <= end; i++)
        if(heights[minidx] > heights[i])
            minidx = i;
    return MAX(heights[minidx]*(end-start+1), MAX(largestRectangleAreaBinarySearch(heights, start, minidx-1), largestRectangleAreaBinarySearch(heights, minidx+1, end)));
}
//======================================================================//
//84. Largest Rectangle in Histogram
//https://leetcode.com/problems/largest-rectangle-in-histogram/solution/
//Here is a good intuitive explination
//https://leetcode.com/problems/largest-rectangle-in-histogram/solution/245709
//Good problem, worth looking at the stack implementation

int largestRectangleAreaStack(vector<int>& heights) {

    int maxSize = 0;
    int top_idx = -1;
    stack<int>stk;      // Stack of indexes
    
    stk.push(top_idx);       // Base index pushed in stack

    for(int i = 0; i < (int)heights.size(); i++){
        top_idx = stk.top();
        int curr_ele = heights[i];
        
        // Push elements to the stack that are higher than the stack top
        // This means that next smaller element to the left of current element is current-1
        // Use this knowledge to process the elements below. Take the height of smaller element
        if(top_idx == -1 || curr_ele > heights[top_idx]){
            stk.push(i);
        }
        else{
            // Process elements from stack because we have a right side of small element(R)
            // Exapand from i towards left to figure out maxArea for each elemnet greater than than R
            // Calculate max area for each element when trying to find the L
            while(top_idx != -1 && curr_ele < heights[top_idx]){
                stk.pop();
                int poped_ele = heights[top_idx];           // Heighest element in the stack
                top_idx = stk.top();                        // Next smaller element in stack to the left
                maxSize = MAX(maxSize, poped_ele * (i-top_idx-1));
            }
            stk.push(i);
        }
    }
    top_idx = stk.top();
    // Remove element until stack is empty
    while(top_idx != -1){
        stk.pop();
        int poped_ele = heights[top_idx];           // Heighest element in the stack
        top_idx = stk.top();                        // Next smaller element in stack to the left
        
        // Because stack now contains small elements in decresing order
        // Take area between top-1 (next top in stack) index and end of array by multiplying it with array[top]
        maxSize = MAX(maxSize, poped_ele * ((int)heights.size()-top_idx-1));
    }
    return maxSize;
}


//======================================================================//

// __MAIN__
void run_leetcode1()
{
    vector<int>histeresis = {2,5,5,6,2,3};
    printf("Largest Area = %d\r\n", largestRectangleAreaStack(histeresis));
}
