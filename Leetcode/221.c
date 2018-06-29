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

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int max = 0;
    for (int i = 0; i < matrixRowSize; i++) {
        if (i + max > matrixRowSize) {
            break;
        }
        for (int j = 0; j < matrixColSize; j++) {
            char val = matrix[i][j];
            if (val == '0') {
                continue;
            }
            if (j + max > matrixColSize) {
                break;
            }
            int len = 1;
            if (!(i == matrixRowSize - 1 || j == matrixColSize - 1)) {
                while (val == '1' && len + j < matrixColSize) {
                    val = matrix[i][len + j];
                    if (val == '1') {
                        len++;
                    }
                }
                int y = 1;
                while (y < len && y + i < matrixRowSize) {
                    int xLen = len;
                    for (int x = 0; x < xLen; x++) {
                        char squVal = matrix[i + y][j + x];
                        if (squVal == '0') {
                            xLen = x;
                            break;
                        }
                    }
                    len = (xLen < y) ? y : xLen;
                    y++;
                }
                len = len < 1 ? 1 : len;
                len = len > y ? y : len;
            }
            max = max > len ? max : len;
        }
    }
    return max * max;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int size = 9;
    char **p = malloc(sizeof(char *) * size);
    char *arr1 = "00010111";
    char *arr2 = "01100101";
    char *arr3 = "10111101";
    char *arr4 = "00010000";
    char *arr5 = "00100010";
    char *arr6 = "11100111";
    char *arr7 = "10011001";
    char *arr8 = "01001100";
    char *arr9 = "10010000";
    p[0] = arr1;
    p[1] = arr2;
    p[2] = arr3;
    p[3] = arr4;
    p[4] = arr5;
    p[5] = arr6;
    p[6] = arr7;
    p[7] = arr8;
    p[8] = arr9;
    printf("%d\n", maximalSquare(p, size, 8));
}
