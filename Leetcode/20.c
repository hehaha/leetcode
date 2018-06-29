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


bool isValid(char* s) {
    char stack[10000] = {'\0'};
    int top = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        char val = s[i];
        if (top < 0) {
            stack[++top] = val;
            continue;
        }
        char topChar = stack[top];
        if ((topChar == '(' && val == ')') || (topChar == '{' && val == '}') || (topChar == '[' && val == ']')) {
            top--;
        }
        else if (val == ')' || val == '}' || val == ']') {
            return false;
        }
        else {
            stack[++top] = val;
        }
    }
    return top == -1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n", isValid("{}()[]"));
    return 0;
}
