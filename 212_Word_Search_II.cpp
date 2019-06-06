#include "heads.h"
using namespace std;

class Solution {
    public:
    struct TrieNode {
        TrieNode* child[26];
        string str;
        TrieNode() : str("") {
            for (auto &a : child) {
                a = NULL;
            }
        }
    };
    struct Trie {
        TrieNode* root;
        Trie() : root(new TrieNode()){}
        void insert(string word) {
            TrieNode* p = root;
            for (auto &a : word) {
                int i = a - 'a';
                if (!p->child[i]) {
                    p->child[i] = new TrieNode();
                }
                p = p->child[i];
            }
            p->str = word;
        }
    };

    public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || board[0].empty()) {
            return res;
        }
        Trie T;
        for (auto &word : words) {
            T.insert(word);
        }
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (T.root->child[board[i][j] - 'a']) {
                    search(board, T.root->child[board[i][j] - 'a'], i, j, visit, res);
                }
            }
        }
        return res;
    }

    int search(vector<vector<char>>& board, TrieNode* p, int i, int j, vector<vector<bool>>& visit, vector<string>& res) {
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();
        }
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visit[i][j] = true;
        for (auto &a : d) {
            int dx = a[0] + i;
            int dy = a[1] + j;
            if (dx >= 0 && dx < (int)board.size() && dy >= 0 && dy < (int)board[0].size() \
                && p->child[board[dx][dy] - 'a'] && visit[dx][dy] == false) {
                search(board, p->child[board[dx][dy] - 'a'], dx, dy, visit, res);
            }
        }
        visit[i][j] = false;
        return 0;
    }
};

int main() {
    return 0;
}
