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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        getInorder(root, res);

        return res;
    }
    void getInorder(TreeNode* root, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        getInorder(root->left, res);
        res.push_back(root->val);
        getInorder(root->right, res);
    }
};

int main() {

    return 0;
}
