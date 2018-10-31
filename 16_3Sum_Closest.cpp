#include <cstdio>
#include <cmath>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * https://leetcode.com/problems/3sum-closest/description/
 * 如果三个数的和等于目标数的话 就直接返回
 * 如果目标数与三个数和的差 小于diff(表示在此之前目标值与三个数和的最小值)，修改diff,同时记录这三个数的和
 * 否则根据三个数的和与目标值得关系修改s,e指针
 */

class Solution {
    public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int s, e;
        int n = (int) nums.size();
        int diff = INT_MAX;
        int res = 0;
        for (int i = 0; i < (int) nums.size(); i++) {
            s = i + 1;
            e = n - 1;
            int tempSum;
            while (s < e) {
                tempSum = nums[i] + nums[s] + nums[e];
                if (target - tempSum == 0) {

                    return tempSum;

                } else if (fabs(target - tempSum) < diff) {
                    diff = fabs(target - tempSum);
                    res = tempSum;
                }

                if (tempSum < target) {
                    s++;
                } else {
                    e--;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution* solution = new Solution();
    int n, m;
    vector<int> nums;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        cout << solution->threeSumClosest(nums, m);

    }


    return 0;
}
