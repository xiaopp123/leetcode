#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
		ListNode* l0 = res;
        int carry = 0;
        int sum = 0;
        while(l1 || l2) {
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;
            sum = n1 + n2 + carry;
            carry = sum / 10;
            l0->next = new ListNode(sum % 10);
			l0 = l0->next;
			if(l1) {
				l1 = l1->next;
			}
			if(l2) {
				l2 = l2->next;
			}
        }
		if (carry) {
			l0->next = new ListNode(carry);
		}

        return res->next;
    }
};

int main() {
    ListNode* l1 = new ListNode(0);
	ListNode* lt1 = l1;
	ListNode* l2 = new ListNode(0);
	ListNode* lt2 = l2;
	int len1, len2;
	int t;
	cin >> len1 >> len2;
	for (int i = 0; i < len1; i++) {
		cin >> t;
		lt1->next = new ListNode(t);
		lt1 = lt1->next;
	}
	for (int i = 0; i < len2; i++) {
		cin >> t;
		lt2->next = new ListNode(t);
		lt2 = lt2->next;
	}
//	while (l1) {
//		cout << l1->val << endl;
//		l1 = l1->next;
//	}
	Solution* solution = new Solution();
	ListNode* res = solution->addTwoNumbers(l1->next, l2->next);
	while (res) {
		cout << res->val << endl;
		res = res->next;
	}

    return 0;
}
