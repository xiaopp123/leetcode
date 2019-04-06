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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

/*
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            depth++;
            int que_size = que.size();
            for (int i = 0; i < que_size; i++) {
                TreeNode* top = que.front();
                que.pop();
                if (top->left) {
                    que.push(top->left);
                }
                if (top->right) {
                    que.push(top->right);
                }
            }
        }
        return depth;
    }
};
*/
int main() {

    return 0;
}
