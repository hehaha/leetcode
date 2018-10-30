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

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    struct ListNode *oneNode = head, *twoNode = head->next, *before = NULL;
    head = NULL;
    while (oneNode && twoNode) {
        struct ListNode *next = twoNode->next;
        oneNode->next = twoNode->next;
        twoNode->next = oneNode;
        if (before) {
            before->next = twoNode;
        }
        if (!head) {
            head = twoNode;
        }
        before = oneNode;
        oneNode = next;
        if (oneNode) {
            twoNode = oneNode->next;
        }
    }
    return head;
}


int main(int argc, const char * argv[]) {
    printf("%p\n", swapPairs(NULL));
    return 0;
}
