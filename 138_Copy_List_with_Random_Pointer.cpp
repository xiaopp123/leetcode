#include "heads.h"
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        return helper(head, mp);
    }
    Node* helper(Node* cur, map<Node*, Node*>& mp) {
        if (!cur) {
            return cur;
        }
        if (mp.count(cur)) {
            return mp[cur];
        }
        Node* tmp = new Node(cur->val, nullptr, nullptr);
        mp[cur] = tmp;
        tmp->next = helper(cur->next, mp);
        tmp->random = helper(cur->random, mp);

        return tmp;
    }
};
/*
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }
        map<Node*, Node*> mp;
        Node* node = head;
        Node* res = new Node(head->val, nullptr, nullptr);
        Node* tmp = res;
        mp[node] = res;

        while (node->next) {
            node = node->next;
            tmp->next = new Node(node->val, nullptr, nullptr);
            tmp = tmp->next;
            mp[node] = tmp;
        }
        node = head;
        res->random = mp[head->random];
        tmp = res;
        while (node->next) {
            node = node->next;
            tmp = tmp->next;
            tmp->random = mp[node->random];
        }

        return res;
    }
};
*/

int main() {

    return 0;
}
