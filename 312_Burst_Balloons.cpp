#include "heads.h"
using namespace std;

class Solution {
    public:
    int helper(int i, int j, vector<vector<int>>& dp, vector<int>& nums) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j] > 0) {
            return dp[i][j];
        }
        for (int k = i; k <= j; k++) {
            int left = helper(i, k - 1, dp, nums);
            int right = helper(k + 1, j, dp nums);
            dp[i][j] = max(dp[i][j], left + right + nums[k] * nums[i - 1] * nums[j + 1]);
        }
        return dp[i][j];
    }
    int maxCoins(vector<int>& nums) {
        int n = (int)nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        return helper(1, n, dp);
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i <= n; i++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k++) {
                    if (j > n) {
                        break;
                    }
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1]);
                }
            }
        }
        return dp[1][n];
    }
    int dfs(int res, vector<int> nums, int& _res) {
        if ((int)nums.size() == 0) {
            _res = max(_res, res);
            return 0;
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            /*
            if (i == 0) {
                res += nums[i] * nums[i + 1];
            } else if (i == (int) nums.size() - 1) {
                res += nums[i - 1] * nums[i];
            } else {
                res += nums[i - 1] * nums[i] * nums[i + 1];
            }
            */
            int delt = nums[i] * (i - 1 < 0 ? 1 : nums[i - 1]) * (i + 1 == (int)nums.size() ? 1 : nums[i + 1]);
            int tmp = nums[i];
            nums.erase(nums.begin() + i);
            dfs(res + delt, nums, _res);
            nums.insert(nums.begin() + i, tmp);
        }
        return 0;
    }
};

int main() {
    return 0;
}
