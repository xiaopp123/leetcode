#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp = nums;
        int maxSub = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            if (dp[i - 1] > 0) {
                dp[i] += dp[i - 1];
            } else {
                dp[i] = nums[i];
            }
            maxSub = max(maxSub, dp[i]);
        }

        return maxSub;
    }
};

int main() {

    Solution* solution = new Solution();
    int n;
    vector<int> nums;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }

        cout << solution->maxSubArray(nums) << endl;
    }
    return 0;
}
