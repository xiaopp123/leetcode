#include <cstdio>
#include <iostream>
#include <cstring>
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
 * 先求长度，然后用k对len取模，此时的k就是要旋转的
 * 然后查找到len-k个位置的节点
 * 进行重组
 *
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        if (len <= 1) {
            return head;
        }
        k = k % len;
        ListNode* parent = head;
        temp = head->next;
        int n = 0;
        while (n < len - k - 1) {
            temp = temp->next;
            parent = parent->next;
            n++;
        }
        parent->next = NULL;
        ListNode* last = temp;
        while (last) {
            last = last->next;
        }
        last->next = head;

        return temp;
    }
};
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == NULL) {
            return head;
        }
        int len = 0;
        ListNode* first = head, *last;
        //计算长度和求最后一个节点
        while (head) {
            len++;
            last = head;
            head = head->next;
        }

        k = k % len;
        int n = 0;
        head = first;
        while ((++n) != (len - k)) {
            head = head->next;
        }
        //head即为要断开的父节点，
        last->next = first;
        first = head->next;
        head->next = NULL;

        return first;
    }
};


int main () {
    Solution* solution = new Solution();
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k;
    cin >> k;
    solution->rotateRight(head, k);

    return 0;
}
