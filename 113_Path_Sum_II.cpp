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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> item;
        if (root == NULL) {
            return res;
        }
        DFS(root, res, item, sum);

        return res;
    }
    void DFS(TreeNode* root, vector<vector<int> >& res, vector<int> item, int sum) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            item.push_back(root->val);
            if (sumItem(item) == sum) {
                res.push_back(item);
            }
            item.pop_back();
            return;
        }
        item.push_back(root->val);
        DFS(root->left, res, item, sum);
        DFS(root->right, res, item, sum);
        item.pop_back();
    }

    int sumItem(vector<int> item) {
        int sum = 0;
        for (int i = 0; i < (int)item.size(); i++) {
            sum += item[i];
        }
        return sum;
    }
};

int main() {
    return 0;
}
