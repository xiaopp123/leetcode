#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        while (pre->next && pre->next->next) {
            ListNode* t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = pre->next->next;
        }

        return dummy->next;
    }
};

int main() {
    return 0;
}
