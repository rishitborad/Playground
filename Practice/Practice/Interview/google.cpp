//
//  google.cpp
//  Practice
//
//  Created by Dexter's Lab on 11/4/20.
//

#include <stdio.h>
#include <stdint.h>

using namespace std;

void printBinary(uint8_t val)
{
    for(int8_t i = 7; i >= 0; i--)
    {
        printf("%d", (val & (1<<i)) ? 1 : 0);
    }
}

void printMatrixBinary(uint8_t* arr, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printBinary(arr[(i*m)+j]);
            printf(" ");
        }
        printf("\r\n");
    }
}

uint8_t mirror(uint8_t val)
{
    uint8_t ret = 0;
    
    for(int i = 0; i < 8; i++)
    {
        if((1 << i) & val){
            ret |= (1 << (8 - i - 1));
        }
    }
    return ret;
}

void swap(uint8_t* val1, uint8_t* val2)
{
    uint8_t temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void mirrorMatrix(uint8_t* arr, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < (n+1)/2; j++)
        {
            uint8_t val1 = mirror(arr[(i*m)+j]);
            uint8_t val2 = mirror(arr[(i*m)+(n-j-1)]);
            swap(&val1, &val2);
            arr[(i*m)+j] = val1;
            arr[(i*m)+(n-j-1)] = val2;
        }
    }
}

// __MAIN__
void run_google()
{
//    uint8_t matrix3x3[9] = {1,2,3,4,5,6,7,8,9};
    uint8_t matrix2x2[4] = {1,2,3,4};
    printf("\r\n");
    printMatrixBinary(matrix2x2, 2, 2);
    printf("\r\n");
    mirrorMatrix(matrix2x2, 2, 2);
    printMatrixBinary(matrix2x2, 2, 2);
}
