#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 求和很好求，但是乘积最大就不好算了，想到了需要两个数组，一个最大，一个最小，但是不知道怎么更新
 *
 * 以最大值来说，对于某个位置的数，有三个来源，nums[i], dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]
 * 所以求最大就在这三个中取最大，求最小就在这三个数中取最小
 */

/**
class Solution {
    public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int dp_max[n], dp_min[n];
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int res = dp_max[0];

        for (int i = 1; i < n; i++) {
            dp_max[i] = max(max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]), nums[i]);
            dp_min[i] = min(min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]), nums[i]);
            res = max(res, dp_max[i]);
        }

        return res;
    }
};
*/

/**
 * 一种空间复杂度O(1)的解法，因为dp_max, dp_min只和前一个有关，所以没必要用整个数组存储
 */
class Solution {
    public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int preMax = nums[0];
        int preMin = nums[0];
        int curMax, curMin;
        int res = preMax;
        for (int i = 1; i < n; i++) {
            curMax = max(max(preMax * nums[i], preMin * nums[i]), nums[i]);
            curMin = min(min(preMax * nums[i], preMin * nums[i]), nums[i]);
            preMax = curMax;
            preMin = curMin;
            res = max(curMax, res);
        }

        return res;
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
        cout << solution->maxProduct(nums) << endl;
    }
    return 0;
}
