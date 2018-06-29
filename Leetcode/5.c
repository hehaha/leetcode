//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

char* longestPalindrome(char* s) {
    int index = 0, len = 0, maxLen = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char val = s[i], next = s[i + 1];
        int nIndex = i + 1, left = i - 1;
        for(;next == val; next = s[++nIndex]) {
            i = nIndex;
        }
        int right = nIndex;
        while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
            left--;
            right++;
        }
        int currentLen = right - left - 1;
        if (currentLen > maxLen) {
            index = left + 1;
            len = currentLen;
            maxLen = currentLen;
        }
    }
    if (!index && !len) {
        return NULL;
    }
    char *result = (char *)malloc(sizeof(char) * (len + 1));
    memcpy(result, s + index, len);
    result[len] = '\0';
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%s\n", longestPalindrome("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"));
    return 0;
}
