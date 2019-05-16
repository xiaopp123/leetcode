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
    TreeNode* convertBST(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        int sum = 0;
        dfs(root, sum);
        return root;
    }
    int dfs(TreeNode* root, int& sum) {
        if (root->left == NULL && root->right == NULL) {
            root->val += sum;
            sum = root->val;
            return 0;
        }
        if (root->right) {
            dfs(root->right, sum);
        }
        root->val += sum;
        sum = root->val;
        if (root->left) {
            dfs(root->left, sum);
        }

        return 0;
    }
};

int main() {
    return 0;
}

