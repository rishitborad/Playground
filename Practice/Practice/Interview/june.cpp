//
//  june.cpp
//  Practice
//
//  Created by Dexter's Lab on 1/11/21.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

//======================================================================//

//Question1: Remove nodes with values greater than the input parameter from a linked list

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}



SinglyLinkedListNode* removeNodes(SinglyLinkedListNode* listHead, int x) {
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* curr = listHead;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode* newHead = listHead;
    
    if(curr == nullptr)
        return curr;
        
    next = curr->next;
    
    while(curr != nullptr){
            
        if(curr->data > x){
            // Head node
            if(prev == nullptr){
                free(curr);
                curr = nullptr;
                newHead = next;
            }
            // rest nodes
            else{
                prev->next = next;
                free(curr);
                curr = nullptr;
            }
        }
        if(curr!=nullptr)
            prev = curr;
        curr = next;
        if(next != nullptr)
            next = next->next;
    }
    return newHead;
}




//======================================================================//

//Question2:

//Reverse all the bits in a number received as a parameter. Do not reverse insignificant zeros ahead of MSB 1. Eg. 01011→ 00100,
int reverse_bits(int base10){return -1;}


//======================================================================//

//Question3:

//Find the maximum volatility range in water level passed as a parameter. Return -1 when the water level has consistently gone down.
//Eg1. [5,4,3,2,1] → returns -1
//Eg2.[1,4,2,6,3,2,1] → returns 5
//Explanation: 4-1 = 3, 2-1 = 1, 6-1 = 5, 6-4 = 2, 6-2 = 4, 3-2 =1, 3-1 = 2, 2-1 = 1
int maximum_range(vector<int> water_level){return -1;}

