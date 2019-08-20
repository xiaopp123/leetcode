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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while (cur || !st.empty()) {
            if (cur) {
                res.push_back(cur->val);
                if (cur->right) {
                    st.push(cur->right);
                }
                if (cur->left) {
                    st.push(cur->left);
                }
            }
            if (!st.empty()) {
                cur = st.top();
                st.pop();
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
