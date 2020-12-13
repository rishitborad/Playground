//
//  heap.cpp
//  Practice
//
//  Created by Dexter's Lab on 11/17/20.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class MedianOfAStream{
private:
    priority_queue<int>max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;
    float median;
    int currSum;
public:
    MedianOfAStream():median(0.0),currSum(0){}
    void insertNum(int num){
        
    }
   void findMedian(){
       
    }
};

// __MAIN__
void run_heap()
{
    MedianOfAStream med;
    med.insertNum(6);
    med.insertNum(7);
    med.findMedian();
    med.insertNum(1);
    med.insertNum(4);
    med.findMedian();
    med.insertNum(2);
    med.insertNum(6);
    med.insertNum(3);
    med.findMedian();
}
