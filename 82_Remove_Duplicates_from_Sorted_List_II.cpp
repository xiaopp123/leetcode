#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * 首先有这么三个指针非常重要
 * 当前节点tmp，上一个节点parent, 下一个节点tmp->next
 * 当当前节点值与下一个节点值相等时，tmp就一直往后进行，
 * 直到 tmp->val != tmp->next->val
 * 有这么两种情况：1. tmp是一个不重复的点，2tmp是一个重复的点
 * 所以指针parent->next预先设置，对于1的情况就是parent->next == tmp, 此时parent = tmp
 *                              对于2的情况就是parent->next != tmp, 此时将parent->next = tmp->next
 *
 * 最后的时候，就是判断parent->next 是否与 tmp相等，如果不相等的话，表明tmp不可以留，parent->next = tmp->next,
 * 如果相等的话，tmp就是一个不重复的节点
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        head = pre;
        ListNode* tmp = head;
        ListNode* parent = head;
        tmp = tmp->next;
        while (tmp->next) {
             if (tmp->val != tmp->next->val) {
                 if (parent->next == tmp) {
                     parent = tmp;
                 } else {
                     parent->next = tmp->next;
                 }
            }
            tmp = tmp->next;
        }

        if (parent->next != tmp) {
            parent->next = tmp->next;
        }
        return pre->next;
    }
};

int main() {
    Solution* solution = new Solution();
    int n;
    while (cin >> n) {
        ListNode* pre = new ListNode(-1);
        ListNode* head = pre;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            ListNode* t = new ListNode(v);
            head->next = t;
            head = head->next;
        }
        ListNode* tmp = solution->deleteDuplicates(pre->next);
    }

    return 0;
}
