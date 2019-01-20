#include "heads.h"
using namespace std;

/**
 * sp表示正数和，sn表示负数绝对值和, 则有sp - sn = S
 * sp + sn + sp - sn = sum + S => 2sp = sum + S => sp = (sum + S) / 2
 * 所以该问题转化成 在数组nums中 选择和为(sum + S) / 2的自序列的个数
 *
 */

class Solution {
    public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + S) % 2 || sum < S) {
            return 0;
        }
        int target = (sum + S) / 2;
        int dp[target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j = target; j - nums[i] >= 0; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};

/**
class Solution {
    public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        dfs(nums, S, 0, 0, res);
        return res;
    }
    void dfs(vector<int>& nums, int S, int cnt, int sum, int& res) {
        if (cnt == (int)nums.size()) {
            if (sum == S) {
                res++;
            }
            return;
        }
        dfs(nums, S, cnt + 1, sum + nums[cnt], res);
        dfs(nums, S, cnt + 1, sum - nums[cnt], res);
    }
};
*/

int main () {
    int n;
    int S;
    while (cin >> n >> S) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        Solution* solution = new Solution();
        cout << solution->findTargetSumWays(nums, S);
    }
    return 0;
}
