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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        search_tree(root);

        return res;
    }

    int search_tree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int cur_val = root->val;
        int lmax = search_tree(root->left);
        int rmax = search_tree(root->right);
        if (lmax > 0) {
            cur_val += lmax;
        }
        if (rmax > 0) {
            cur_val += rmax;
        }
        res = max(res, cur_val);

        return max(root->val, max(root->val + lmax, root->val + rmax));
    }
};


int main() {

    return 0;
}
