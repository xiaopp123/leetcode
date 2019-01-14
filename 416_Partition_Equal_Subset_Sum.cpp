#include "heads.h"

using namespace std;

/**
 * 本质就是一个01背包问题
 */

/**
class Solution {
    public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];
        }
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        bool dp[target + 1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j =  target; j > 0; j--) {
                if (j - nums[i] >= 0) {
                    dp[j]  = dp[j] | dp[j - nums[i]];
                }
            }
        }

        return dp[target];
    }
};
*/
/**
 * http://www.cnblogs.com/grandyang/p/5951422.html
 * 不太明白这种解法的思想
 */
class Solution {
    public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        bitset<5001> bits(1);
        for (int i = 0; i < (int)nums.size(); i++) {
            bits |= bits << nums[i];
        }

        return sum % 2 == 0 && bits[sum >> 1];
    }
};

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
        cout << solution->canPartition(nums) << endl;
    }
    return 0;
}
