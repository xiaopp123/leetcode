#include "heads.h"
using namespace std;

/**
 * Definition for singly-linked list.
 *
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* slow, *fast;
        slow = fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;
        slow = reverseList(slow);

        /*
        ListNode* testNode = slow;
        while (testNode) {
            cout << testNode->val << endl;
            testNode = testNode->next;
        }
        */

        fast = head;
        while (slow) {
            if (fast->val != slow->val) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }

        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = newHead;
            newHead = tmp;
        }

        return newHead;
    }
};

int main() {
    int n;
    cin >> n;
    ListNode* head = new ListNode(-1);
    ListNode* tmp = head;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        ListNode* t = new ListNode(v);
        head->next = t;
        head = t;
    }
    Solution* solution = new Solution();
    cout << solution->isPalindrome(tmp->next) << endl;

    return 0;
}
