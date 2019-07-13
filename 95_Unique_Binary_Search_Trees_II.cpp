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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        vector<vector<vector<TreeNode*>>> mem(n, vector<vector<TreeNode*>>(n));

        return helper(1, n, mem);
    }

    vector<TreeNode*> helper(int start, int end, vector<vector<vector<TreeNode*>>>& mem) {
        if (start > end) {
            return {nullptr};
        }
        if (!mem[start - 1][end - 1].empty()) {
            return mem[start - 1][end - 1];
        }
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = helper(start, i - 1, mem);
            vector<TreeNode*> right = helper(i + 1, end, mem);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }

        return mem[start - 1][end - 1] = res;
    }
};

/*
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return helper(1, n);
    }
    vector<TreeNode*> helper(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = helper(start, i - 1);
            vector<TreeNode*> right = helper(i + 1, end);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }

        return res;
    }
};
*/

int main() {

    return 0;
}
