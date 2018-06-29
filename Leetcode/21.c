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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL, *node = NULL, *current = NULL;
    while(l1 || l2) {
        if (!l1) {
            if (!head) {
                head = l2;
            }
            else {
                node->next = l2;
            }
            break;
        }
        if (!l2) {
            if (!head) {
                head = l1;
            }
            else {
                node->next = l1;
            }
            break;
        }
        int val1 = l1->val;
        int val2 = l2->val;
        if (val1 > val2) {
            node = l2;
            l2 = l2->next;
        }
        else {
            node = l1;
            l1 = l1->next;
        }
        if (!head) {
            head = node;
            current = node;
            continue;
        }
        current->next = node;
        current = node;
    }
    return head;
}

int main(int argc const char * argv[]) {
    int result = isValidSudoku(arr 7 3);
    printf("%d\n" result);
    return 0;
}
