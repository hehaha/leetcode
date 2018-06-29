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

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int result[1000] = {0}, min;
    for (int i = 0; i < triangleRowSize; i++) {
        min = 0x7fffffff;
        int col = triangleColSizes[i];
        for (int j = col - 1; j >= 0; j--) {
            int val = triangle[i][j];
            if (j == 0) {
                result[j] += val;
            }
            else if (j == col - 1) {
                result[j] = result[j - 1] + val;
            }
            else {
                result[j] = (result[j] > result[j - 1] ? result[j - 1] : result[j]) + val;
            }
            min = result[j] < min ? result[j] : min;
        }
    }
    return min;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {2};
    int size[] = {1};
    int *p = arr;
    int **t = &p;
    printf("%d\n", minimumTotal(t, 1, size));
    return 0;
}
