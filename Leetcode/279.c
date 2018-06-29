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

int findSquareNum(int n) {
    int r = 1;
    while (r * r <= n) {
        r++;
    }
    return r - 1;
}

int numSquares(int n) {
    int stack[100] = {0}, val = 0;
    stack[0] = 0;
    while (val++ < n) {
        int max = findSquareNum(val);
        int square = 0x7fffffff;
        while(max > 0) {
            int back = val - max * max;
            int current =  stack[back] + 1;
            square = square < current ? square : current;
            max--;
        }
        stack[val] = square;
    }
    return stack[n];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n", numSquares(48));
}
