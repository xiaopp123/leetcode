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
