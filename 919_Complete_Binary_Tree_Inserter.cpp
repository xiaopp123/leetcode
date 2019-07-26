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

class CBTInserter {
public:
    vector<TreeNode*> a;
    CBTInserter(TreeNode* root) {
        a.clear();
        a.push_back(NULL);
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int n = que.size();
            for (int i = 0; i < n; i++) {
                TreeNode* tmp = que.front();
                que.pop();
                a.push_back(tmp);
                if (tmp->left) {
                    que.push(tmp->left);
                }
                if (tmp->right) {
                    que.push(tmp->right);
                }
            }
        }
    }

    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        int len = a.size();
        if (len % 2 == 0) {
            a[len / 2]->left = node;
        } else {
            a[len / 2]->right = node;
        }
        a.push_back(node);

        return a[len / 2]->val;
    }

    TreeNode* get_root() {
        return a[1];
    }
};

int main() {
    return 0;
}
