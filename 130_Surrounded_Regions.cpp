#include "heads.h"
using namespace std;

class Solution {
    public:
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < (int)board.size(); i++) {
            for (int j = 0; j < (int)board[i].size(); j++) {
                if (i == 0 || i == (int)board.size() - 1 || j == 0 || j == (int)board[i].size() - 1) {
                    if (board[i][j] == 'O') {
                        dfs(i, j, board);
                    }
                }
            }
        }
        for (int i = 0; i < (int)board.size(); i++) {
            for (int j = 0; j < (int)board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '$') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(int x, int y, vector<vector<char>>& board) {
        if (board[x][y] == 'X' || board[x][y] == '$') {
            return;
        }
        board[x][y] = '$';
        // up
        if (x - 1 >= 0) {
            dfs(x - 1, y, board);
        }
        // down
        if (x + 1 <= (int)board.size() - 1) {
            dfs(x + 1, y, board);
        }
        // left
        if (y - 1 >= 0) {
            dfs(x, y - 1, board);
        }
        //right
        if (y + 1 <= (int)board[x].size() - 1) {
            dfs(x, y + 1, board);
        }
    }
};

int main() {
    return 0;
}
