#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * https://leetcode.com/problems/sudoku-solver/
 * 递归回溯
 * 对每一个空位置，尝试去放1-9，然后递归，如果true的话就返回
 * 否则退出之前放的数
 */

class Solution {
    private:
        map<int, set<int> > row;
        map<int, set<int> > col;
        map<int, set<int> > sudo;
    public:
    void solveSudoku(vector<vector<char> >& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[i].insert(board[i][j] - '0');
                    col[j].insert(board[i][j] - '0');
                    sudo[i / 3 * 3 + j / 3].insert(board[i][j] - '0');
                }
            }
        }
        solve(board);
    }

    bool solve(vector<vector<char> >& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k < 10; k++) {
                        if (row[i].count(k) == 0 && col[j].count(k) == 0 && sudo[i / 3 * 3 + j / 3].count(k) == 0) {
                            board[i][j] = k + '0';
                            row[i].insert(k);
                            col[j].insert(k);
                            sudo[i / 3 * 3 + j / 3].insert(k);
                            if(solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                            row[i].erase(k);
                            col[j].erase(k);
                            sudo[i / 3 * 3 + j / 3].erase(k);
                        }
                    }
                    // 1-9都试过了，返回false
                    return false;
                }
            }
        }
        //所有的位置都遍历完了，返回true
        return true;
    }
};
int main() {

    return 0;
}
