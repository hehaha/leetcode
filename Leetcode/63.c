//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int map[100][100];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            map[i][j] = 0;
        }
    }
    map[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
    int row = 0, col = 0;
    int rowS = 0, colS = 0;
    while (++row < obstacleGridRowSize && !rowS) {
        rowS = obstacleGrid[row][0] == 1;
        map[row][0] = map[row - 1][0] && !rowS;
    }
    while (++col < obstacleGridColSize && !colS) {
        colS = obstacleGrid[0][col] == 1;
        map[0][col] = map[0][col - 1] && !colS;
    }
    for (int i = 1; i < obstacleGridRowSize; i++) {
        for (int j = 1; j < obstacleGridColSize; j++) {
            map[i][j] = obstacleGrid[i][j] == 1 ? 0 : map[i][j - 1] + map[i - 1][j];
        }
    }
    return map[obstacleGridRowSize - 1][obstacleGridColSize - 1];
}

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
    int r[6] = {0, 1, 0, 0, 1, 0};
    int *p1 = r;
    int *p2 = r + 3;
//    int *p3 = r + 4;
    int *g[2];
    g[0] = p1;
    g[1] = p2;
//    g[2] = p3;
    printf("%d\n", uniquePathsWithObstacles(g, 2, 3));
    return 0;
}
