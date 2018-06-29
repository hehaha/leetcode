//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

int numDecodings(char* s) {
    if (s[0] == '0') {
        return 0;
    }
    int last = s[0] - '0', result = last != 0;
    int count[10000] = {0};
    count[1] = last != 0;
    count[0] = 1;
    for (int i = 1; s[i] != '\0'; i++) {
        int val = s[i] - '0';
        int total = val + last * 10;
        if (total == 0 || (val == 0 && total > 26)) {
            return 0;
        }
        else if (total == 10 || total == 20) {
            result = count[i - 1];
        }
        else if (!(total > 10 && total <= 26)) {
            result = count[i];
        }
        else {
            result = count[i - 1] + count[i];
        }
        last = val;
        count[i + 1] = result;
    }
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n", numDecodings("230"));
    return 0;
}
