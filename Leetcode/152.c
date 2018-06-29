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

int maxProduct(int* nums, int numsSize) {
    int max = 0x80000000, lastVal = -1;
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        int product = val;
        if (product > max) {
            max = product;
        }
        if (lastVal > 0) {
            lastVal = val;
            continue;
        }
        if (val) {
            for (int j = i + 1; j < numsSize; j++) { 
                product *= nums[j];
                if (product > max) {
                    max = product;
                }
                if (!product) {
                    break;
                }
            }
        }
        lastVal = val;
    }
    return max;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[7] = {1,0,-1,2,3,-5,-2};
    printf("%d\n", maxProduct(arr, 7));
}
