#include "heads.h"
using namespace std;

/**
 *  * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = odd->next;
        ListNode* even_head = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;

        return head;
    }
};

/*
class Solution {
    public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* odd_list = NULL;
        ListNode* odd_head = new ListNode(-1);
        ListNode* even_list = NULL;
        ListNode* even_head = new ListNode(-1);
        odd_list = odd_head;
        even_list = even_head;
        int num = 0;
        ListNode* tmp = NULL;
        while (head) {
            if (num % 2) {
                odd_head->next = head;
                odd_head = odd_head->next;
                tmp = head->next;
                head->next = NULL;
                head = tmp;
            } else {
                even_head->next = head;
                even_head = even_head->next;
                tmp = head->next;
                head->next = NULL;
                head = tmp;
            }
            num++;
        }
        if (odd_list->next) {
            even_head->next = odd_list->next;
        }
        return even_list->next;
    }
};
*/

int main() {

    ListNode* head = new ListNode(1);
    ListNode* head_2 = new ListNode(2);
    ListNode* head_3 = new ListNode(3);
    ListNode* head_4 = new ListNode(4);
    ListNode* head_5 = new ListNode(5);
    head->next = head_2;
    head_2->next = head_3;
    head_3->next = head_4;
    head_4->next = head_5;
    cout << "hhhh";

    Solution* solution = new Solution();
    solution->oddEvenList(head);


    return 0;
}
