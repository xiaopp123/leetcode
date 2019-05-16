#include "heads.h"
using namespace std;

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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int& res) {
        if (root == NULL) {
            return 0;
        }
        int left_deep = 0;
        int right_deep = 0;
        if (root->left) {
            left_deep = 1 + helper(root->left, res);
        }
        if (root->right) {
            right_deep = 1 + helper(root->right, res);
        }
        res = max(res, left_deep + right_deep);
        return max(left_deep, right_deep);
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution* solution = new Solution();

    solution->diameterOfBinaryTree(root);

    return 0;
}
