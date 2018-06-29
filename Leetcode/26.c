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

int removeDuplicates(int* nums, int numsSize) {
    int vernier = 0;
    int flagArr[1000] = {0};
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        int flag = flagArr[val];
        if (flag) {
            continue;
        }
        flagArr[val] = 1;
        nums[vernier++] = val;
    }
    return vernier; 
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[3] = {1, 1, 2};
    int size = 3;
    printf("%d\n", removeDuplicates(&arr, 3));
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}
