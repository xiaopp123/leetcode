#include <cstdio>
#include <vector>
#include <limits.h>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * https://leetcode.com/problems/next-permutation/description/
 * 从右往左扫描，找到第一个a[i] < a[i + 1]
 * 然后在 a[i + 1] - a[n - 1]中找到比a[i]稍微大一点的数a[j] （可以从右往左扫描，因为右边的已经有序)
 * 交换a[i]和a[j]
 * 然后对a[i + 1] - a[n - 1]进行排序
 *
 * 代码写的太差劲
 */

class Solution {
    public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = n - 2;
        while (index >= 0) {
            if (nums[index] >= nums[index + 1]) {
                index--;
                //continue记住
                continue;
            }
            break;
        }
        if (index >= 0) {
            int minD = INT_MAX;
            int largerIndex;
            for (int i = index + 1; i < n; i++) {
                //这里一定是保证nums[i] > nums[index]
                if (nums[i] - nums[index] > 0 && nums[i] - nums[index] < minD) {
                    minD = nums[i] - nums[index];
                    largerIndex = i;
                }
            }
            swap(nums[index], nums[largerIndex]);
        }

        sort(nums.begin() + index + 1, nums.end());

    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        Solution* solution = new Solution();
        solution->nextPermutation(nums);
    }
    return 0;
}
