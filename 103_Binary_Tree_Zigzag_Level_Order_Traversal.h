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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        vector<TreeNode*> row;
        row.push_back(root);
        queue<vector<TreeNode*>> que;
        que.push(row);
        bool flag = false;
        while (!que.empty()) {
            row = que.front();
            que.pop();
            vector<int> row_val;
            for (int i = 0; i < (int)row.size(); i++) {
                row_val.push_back(row[i]->val);
            }
            if (flag) {
                reverse(row_val.begin(), row_val.end());
            }
            res.push_back(row_val);
            flag = !flag;
            vector<TreeNode*> next_row;
            next_row.clear();
            for (int i = 0; i < (int)row.size(); i++) {
                if (row[i]->left) {
                    next_row.push_back(row[i]->left);
                }
                if (row[i]->right) {
                    next_row.push_back(row[i]->right);
                }
            }
            if (next_row.size() > 0) {
                que.push(next_row);
            }
        }
        return res;
    }
};
