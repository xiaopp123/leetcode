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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            if (--k == 0) {
                return st.top()->val;
            }
            p = st.top()->right;
            st.pop();
        }
        return 0;
    }
};

/*
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestDFS(root, k);
    }
    int kthSmallestDFS(TreeNode* root, int& k) {
        if (!root) {
            return -1;
        }
        int val = kthSmallestDFS(root->left, k);
        if (k == 0) {
            return val;
        }
        if (--k == 0) {
            return root->val;
        }
        return kthSmallestDFS(root->right, k);
    }
};
*/

int main() {
    return 0;
}
