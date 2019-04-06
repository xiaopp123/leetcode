#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    private:
        bool dfs(int x, int y, int index, vector<vector<char> > & board, string word, vector<vector<bool> >&vis) {
            if (index == (int)word.length()) {
                return true;
            }
            if (x < 0 || y < 0 || x >= (int)board.size() || y >= (int)board[0].size() || vis[x][y] || word[index] != board[x][y]) {
                return false;
            }
            vis[x][y] = true;

            bool ret = dfs(x - 1, y, index + 1, board, word, vis) || dfs(x + 1, y, index + 1, board, word, vis) ||
                       dfs(x, y - 1, index + 1, board, word, vis) || dfs(x, y + 1, index + 1, board, word, vis);

            vis[x][y] = false;
            return ret;
        }

    public:
    bool exist(vector<vector<char> > & board, string word) {
        if (board.empty() || board[0].empty()) {
            return word == "";
        }
        int m = (int)board.size();
        int n = (int)board[0].size();
        vector<vector<bool> > vis(m, vector<bool>(m, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, board, word, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {

    return 0;
}
