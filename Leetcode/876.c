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

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* middleNode(struct ListNode* head) {
    int len = 0;
    struct ListNode* node = head;
    while (++len && node->next) {
        node = node->next;
    }
    int pos = len / 2;
    node = head;
    while (pos--) {
        node = node->next;
    }
    return node;
}


int main(int argc, const char * argv[]) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node = head;
    for (int i = 0; i < 1; i++) {
        node->val = i + 1;
        if (i < 0) {
            node->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            node = node->next;
        }
        else {
            node->next = NULL;
        }
    }
    struct ListNode* result = middleNode(head);
    while (result) {
        printf("%d\n", result->val);
        result = result->next;
    }
    return 0;
}
