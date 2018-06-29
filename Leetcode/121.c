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

int maxProfit(int* prices, int pricesSize) {
    int max = 0, sellIndex = 0;
    for (int i = 0; i < pricesSize; i++) {
        int val = prices[i];
        if (sellIndex && i < sellIndex) {
            max = prices[sellIndex] - val;
        }
        else {
            for (int j = i + 1; j < pricesSize; j++) {
                int profit =  prices[j] - val;
                if (profit > max) {
                    max = profit;
                    sellIndex = j;
                }
            }
        }
        while (prices[i + 1] > val) {i++;};
    }
    return max;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[6] = {7, 1, 5, 3, 6, 4};
    printf("%d\n", maxProfit(arr, 5));
    return 0;
}
