#include "heads.h"
using namespace std;

class Solution {
    public:
    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& mp) {
        if (x - 1 >= 0 && matrix[x - 1][y] > matrix[x][y] && mp[x - 1][y] < mp[x][y] + 1) {
            mp[x - 1][y] = mp[x][y] + 1;
            dfs(x - 1, y, matrix, mp);
        }
        if (x + 1 < (int)matrix.size() && matrix[x + 1][y] > matrix[x][y] && mp[x + 1][y] < mp[x][y] + 1) {
            mp[x + 1][y] = mp[x][y] + 1;
            dfs(x + 1, y, matrix, mp);
        }
        if (y - 1 >= 0 && matrix[x][y - 1] > matrix[x][y] && mp[x][y - 1] < mp[x][y] + 1) {
            mp[x][y - 1] = mp[x][y] + 1;
            dfs(x, y - 1, matrix, mp);
        }
        if (y + 1 < (int)matrix[0].size() && matrix[x][y + 1] > matrix[x][y] && mp[x][y + 1] < mp[x][y] + 1) {
            mp[x][y + 1] = mp[x][y] + 1;
            dfs(x, y + 1, matrix, mp);
        }

        return 0;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> mp(n, vector<int>(m, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, matrix, mp);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, mp[i][j]);
            }
        }

        return res;
    }
};

int main() {

    return 0;
}
