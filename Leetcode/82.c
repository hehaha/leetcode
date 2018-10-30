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

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) {
        return NULL;
    }
    struct ListNode *last = head, *next = head->next, *before = NULL;
    if (!next) {
        return head;
    }
    while(next) {
        int duplicate = 0;
        while(next && last->val == next->val) {
            next = next->next;
            duplicate = 1;
        }
        if (!next) {
            if (before && duplicate) {
                before->next = NULL;
            }
            else if (duplicate && !before) {
                head = NULL;
            }
            return head;
        }
        else if (duplicate) {
            if (!before) {
                head = next;
            }
            else {
                before->next = next;
            }
        }
        else {
            before = last;
        }
        last = next;
        next = next->next;
    }
    return head;
}


int main(int argc, const char * argv[]) {
    printf("%p\n", deleteDuplicates(NULL));
    return 0;
}
