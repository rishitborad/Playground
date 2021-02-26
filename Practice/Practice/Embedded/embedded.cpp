//
//  embedded.cpp
//  Practice
//
//  Created by Dexter's Lab on 2/15/21.
//

#include <stdio.h>
#include <stdint.h>
#include <vector>

using namespace std;


// Function pointers
void (*foo)(void);
int (*fii)(int a, int b);

// Array
int arr1[10];
//pointer to an array of int
int * arr2[10];
//array of pointers
int (*arr3)[10];
// arrey of function pointers
int (*arr4[10])();



uint16_t intToUint(int16_t val){
    return (uint16_t)val;
}

int32_t uintToInt(uint16_t val){
    
    return (int32_t)val;
}


class ringBuffer{
private:
    int head;
    int tail;
    int size;
    vector<int> buffer;
public:
    ringBuffer(){}
    ringBuffer(int n)
    :size(n)
    {
        head = 0; tail = 0;
        buffer.resize(size+1);
    }
    
    void push(int item){
        int pos = head+1;
        if(pos >= size){
            // outof bounds
            pos = 0;
        }
        if(pos == tail){
            // Overflow
            return;
        }
        buffer[head] = item;
        head = pos;
    }
    int pop(){
        int pos = tail+1;
        if(pos == head){
            return -1;
        }
        if(pos >= size){
            // out of bounds
            return -1;
        }
        int item = buffer[tail];
        tail = pos;
        return item;
    }
    int peek(){
        
        int pos = tail+1;
        if(pos >= size){
            pos = 0;
        }
        if(pos == head){
            return 0;
        }
        return buffer[pos];
    }
    bool isEmpty(){
        int pos = tail+1;
        if(pos >= size){
            pos = 0;
        }
        if(pos == head){
            return false;
        }
        return true;
    }
};

//======================================================================//
struct metaNode{
    uint16_t size;
    bool isFree;
    struct metaNode* next;
};

#define METANODE_SIZE (sizeof(metaNode))

class RAM{
private:
    uint8_t* memory;
    uint32_t empty;
    uint32_t size;
    
public:
    RAM():size(512){
        memory = new uint8_t[512];
    }
    RAM(uint32_t size):size(size){
        memory = new uint8_t[size];
        empty = 0;
    }
    
    void* sbrk(uint32_t size){
        if(empty + size > size){
            return nullptr;
        }
        uint8_t* startOfEmptyBlock = &memory[empty];
        empty += size;
        return startOfEmptyBlock;
    }
};

class memoryManagement{
private:
    void* globalPointer;
    RAM* memory;
    
    void* findEmptyBlock(void** last, uint32_t size){
        metaNode* curr = (metaNode*)globalPointer;
        while(curr){
            if(curr->isFree && curr->size >= size){
                curr->isFree = false;
                return curr;
            }
            curr = curr->next;
        }
        *last = curr;
        return nullptr;
    }
    
    void* createNewBlock(void* last, uint32_t size){
        metaNode* node = (metaNode*)memory->sbrk(METANODE_SIZE+size);
        if(node == nullptr){
            return nullptr;
        }
        ((metaNode*)last)->next = node;
        node->isFree = false;
        node->size = size;
        node->next = nullptr;
        return node;
    }
    
public:
    memoryManagement()
    : globalPointer(nullptr)
    ,memory(new RAM()){}
    
    memoryManagement(uint32_t size)
    : globalPointer(nullptr)
    , memory(new RAM(size)){}
    
    void* malloc(int size){
        if(globalPointer == nullptr){
            // No allocated spaces
            metaNode* node = (metaNode*)createNewBlock(NULL, size);
            globalPointer = node;
            if(node != nullptr){
                return node+1;
            }
        }else{
            metaNode* last = nullptr;
            // Find empty block from the allocated space
            metaNode* node = (metaNode*)findEmptyBlock((void**)&last, size);
            if(node != nullptr){
                return node+1;
            }
            node = (metaNode*)createNewBlock(last,size);
            if(node != nullptr){
                return node+1;
            }
        }
        return nullptr;
    }
};


//======================================================================//
// __MAIN__
void run_embedded()
{
    printf("%X\r\n",intToUint(32000));
    printf("%X\r\n",uintToInt(65535));
    
//    // pointer to location in memory
//    int val = 5;
//    uint32_t* STATUS_REG;
//    STATUS_REG = (uint32_t*)0x84000U;
//    *STATUS_REG = val;

}
