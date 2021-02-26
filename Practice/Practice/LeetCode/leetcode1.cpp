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
#include <numeric>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include "common.hpp"
#include "string"

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

// INPUT
//    vector<int>histeresis = {2,5,5,6,2,3};
//    printf("Largest Area = %d\r\n", largestRectangleAreaStack(histeresis));

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
//Input:

//    string s = "aab";
//    vector<vector<string>> answer = palindrom_partitions(s);
//    for(int i = 0; i < answer.size(); i++){
//        for(int j = 0; j < answer[i].size(); j++)
//        {
//            printf("%s ", answer[i][j].c_str());
//        }
//        printf("\r\n");
//    }

bool isPalindrom(string s){
    int start = 0;
    int end = (int)s.length()-1;
    printf("len is %d\r\n", end);
    if(end < 0)
        return false;
    if(end==0){
        return true;
    }
    else{
        while(start <= end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
    }
    return true;
}

void palindrom_partitions_util(string s, int curr, vector<string>&pal, vector<vector<string>>&ans){
    int len = (int)s.length();
    if(curr >= len){
        ans.push_back(pal);
    }
    for(int i = curr; i < len; i++){
        if(isPalindrom(s.substr(curr,i-curr+1))){
            pal.push_back(s.substr(curr,i-curr+1));
            palindrom_partitions_util(s, i+1, pal, ans);
            pal.pop_back();
        }
    }
}

vector<vector<string>> palindrom_partitions(string s) {
    vector<vector<string>>ans;
    vector<string>curr_ans;
    if(isPalindrom(s)){
        vector<string>a;
        a.push_back(s);
        ans.push_back(a);
    }
    palindrom_partitions_util(s, 0, curr_ans, ans);
    return ans;
}

//======================================================================//
//1011. Capacity To Ship Packages Within D Days
// INPUT:
//    vector<int>weights = {1,2,3,4,5,6,7,8,9,10};
//    int shippingDays = 5;
//    vector<int>weights = {3,2,2,4,1,4};
//    int shippingDays = 3;
//    vector<int>weights = {1,2,3,1,1};
//    int shippingDays = 4;
//    printf("A truck that could carry %d load in a day is good fit to transport all the packages in %d days\r\n", shipWithinDays(weights, shippingDays), shippingDays);

bool checkDays(vector<int>& weights, int D, int truck_capacity){
    int currLoad = 0;
    int days = 0;
    for(int i = 0; i < (int)weights.size(); i++){
        currLoad += weights[i];
        
        if(currLoad > truck_capacity){
//            printf("currLoad: %d, truckCap: %d, days %d\r\n", currLoad, truck_capacity, days);
            days++;
            currLoad = weights[i];
            if(days >= D)
                return false;
        }
        else{
//            printf("currLoad: %d, truckCap: %d, days %d\r\n", currLoad, truck_capacity, days);
        }
    }
    return true;
}

int converge(vector<int>& weights, int D, int min_cap, int max_cap){
    printf("Min: %d, Max: %d", min_cap, max_cap);
    if(min_cap >= max_cap){
        // IMPORTANT: max_cap"+1" because min_cap is now more than max_cap, max_cap was reduced by 1 before sending here in recursion, so the right answer is previous value of max_cap
        return max_cap+1;
    }
    int mid = min_cap + ((max_cap - min_cap) / 2);
    printf(" Mid: %d\r\n", mid);
    int load_capacity = 0;
    
    // Check if the truck with 'min_cap' load capacity can carry this load withing 'D' days
    // if truck can carry that much load, try a truck capacity range lower than the current
    // else try a truck capacity higher than the current
    if(checkDays(weights, D, mid)){
        load_capacity = converge(weights, D, min_cap, mid-1);
    }else{
        load_capacity = converge(weights, D, mid+1, max_cap);
    }
    return load_capacity;
}

int shipWithinDays(vector<int>& weights, int D){
    int totalWeight = std::accumulate(weights.begin(), weights.end(), 0);
    int maxWeight = 0 ;
    for(int w : weights){
        maxWeight = MAX(maxWeight, w);
    }
    // maxWeight should be the minimum capacity a truck should carry
    // maximum a truck should carry is total weight
    // but we re finding optimum
    // so use binary search
    return converge(weights, D, maxWeight, totalWeight);
}

//======================================================================//
// INPUT:
    //ListNode* head = new ListNode(-10);
    //head->next = new ListNode(-3);
    //head->next->next = new ListNode(0);
    //head->next->next->next = new ListNode(5);
    //head->next->next->next->next = new ListNode(9);
    //TreeNode* tree_head =sortedListToBST(head);
    //printLevelOrderBT(tree_head);

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLevelOrderBT(TreeNode* head)
{
    if(!head)
        return;
    
    queue<TreeNode*> q;
    q.push(head);
    while(!q.empty())
    {
        TreeNode* frnt = q.front();
        q.pop();
        printf("%d ", frnt->val);
        if(frnt->left != nullptr)
            q.push(frnt->left);
        if(frnt->right != nullptr)
            q.push(frnt->right);
    }
}

ListNode* findMiddle(ListNode* head, ListNode* tail){
    // Send null pointer when head is null as well as when ther is only one node in the list
    if(head == nullptr || head ->next == nullptr || head == tail){
        return nullptr;
    }
    
    if(head->next->next == nullptr){
        return nullptr;
    }
    
    ListNode* curr_slow = head;
    ListNode* curr_fast = head;
    printf("%d\r\n",curr_slow->val);
    while(curr_fast != nullptr && curr_fast->next != nullptr && curr_fast != tail && curr_fast->next != tail){
        curr_fast = curr_fast->next->next;
        curr_slow = curr_slow->next;
    }
    
    return curr_slow;
}

void sortedListToBST_util(TreeNode** root, ListNode* head, ListNode* tail){
    if(head)
        printf("head %d",head->val);
    if(tail)
        printf("tail %d",tail->val);
    printf("\r\n");
    if(head == nullptr){
        root = nullptr;
        return;
    }
    
    ListNode* middle = findMiddle(head, tail);
    
    if(middle == nullptr){
        // If it gets here, it means there is only one node or no node in currnt LL
        // Set that as a root node
//        *root = new TreeNode(head->val);
//        printf("MiddleNull: %d\r\n",head->val);
//        sortedListToBST_util(&(*root)->left, head->next, nullptr);
    }else{
        *root = new TreeNode(middle->val);
        printf("NotNull%d %d\r\n",head->val, middle->val);
        sortedListToBST_util(&(*root)->left, head, middle);
        sortedListToBST_util(&(*root)->right, middle->next, nullptr);
    }
    
    return;
}

TreeNode* sortedListToBST(ListNode* head){
    TreeNode* root;
    sortedListToBST_util(&root, head, nullptr);
    return root;
}

//======================================================================//
//1048. Longest String Chain
//https://leetcode.com/problems/longest-string-chain/discuss/294890/C%2B%2BJavaPython-DP-Solution
//    Explanation
//    Sort the words by word's length. (also can apply bucket sort)
//    For each word, loop on all possible previous word with 1 letter missing.
//    If we have seen this previous word, update the longest chain for the current word.
//    Finally return the longest word chain.
//
//
//    Complexity
//    Time O(NlogN) for sorting,
//    Time O(NSS) for the for loop, where the second S refers to the string generation and S <= 16.
//    Space O(NS)

//INPUT
//    vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
//    printf("Longest WordChain is %d\r\n", longestStrChain(words));

static bool compare(const string& s1, const string& s2){
    return s1.length() < s2.length();
}

int longestStrChain(vector<string>& words)
{
    std:sort(words.begin(), words.end(), compare);
    map<string, int> dp;
    int res = 0;
    for(int i = 0 ; i < words.size(); i++){
        for(int j = 0; j < words[i].length(); j++){
            dp[words[i]] = MAX(dp[words[i]], dp[words[i].substr(0,j)+words[i].substr(j+1)]+1);
        }
        res = MAX(res, dp[words[i]]);
    }
    return res;
}

//======================================================================//
//INPUT
//    vector<int>nums = {3,2,1};
//    static CountSmaller c;
//    vector<int> ans = c.countSmaller(nums);
//    common_print_1D_vector(ans);

class CountSmaller {
    typedef vector<pair<int, int>> Pii;
    typedef Pii::iterator Pit;
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> res(n);
        Pii nums_(n);
        for(int i = 0; i < n; ++i)
            nums_[i] = {nums[i], i};
        printf("nums %d\r\n", nums_.end()->second);
        merge(nums_.begin(), nums_.end(), res);
        return res;
    }
    
    void merge(Pit begin, Pit end, vector<int>& res){
        
        
        if(end - begin <= 1)
            return;
        auto mid = begin + (end - begin) / 2;
        merge(begin, mid, res);
        merge(mid, end, res);
        for(auto i = begin, j = mid; i != mid; ++i){
            while(j != end && i->first > j->first)
                ++j;
            res[i->second] += j - mid;
        }
        inplace_merge(begin, mid, end);
    }
};

//======================================================================//

int solveMathEquation(string eqn){
    stack<char>stk;
    stack<char>smallstk;
    int ans = 0;
    int i = 0;
    while(i<(int)eqn.size()){
        if(eqn[i] == ')' || i == eqn.size()-1){
            char currC = '\0';
            while(!stk.empty() && currC != '('){
                currC = stk.top();
                stk.pop();
                smallstk.push(currC);
            }
            while(!smallstk.empty()){
                currC = smallstk.top();
                smallstk.pop();
                
            }
        }
        stk.push(eqn[i++]);
    }
    
    return ans;
}

//======================================================================//
//Not from leetcode
// Simplify Math expression involving +,- and parenthesis

#define MAXOPERANDS     10
#define MAXOPERATORS    (MAXOPERANDS-1)

static char precedence[2] = {'-', '+'};

class expression{
private:
    
public:
    
    expression(){}
    
    bool isNumber(char c){
        return ('0' <= c && c <= '9') ? true : false;
    }
    bool isOperator(char c){
        return (c == '+' || c == '-') ? true : false;
    }
    int solveExpr(string operand1, string operand2, char operator1){
        int op1 = atoi(operand1.c_str());
        int op2 = atoi(operand2.c_str());
        switch(operator1){
            case '+':
                return op1 + op2;
            case '-':
                return op1 - op2;
            default:
                return 0;
        }
    }

    void process(vector<string>&operands, vector<char>&operators){
        if(operands.size()-operators.size() != 1){
            return;
        }
        for(int i = 0; i < 2; i++){
            auto itr = find(operators.begin(), operators.end(), precedence[i]);
            while( itr != operators.end()){
                int idx = (int)(itr - operators.begin());
                int res = solveExpr(operands[idx], operands[idx+1], operators[idx]);
//                cout << res << endl;
                operands[idx] = to_string(res);
                operands.erase(operands.begin()+idx+1);
                operators.erase(operators.begin()+idx);
                itr = find(operators.begin(), operators.end(), precedence[i]);
            }
        }
    }
    
    void fillVectors(string exp, vector<string>&operands, vector<char>&operators){
        int i = 0;
        while(i < exp.size()){
            if(isNumber(exp[i])){
                string s;
                while(i < exp.size() && isNumber(exp[i])){
                    s+=exp[i++];
                }
                operands.push_back(s);
                continue;
            }
            if(i < exp.size() && isOperator(exp[i])){
                operators.push_back(exp[i]);
                i++;
                continue;
            }
            if(i < exp.size() && exp[i] == '('){
                int parentheseCount = 1;
                int start = i++;
                while(i < exp.size() && parentheseCount != 0){
                    if(exp[i]== ')')
                        parentheseCount--;
                    if(exp[i] == '(')
                        parentheseCount++;
                    i++;
                }
                if(parentheseCount != 0){
                    while(1);
                }
                operands.push_back(to_string(simplifyExpression(exp.substr(start+1,(i-1)-(start+1)))));
            }
        }
        // Invalid expression
        if(operands.size() - operators.size() != 1){
            while(1);
        }
    }
    
    int simplifyExpression(string exp){
        cout << exp << endl;
        vector<string> operands;
        vector<char> operators;
        fillVectors(exp,operands,operators);
//        for(int i = 0; i < operands.size(); i++){
//            cout << operands[i] << endl;
//        }
//        for(int i = 0; i < operators.size(); i++){
//            cout << operators[i] << endl;
//        }
        process(operands, operators);
        return atoi(operands[0].c_str());
    }
};

//======================================================================//

// __MAIN__
void run_leetcode1()
{
    expression e;
    cout << e.simplifyExpression("((5+1)-3)+(1+1)") << endl;
}

