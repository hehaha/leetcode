//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

int climbStairs(int n) {
    int stairs[10000] = {0};
    stairs[0] = 1, stairs[1] = 2;
    for (int i = 2; i < n; i++) {
        stairs[i] = stairs[i - 1] + stairs[i -2];
    }
    return stairs[n - 1];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n", climbStairs(3));
    return 0;
}
