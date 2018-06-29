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

int lengthOfLIS(int* nums, int numsSize) {
    int max = 0, maxCount[10] = {};
    for (int i = 0; i < numsSize; i++) {
        int find = 0, val = nums[i], len = 0;
        for (int j = i - 1; j >= 0; j--) {
            int innerVal = nums[j];
            if (innerVal < val) {
                len = maxCount[j] + 1;
                maxCount[i] = len > maxCount[i] ? len : maxCount[i];
                find = 1;
            }
        }
        if (!find) {
            maxCount[i] = 1;
        }
        max = maxCount[i] > max ? maxCount[i] : max;
    }
    return max;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[9] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    printf("%d\n", lengthOfLIS(arr, 9));
}
