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

int maxArea(int* height, int heightSize) {
    int maxArea = 0;
    int last = -1;
    for (int i = 0; i < heightSize; i++) {
        int left = height[i];
        if (left < last) {
            last = left;
            continue;
        }
        for (int j = i + 1; j < heightSize; j++) {
            int right = height[j];
            int area = (right < left ? right : left) * (j - i);
            maxArea = area > maxArea ? area : maxArea;
        }
        last = left;
    }
    return maxArea;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int *arr = malloc(sizeof(int) * 15000);
    for (int i = 0; i < 15000; i++) {
        arr[i] = 15000 - i;
    }
    printf("%d\n", maxArea(arr, 15000));
    free(arr);
}
