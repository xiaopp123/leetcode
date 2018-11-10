#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/**
 * https://leetcode.com/problems/valid-sudoku/description/
 * 非常ugly
 *
 * 可以直接一次两重循环解决
 *     对于board[i][j]分别判断他所对应的行列和块，还有这是一个九宫格就没必要进行确定维数的操作了
 */

class Solution {
    public:
    bool isValidSudoku(vector<vector<char> >& board) {
        int h = board.size();
        bool flag = true;

        //判断行
        for (int i = 0; i < h; i++) {
            vector<char> row = board[i];
            int w = row.size();
            set<char> rows;
            rows.clear();
            for (int j = 0; j < w; j++) {
                if (row[j] != '.') {
                    if (rows.count(row[j]) == 0) {
                        rows.insert(row[j]);
                    } else {
                        flag = false;
                        return flag;
                    }
                }
            }
        }

        //判断列
        int w = board[0].size();
        for (int i = 0; i < w; i++) {
            set<char> columns;
            columns.clear();
            for (int j = 0; j < h; j++) {
                vector<char> row = board[j];
                if (row[i] != '.') {
                    if (columns.count(row[i]) == 0) {
                        columns.insert(row[i]);
                    } else {
                        flag = false;
                        return flag;
                    }
                }
            }
        }

        //判断3*3
        for (int i = 0; i < h - 2; i += 3) {
            for (int j = 0; j < w - 2; j += 3) {
                flag = judge(board, i, j);
                if (!flag) {
                    //cout << i << " " << j << endl;
                    return flag;
                }
            }
        }

        return flag;
    }
    public:
    bool judge(vector<vector<char> >& board, int h, int w) {
        set<char> q;
        q.clear();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + h][j + w] != '.') {
                    if (q.count(board[i + h][j + w]) == 0) {
                        q.insert(board[i + h][j + w]);
                    } else {
                        //cout << "3*3 = " << i << " " << j << endl;
                        return false;
                    }
                }

            }
        }

        return true;
    }
};

int main() {
    int n, m;
    vector<vector<char> > board;
    Solution* solution = new Solution();
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            vector<char> row;
            for (int j = 0; j < m; j++) {
                char ch;
                cin >> ch;
                row.push_back(ch);
            }
            board.push_back(row);
        }
        cout << solution->isValidSudoku(board) << endl;

    }

    return 0;
}
