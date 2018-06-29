//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

void quickSort(int *nums, int low, int high) {
    if (low > high) {
        return;
    }
    int pirot = nums[low];
    int i = low, j = high;
    while (i < j) {
        while(i < j && nums[j] >= pirot) {
            j--;
        }
        nums[i] = nums[j];
        while(i < j && nums[i] <= pirot) {
            i++;
        }
        nums[j] = nums[i];
    }
    nums[i] = pirot;
    quickSort(nums, low, i - 1);
    quickSort(nums, j + 1, high);
}

int arrayPairSum(int* nums, int numsSize) {
    quickSort(nums, 0, numsSize - 1);
    int result = 0;
    for (int i = 0; i < numsSize;i += 2) {
        result += nums[i];
    }
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int l[4] = {1, 3, 2, 4};
    printf("%d\n", arrayPairSum(l, 4));
    return 0;
}
