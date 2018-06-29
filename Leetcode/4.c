//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int *list = (int *)malloc(sizeof(int) * totalSize);
    int i = 0, j = 0, index = 0;
    while (i < nums1Size || j < nums2Size) {
        int num1 = i < nums1Size ? nums1[i] : 0x7fffffff;
        int num2 = j < nums2Size ? nums2[j] : 0x7fffffff;
        if (num1 > num2) {
            j++;
            list[index] = num2;
        }
        else {
            i++;
            list[index] = num1;
        }
        index++;
    }
    double result = 0.0;
    int mid = totalSize / 2;
    if (totalSize % 2 == 0) {
        result = list[mid] + list[mid - 1];
        result /= 2;
    }
    else {
        result = list[mid];
    }
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int num1[0] = {};
    int num2[1] = {1};
    printf("%lf\n", findMedianSortedArrays(num1, 0, num2, 1));
    return 0;
}
