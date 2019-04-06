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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return;
        }
        int res = find(root, 0, sum) + find(root->left, 0, sum) + find(root->right, 0, sum);
    }
    int find(TreeNode* root, int curSum, int sum) {
        if (root == NULL) {
            return 0;
        }
        curSum += root->val;

        return (curSum == sum) + find(root->left, curSum, sum) + find(root->right, curSum, sum);
    }
};
/*
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        vector<TreeNode*> vec;
        int res = 0;
        findPath(root, sum, 0, res, vec);
        return res;
    }
    void findPath(TreeNode* root, int sum, int curSum, int &res, vector<TreeNode*> &vec) {
        if (root == NULL) {
            return;
        }
        vec.push_back(root);
        curSum += root->val;
        if (curSum == sum) {
            res++;
        }
        int tmp = curSum;
        for (int i = 0; i < (int) vec.size() - 1; i++) {
            tmp -= vec[i]->val;
            if (tmp == sum) {
                res++;
            }
        }

        findPath(root->left, sum, curSum, res, vec);
        findPath(root->right, sum, curSum, res, vec);
        vec.pop_back();
    }
};
*/

int main() {
    return 0;
}
