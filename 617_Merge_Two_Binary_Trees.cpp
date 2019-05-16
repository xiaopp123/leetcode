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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) {
            return t2;
        }
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push(make_pair(t1, t2));
        while (!que.empty()) {
            pair<TreeNode*, TreeNode*> tmp = que.front();
            que.pop();
            if (tmp.first == NULL || tmp.second == NULL) {
                continue;
            }
            tmp.first->val += tmp.second->val;
            if (tmp.first->left) {
                que.push(make_pair(tmp.first->left, tmp.second->left));
            } else {
                tmp.first->left = tmp.second->left;
            }
            if (tmp.first->right) {
                que.push(make_pair(tmp.first->right, tmp.second->right));
            } else {
                tmp.first->right = tmp.second->right;
            }
        }
        return t1;
    }
};
/*
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) {
            return t2;
        }
        if (t2 == NULL) {
            return t1;
        }
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }
};
*/

int main() {

    return 0;
}
