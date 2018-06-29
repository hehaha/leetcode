//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
    int* bitList = (int *)malloc(sizeof(int) * 256);
    memset(bitList, 0, sizeof(int) * 256);
    int len = 0;
    int head = 0;
    int maxLen = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        int val = (int)c;
        if (bitList[val] == 0) {
            bitList[val] = i + 1;
            len++;
        }
        else {
            int newHead = bitList[val];
            for (; head < newHead; head ++) {
                int freshIndex = (int)s[head];
                bitList[freshIndex] = 0;
            }
            bitList[val] = i + 1;
            if (len > maxLen) {
                maxLen = len;
            }
            len = i - head + 1;
        }
    }
    free(bitList);
    maxLen = len > maxLen ? len : maxLen;
    return maxLen;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char* a = "abba";
    printf("%d\n", lengthOfLongestSubstring(a));
    return 0;
}
