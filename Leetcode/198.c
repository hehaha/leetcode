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

int rob(int* nums, int numsSize) {
    int max = 0, rob = 0;
    int *counter = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        if (i == 0) {
            rob = val;
        }
        else if(i == 1) {
            rob = counter[0] > val ? counter[0] : val;
        }
        else {
            int newRob = counter[i - 2] + val;
            rob = counter[i - 1] > newRob ? counter[i - 1] : newRob;
        }
        counter[i] = rob;
        max = max > rob ? max : rob;
    }
    return max;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[5] = {2, 7, 9, 3, 1};
    printf("%d\n", rob(arr, 5));
}
