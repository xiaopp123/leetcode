#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * https://leetcode.com/problems/maximal-square/
 * dp题
 * dp[i][j]表示以(i,j)为右下角的正方形的最大边长
 * (i,j)可以由三个地方更新，上面(i - 1, j),左边(i, j - 1), 斜上角(i - 1, j - 1)
 * 取这三个中最小的那个
 * dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1
 */
class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int> > len(n, vector<int>(m,0));
        int maxLen = 0;
        for (int i = 0; i < m; i++) {
            len[0][i] = matrix[0][i] - '0';
            maxLen = max(maxLen, len[0][i]);
        }
        for (int i = 0; i < n; i++) {
            len[i][0] = matrix[i][0] - '0';
            maxLen = max(maxLen, len[i][0]);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '0') {
                    len[i][j] = 0;
                } else {
                    len[i][j] = min(min(len[i - 1][j], len[i][j - 1]), len[i - 1][j - 1]) + 1;
                    maxLen = max(maxLen, len[i][j]);
                }
            }
        }
        return maxLen * maxLen;
    }
};

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char> > matrix;
        for (int i = 0; i < n; i++) {
            vector<char> row;
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                row.push_back(c);
            }
            matrix.push_back(row);
        }
        Solution* solution = new Solution();
        cout << solution->maximalSquare(matrix) << endl;
    }
    return 0;
}
