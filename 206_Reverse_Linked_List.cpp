#include <cstdio>
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = new ListNode(0);
        while (head) {
            ListNode* t = head;
            head = head->next;
            t->next = pre->next;
            pre->next = t;
        }
        return pre->next;
    }
};

int main() {

    return 0;
}
