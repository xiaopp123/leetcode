#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 * 三种方法
 * 1、快排
 * 2、优先队列
 * 3、利用快排的思想，按照从大到小的顺序进行排序，每次找到privot，根据privot的index与k进行比较，判断是需要递归左边的还是右边的
 */
class Solution {
    public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (true) {
            int pos = partition(nums, l, r);
            if (pos == k - 1) {
                return nums[pos];
            } else if (k - 1 < pos) {
                r = pos - 1;
            } else {
                l = pos + 1;
            }
        }
    }
    public:
    int partition(vector<int>& nums, int l, int r) {
        int target = nums[l];
        while (l < r) {
            while (l < r && target >= nums[r]) {
                r--;
            }
            if (l < r) {
                swap(nums[l], nums[r]);
            }
            while (l < r && nums[l] >= target) {
                l++;
            }
            if (l < r) {
                swap(nums[l], nums[r]);
            }
        }
        return r;
    }
};
/**
class Solution {
    public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
*/
class Solution {
    public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            q.pop();
        }
        return q.top();
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
        cout << solution->findKthLargest(nums, k);
    }

    return 0;
}

