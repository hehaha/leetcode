//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

int longestValidParentheses(char* s) {
    char stack[20];
    int flag[20] = {0}, stackVal[20] = {0};
    memset(stack, '\0', 20);
    int top = 0, i = 0;
    for (; s[i] != '\0'; i++) {
        char val = s[i];
        if (top == 0 && val == '(') {
            stack[++top] = val;
            stackVal[top] = i;
            continue;
        }
        char topChar = stack[top];
        if (topChar == '(' && val == ')') {
            flag[i] = i - stackVal[top] + 1;
            top--;
        }
        else if (val == ')') {
            flag[i] = 0;
        }
        else {
            stack[++top] = val;
            stackVal[top] = i;
        }
    }
    int maxLen = 0, len = 0;
    for (int j = i; j >= 0; j--) {
        int val = flag[j];
        len += val;
        if (!val) {
            if (len > maxLen) {
                maxLen = len;
            }
            len = 0;
            continue;
        }
        j -= flag[j] - 1;
    }
    if (len > maxLen) {
        maxLen = len;
    }
    return maxLen;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n", longestValidParentheses(")()())"));
    return 0;
}
