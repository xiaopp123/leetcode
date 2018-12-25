#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
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
 * 设置两个指针，第一个是最后一个小于x的位置low，第二个是链表的尾节点
 * 当前节点 大于 目标，直接插入到链表表尾
 * 当前节点 小于 目标，插入到low后面，
 * 初始化low = tail,
 * 当插入在第一个low后面时，需要根据low == tail判断是否修改tail,
 *  low == tail时，插入low节点后，tail也要改变，
 *  low ！= tail时，tail就不需要改变
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* res = new ListNode(-1);
        ListNode* low = res, *tail = res;
        while (head) {
            ListNode* tmp = head->next;
            if (head->val < x) {
                head->next = low->next;
                low->next = head;
                if (low == tail) {
                    low = low->next;
                    tail = low;
                } else {
                    low = low->next;
                }
            } else {
                head->next = tail->next;
                tail->next = head;
                tail = tail->next;
            }
            head = tmp;
        }
        return res->next;
    }
};

int main() {
    return 0;
}
