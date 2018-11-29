#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/
 * 主要的知识就是反转链表
 * 但是还要注意一些细节
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;

        int t = 0;
        ListNode* pre = head;
        ListNode* end = head;
        while (end->next != NULL) {
            //当前指针处于真正开始的前一个，所以要判断end->next是否为空
            while (t < k && end->next) {
                t++;
                end = end->next;
            }
            //最后不足k就不用反转了
            if (t < k) {
                break;
            }
            //反正的区间是(pre, pre + k - 1]
            //所以反转完后 将反转的插入到pre后面
            pre->next = reversed(pre, k);

            //然后从pre开始继续找k个，进行下一次的反转
            for (int i = 0; i < k; i++) {
                pre = pre->next;
            }
            end = pre;
            t = 0;
        }

        return head->next;
    }

public:
    ListNode* reversed(ListNode* head, int k) {
        //这就是反转k个节点的链表
        ListNode* reversedL = head;
        head = head->next;
        for(int i = 0; i < k; i++) {
            ListNode* t = head;
            ListNode* headNext = head->next;
            t->next = reversedL->next;
            reversedL->next = t;
            head = headNext;
        }

        //反转完之后要将最后反转的那个节点的next放到反转后的后面，也就是head指向的是后面的还没反转的
        ListNode* tmp = reversedL;
        for (int i = 0; i < k; i++) {
            tmp = tmp->next;
        }
        //需要将后面的还未反转的放到反转的后面
        tmp->next = head;

        return reversedL->next;
    }
};

int main() {

    ListNode* head = new ListNode(0);
    ListNode* t = head;
    for (int i = 1; i < 6; i++) {
        t->next = new ListNode(i);
        t = t->next;
    }
    Solution* solution =  new Solution();
    solution->reverseKGroup(head->next, 2);

    return 0;
}
