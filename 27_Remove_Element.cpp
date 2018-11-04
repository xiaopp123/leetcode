#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

/**
 * https://leetcode.com/problems/remove-element/description/
 * 设置两个指针，一个在前，一个在后
 * 前面的指代的是val,后面的指的不是val，交换这两个位置
 */

class Solution {
    public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int s = 0, e = len - 1;
        while (s < e) {
            while (s < e && nums[s] != val) {
                s++;
            }
            while (s < e && nums[e] == val) {
                e--;
            }
            if (s < e && e >= 0) {
                swap(nums[s++], nums[e--]);
            }
        }
        if (s < len && nums[s] == val) {
            return s;
        }

        return s + 1;
    }
};

int main() {
    int n;
    Solution* solution = new Solution();
    vector<int> nums;
    int val;
    while (cin >> n >> val) {
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        solution->removeElement(nums, val);
    }

    return 0;
}
