#include "heads.h"
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    int res = 0;
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return search_tree(root, 0);
    }

    int search_tree(TreeNode* root, int val) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return val * 10 + root->val;
        }
        return search_tree(root->left, val * 10 + root->val) +
            search_tree(root->right, val * 10 + root->val);
    }
    /*
    int search_tree(TreeNode* root, int val) {
        if (root->left == NULL && root->right == NULL) {
            res += val * 10 + root->val;
            return 0;
        }
        if (root->left) {
            search_tree(root->left, val * 10 + root->val);
        }
        if (root->right) {
            search_tree(root->right, val * 10 + root->val);
        }

        return 0;
    }
    */
};

int main() {

    return 0;
}
