#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "absVal.h"
#include "addOK.h"
#include "bitOr.h"
#include "bitAnd.h"
#include "bitXor.h"
#include "bitMask.h"
#include "bitCount.h"
#include "byteSwap.h"
#include "isTmax.h"
#include "negate.h"

const int N = 1000;
const int M = 20;

int main(){
    srand(time(NULL));
    int ranint[N];
    for(int i = 0; i < N; i++){
        ranint[i] = rand() % ((long)INT_MAX - INT_MIN + 1) + INT_MIN;
    }

    int ranbit[M];
    for(int i = 0; i < M; i++){
        ranbit[i] = rand() % 32;
    }


    printf("Test absVal function...\n");
    for(int i = 0; i < N; i++){
        int a = absVal(ranint[i]);
        int b = absVal_standard(ranint[i]);
        if(a != b){
            printf("absVal not right for value %d: absVal = %d, absVal_standard = %d\n", ranint[i], a, b);
        }
    } 

    printf("Test addOK function...\n");
    for(int i = 0; i < N - 1; i++){
        int a = addOK(ranint[i], ranint[i + 1]);
        int b = addOK_standard(ranint[i], ranint[i + 1]);
        if( a != b){
            printf("addOK not right for value %d and %d: addOK = %d, addOK_standard = %d\n", ranint[i], ranint[i + 1], a, b);
        }
    }

    printf("Test bitOr function...\n");
    for(int i = 0; i < N - 1; i++){
        int a = bitOr(ranint[i], ranint[i + 1]);
        int b = bitOr_standard(ranint[i], ranint[i + 1]);
        if(a != b){
            printf("bitOr not right for value %d and %d: bitOr = %d, bitOr_standard = %d\n", ranint[i], ranint[i + 1], a, b);
        }
    }

    printf("Test bitAnd function...\n");
    for(int i = 0; i < N - 1; i++){
        int a = bitAnd(ranint[i], ranint[i + 1]);
        int b = bitAnd_standard(ranint[i], ranint[i + 1]);
        if(a != b){
            printf("bitAnd not right for value %d and %d: bitAnd = %d, bitAnd_standard = %d\n", ranint[i], ranint[i + 1], a, b);
        }
    }

    printf("Test bitXor function...\n");
    for(int i = 0; i < N - 1; i++){
        int a = bitXor(ranint[i], ranint[i + 1]);
        int b = bitXor_standard(ranint[i], ranint[i + 1]);
        if(a != b){
            printf("bitXor not right for value %d and %d: bitXor = %d, bitXor_standard = %d\n", ranint[i], ranint[i + 1], a, b);
        }
    } 

    printf("Test bitMask function...\n");
    for(int i = 0; i < M - 1 ; i++){
        int a = bitMask(ranbit[i], ranbit[i + 1]);
        int b = bitMask_standard(ranbit[i], ranbit[i + 1]);
        if(a != b){
            printf("bitMask not right for value %d and %d: bitMask = %d, bitMask_standard = %d\n", ranbit[i], ranbit[i + 1], a, b);
        }
    } 

    printf("Test bitCount function...\n");
    for(int i = 0; i < N; i++){
        int a = bitCount(ranint[i]);
        int b = bitCount_standard(ranint[i]);
        if(a != b){
            printf("bitCount not right for value %d: bitCount = %d, bitCount_standard = %d\n", ranint[i], a, b);
        }
    }

    printf("Test byteSwap function...\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 4; j ++){
            for(int k = j+1; k < 4; k++){

                int a = byteSwap(ranint[i], j, k);
                int b = byteSwap_standard(ranint[i], j, k);
                if(a != b){
                    printf("byteSwap not right for target %d, location %d and %d: byteSwap = %d, byteSwap_standard = %d\n", ranint[i], j, k, a, b);
                }
            }
        }
    }


    printf("Test isTmax function...\n");
    for(int i = 0; i < N; i++){
        int a = isTmax(ranint[i]);
        int b = isTmax_standard(ranint[i]);
        if(a != b){
            printf("isTmax not right for value %d, isTmax = %d, isTmax_standard = %d\n", ranint[i], a, b);
        }
    }


    printf("Test negate function...\n");
    for(int i = 0; i < N; i++){
        int a = negate(ranint[i]);
        int b = negate_standard(ranint[i]);
        if(a != b){
            printf("negate not right value %d, negate = %d, negate_standard = %d\n", ranint[i], a, b);
        }
    }

    return 0;
}
