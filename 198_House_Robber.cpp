#include "heads.h"
using namespace std;

class Solution {
    public:
    int rob(vector<int>& nums) {

    }
};
/*
class Solution {
    public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n, 0);
        int res = 0;
        dp[0] = nums[0];
        dp[1] = nums[1];
        res = max(dp[0], dp[1]);
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < i - 1; j++) {
                dp[i] = max(dp[j] + nums[i], dp[i]);
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};
*/

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        Solution* solution = new Solution();
        cout << solution->rob(nums) << endl;
    }
    return 0;
}
