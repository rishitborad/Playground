//
//  embedded.cpp
//  Practice
//
//  Created by Dexter's Lab on 2/15/21.
//

#include <stdio.h>
#include <stdint.h>

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
