#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/**
 *  * Definition for a binary tree node.
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 第一种方法，直接dfs，用hash记录结点值
 * 当前节点值 = max(当前值+孙子节点，左子树 + 右子树）
 *
 */
/*
class Solution {
    public:
    int rob(TreeNode* root) {
        map<TreeNode*, int> m;

        return dfs(root, m);
    }

    int dfs(TreeNode* cur, map<TreeNode*, int> m) {
        if (!cur) {
            return 0;
        }
        if (m.count(cur) > 0) {
            return m[cur];
        }
        int val = 0;

        if (cur->left) {
            val += dfs(cur->left->left, m) + dfs(cur->left->right, m);
        }
        if (cur->right) {
            val += dfs(cur->right->left, m) + dfs(cur->right->right, m);
        }

        m[cur] = max(cur->val + val, dfs(cur->left, m) + dfs(cur->right, m));

        return m[cur];
    }
};
*/
/*第二种方法，一个二值数组，第一个值表示不取该节点，第二个值表示取该节点
 * 当前点不取，那么左儿子和右儿子节点就可以取，从中取最大的
 * res[0] = max(left[0], left[1]) + max(right[0], right[1]);
 * 当前点取 结果为当前点 + 不取左儿子+ 不取右儿子
 * res[1] = cur->val + left[0] + right[0]
 */
class Solution {
    public:
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return vector<int> (2, 0);
        }
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        vector<int> cur(2);
        cur[0] = max(left[0], left[1]) + max(right[0], right[1]);
        cur[1] = root->val + left[0] + right[0];

        return cur;
    }
};

int main() {
    return 0;
}
