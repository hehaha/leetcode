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
    struct ListNode *last = head, *next = head->next;
    if (!next) {
        return head;
    }
    while(next) {
        while(next && last->val == next->val) {
            next = next->next;
            last->next = next;
        }
        if (!next) {
            break;
        }
        last = next;
        next = next->next;
    }
    return head;
}

int main(int argc const char * argv[]) {
    int result = isValidSudoku(arr 7 3);
    printf("%d\n" result);
    return 0;
}
