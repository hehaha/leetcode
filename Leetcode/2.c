//
//  main.c
//  Leetcode
//
//  Created by wecash on 2018/6/21.
//  Copyright © 2018年 wecash. All rights reserved.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* number2List(long num) {
    struct ListNode* l = malloc(sizeof(struct ListNode));
    if (!num) {
        l->val = 0;
        return l;
    }
    struct ListNode* current = l;
    while (num) {
        current->val = num % 10;
        num = num / 10;
        if (num) {
            struct ListNode* next = malloc(sizeof(struct ListNode));
            current->next = next;
            current = current->next;
        }
        else {
            current->next = NULL;
        }
    }
    return l;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* current1 = l1;
    struct ListNode* current2 = l2;
    struct ListNode* l = head;
    int plus = 0;
    while (current1 || current2) {
        int num1 = 0, num2 = 0;
        if (current1){
            num1 = current1->val;
            current1 = current1->next;
        }
        if (current2){
            num2 = current2->val;
            current2 = current2->next;
        }
        int val = num2 + num1 + plus;
        if (val >= 10) {
            plus = 1;
            val -= 10;
        }
        else {
            plus = 0;
        }
        l->val = val;
        if (current1 || current2) {
            struct ListNode* next = malloc(sizeof(struct ListNode));
            l->next = next;
            l = l->next;
        }
        else if (plus) {
            struct ListNode* next = malloc(sizeof(struct ListNode));
            next->next = NULL;
            next->val = 1;
            l->next = next;
            l = l->next;
        }
        else {
            l->next = NULL;
        }
    }
    return head;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode* l1 = number2List(99);
    struct ListNode* l2 = number2List(1);
    struct ListNode* l = addTwoNumbers(l1, l2);
    while (l) {
        printf("%d", l->val);
        l = l->next;
    }
    printf("\n");
    return 0;
}
