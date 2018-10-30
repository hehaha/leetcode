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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode *stack[100] = {}, *node = root;
    int top = 0, size = 0;
    int *result = malloc(sizeof(int) * 1000);
    stack[top++] = root;
    while(node && top) {
        struct TreeNode *left = node->left;
        if (left) {
            stack[top++] = left;
            node->left = NULL;
            node = left;
            continue;
        }
        result[size++] = node->val;
        top--;
        struct TreeNode *right = node->right;
        if (right) {
            stack[top++] = right;
            node = right;
        }
        else if (top) {
            node = stack[top-1];
        }
    }
    *returnSize = size;
    return result;
}


int main(int argc, const char * argv[]) {
    int returnSize = 0;
    printf("%d\n", inorderTraversal(NULL, &returnSize));
    return 0;
}
