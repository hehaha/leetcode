//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>


int compare_int( const void* a, const void* b )
{
    if( *(int*)a == *(int*)b ) return 0;
    return *(int*)a < *(int*)b ? -1 : 1;
}

struct Couple {
    int a;
    int b;
    struct Couple *next;
} typedef Couple;


int twoSum(int* nums, int numSize, int target, Couple** result);


int** threeSum(int* nums, int numsSize, int* returnSize) {
    int totalSize = 1000, size = 0, last = 0x80000000;
    Couple *resultCouple[totalSize];
    for (int i = 0; i < totalSize; i++) {
        resultCouple[i] = NULL;
    }
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        if (val == last) {
            continue;
        }
        int target = 0 - val;
        Couple *two = NULL;
        size += twoSum((nums + i + 1), numsSize - i - 1, target, &two);
        resultCouple[i] = two;
        last = val;
    }
    int **result = malloc(sizeof(int*) * size), resultIndex = 0;
    for (int i = 0; i < numsSize; i++) {
        Couple *two = resultCouple[i];
        if (!two) {
            continue;
        }
        int val = nums[i];
        while(two) {
            int *answer = malloc(sizeof(int) * 3);
            answer[0] = val;
            answer[1] = two->a;
            answer[2] = two->b;
            Couple* c = two;
            two = two->next;
            free(c);
            result[resultIndex++] = answer;
        }
    }
    *returnSize = size;
    return result;
}

int twoSum(int* nums, int numSize, int target, Couple** returnCouple) {
    int head = 0, tail = numSize - 1, returnSize = 0;
    int lastHead = 0x80000000, lastTail = 0x7fffffff;
    Couple *result = NULL;
    while(head < tail) {
        int headVal = nums[head];
        if (headVal == lastHead) {
            head++;
            continue;
        }
        int tailVal = nums[tail];
        if (lastTail == tailVal) {
            tail--;
            continue;
        }
        int total = headVal + tailVal;
        if (total == target) {
            Couple *new = malloc(sizeof(Couple));
            new->a = headVal;
            new->b = tailVal;
            new->next = result;
            result = new;
            head++;
            tail--;
            returnSize++;
            lastHead = headVal;
            lastTail = tailVal;
        }
        else if (total > target) {
            tail--;
            lastTail = tailVal;
        }
        else {
            head++;
            lastHead = headVal;
        }
    }
    *returnCouple = result;
    return returnSize;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[108] = {-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1};
    int returnSize = 0;
    int **result = threeSum(arr, 108, &returnSize);
    printf("%d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        int *answer = result[i];
        printf("%d, %d, %d\n", answer[0], answer[1], answer[2]);
        free(answer);
        answer = NULL;
    }
    free(result);
    result = NULL;
    return 0;
}
