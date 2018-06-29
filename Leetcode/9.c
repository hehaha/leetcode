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


bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    long result = 0;
    long longX = x;
    while(longX) {
        result = result * 10 + longX % 10;
        longX = longX / 10;
    }
    return result == x;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n", isPalindrome(10));
    return 0;
}
