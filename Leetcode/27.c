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

int removeElement(int* nums, int numsSize, int val) {
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
        if (v == val) {
            continue;
        }
        nums[index++] = nums[i];
    }
    return index;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[7] = {};
    printf("%d\n", removeElement(&arr, 0, 6));
    for (int i = 0; i < 9; i++) {
        printf("%d, ", arr[i]);
    }
}
