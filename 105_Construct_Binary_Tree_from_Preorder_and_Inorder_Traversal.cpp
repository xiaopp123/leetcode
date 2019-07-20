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
    TreeNode* dfs(vector<int>& preorder, int k, int i, int j,  vector<int>& inorder) {
        if (k < 0 || k > (int)preorder.size() - 1) {
            return NULL;
        }
        if (i > j) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[k]);
        int t = i;
        while (t <= j) {
            if (inorder[t] == preorder[k]) {
                break;
            }
            t++;
        }

        root->left = dfs(preorder, k + 1, i, t - 1, inorder);
        root->right = dfs(preorder, k + t - i + 1, t + 1, j, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, 0, 0, inorder.size() - 1, inorder);
    }

};

int main () {
    return 0;
}
