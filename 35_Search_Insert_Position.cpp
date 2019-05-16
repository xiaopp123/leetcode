#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

/**
 * https://leetcode.com/problems/search-insert-position/description/
 * 二分查找
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target <= nums[mid]) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        if (left - 1 >= 0 && target >= nums[left - 1]) {
            return left - 1;
        }
        return left;
    }
};
int main() {
    int n;
    int target;
    Solution* solution = new Solution();
    while (cin >> n >> target) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        cout << solution->searchInsert(nums, target) << endl;

    }

    return 0;
}
