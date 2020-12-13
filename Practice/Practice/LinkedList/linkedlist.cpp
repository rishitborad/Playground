//
//  linkedlist.cpp
//  Practice
//
//  Created by Dexter's Lab on 11/7/20.
//

#include <stdio.h>

using namespace std;

typedef struct Node
{
    int val;
    struct Node* next;
    Node(){}
    Node(int val):val(val),next(nullptr){}
}NODE_t, *NODE_p;

void printLinkedList(NODE_p head)
{
    NODE_p curr = head;
    while(curr)
    {
        printf("%d-->", curr->val);
        curr = curr->next;
    }
    printf("EOL\r\n");
}

NODE_p reverseSubList(NODE_p head, int l, int r)
{
    NODE_p curr = head;
    NODE_p prev = nullptr;
    NODE_p next = nullptr;
    NODE_p endOfFL = nullptr;
    NODE_p lastNodeofsubList = nullptr;
    int cntr = 0;
    
    while(curr != nullptr && cntr < l)
    {
        cntr++;
        prev = curr;
        curr = curr->next;
    }
    // curr now is at start of list to be reversed
    // Prev now is at the end of first list
    
    endOfFL = prev;
    lastNodeofsubList = curr;
    cntr = 0;
    while(curr != nullptr && cntr <= r-l){
        cntr++;
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if(endOfFL != nullptr){
        endOfFL->next = prev;
    }else{
        head = prev;
    }
    lastNodeofsubList->next = curr;
    return head;
}

// __ MAIN__
void run_linkedList()
{
    NODE_p head = new NODE_t(5);
    head->next = new NODE_t(4);
    head->next->next = new NODE_t(3);
    head->next->next->next = new NODE_t(2);
    head->next->next->next->next = new NODE_t(1);
    printLinkedList(head);
    printLinkedList(reverseSubList(head, 0, 4));
}
