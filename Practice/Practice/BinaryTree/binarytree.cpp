//
//  binarytree.cpp
//  Practice
//
//  Created by Dexter's Lab on 11/9/20.
//

#include <stdio.h>
#include <queue>
#include <cmath>

using namespace std;

typedef struct node{
    int val;
    struct node* left;
    struct node* right;
    node():val(0),left(nullptr),right(nullptr){}
    node(int val):val(val),left(nullptr),right(nullptr){}
}NODE_t, *NODE_p;


typedef struct node3{
    int val;
    struct node3* left;
    struct node3* right;
    struct node3* level;
    node3():val(0),left(nullptr),right(nullptr),level(nullptr){}
    node3(int val):val(val),left(nullptr),right(nullptr),level(nullptr){}
}NODE3_t, *NODE3_p;

class LevelOrder{
private:
public:
    void printLevelOrderBT(NODE_p head)
    {
        if(!head)
            return;
        
        queue<NODE_p> q;
        q.push(head);
        while(!q.empty())
        {
            NODE_p frnt = q.front();
            q.pop();
            printf("%d ", frnt->val);
            if(frnt->left != nullptr)
                q.push(frnt->left);
            if(frnt->right != nullptr)
                q.push(frnt->right);
        }
    }
    
    vector<float> levelAverageBT(NODE_p head)
    {
        vector<float> levelAverages;
        queue<NODE_p> que;
        if(!head)
            return levelAverages;
        que.push(head);
        while(!que.empty())
        {
            float lvlAvg = 0.0;
            int levelSize = (int)que.size();
            for(int i = 0; i < levelSize; i++)
            {
                NODE_p curr = que.front();
                que.pop();
                lvlAvg += curr->val;
                if(curr->left != nullptr){
                    que.push(curr->left);
                }
                if(curr->right != nullptr){
                    que.push(curr->right);
                }
            }
            levelAverages.push_back(lvlAvg/levelSize);
        }
        return levelAverages;
    }
    
    int minDepthBT(NODE_p head){
        int levelCount = 0;
        queue<NODE_p> que;
        if(head == nullptr)
            return 0;
        
        que.push(head);
        
        while(!que.empty()){
            size_t levelSize = que.size();
            levelCount++;
            for(int i = 0; i < levelSize; i++)
            {
                NODE_p curr = que.front();
                printf("curr %d\r\n", curr->val);
                que.pop();
                if(curr->left == nullptr || curr->right == nullptr)
                    return levelCount;
                if(curr->left != nullptr)
                    que.push(curr->left);
                if(curr->right != nullptr)
                    que.push(curr->right);
            }
        }
        return levelCount;
    }
    
    void connectLevelOrderSiblings(NODE3_p head){
        queue<NODE3_p> que;
        NODE3_p prev = nullptr;
        if(head == nullptr){
            return;
        }
        que.push(head);
        while (!que.empty()) {
            int levelSize = (int)que.size();
            for(int i = 0; i < levelSize; i++)
            {
                NODE3_p curr = que.front();
                que.pop();
                if(prev != nullptr){
                    prev->level = curr;
                }
                if(curr->left != nullptr)
                    que.push(curr->left);
                if(curr->right != nullptr)
                    que.push(curr->right);
                prev = curr;
            }
            prev->level = nullptr;
        }
    }
    
    bool pathSumBT(NODE_p head, int sum)
    {
        if(head == nullptr)
            return false;
        if(head->left == nullptr && head->right == nullptr && (sum - head->val) == 0){
            return true;
        }
        else{
            return pathSumBT(head->left, sum - head->val) || pathSumBT(head->right, sum - head->val);
        }
        return false;
    }
    
    int allpathSumBT(NODE_p head, int sum){
        if(head == nullptr)
            return 0;
        if(head->left == nullptr && head->right == nullptr && (sum-head->val) == 0){
            return 1;
        }
        return allpathSumBT(head->left, sum-head->val) + allpathSumBT(head->right, sum-head->val);
    }
    
    void printTreePaths(NODE_p head, vector<vector<int>>& treePaths){
        
        vector<int> path;
        if(head == nullptr){
            return;
        }
        printTreePathsUtil(head, path, treePaths);
    }
    
    void printTreePathsUtil(NODE_p head, vector<int>& currPath, vector<vector<int>>& tp){
        
        if(head == nullptr){
            return;
        }
        
        currPath.push_back(head->val);
        
        if(head->left == nullptr && head->right == nullptr){
            tp.push_back(currPath);
        }else{
            printTreePathsUtil(head->left, currPath, tp);
            printTreePathsUtil(head->right, currPath, tp);
        }
        currPath.pop_back();
    }
    
    void getAllPathSum(NODE_p head, int& val, vector<int>& pathSum, int level){
        if(head == nullptr)
            return;
        
        val += (int)pow(10,level) * head->val;
        
        if(head->left == nullptr && head->right == nullptr){
            pathSum.push_back(val);
        }else{
            getAllPathSum(head->left, val, pathSum, level+1);
            getAllPathSum(head->right, val, pathSum, level+1);
        }
        val -= (int)pow(10,level) * head->val;
    }
    
    bool pathWithGivenSequenceUtil(NODE_p head, vector<int>seq, int idx){
        if(head == nullptr){
            return false;
        }
        
        if(head->left == nullptr && head->right == nullptr && idx == seq.size()-1 && head->val == seq[idx]){
            return true;
        }

        if(head->val == seq[idx]){
            return pathWithGivenSequenceUtil(head->left, seq, idx+1) || pathWithGivenSequenceUtil(head->right, seq, idx+1);
        }
        return false;
    }
    
    bool pathWithGivenSequence(NODE_p head, vector<int>seq)
    {
        if(head == nullptr){
            return false;
        }
        
        return pathWithGivenSequenceUtil(head, seq, 0);
    }
    
    // CAUTION: This problem has an interesting catch:
    // This problem requires reverse interator because the vector when you go from front to back it calculates previous paths eachtime, if you go from back to front it will sumup values untill the current path.
    int countPathsForSumUtil(NODE_p head, vector<int>& vec, int sum, vector<vector<int>>& capture){
        if(head == nullptr)
            return 0;
        int pathSum = 0, pathCount = 0;
        vec.push_back(head->val);
        vector<int>::reverse_iterator itr;
        for(itr = vec.rbegin(); itr != vec.rend(); itr++ ){
            pathSum += *itr;
            if(pathSum == sum){
                pathCount++;
                capture.push_back(vec);
            }
        }
        pathCount += countPathsForSumUtil(head->left, vec, sum, capture);
        pathCount += countPathsForSumUtil(head->right, vec, sum, capture);
        vec.pop_back();
        return pathCount;
    }
    
    int countPathsForSum(NODE_p head, int sum){
        vector<int> pathsums;
        vector<vector<int>> capture;
        int count = countPathsForSumUtil(head, pathsums, sum, capture);
        for(int i = 0; i < capture.size(); i++)
        {
            for(int j = 0; j < capture[i].size(); j++)
            {
                printf("%d, ",capture[i][j]);
            }
            printf("\r\n");
        }
        return count;
    }
};

// __MAIN__
void run_binarytree()
{
    LevelOrder a;
    NODE_p head = new NODE_t(10);
    head->left = new NODE_t(8);
    head->right = new NODE_t(9);
    head->left->left = new NODE_t(3);
    head->left->right = new NODE_t(4);
    head->right->left = new NODE_t(5);
    head->right->right = new NODE_t(6);
    head->left->left->left = new NODE_t(1);
    head->left->right->left = new NODE_t(2);
    head->right->right->right = new NODE_t(7);
    a.printLevelOrderBT(head);
    
    vector<float> levelAverages = a.levelAverageBT(head);
    for(int i = 0; i < (int)levelAverages.size(); i++){printf("level %d avg is %f\r\n", i, levelAverages[i]);}
    
    printf("Binary tree Min level count is %d\r\n", a.minDepthBT(head));
    for(int i = 0;i<100; i++){
        if(a.pathSumBT(head, i)){
            printf("BT has sum %d\r\n",i);
        }
    }
    int sum = 25;
    printf("There are %d path in BT with sum %d\r\n", a.allpathSumBT(head, sum), sum);
    
    vector<vector<int>> treePaths;
    a.printTreePaths(head, treePaths);
    for(int i = 0; i < (int)treePaths.size(); i++){
        for(int j = 0; j < (int)treePaths[i].size(); j++){
            printf("%d, ", treePaths[i][j]);
        }
        printf("\r\n");
    }
    
    vector<int> pathSum;
    int pathTotal = 0;
    a.getAllPathSum(head->left, pathTotal, pathSum, 0);
    for(int i = 0 ; i < pathSum.size(); i++){
        pathTotal += pathSum[i];
    }
    printf("Total of all paths is %d\r\n",pathTotal);
    
    vector<int>pathSequence = {10,9,5};
    if(a.pathWithGivenSequence(head, pathSequence)){
        printf("This path is present in BT\r\n");
    }
    printf("counts paths for a sum %d\r\n", a.countPathsForSum(head, 18));
}
