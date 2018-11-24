#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * https://leetcode.com/problems/first-missing-positive/description/
 * 计数排序的思想
 * 最终的目标就是 nums[index] = index + 1
 */
class Solution {
    public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 1;
        }
        //枚举每一个位置
        for (int i = 0; i < len; i++) {
            // 如果 nums[i] != i + 1时，就将nums[i]放到它该去的地方，nums[i] - 1 的位置
            while (nums[i] != (i + 1) && nums[i] - 1 >= 0 && nums[i] - 1 < len && nums[ nums[i] - 1 ] != nums[i]) {
                swap(nums[ nums[i] - 1 ], nums[i]);
            }
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return len + 1;
    }
};

int main() {
    Solution* solution = new Solution();
    int n;
    while (cin >> n) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        cout << solution->firstMissingPositive(nums) << endl;
    }


    return 0;
}
