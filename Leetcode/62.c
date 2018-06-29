//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

int uniquePaths(int m, int n) {
    int map[10][10];
    map[0][0] = 1;
    int row = n, col = m;
    while (row-- > 0) {
        map[row][0] = 1;
    }
    while (col-- > 0) {
        map[0][col] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            map[i][j] = map[i][j - 1] + map[i - 1][j];
        }
    }
    return map[n - 1][m - 1];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n", uniquePaths(7, 3));
    return 0;
}
