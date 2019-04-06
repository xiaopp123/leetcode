#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = (int) grid.size();
        int n = (int) grid[0].size();
        int sum[m][n];
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < m; i++) {
            if (i == 0) {
                sum[i][0] = grid[i][0];
            } else {
                sum[i][0] = sum[i - 1][0] + grid[i][0];
            }
        }
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                sum[0][j] = grid[0][j];
            } else {
                sum[0][j] = sum[0][j - 1] + grid[0][j];
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
            }
        }

        return sum[m - 1][n - 1];
    }
};
int main() {
    int m, n;
    while (cin >> m >> n) {
        Solution* solution = new Solution();
        vector<vector<int> > grid;
        for (int i = 0; i < m; i++) {
            int t;
            vector<int> v;
            for (int j = 0; j < n; j++) {
                cin >> t;
                v.push_back(t);
            }
            grid.push_back(v);
        }
        cout << solution->minPathSum(grid) << endl;
    }

    return 0;
}
