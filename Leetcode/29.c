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

int divide(int dividend, int divisor) {
    int minus = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
    long rdividend = labs((long)dividend);
    long rdivisor = labs((long)divisor);
    long result = 0, base = 0;
    while (rdividend - base >= rdivisor) {
        long innerResult = 1, d = rdivisor, next = d + rdivisor, left = rdividend - base;
        while(next <= left) {
            d += d;
            innerResult += innerResult;
            next = d + d;;
        }
        result += innerResult;
        base += d;
    }
    result = minus ? -result : result;
    int bottom = 0x80000000, top = 0x7fffffff;
    if (result > (long)top || result < (long)bottom) {
        return 0x7fffffff;
    }
    return (int)result;
}

int main(int argc, const char * argv[]) {
    printf("%d\n", divide(10, 3));
    return 0;
}
