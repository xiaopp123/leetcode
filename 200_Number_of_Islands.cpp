#include "heads.h"
using namespace std;
class Solution {
    public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        vector<pair<int, int>> dir_xy;
        dir_xy.push_back(make_pair(-1, 0));
        dir_xy.push_back(make_pair(1, 0));
        dir_xy.push_back(make_pair(0, -1));
        dir_xy.push_back(make_pair(0, 1));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0' || vis[i][j]) {
                    continue;
                }
                res++;
                vis[i][j] = true;
                queue<int> que({i * m + j});
                while (!que.empty()) {
                    int targ = que.front();
                    que.pop();
                    int x = targ / m;
                    int y = targ % m;
                    for (int k = 0; k < (int)dir_xy.size(); k++) {
                        int dx = x + dir_xy[k].first;
                        int dy = y + dir_xy[k].second;
                        if (dx < 0 || dy < 0 || dx >= n || dy >= m || vis[dx][dy] || grid[dx][dy] == '0') {
                            continue;
                        }
                        vis[dx][dy] = true;
                        que.push(dx * m + dy);
                    }
                }
            }
        }
        return res;
    }
};

/*
class Solution {
    public:
    bool dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        if (i >= n || j >= m || i < 0 || j < 0) {
            return 0;
        }
        if (grid[i][j] == '0' || vis[i][j]) {
            return 0;
        }
        vis[i][j] = true;
        dfs(i - 1, j, n, m, grid, vis);
        dfs(i + 1, j, n, m, grid, vis);
        dfs(i, j - 1, n, m, grid, vis);
        dfs(i, j + 1, n, m, grid, vis);

        return 0;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();
        if (m == 0) {
            return 0;
        }
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vis[i][j] == false) {
                    dfs(i, j, n, m, grid, vis);
                    res++;
                }
            }
        }
        return res;
    }
};
*/

int main() {
    return 0;
}
