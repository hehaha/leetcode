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


int myAtoi(char* str) {
    char *newStr = str;
    for (int i = 0; str[i] == ' '; i++, newStr++){};
    int start = 0;
    long result = 0;
    int plus = 1;
    for (int i = 0; newStr[i] != '\0'; i++) {
        char a = newStr[i];
        if (a >= '0' && a <= '9') {
            start = 1;
            int val = a - '0';
            result = result * 10 + val;
            long tempResult = plus ? result : -result;
            if (tempResult > 0x7fffffff) {
                return 0x7fffffff;
            }
            else if (tempResult < (int)0x80000000) {
                return 0x80000000;
            }
        }
        else if (!start) {
            start = 1;
            if (a == '-') { plus = 1 - plus; }
            else if (a != '+') { break; }
        }
        else {
            break;
        }
    }
    result = plus ? result : -result;
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n", myAtoi("42"));
    return 0;
}
