#include <iostream>
#include <cstdio>
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
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != tail && fast->next->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* curNode = new TreeNode(slow->val);
        curNode->left = buildTree(head, slow);
        curNode->right = buildTree(slow->next, tail);

        return curNode;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        return buildTree(head, NULL);
    }
};

int main() {

    return 0;
}
