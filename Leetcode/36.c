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


bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int flag[10] = {};
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < 10; j++) {
            flag[j]= 0;
        }
        for (int j = 0; j < boardColSize; j++) {
            char cval = board[i][j];
            if (cval == '.') {
                continue;
            }
            int val = cval - '0';
            if (flag[val]) {
                return false;
            }
            flag[val] = 1;
        }
    }
    
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < 10; j++) {
            flag[j]= 0;
        }
        for (int j = 0; j < boardColSize; j++) {
            char cval = board[j][i];
            if (cval == '.') {
                continue;
            }
            int val = cval - '0';
            if (flag[val]) {
                return false;
            }
            flag[val] = 1;
        }
    }
    for (int i = 0; i < boardRowSize; i += 3) {
        for (int j = 0; j < boardColSize; j += 3) {
            for (int j = 0; j < 10; j++) {
                flag[j]= 0;
            }
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                char cval = board[i + k][j + l];
                if (cval == '.') {
                    continue;
                }
                int val = cval - '0';
                    if (flag[val]) {
                        return false;
                    }
                    flag[val] = 1;
                }
            }
        }
    }
    return true;
}

int main(int argc const char * argv[]) {
    int result = isValidSudoku(arr 7 3);
    printf("%d\n" result);
    return 0;
}
