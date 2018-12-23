#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *   4  * 如果出现了可以重复的元素之后，那么左边的就有可能不是有序数组，
 *     3  * 比如 1 3 1 1 1，左边的为 1 3 1，显然不是有序数组
 *       2  * 所以对于左边的数组，先判断nums[l] == nums[mid], 如果相等的话，l + 1, 跳过最左边的元素
 *         1  */
class Solution {
    public:
    bool search(vector<int>& nums, int target) {
        int r = nums.size();
        if (r == 0) {
            return false;
        }
        int l = 0;
        r--;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[l] <= nums[mid]) {
                if (nums[l] == nums[mid]) {
                    l++;
                    continue;
                }
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] <= nums[r]) {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};

int main () {
    Solution* solution = new Solution();
    int n;
    int target;
    while (cin >> n >> target) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        cout << solution->search(nums, target) << endl;
    }
    return 0;
}

