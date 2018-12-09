#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


class Solution {
    public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = (int)obstacleGrid.size();
        int n = (int)obstacleGrid[0].size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        //初始化时，如果第一行遇到1，往后的都是0，所以直接break
        for (int i = 0; i < m; i ++) {
            if (obstacleGrid[i][0] != 1) {
                dp[i][0] = 1;
            } else {
                break;
            }
        }
        // 对列的处理也是一样的
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] != 1) {
                dp[0][i] = 1;
            } else {
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<vector<int> > obstacleGrid;
        for (int i = 0; i < m; i++) {
            int t;
            vector<int> item;
            for (int j = 0; j < n; j++) {
                cin >> t;
                item.push_back(t);
            }
            obstacleGrid.push_back(item);
        }
        Solution* solution = new Solution();
        cout << solution->uniquePathsWithObstacles(obstacleGrid) << endl;
    }
    return 0;
}
