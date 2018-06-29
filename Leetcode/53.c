//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

int maxSubArray(int* nums, int numsSize) {
    int max = 0x80000000;
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        if (val < 0) {
            if (val > max) {
                max = val;
            }
            continue;
        }
        int maxSub = val, value = val;
        for (int j = i + 1; j < numsSize; j++) {
            value += nums[j];
            if (value > maxSub) {
                maxSub = value;
            }
        }
        if (maxSub > max) {
            max = maxSub;
        }
        for (int j = i; j < numsSize; j++) {
            int subVal = nums[j];
            if (subVal > 0) {
                i++;
            }
            else {
                break;
            }
        }
    }
    return max;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[1] = {1};
    printf("%d\n", maxSubArray(arr, 1));
    return 0;
}
