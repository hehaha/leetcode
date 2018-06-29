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


int singleNumber(int* nums, int numsSize) {
    int flag = 0;
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        flag ^= val;
    }
    return flag;
}

int main(int argc, const char * argv[]) {
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    int result = singleNumber(arr, 7);
    printf("%d\n", result);
    return 0;
}
