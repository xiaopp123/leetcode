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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        int lower_limit = INT_MIN;
        while (root || !st.empty()) {
            while (root) {
                st.push(root->left);
                root = root->left;
            }
            TreeNode* top = st.top();
            st.pop();
            if (top->val > lower_limit) {
                lower_limit = top->val;
                root = top->right;
            } else {
                return false;
            }
        }
        return true;
    }
};
/*
class Solution {
public:
    bool isBSTHelper(TreeNode* root, int lower_limit, int upper_limit) {
        if (root->val <= lower_limit || root->val >= upper_limit) {
            return false;
        }
        bool left = true;
        if (root->left) {
            left = isBSTHelper(root->left, lower_limit, root->val);
        }
        if (left) {
            if (root->right) {
                return isBSTHelper(root->right, root->val, upper_limit);
            } else {
                return true;
            }
        } else {
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isBSTHelper(root, INT_MIN, INT_MAX);
    }
};
*/

int main() {

    return 0;
}
