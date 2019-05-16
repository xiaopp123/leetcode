#include "heads.h"
using namespace std;

/*
// Definition for a Node.
*/
class Node {
    public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
            val = _val;
            left = _left;
            right = _right;
            next = _next;
        }
};
/*
class Solution {
    public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }
        if (root->left) {
            root->left->next = root->right;
        }
        if (root->right) {
            root->right->next = root->next == NULL ? NULL : root->next->right;
        }
        connect(root->left);
        connect(root->right);

        return root;
    }
};
*/
class Solution {
    public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int n = que.size();
            for (int i = 0; i < n; i++) {
                Node* tmp = que.front();
                que.pop();
                if (i < n - 1) {
                    tmp->next = que.front();
                }
                if (tmp->left) {
                    que.push(tmp->left);
                }
                if (tmp->right) {
                    que.push(tmp->right);
                }
            }
        }
        return root;
    }
};

int main() {
    return 0;
}
