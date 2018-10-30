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

char** letterCombinations(char* digits, int* returnSize) {
    int len = 0;
    while(digits[len++] != '\0') {}
    len -= 1;
    if (!len) {
        return NULL;
    }
    char **result = malloc(sizeof(char *) * (10000));
    char map[9][5] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int sizeMap[9] = {0, 3, 3, 3, 3, 3, 4, 3, 4};
    int sizeCount[10000] = {};
    int sizeLimit[10000] = {};
    for (int i = 0; i < len; i ++) {
        sizeCount[i] = 0;
        int val = digits[i] - '0';
        sizeLimit[i] = sizeMap[val - 1];
    }
    int finish = 0, size = 0;
    while (!finish) {
        char *newChar = malloc(sizeof(char) * (len + 1));
        for (int i = 0; i < len; i++) {
            int val = digits[i] - '0';
            int count = sizeCount[i];
            newChar[i] = map[val - 1][count];
        }
        for (int i = len - 1; i >= 0; i--) {
            int count = sizeCount[i];
            int limit = sizeLimit[i];
            if (count < limit - 1) {
                sizeCount[i]++;
                break;
            }
            else {
                sizeCount[i] = 0;
            }
            if (i == 0) {
                finish = 1;
            }
        }
        newChar[len] = '\0';
        result[size++] = newChar;
    }
    *returnSize = size;
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int size = 0;
//    char test = '0' - 48;
//    printf("%c\n", test);
//    return 0;
    char **result = letterCombinations("23", &size);
    int i = 0;
    printf("%d\n", size);
    while (i < size) {
        char *val = result[i];
        printf("%s\n", val);
        free(val);
        i++;
    }
    free(result);
    return 0;
}
