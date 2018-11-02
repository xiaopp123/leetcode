#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 * 两种方法
 * 1、一个节点扫描一遍
 * 2、两个节点，保持间距
 * 看了人家的代码发现好简单，自己却鼓捣了一个多小时
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first, *second, *p;
        first = head;
        second = head;
        p = head;

        for (int i = 0; i < n - 1; i++) {
            second = second->next;
        }
        if (second == NULL || second->next == NULL) {
            head = head->next;
            return head;
        }
        while (second->next ) {
            p = first;
            first = first->next;
            second = second->next;
        }
        p->next = first->next;
        return head;
    }

    /**
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        len = len - n + 1;

        temp = head;
        ListNode* p = head;
        if (len == 1) {
            head = head->next;
            return head;
        }
        for (int i = 1; i < len; i++) {
            p = temp;
            temp = temp->next;
        }
        p->next = temp->next;

        return head;
    }
    */
};

int main() {
    Solution * soluton = new Solution();
    int n;

    ListNode *head  = NULL;
    ListNode *p = NULL;

    for (int i = 1; i < 6; i++) {
        ListNode *t = new ListNode(i);
        if (i == 1) {
            head = t;
            p = t;
        } else {
            p ->next = t;
            p = t;
        }
    }

    head = soluton->removeNthFromEnd(head, 1);
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }


    return 0;
}
