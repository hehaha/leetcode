//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int map[1000][1000];
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            map[i][j] = 0;
        }
    }
    map[0][0] = grid[0][0];
    int row = 0, col = 0;
    while (++row < gridRowSize) {
        map[row][0] = map[row - 1][0] + grid[row][0];
    }
    while (++col < gridColSize) {
        map[0][col] = map[0][col - 1] + grid[0][col];
    }
    for (int i = 1; i < gridRowSize; i++) {
        for (int j = 1; j < gridColSize; j++) {
            int left = map[i][j - 1];
            int up = map[i - 1][j];
            map[i][j] = (left > up ? up : left) + grid[i][j];
        }
    }
    return map[gridRowSize - 1][gridColSize - 1];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int r[9] = {1, 3, 1, 1, 5, 1, 4, 2, 1};
    int *p1 = r;
    int *p2 = r + 3;
    int *p3 = r + 6;
    int *g[3];
    g[0] = p1;
    g[1] = p2;
    g[2] = p3;
    printf("%d\n", minPathSum(g, 3, 3));
    return 0;
}
