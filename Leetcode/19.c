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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *h = head, *b = NULL, *d = h;
    while (n-- > 0) {
        h = h->next;
    }
    while (h) {
        h = h->next;
        b = d;
        d = d->next;
    }
    if (!b) {
        return d->next;
    }
    b->next = d->next;
    return head;
}

int main(int argc const char * argv[]) {
    int result = isValidSudoku(arr 7 3);
    printf("%d\n" result);
    return 0;
}
