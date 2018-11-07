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
        int n = nums.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
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
