#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
/**
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 * 两种解法
 * 1、直接二分查找
 * 2、类二分，确定区间内是有序才进行二分（我的思路）
 *
 * 直接二分：
 * 确定mid,
 *     然后确定mid是位于前面有序数组还是后面的有序数组中
 *     nums[l] <= nums[mid],此时位于前面，nums[mid] <= nums[r]此时位于后面的
 *     对于前边的来说，当nums[l] <= nums[mid]时
 *     如果target位于[l, mid],则 r = mid - 1，否则l = mid + 1
 *类二分：
  确定mid,
      然后判断target是否在有序的区间[l, mid]或[mid, r]中，然后就可以对该区间使用二分查找
      否则确定mid在前面的序列还是后面的序列，即nums[l] <= nums[mid], 那么此时target在区间[mid, r]中,所以l = mid + 1(这个逻辑困惑了好久)
*/

/*
class Solution {
    public:
    int search(vector<int>& nums, int target) {
        int r= nums.size();
        if (r == 0) {
            return -1;
        }
        int l = 0;
        r = r - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (nums[mid] <= nums[r]) {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
*/

class Solution {
    public:
    int search(vector<int>& nums, int target) {
        int r = nums.size();
        if (r == 0) {
            return -1;
        }
        r = r - 1;
        int l = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if (target >= nums[l] && target <= nums[mid]) {
                return binarySearch(nums, l, mid, target);
            } else if (target >= nums[mid] && target <= nums[r]) {
                return binarySearch(nums, mid, r, target);
            }

            if (nums[l] <= nums[mid]) {
                l = mid + 1;
            }
            if (nums[mid] <= nums[r]) {
                r = mid - 1;
            }
        }

        return -1;
    }
    public:
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    int n, target;
    while (cin >> n >> target) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        Solution* solution = new Solution();
        cout << solution->search(nums, target) << endl;
    }

    return 0;
}

