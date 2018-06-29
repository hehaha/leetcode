//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
    long longX = x;
    long result = 0;
    long plusX = longX < 0 ? -longX : longX;
    while(plusX) {
        result = result * 10 + plusX % 10;
        plusX = plusX / 10;
    }
    if (result > 0x7fffffff) {
        return 0;
    }
    if (x < 0) {
        result = -result;
    }
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n", reverse(-2147483648));
    return 0;
}
