#include "heads.h"

using namespace std;

/**
 * hash表存放的是 前缀和对k的模:index
 * 初始化 sum[0] = -1
 * 然后对nums数组开始枚举
 * 如果k != 0, 就用sub_sum 对k取模
 * 然后取hash表里查找是否存在sub_sum,
 * 如果存在根据index判断是否相差大于2, 主要是这样的case: [0] , 0
 */

class Solution {
    public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum;
        sum[0] = -1;
        int sub_sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sub_sum += nums[i];
            if (k != 0) {
                sub_sum %= k;
            }
            if (sum.count(sub_sum) > 0) {
                if ( i - sum[sub_sum] > 1) {
                    return true;
                }
            } else {
                sum[sub_sum] = i;
            }
        }
        return false;
    }
};

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        Solution* solution = new Solution();

        cout << solution->checkSubarraySum(nums, k) << endl;
    }
    return 0;
}
