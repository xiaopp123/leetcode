#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    private:
        bool dfs(int x, int y, int index, int m, int n, bool** vis, vector<vector<char> > & board, string word) {
            if (index == (int)word.length()) {
                return true;
            }
            if ( x - 1 >= 0 && vis[x - 1][y] == false) {
                if (board[x - 1][y] == word[index]) {
                    vis[x - 1][y] = true;
                    dfs(x - 1, y, index + 1, m, n, vis, board, word);
                    vis[x - 1][y] = false;
                }
            }
            if (x + 1 < m && vis[x + 1][y] == false) {
                if (board[x + 1][y] == word[index]) {
                    vis[x + 1][y] = true;
                    dfs(x + 1, y, index + 1, m, n, vis, board, word);
                    vis[x + 1][y] = false;
                }
            }
            if (y - 1 >= 0 && vis[x][y - 1] == false) {
                if (board[x][y - 1] == word[index]) {
                    vis[x][y - 1] = true;
                    dfs(x, y - 1, index + 1, m, n, vis, board, word);
                    vis[x][y - 1] = false;

                }
            }
            if (y + 1 < n && vis[x][y + 1] == false) {
                if (board[x][y + 1] == word[index]) {
                    vis[x][y + 1] = true;
                    dfs(x, y + 1, index + 1, m, n, vis, board, word);
                    vis[x][y + 1] = false;
                }
            }

            return false;
        }

    public:
    bool exist(vector<vector<char> > & board, string word) {
        int m = (int)board.size();
        int n = (int)board[0].size();
        if (word.length() == 0 || n == 0) {
            return false;
        }
        bool **vis;
        vis = new bool*[m];
        for (int i = 0; i < m; i++) {
            vis[i] = new bool[n];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    for (int k1 = 0; k1 < m; k1++) {
                        for (int k2 = 0; k2 < n; k2++) {
                            vis[k1][k2] = false;
                        }
                    }
                    vis[i][j] = true;
                    if (dfs(i, j, 1, m, n, vis, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main() {

    return 0;
}
