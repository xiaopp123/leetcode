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
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 * 开辟一个新的列表，第一个节点设为0，然后就想合并数组合并链表
 * 需要记录一下新列表的第一个节点
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* MergedList = new ListNode(0);
        ListNode* firstNode = MergedList;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                MergedList->next = l1;
                l1 = l1->next;
            } else {
                MergedList->next = l2;
                l2 = l2->next;
            }
            MergedList = MergedList->next;
        }
        while (l1 != NULL) {
            MergedList->next = l1;
            MergedList = MergedList->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            MergedList->next = l2;
            MergedList = MergedList->next;
            l2 = l2->next;
        }

        return firstNode->next;
    }
};

int main() {

    return 0;
}
