#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    int dfs(TreeNode* root, int level, vector<vector<int>>& res) {
        if (!root) {
            return 0;
        }
        if ((int)res.size() == level) {
            res.push_back({});
        }
        res[level].push_back(root->val);
        dfs(root->left, level + 1, res);
        dfs(root->right, level + 1, res);

        return 0;
    }
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        dfs(root, 0, res);
        return res;
    }
};

class Solution {
    public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> one_leval;
            one_leval.clear();
            int n = que.size();
            for (int i = 0; i < n; i++) {
                TreeNode* tmp = que.front();
                que.pop();
                one_leval.push_back(tmp->val);
                if (tmp->left) {
                    que.push(tmp->left);
                }
                if (tmp->right) {
                    que.push(tmp->right);
                }
            }
            res.push_back(one_leval);
        }
        return res;
    }
};

class Solution {
    public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL) {
            return res;
        }
        queue<vector<TreeNode> > que;
        vector<TreeNode> itemNode;
        itemNode.push_back(*root);
        que.push(itemNode);
        while (!que.empty()) {
            itemNode  = que.front();
            que.pop();
            vector<TreeNode> nextLayer;
            vector<int> itemRes;
            for (int i = 0; i < (int) itemNode.size(); i++) {
                TreeNode node = itemNode[i];
                itemRes.push_back(node.val);
                if (node.left != NULL) {
                    nextLayer.push_back(*node.left);
                }
                if (node.right != NULL) {
                    nextLayer.push_back(*node.right);
                }
            }
            if (nextLayer.size() > 0) {
                que.push(nextLayer);
            }
            res.push_back(itemRes);
        }

        return res;
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution* solution = new Solution();
    vector<vector<int> > res = solution->levelOrder(root);

    return 0;
}
