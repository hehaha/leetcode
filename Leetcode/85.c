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

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    int max = 0;
    for (int i = 0; i < matrixRowSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            char val = matrix[i][j];
            if (val == '0') {
                continue;
            }
            int width = 1, height = 1;
            while (val == '1' && width + j < matrixColSize) {
                val = matrix[i][width + j];
                if (val == '1') {
                    width++;
                }
            }
            while (height + i < matrixRowSize && matrix[i + height][j] == '1') {
                int square = width * height;
                max = max > square ? max : square;
                int xLen = width;
                for (int x = 0; x < xLen; x++) {
                    char squVal = matrix[i + height][j + x];
                    if (squVal == '0') {
                        xLen = x;
                        break;
                    }
                }
                width = xLen;
                height++;
            }
            int square = width * height;
            max = max > square ? max : square;
        }
    }
    return max;
}

int main(int argc, const char * argv[]) {
    int size = 10;
    char **p = malloc(sizeof(char *) * size);
    char *arr1 = "0001010";
    char *arr2 = "0100000";
    char *arr3 = "0101001";
    char *arr4 = "0011001";
    char *arr5 = "1111110";
    char *arr6 = "1001011";
    char *arr7 = "0100101";
    char *arr8 = "1101110";
    char *arr9 = "1010101";
    char *arr10 = "1110000";
    p[0] = arr1;
    p[1] = arr2;
    p[2] = arr3;
    p[3] = arr4;
    p[4] = arr5;
    p[5] = arr6;
    p[6] = arr7;
    p[7] = arr8;
    p[8] = arr9;
    p[9] = arr10;
    printf("%d\n", maximalRectangle(p, size, 7));
}
