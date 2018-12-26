#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/**
 *  * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
/**
 * 对一个链表进行排序，使用归并排序方法
 * 先找到中间位置，进行二分，这里使用快慢指针方法
 * 左右两个链表递归进行排序
 * 合并链表
 */
class Solution {
    public:
        ListNode* mergeList(ListNode* l1, ListNode* l2) {
            ListNode* dumpy = new ListNode(-1);
            ListNode* tmp = dumpy;
            while (l1 != NULL && l2 != NULL) {
                if (l1->val < l2->val) {
                    tmp->next = l1;
                    l1 = l1->next;
                } else {
                    tmp->next = l2;
                    l2 = l2->next;
                }
                tmp = tmp->next;
            }
            if (l1) {
                tmp->next = l1;
            }
            if (l2) {
                tmp->next = l2;
            }

            return dumpy->next;
        }
    public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(fast);

        return mergeList(l1, l2);
    }
};

int main() {
    int n;
    while (cin >> n) {
        ListNode* head = new ListNode(-1);
        ListNode* tmp = head;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            ListNode* t = new ListNode(v);
            tmp->next = t;
            tmp = tmp->next;
        }
        Solution* solution = new Solution();
        ListNode* res = solution->sortList(head->next);
        while (res) {
            cout << res->val << " ";
            res = res->next;
        }
    }
    return 0;
}
