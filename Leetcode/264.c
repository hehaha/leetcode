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

int nthUglyNumber(int n) {
    int index2 = 1, index3 = 1, index5 = 1;
    int result[2000] = {};
    int i = 1;
    result[i] = 1;
    while (i <= n) {
        int value2 = result[index2] * 2;
        int value3 = result[index3] * 3;
        int value5 = result[index5] * 5;
        int val = value2 < value3 ? value2 : value3;
        val = val < value5 ? val : value5;
        if (val == value2) {
            index2++;
        }
        if (val == value3) {
            index3++;
        }
        if (val == value5) {
            index5++;
        }
        result[++i] = val;
    }
    return result[n];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n", nthUglyNumber(1690));
}
